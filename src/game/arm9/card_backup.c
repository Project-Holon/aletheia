/*
 * file:     card_backup.c
 * unit:     yes
 * function: CARDi_OnFifoRecv, CARDi_Request, CARDi_RequestStreamCommandCore, CARDi_IdentifyBackupCore2, CARDi_IdentifyBackupCore, CARDi_BeginBackupCommand, CARDi_RequestStreamCommand, CARD_IdentifyBackup, CARD_GetBackupSectorSize, CARD_WaitBackupAsync, CARD_TryWaitBackupAsync, CARD_CancelBackupAsync
 * address:  0x020763BC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * sdk:      CARD_CancelBackupAsync (libcard.TWL.HYB.a card_backup.o)
 *
 * symbols:
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   cardi_common  0x02150200  data
 *   PXI_IsCallbackReady  0x020885EC  arm
 *   OS_SpinWaitSysCycles  0x02087A04  arm
 *   CARDi_Request  0x020763F0  arm
 *   DC_FlushRange  0x020862F0  arm
 *   DC_WaitWriteBufferEmpty  0x02086314  arm
 *   PXI_SendWordByFifo  0x02088610  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_SleepThread  0x020857B0  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   DC_InvalidateRange  0x020862B8  arm
 *   OSi_ThreadInfo  0x02150FEC  data
 *   OSi_ReferSymbol  0x02004EB0  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   cardi_backup_assert  0x02005094  data
 *   CARDi_backup_cache_page_buf  0x02150740  data
 *   MI_CpuFill8                      0x02082BCC  arm
 *   CARD_CheckEnabled  0x02075DB0  arm
 *   CARDi_GetAccessLevel  0x02075FCC  arm
 *   OS_Terminate  0x02088234  arm
 *   CARDi_WaitForTask  0x02076230  arm
 *   CARDi_BeginBackupCommand  0x02076A70  arm
 *   CARDi_ExecuteOldTypeTask  0x02076170  arm
 *   CARDi_RequestStreamCommandCore  0x02076540  arm
 *   CARDi_IdentifyBackupCore  0x02076A20  arm
 *   CARDi_TryWaitAsync  0x02076070  arm
 *   CARDi_WaitAsync  0x02076050  arm
 */
#define CARD_REQ_ERASE_SECTOR_BACKUP    11
#define CARD_REQ_ERASE_SUBSECTOR_BACKUP 15
#define CARD_REQ_VERIFY_BACKUP          9
#define CARD_REQUEST_MODE_RECV          0
#define CARD_REQUEST_MODE_SEND          1
#define CARD_REQUEST_MODE_SEND_VERIFY   2
#define CARD_REQUEST_MODE_SPECIAL       3
#define CARD_STAT_CANCEL                0x40
#define CARD_RESULT_CANCELED            7
#define CARD_BACKUP_TYPE_DEVICE_SHIFT  0
#define CARD_BACKUP_TYPE_DEVICE_MASK   0xFF
#define CARD_BACKUP_TYPE_DEVICE_EEPROM 1
#define CARD_BACKUP_TYPE_DEVICE_FLASH  2
#define CARD_BACKUP_TYPE_DEVICE_FRAM   3
#define CARD_BACKUP_TYPE_SIZEBIT_SHIFT 8
#define CARD_BACKUP_TYPE_SIZEBIT_MASK  0xFF
#define CARD_BACKUP_TYPE_VENDER_SHIFT  16
#define CARD_BACKUP_TYPE_VENDER_MASK   0xFF
#define CARD_BACKUP_CAPS_AVAILABLE       0x003F
#define CARD_BACKUP_CAPS_READ            0x0040
#define CARD_BACKUP_CAPS_WRITE           0x0080
#define CARD_BACKUP_CAPS_PROGRAM         0x0100
#define CARD_BACKUP_CAPS_VERIFY          0x0200
#define CARD_BACKUP_CAPS_ERASE_PAGE      0x0400
#define CARD_BACKUP_CAPS_ERASE_SECTOR    0x0800
#define CARD_BACKUP_CAPS_ERASE_CHIP      0x1000
#define CARD_BACKUP_CAPS_READ_STATUS     0x2000
#define CARD_BACKUP_CAPS_WRITE_STATUS    0x4000
#define CARD_BACKUP_CAPS_ERASE_SUBSECTOR 0x8000
#define CARD_RESULT_UNSUPPORTED 3
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef long s32;

