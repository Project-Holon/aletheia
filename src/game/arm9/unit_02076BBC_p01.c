/*
 * file:     unit_02076BBC_p01.c
 * unit:     yes
 * function: func_02076BBC, func_02076C3C, func_02076C88, func_02076CD0, func_02076D38, func_02076DA0, func_02076E00, func_02076E4C, func_02076F68, func_02077008, func_02077084
 * address:  0x02076BBC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   CARD_GetOwnRomHeaderTWL  0x02075E04  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   OS_GetBootType  0x02087B04  arm
 *   CARDi_IsNormalMode  0x02076C3C  arm
 *   CARDi_SetRomOp  0x02076BBC  arm
 *   CARDi_ReadRomStatusCore  0x02076D38  arm
 *   CARDi_RefreshRomCore  0x02076E00  arm
 *   OS_IsAlarmAvailable  0x02087244  arm
 *   OS_Sleep  0x02085A38  arm
 *   OSi_IsThreadInitialized  0x02150FDC  data
 *   CARDi_StartRomPageTransfer  0x02076C88  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   CARDi_ReadRomIDCore  0x02076CD0  arm
 *   CARDi_CheckPulledOutCore  0x02077518  arm
 *   CARDiEnableCacheInvalidationDC  0x020A8498  data
 *   CARDi_cache_buf  0x02150900  data
 *   OS_DisableIrqMask  0x02084998  arm
 *   OS_ResetRequestIrqMask  0x020849C8  arm
 *   cardi_rom_base  0x02150840  data
 *   cardi_common  0x02150200  data
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_SetIrqFunction  0x02084774  arm
 *   OS_EnableIrqMask  0x02084968  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   CARDi_DmaReadPageCallback  0x02076F68  arm
 *   CARDi_RefreshRom  0x02076DA0  arm
 *   CARDi_EndTask  0x020762A8  arm
 */
typedef unsigned short u16;

typedef unsigned long u32;

typedef volatile u16 vu16;

typedef volatile u32 vu32;

typedef unsigned char u8;

typedef int BOOL;

typedef struct CARDRomHeaderTWL
{
    u8 ntr[0x1B4];
    struct
    {
        u32 bit00_04 : 5;
        u32 bit05 : 1;
        u32 bit06_07 : 2;
        u32 bit08 : 1;
        u32 bit09_31 : 23;
    } access_control;
} CARDRomHeaderTWL;

typedef struct CARDiRomCacheState
{
    BOOL enable_dc_invalidation;
    u32 cached_page;
} CARDiRomCacheState;

typedef long s32;

typedef struct OSThread OSThread;

typedef struct OSThreadQueue
{
    OSThread *head;
    OSThread *tail;
} OSThreadQueue;

typedef struct CARDiCommandArg CARDiCommandArg;

typedef struct CARDDmaInterface
{
    void (*Recv_02076BBC)(u32 channel, const void *src, void *dst, u32 len);
    void (*Stop)(u32 channel);
} CARDDmaInterface;

