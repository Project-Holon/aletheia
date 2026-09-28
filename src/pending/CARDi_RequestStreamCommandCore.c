/*
 * function: CARDi_RequestStreamCommandCore
 * address:  0x02076540
 * packet:   pkt_02076540
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * TwlSDK libcard card_backup.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  Static
 * in the vendor object: runs a backup transfer in chunks of at most one cache
 * page (a sector for sector writes, the device's page size for type 15),
 * staging each chunk through CARDi_backup_cache_page_buf by request mode,
 * with a verify pass for send-verify, until the length is used up, a request
 * fails or the transfer is cancelled.
 *
 * symbols:
 *   OSi_ReferSymbol              0x02004EB0  arm
 *   CARD_GetBackupSectorSize     0x02076B6C  arm
 *   DC_InvalidateRange           0x020862B8  arm
 *   MI_CpuCopy8                  0x02082D44  arm
 *   DC_FlushRange                0x020862F0  arm
 *   DC_WaitWriteBufferEmpty      0x02086314  arm
 *   CARDi_Request                0x020763F0  arm
 *   cardi_backup_assert          0x02005094  data
 *   cardi_common                 0x02150200  data
 *   CARDi_backup_cache_page_buf  0x02150740  data
 */

typedef unsigned char u8;
typedef unsigned long u32;
typedef int BOOL;

#define CARD_STAT_CANCEL               0x40
#define CARD_RESULT_CANCELED           7
#define CARD_REQ_VERIFY_BACKUP         9
#define CARD_REQ_WRITE_SECTOR_BACKUP   11
#define CARD_REQ_15                    15

enum {
    CARD_REQUEST_MODE_RECV,
    CARD_REQUEST_MODE_SEND,
    CARD_REQUEST_MODE_SEND_VERIFY,
    CARD_REQUEST_MODE_SPECIAL
};

typedef struct CARDiCommandArg {
    int result;
    int type;
    u32 id;
    u32 src;
    u32 dest;
    u32 len;
    u32 total_size;
    u32 sect_size;
    u32 page_size;
} CARDiCommandArg;

typedef struct CARDiCommon {
    CARDiCommandArg *cmd;
    volatile u32 flag;
    u8 opaque[0x4FC - 0x8];
    u32 src;
    u32 dst;
    u32 len;
    u32 dma;
    void *DmaCall;
    int req_type;
    int req_retry;
    int req_mode;
} CARDiCommon;

extern CARDiCommon cardi_common;
extern const char cardi_backup_assert[22];
extern u8 CARDi_backup_cache_page_buf[256];

extern void OSi_ReferSymbol(const void *symbol);
extern u32 CARD_GetBackupSectorSize(void);
extern void DC_InvalidateRange(void *startAddr, u32 nBytes);
extern void DC_FlushRange(const void *startAddr, u32 nBytes);
extern void DC_WaitWriteBufferEmpty(void);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern BOOL CARDi_Request(CARDiCommon *p, int req_type, int retry_count);

void CARDi_RequestStreamCommandCore(CARDiCommon *p)
{
    const int req_type = p->req_type;
    const int req_mode = p->req_mode;
    const int retry_count = p->req_retry;
    u32 size = sizeof(CARDi_backup_cache_page_buf);

    OSi_ReferSymbol(cardi_backup_assert);

    if (req_type == CARD_REQ_WRITE_SECTOR_BACKUP) {
        size = CARD_GetBackupSectorSize();
    } else if (req_type == CARD_REQ_15) {
        size = cardi_common.cmd->page_size;
    }

    do {
        const u32 len = (size < p->len) ? size : p->len;
        p->cmd->len = len;

        if ((p->flag & CARD_STAT_CANCEL) != 0) {
            p->flag &= ~CARD_STAT_CANCEL;
            p->cmd->result = CARD_RESULT_CANCELED;
            break;
        }

        switch (req_mode) {
        case CARD_REQUEST_MODE_RECV:
            DC_InvalidateRange(CARDi_backup_cache_page_buf, len);
            p->cmd->src = p->src;
            p->cmd->dest = (u32)CARDi_backup_cache_page_buf;
            break;
        case CARD_REQUEST_MODE_SEND:
        case CARD_REQUEST_MODE_SEND_VERIFY:
            MI_CpuCopy8((const void *)p->src, CARDi_backup_cache_page_buf, len);
            DC_FlushRange(CARDi_backup_cache_page_buf, len);
            DC_WaitWriteBufferEmpty();
            p->cmd->src = (u32)CARDi_backup_cache_page_buf;
            p->cmd->dest = p->dst;
            break;
        case CARD_REQUEST_MODE_SPECIAL:
            p->cmd->src = p->src;
            p->cmd->dest = p->dst;
            break;
        }

        if (!CARDi_Request(p, req_type, retry_count)) {
            break;
        }

        if (req_mode == CARD_REQUEST_MODE_SEND_VERIFY) {
            if (!CARDi_Request(p, CARD_REQ_VERIFY_BACKUP, 1)) {
                break;
            }
        } else if (req_mode == CARD_REQUEST_MODE_RECV) {
            MI_CpuCopy8(CARDi_backup_cache_page_buf, (void *)p->dst, len);
        }

        p->src += len;
        p->dst += len;
        p->len -= len;
    } while (p->len > 0);
}