typedef int BOOL;

typedef struct OSThread OSThread;

typedef struct OSThreadQueue
{
    OSThread *head;
    OSThread *tail;
} OSThreadQueue;

typedef enum CARDBackupType {
    CARD_BACKUP_TYPE_NOT_USE = 0
} CARDBackupType;

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
    CARDBackupType type;
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

typedef struct OSThreadInfo
{
    u16 isNeedRescheduling;
    u16 irqDepth;
    OSThread *current;
} OSThreadInfo;

extern void OS_WakeupThreadDirect(OSThread *thread);
extern BOOL PXI_IsCallbackReady(int fifotag, int proc);
extern void OS_SpinWaitSysCycles(u32 cycle);
extern void DC_FlushRange(void *startAddr, u32 nBytes);
extern void DC_WaitWriteBufferEmpty(void);
extern int PXI_SendWordByFifo(int fifotag, u32 data, BOOL err);
extern u32 OS_DisableInterrupts(void);
extern void OS_SleepThread(OSThreadQueue *queue);
extern u32 OS_RestoreInterrupts(u32 state);
extern void DC_InvalidateRange(void *startAddr, u32 nBytes);
BOOL CARDi_Request(CARDiCommon *p, int req_type, int retry_count);
extern void OSi_ReferSymbol(const void *symbol);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern void CARD_CheckEnabled(void);
extern u32 CARDi_GetAccessLevel(void);
extern void OS_Terminate(void);
extern BOOL CARDi_WaitForTask(CARDiCommon *p, BOOL restart, void (*callback)(void *), void *callback_arg);
extern void CARDi_BeginBackupCommand(u32 level, void (*callback)(void *), void *arg);
extern BOOL CARDi_ExecuteOldTypeTask(void (*task)(CARDiCommon *), BOOL async);
extern void CARDi_RequestStreamCommandCore(CARDiCommon *p);
extern void CARDi_IdentifyBackupCore(CARDiCommon *p);
extern void CARDi_WaitAsync(void);
extern int CARDi_TryWaitAsync(void);
void CARDi_OnFifoRecv(int tag, u32 data, BOOL err);
BOOL CARDi_RequestStreamCommand(u32 src, u32 dst, u32 len, void (*callback)(void *), void *arg, BOOL is_async, int req_type, int req_retry, int req_mode);
BOOL CARD_IdentifyBackup(int type);
u32 CARD_GetBackupSectorSize(void);
void CARD_WaitBackupAsync(void);
u32 CARD_TryWaitBackupAsync(void);
void CARD_CancelBackupAsync(void);
extern CARDiCommon cardi_common;
extern OSThreadInfo OSi_ThreadInfo;
extern const char cardi_backup_assert[22];






/*
 * sdk:      CARDi_OnFifoRecv (libcard.TWL.HYB.a card_backup.o)
 */
void CARDi_OnFifoRecv(int tag, u32 data, BOOL err)
{
#pragma unused(data)
    if ((tag == 11) && err)
    {
        CARDiCommon *const p = &cardi_common;

        p->flag &= ~0x20;
        OS_WakeupThreadDirect(p->current_thread_9);
    }
}






static inline OSThread *OS_GetCurrentThread(void)
{
    return OSi_ThreadInfo.current;
}






/*
 * sdk:      CARDi_Request (libcard.TWL.HYB.a card_backup.o)
 */
