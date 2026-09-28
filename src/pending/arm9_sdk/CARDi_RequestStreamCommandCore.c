/*
 * function: func_02076540
 * address:  0x02076540
 * packet:   pkt_02076540
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * notes:    DIFF 408/408, 21 bytes: a pure register permutation (image: buf r4, req_type r5,
 *            req_mode r6, size r7; this: req_mode r4, size r5, buf r6, req_type r7). A zero-byte
 *            `asm { .align 4 }` as the last statement of the function gives EXACT (match.py one), as
 *            does `#pragma opt_loop_invariants off`; held in pending: no asm instruction and no object
 *            evidence for either (brief asm rule). Shape confirmed by the Rom line table (lines
 *            147-222) and the Debug build (same locals, same switch and MIN clamp).
 *            sdk9f_card: the four registers are allocated in declaration order for non-const
 *            locals, then the hoisted buffer address, then a `const` req_type (const req_mode and
 *            const retry_count change nothing). Declaring `size` first with type/mode/retry
 *            non-const gives type r5, mode r6 and only size/buf swapped (12 bytes), but that
 *            contradicts the DWARF declaration order (req_type, req_mode, retry_count, size, len).
 *
 * sdk:      CARDi_RequestStreamCommandCore (libcard.TWL.HYB.a card_backup.o, static)
 *
 * symbols:
 *   OSi_ReferSymbol  0x02004EB0  arm
 *   CARD_GetBackupSectorSize  0x02076B6C  arm
 *   DC_InvalidateRange  0x020862B8  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   DC_FlushRange  0x020862F0  arm
 *   DC_WaitWriteBufferEmpty  0x02086314  arm
 *   CARDi_Request  0x020763F0  arm
 *   cardi_backup_assert  0x02005094  data
 *   cardi_common  0x02150200  data
 *   CARDi_backup_cache_page_buf  0x02150740  data
 */

typedef unsigned char u8;
typedef unsigned long u32;
typedef long s32;
typedef int BOOL;

typedef struct OSThread OSThread;

typedef struct OSThreadQueue
{
    OSThread *head;
    OSThread *tail;
} OSThreadQueue;

typedef struct CARDBackupTypeInfo
{
    u32 total_size;
    u32 sect_size;
    u32 subsect_size;
    u32 page_size;
    u32 addr_width;
    u32 program_page;
    u32 write_page;
    u32 write_page_total;
    u32 erase_chip;
    u32 erase_chip_total;
    u32 erase_sector;
    u32 erase_sector_total;
    u32 erase_subsector;
    u32 erase_subsector_total;
    u32 erase_page;
    u8 initial_status;
    u8 padding1[3];
    u32 caps;
    u8 padding2[4];
} CARDBackupTypeInfo;

typedef struct CARDiCommandArg
{
    int result;
    int type;
    u32 id;
    u32 src;
    u32 dst;
    u32 len;
    CARDBackupTypeInfo spec;
} CARDiCommandArg;

typedef struct CARDDmaInterface CARDDmaInterface;

typedef struct CARDiCommon
{
    CARDiCommandArg *cmd;
    volatile u32 flag;
    u32 priority;
    u32 flush_threshold_ic;
    u32 flush_threshold_dc;
    s32 lock_owner;
    int lock_ref;
    OSThreadQueue lock_queue[1];
    int lock_target;
    u8 thread[1216];
    void (*task_func)(struct CARDiCommon *);
    void (*callback)(void *);
    void *callback_arg;
    OSThreadQueue busy_q[1];
    u32 src;
    u32 dst;
    u32 len;
    u32 dma;
    CARDDmaInterface *DmaCall;
    int req_type;
    int req_retry;
    int req_mode;
    OSThread *current_thread_9;
} CARDiCommon;

#define CARD_REQ_ERASE_SECTOR_BACKUP    11
#define CARD_REQ_ERASE_SUBSECTOR_BACKUP 15
#define CARD_REQ_VERIFY_BACKUP          9

#define CARD_REQUEST_MODE_RECV          0
#define CARD_REQUEST_MODE_SEND          1
#define CARD_REQUEST_MODE_SEND_VERIFY   2
#define CARD_REQUEST_MODE_SPECIAL       3

#define CARD_STAT_CANCEL                0x40
#define CARD_RESULT_CANCELED            7

extern const char cardi_backup_assert[22];
extern CARDiCommon cardi_common;
extern u8 CARDi_backup_cache_page_buf[256];

extern void OSi_ReferSymbol(const void *symbol);
extern u32 CARD_GetBackupSectorSize(void);
extern void DC_InvalidateRange(void *startAddr, u32 nBytes);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern void DC_FlushRange(const void *startAddr, u32 nBytes);
extern void DC_WaitWriteBufferEmpty(void);
extern BOOL CARDi_Request(CARDiCommon *p, int req_type, int retry_count);

void func_02076540(CARDiCommon *p)
{
    const int req_type = p->req_type;
    const int req_mode = p->req_mode;
    const int retry_count = p->req_retry;
    u32 size = sizeof(CARDi_backup_cache_page_buf);

    OSi_ReferSymbol(cardi_backup_assert);
    if (req_type == CARD_REQ_ERASE_SECTOR_BACKUP)
    {
        size = CARD_GetBackupSectorSize();
    }
    else if (req_type == CARD_REQ_ERASE_SUBSECTOR_BACKUP)
    {
        size = cardi_common.cmd->spec.subsect_size;
    }

    do
    {
        const u32 len = (size < p->len) ? size : p->len;

        p->cmd->len = len;
        if ((p->flag & CARD_STAT_CANCEL) != 0)
        {
            p->flag &= ~CARD_STAT_CANCEL;
            p->cmd->result = CARD_RESULT_CANCELED;
            break;
        }
        switch (req_mode)
        {
        case CARD_REQUEST_MODE_RECV:
            DC_InvalidateRange(CARDi_backup_cache_page_buf, len);
            p->cmd->src = p->src;
            p->cmd->dst = (u32)CARDi_backup_cache_page_buf;
            break;
        case CARD_REQUEST_MODE_SEND:
        case CARD_REQUEST_MODE_SEND_VERIFY:
            MI_CpuCopy8((const void *)p->src, CARDi_backup_cache_page_buf, len);
            DC_FlushRange(CARDi_backup_cache_page_buf, len);
            DC_WaitWriteBufferEmpty();
            p->cmd->src = (u32)CARDi_backup_cache_page_buf;
            p->cmd->dst = p->dst;
            break;
        case CARD_REQUEST_MODE_SPECIAL:
            p->cmd->src = p->src;
            p->cmd->dst = p->dst;
            break;
        }
        if (!CARDi_Request(p, req_type, retry_count))
        {
            break;
        }
        if (req_mode == CARD_REQUEST_MODE_SEND_VERIFY)
        {
            if (!CARDi_Request(p, CARD_REQ_VERIFY_BACKUP, 1))
            {
                break;
            }
        }
        else if (req_mode == CARD_REQUEST_MODE_RECV)
        {
            MI_CpuCopy8(CARDi_backup_cache_page_buf, (void *)p->dst, len);
        }
        p->src += len;
        p->dst += len;
        p->len -= len;
    } while (p->len > 0);
}