typedef struct CARDiCommon
{
    CARDiCommandArg *cmd;
    u32 flag;
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

typedef struct CARDTransferInfo
{
    u32 command;
    void (*callback)(void *);
    void *userdata;
    u32 src;
    u32 dst;
    u32 len;
    u32 work;
} CARDTransferInfo;

typedef struct CARDiRomState
{
    u32 rom_base;
    void *read_func;
    u32 unk08;
    CARDTransferInfo *transfer_info;
} CARDiRomState;

typedef struct CARDDmaInterface CARDDmaInterface;

struct CARDiCommandArg
{
    int result;
};

extern CARDRomHeaderTWL *CARD_GetOwnRomHeaderTWL(void);
extern BOOL OS_IsRunOnTwl(void);
extern u16 OS_GetBootType(void);
extern BOOL CARDi_IsNormalMode(void);
extern void CARDi_SetRomOp(u32 command, u32 offset);
extern u32 CARDi_ReadRomStatusCore(void);
extern void CARDi_RefreshRomCore(void);
extern BOOL OS_IsAlarmAvailable(void);
extern void OS_Sleep(u32 msec);
extern void CARDi_StartRomPageTransfer(u32 offset);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern u32 CARDi_ReadRomIDCore(void);
extern void CARDi_CheckPulledOutCore(u32 id);
extern u32 OS_DisableIrqMask(u32 intr);
extern u32 OS_ResetRequestIrqMask(u32 intr);
extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32 state);
extern void OS_SetIrqFunction(u32 intrBit, void (*function)(void));
extern u32 OS_EnableIrqMask(u32 intr);
extern void CARDi_DmaReadPageCallback(void);
extern void CARDi_RefreshRom(u32 warn_mask);
extern void CARDi_EndTask(CARDiCommon *p);
void func_02076BBC(u32 command, u32 offset);
BOOL func_02076C3C(void);
void func_02076C88(u32 offset);
u32 func_02076CD0(void);
u32 func_02076D38(void);
void func_02076DA0(u32 warn_mask);
void func_02076E00(void);
BOOL func_02076E4C(void *userdata, void *buffer, u32 offset, u32 length);
void func_02076F68(void);
void func_02077008(CARDTransferInfo *info);
void func_02077084(void);
extern BOOL OSi_IsThreadInitialized;
extern CARDiRomCacheState CARDiEnableCacheInvalidationDC;
extern CARDiCommon cardi_common;
extern CARDiRomState cardi_rom_base;




#define reg_MI_MCCNT0 (*(vu16 *)0x040001A0)



#define reg_MI_MCCNT1 (*(vu32 *)0x040001A4)



#define reg_MI_MCCMD0 (*(vu32 *)0x040001A8)



#define reg_MI_MCCMD1 (*(vu32 *)0x040001AC)




#define MI_HToBE32(x) ((((x) & 0xFF000000) >> 24) | (((x) & 0x00FF0000) >> 8) | (((x) & 0x0000FF00) << 8) | ((x) << 24))




/*
 * sdk:      CARDi_SetRomOp (libcard.TWL.HYB.a card_rom.o)
 */
void func_02076BBC(u32 command, u32 offset)
{
    u32 cmd1 = (u32)((offset >> 8) | (command << 24));
    u32 cmd2 = (u32)((offset << 24));

    while ((reg_MI_MCCNT1 & 0x80000000) != 0)
    {
    }
    reg_MI_MCCNT0 = (u16)((reg_MI_MCCNT0 & ~0x2000) | 0xC000);
    reg_MI_MCCMD0 = MI_HToBE32(cmd1);
    reg_MI_MCCMD1 = MI_HToBE32(cmd2);
}




/*
 * sdk:      CARDi_IsNormalMode (libcard.TWL.HYB.a card_rom.o)
 */
BOOL func_02076C3C(void)
{
    const CARDRomHeaderTWL *oh = CARD_GetOwnRomHeaderTWL();

    return OS_IsRunOnTwl() &&
           (OS_GetBootType() != 1) &&
           oh->access_control.bit05 &&
           !oh->access_control.bit08;
}




#define CARDi_romctrl (*(vu32 *)0x02FFFAE0)



#define reg_MI_MCCNT1 (*(vu32 *)0x040001A4)




/*
 * sdk:      CARDi_StartRomPageTransfer (libcard.TWL.HYB.a card_rom.o)
 */
void func_02076C88(u32 offset)
{
    u8 op = 0xB7;

    if (CARDi_IsNormalMode())
    {
        op = 0x00;
    }
    CARDi_SetRomOp(op, offset);
    reg_MI_MCCNT1 = (CARDi_romctrl & ~0x07000000) | 0xA1000000;
}




#define CARDi_romctrl (*(vu32 *)0x02FFFAE0)