BOOL CARDi_Request(CARDiCommon *p, int req_type, int retry_count)
{
    if ((p->flag & 2) == 0)
    {
        p->flag |= 2;
        while (!PXI_IsCallbackReady(11, 1))
        {
            OS_SpinWaitSysCycles(50);
        }
        (void)CARDi_Request(p, 0, 1);
    }
    DC_FlushRange(p->cmd, sizeof(*p->cmd));
    DC_WaitWriteBufferEmpty();
    p->current_thread_9 = OS_GetCurrentThread();
    do
    {
        p->flag |= 0x20;
        while (PXI_SendWordByFifo(11, (u32)req_type, 1) < 0)
        {
        }
        if (req_type == 0)
        {
            const u32 arg = (u32)p->cmd;

            while (PXI_SendWordByFifo(11, arg, 1) < 0)
            {
            }
        }
        {
            u32 bak_psr = OS_DisableInterrupts();

            while ((p->flag & 0x20) != 0)
            {
                OS_SleepThread(0);
            }
            (void)OS_RestoreInterrupts(bak_psr);
        }
        DC_InvalidateRange(p->cmd, sizeof(*p->cmd));
    } while ((p->cmd->result == 4) && (--retry_count > 0));
    return (p->cmd->result == 0);
}




extern u8 CARDi_backup_cache_page_buf[256] __attribute__((aligned(32)));





/*
 * notes:    CARDi_backup_cache_page_buf is a 256-byte static in card_backup.o .bss with
 *            sh_addralign 32; declaring that alignment settles the r4-r7 colouring.
 *
 * sdk:      CARDi_RequestStreamCommandCore (libcard.TWL.HYB.a card_backup.o, static)
 */