#define reg_MI_MCCNT1 (*(vu32 *)0x040001A4)



#define reg_MI_MCD1 (*(vu32 *)0x04100010)




/*
 * sdk:      CARDi_ReadRomIDCore (libcard.TWL.HYB.a card_rom.o)
 */
u32 func_02076CD0(void)
{
    u8 op = 0xB8;

    if (CARDi_IsNormalMode())
    {
        op = 0x90;
    }
    CARDi_SetRomOp(op, 0);
    reg_MI_MCCNT1 = (u32)((CARDi_romctrl & ~0x07000000) | 0xA7000000) & ~0x1FFF;
    while ((reg_MI_MCCNT1 & 0x00800000) == 0)
    {
    }
    return reg_MI_MCD1;
}




#define CARDi_romctrl (*(vu32 *)0x02FFFAE0)



#define CARDi_romid (*(vu32 *)0x02FFFC00)



#define reg_MI_MCCNT1 (*(vu32 *)0x040001A4)



#define reg_MI_MCD1 (*(vu32 *)0x04100010)




/*
 * sdk:      CARDi_ReadRomStatusCore (libcard.TWL.HYB.a card_rom.o)
 */
u32 func_02076D38(void)
{
    if ((CARDi_romid & 0x20000000) == 0)
    {
        return 0x20;
    }
    CARDi_SetRomOp(0xD6, 0);
    reg_MI_MCCNT1 = (u32)((CARDi_romctrl & ~0x07000000) | 0xA7000000) & ~0x1FFF;
    while ((reg_MI_MCCNT1 & 0x00800000) == 0)
    {
    }
    return reg_MI_MCD1;
}




/*
 * sdk:      CARDi_RefreshRom (libcard.TWL.HYB.a card_rom.o)
 */
void func_02076DA0(u32 warn_mask)
{
    if ((CARDi_ReadRomStatusCore() & warn_mask) != 0)
    {
        CARDi_RefreshRomCore();
        while ((CARDi_ReadRomStatusCore() & 0x20) == 0)
        {
            if (OSi_IsThreadInitialized && OS_IsAlarmAvailable())
            {
                OS_Sleep(1);
            }
        }
    }
}




#define CARDi_romctrl (*(vu32 *)0x02FFFAE0)



#define reg_MI_MCCNT1 (*(vu32 *)0x040001A4)




/*
 * sdk:      CARDi_RefreshRomCore (libcard.TWL.HYB.a card_rom.o)
 */
void func_02076E00(void)
{
    CARDi_SetRomOp(0xB5, 0);
    reg_MI_MCCNT1 = (u32)((CARDi_romctrl & ~0x07000000) | 0xA0000000) & ~0x1FFF;
    while ((reg_MI_MCCNT1 & 0x80000000) != 0)
    {
    }
}




#define reg_MI_MCCNT1 (*(vu32 *)0x040001A4)



#define reg_MI_MCD1 (*(vu32 *)0x04100010)



extern u8 CARDi_cache_buf[512] __attribute__((aligned(32)));




#define CARD_ROM_PAGE_SIZE 512



#define MATH_ROUNDDOWN(x, align) ((x) & ~((align) - 1))



#define MATH_MIN(a, b) (((a) <= (b)) ? (a) : (b))



#define REG_MI_MCCNT1_RDY_MASK 0x00800000



#define REG_MI_MCCNT1_START_MASK 0x80000000




/*
 * notes:    CARDi_cache_buf is a 512-byte static in card_rom.o .bss with sh_addralign 32;
 *            declaring that alignment keeps n as a real copy at the compare.
 *
 * sdk:      CARDi_ReadRomWithCPU (libcard.TWL.HYB.a card_rom.o)
 */