void CARDi_RequestStreamCommandCore(CARDiCommon *p)
{
    int req_type = p->req_type;
    int req_mode = p->req_mode;
    int retry_count = p->req_retry;
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




static void CARDi_IdentifyBackupCore2(CARDBackupType type)
{
    {
        CARDiCommandArg *const p = cardi_common.cmd;
        MI_CpuFill8(&p->spec, 0, sizeof(p->spec));
        p->type = type;
        p->spec.caps = (CARD_BACKUP_CAPS_AVAILABLE | CARD_BACKUP_CAPS_READ_STATUS);
        if (type != CARD_BACKUP_TYPE_NOT_USE)
        {
            const u32 size = (u32)(1 << ((type >> CARD_BACKUP_TYPE_SIZEBIT_SHIFT) &
                                         CARD_BACKUP_TYPE_SIZEBIT_MASK));
            const int device =
                ((type >> CARD_BACKUP_TYPE_DEVICE_SHIFT) & CARD_BACKUP_TYPE_DEVICE_MASK);
            const int vender =
                ((type >> CARD_BACKUP_TYPE_VENDER_SHIFT) & CARD_BACKUP_TYPE_VENDER_MASK);
            p->spec.total_size = size;
            p->spec.initial_status = 0xFF;
            if (device == CARD_BACKUP_TYPE_DEVICE_EEPROM)
            {
                switch (size)
                {
                default:
                    goto invalid_type;
                case 0x000200:
                    p->spec.page_size = 0x10;
                    p->spec.addr_width = 1;
                    p->spec.program_page = 5;
                    p->spec.initial_status = 0xF0;
                    break;
                case 0x002000:
                    p->spec.page_size = 0x0020;
                    p->spec.addr_width = 2;
                    p->spec.program_page = 5;
                    p->spec.initial_status = 0x00;
                    break;
                case 0x010000:
                    p->spec.page_size = 0x0080;
                    p->spec.addr_width = 2;
                    p->spec.program_page = 10;
                    p->spec.initial_status = 0x00;
                    break;
                case 0x020000:
                    p->spec.page_size = 0x0100;
                    p->spec.addr_width = 3;
                    p->spec.program_page = 5;
                    p->spec.initial_status = 0x00;
                    break;
                }
                p->spec.sect_size = p->spec.page_size;
                p->spec.caps |= CARD_BACKUP_CAPS_READ;
                p->spec.caps |= CARD_BACKUP_CAPS_PROGRAM;
                p->spec.caps |= CARD_BACKUP_CAPS_VERIFY;
                p->spec.caps |= CARD_BACKUP_CAPS_WRITE_STATUS;
            }
            else if (device == CARD_BACKUP_TYPE_DEVICE_FLASH)
            {
                switch (size)
                {
                default:
                    goto invalid_type;
                case 0x040000:
                case 0x080000:
                case 0x100000:
                    p->spec.write_page = 25;
                    p->spec.write_page_total = 300;
                    p->spec.erase_page = 300;
                    p->spec.erase_sector = 5000;
                    p->spec.caps |= CARD_BACKUP_CAPS_WRITE;
                    p->spec.caps |= CARD_BACKUP_CAPS_ERASE_PAGE;
                    break;
                case 0x200000:
                    p->spec.write_page = 23;
                    p->spec.write_page_total = 300;
                    p->spec.erase_sector = 500;
                    p->spec.erase_sector_total = 5000;
                    p->spec.erase_chip = 10000;
                    p->spec.erase_chip_total = 60000;
                    p->spec.initial_status = 0x00;
                    p->spec.caps |= CARD_BACKUP_CAPS_WRITE;
                    p->spec.caps |= CARD_BACKUP_CAPS_ERASE_PAGE;
                    p->spec.caps |= CARD_BACKUP_CAPS_ERASE_CHIP;
                    p->spec.caps |= CARD_BACKUP_CAPS_WRITE_STATUS;
                    break;
                case 0x400000:
                    p->spec.erase_sector = 600;
                    p->spec.erase_sector_total = 3000;
                    p->spec.erase_subsector = 70;
                    p->spec.erase_subsector_total = 150;
                    p->spec.erase_chip = 23000;
                    p->spec.erase_chip_total = 800000;
                    p->spec.initial_status = 0x00;
                    p->spec.subsect_size = 0x1000;
                    p->spec.caps |= CARD_BACKUP_CAPS_ERASE_SUBSECTOR;
                    p->spec.caps |= CARD_BACKUP_CAPS_ERASE_CHIP;
                    p->spec.caps |= CARD_BACKUP_CAPS_WRITE_STATUS;
                    break;
                case 0x800000:
                    if (vender == 0)
                    {
                        p->spec.erase_sector = 1000;
                        p->spec.erase_sector_total = 3000;
                        p->spec.erase_chip = 68000;
                        p->spec.erase_chip_total = 160000;
                        p->spec.initial_status = 0x00;
                        p->spec.caps |= CARD_BACKUP_CAPS_ERASE_CHIP;
                        p->spec.caps |= CARD_BACKUP_CAPS_WRITE_STATUS;
                    }
                    else if (vender == 1)
                    {
                        p->spec.erase_sector = 1000;
                        p->spec.erase_sector_total = 3000;
                        p->spec.erase_chip = 68000;
                        p->spec.erase_chip_total = 160000;
                        p->spec.initial_status = 0x84;
                        p->spec.caps |= CARD_BACKUP_CAPS_ERASE_CHIP;
                        p->spec.caps |= CARD_BACKUP_CAPS_WRITE_STATUS;
                    }
                    break;
                }
                p->spec.sect_size = 0x010000;
                p->spec.page_size = 0x0100;
                p->spec.addr_width = 3;
                p->spec.program_page = 5;
                p->spec.caps |= CARD_BACKUP_CAPS_READ;
                p->spec.caps |= CARD_BACKUP_CAPS_PROGRAM;
                p->spec.caps |= CARD_BACKUP_CAPS_VERIFY;
                p->spec.caps |= CARD_BACKUP_CAPS_ERASE_SECTOR;
            }
            else if (device == CARD_BACKUP_TYPE_DEVICE_FRAM)
            {
                switch (size)
                {
                default:
                    goto invalid_type;
                case 0x002000:
                case 0x008000:
                    break;
                }
                p->spec.page_size = size;
                p->spec.sect_size = size;
                p->spec.addr_width = 2;
                p->spec.initial_status = 0x00;
                p->spec.caps |= CARD_BACKUP_CAPS_READ;
                p->spec.caps |= CARD_BACKUP_CAPS_PROGRAM;
                p->spec.caps |= CARD_BACKUP_CAPS_VERIFY;
                p->spec.caps |= CARD_BACKUP_CAPS_WRITE_STATUS;
            }
            else
            {
              invalid_type:
                p->type = CARD_BACKUP_TYPE_NOT_USE;
                p->spec.total_size = 0;
                cardi_common.cmd->result = CARD_RESULT_UNSUPPORTED;
                return;
            }
        }
    }
}




/*
 * sdk:      CARDi_IdentifyBackupCore (libcard.TWL.HYB.a card_backup.o)
 */
void CARDi_IdentifyBackupCore(CARDiCommon *p)
{
    (void)CARDi_Request(p, 2, 1);
    p->cmd->src = 0;
    p->cmd->dst = (u32)CARDi_backup_cache_page_buf;
    p->cmd->len = 1;
    (void)CARDi_Request(p, 6, 1);
}




/*
 * sdk:      CARDi_BeginBackupCommand (libcard.TWL.HYB.a card_backup.o)
 */
void CARDi_BeginBackupCommand(u32 level, void (*callback)(void *), void *arg)
{
    OSi_ReferSymbol(cardi_backup_assert);
    CARD_CheckEnabled();
    if ((level & CARDi_GetAccessLevel()) != level)
    {
        OS_Terminate();
    }
    (void)CARDi_WaitForTask(&cardi_common, 1, callback, arg);
}




/*
 * sdk:      CARDi_RequestStreamCommand (libcard.TWL.HYB.a card_backup.o)
 */
BOOL CARDi_RequestStreamCommand(u32 src, u32 dst, u32 len, void (*callback)(void *), void *arg, BOOL is_async,
                   int req_type, int req_retry, int req_mode)
{
    CARDiCommon *p;

    CARDi_BeginBackupCommand((req_mode == 0) ? 1 : 2, callback, arg);
    p = &cardi_common;
    p->src = src;
    p->dst = dst;
    p->len = len;
    p->req_type = req_type;
    p->req_retry = req_retry;
    p->req_mode = req_mode;
    return CARDi_ExecuteOldTypeTask(CARDi_RequestStreamCommandCore, is_async);
}




/*
 * sdk:      CARD_IdentifyBackup (libcard.TWL.HYB.a card_backup.o)
 */
BOOL CARD_IdentifyBackup(int type)
{
    if (type == 0)
    {
        OS_Terminate();
    }
    CARDi_BeginBackupCommand(0, 0, 0);
    CARDi_IdentifyBackupCore2(type);
    return CARDi_ExecuteOldTypeTask(CARDi_IdentifyBackupCore, 0);
}




u32 CARD_GetBackupSectorSize(void)
{
    return cardi_common.cmd->spec.sect_size;
}


void CARD_WaitBackupAsync(void){ CARDi_WaitAsync(); }



/*
 * Eight bytes of code and its own pool word: a bare tail call, the shortest
 * shape this front end emits for `void f(void) { g(); }`.  Its one
 * relocation is the pool word naming CARDi_TryWaitAsync, which has no outside
 * label, so the file only reaches EXACT once CARDi_TryWaitAsync itself is in a
 * shard (bottom-up: it was filed as src/matched/CARDi_TryWaitAsync.c first, and
 * the site then resolves through the `matched` class).
 */
u32 CARD_TryWaitBackupAsync(void)
{
    return CARDi_TryWaitAsync();
}


void CARD_CancelBackupAsync(void)
{
    u32 bak_cpsr = OS_DisableInterrupts();

    cardi_common.flag |= 0x40;
    (void)OS_RestoreInterrupts(bak_cpsr);
}