BOOL func_02076E4C(void *userdata, void *buffer, u32 offset, u32 length)
{
    BOOL retval = (BOOL)length;
    u32 cachedPage = CARDiEnableCacheInvalidationDC.cached_page;
    u8 *const cacheBuffer = CARDi_cache_buf;
    while (length > 0)
    {
        u8 *ptr = (u8 *)buffer;
        u32 n = CARD_ROM_PAGE_SIZE;
        u32 pos = MATH_ROUNDDOWN(offset, CARD_ROM_PAGE_SIZE);
        if (pos == cachedPage)
        {
            ptr = cacheBuffer;
        }
        else
        {
            if ((pos != offset) || (((u32)buffer & 3) != 0) || (length < n))
            {
                ptr = cacheBuffer;
                cachedPage = pos;
            }
            CARDi_StartRomPageTransfer(pos);
            {
                u32 word = 0;
                for (;;)
                {
                    u32 ctrl = reg_MI_MCCNT1;
                    if ((ctrl & REG_MI_MCCNT1_RDY_MASK) != 0)
                    {
                        u32 data = reg_MI_MCD1;
                        if (word < CARD_ROM_PAGE_SIZE / sizeof(u32))
                        {
                            ((u32 *)ptr)[word++] = data;
                        }
                    }
                    if ((ctrl & REG_MI_MCCNT1_START_MASK) == 0)
                    {
                        break;
                    }
                }
            }
        }
        if (ptr == cacheBuffer)
        {
            u32 mod = offset - pos;
            n = MATH_MIN(length, CARD_ROM_PAGE_SIZE - mod);
            MI_CpuCopy8(cacheBuffer + mod, buffer, n);
        }
        buffer = (u8 *)buffer + n;
        offset += n;
        length -= n;
    }
    
    CARDi_CheckPulledOutCore(CARDi_ReadRomIDCore());
    CARDiEnableCacheInvalidationDC.cached_page = cachedPage;
    return retval;
}




/*
 * sdk:      CARDi_DmaReadPageCallback (libcard.TWL.HYB.a card_rom.o)
 */
void func_02076F68(void)
{
    CARDTransferInfo *const info = cardi_rom_base.transfer_info;

    if (info)
    {
        info->src += 512;
        info->dst += 512;
        info->len -= 512;
        if (info->len != 0)
        {
            CARDi_StartRomPageTransfer(info->src);
        }
        else
        {
            (*cardi_common.DmaCall->Stop)(cardi_common.dma);
            (void)OS_DisableIrqMask(0x80000);
            (void)OS_ResetRequestIrqMask(0x80000);
            cardi_rom_base.transfer_info = 0;
            CARDi_CheckPulledOutCore(CARDi_ReadRomIDCore());
            if (info->callback)
            {
                (*info->callback)(info->userdata);
            }
        }
    }
}



/*
 * sdk:      CARDi_ReadRomWithDMA (libcard.TWL.HYB.a card_rom.o)
 */
void func_02077008(CARDTransferInfo *info)
{
    u32 bak_psr = OS_DisableInterrupts();

    cardi_rom_base.transfer_info = info;
    OS_SetIrqFunction(0x80000, CARDi_DmaReadPageCallback);
    (void)OS_ResetRequestIrqMask(0x80000);
    (void)OS_EnableIrqMask(0x80000);
    (void)OS_RestoreInterrupts(bak_psr);
    {
        CARDiCommon *const p = &cardi_common;

        (*p->DmaCall->Recv_02076BBC)(p->dma, (const void *)0x04100010, (void *)info->dst, 0x200);
    }
    CARDi_StartRomPageTransfer(info->src);
}



/*
 * sdk:      CARDi_DmaReadDone (libcard.TWL.HYB.a card_rom.o)
 */
void func_02077084(void)
{
    CARDi_CheckPulledOutCore(CARDi_ReadRomIDCore());
    CARDi_RefreshRom(8);
    cardi_common.cmd->result = 0;
    CARDi_EndTask(&cardi_common);
}
