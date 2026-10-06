/*
 * file:     unit_02076BBC_p02.c
 * unit:     yes
 * function: func_020770B4, func_02077168
 * address:  0x020770B4
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
 *   OS_GetDTCMAddress  0x02086CE0  arm
 *   CARDi_ReadRomIDCore  0x02076CD0  arm
 *   CARDi_CheckPulledOutCore  0x02077518  arm
 *   CARDi_RefreshRom  0x02076DA0  arm
 *   cardi_rom_base  0x02150840  data
 *   cardi_common  0x02150200  data
 */
typedef unsigned long u32;

typedef int BOOL;

typedef unsigned char u8;

typedef unsigned short u16;

typedef long s32;

typedef struct OSThread OSThread;

typedef struct OSThreadQueue
{
    OSThread *head;
    OSThread *tail;
} OSThreadQueue;

typedef struct CARDiCommandArg CARDiCommandArg;

typedef struct CARDDmaInterface CARDDmaInterface;

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

struct CARDiCommandArg
{
    int result;
};

typedef struct CARDiRomState
{
    u32 rom_base;
    int (*read_func)(void *userdata, void *buffer, u32 offset, u32 length);
} CARDiRomState;

extern void *OS_GetDTCMAddress(void);
extern u32 CARDi_ReadRomIDCore(void);
extern void CARDi_CheckPulledOutCore(u32 id);
extern void CARDi_RefreshRom(u32 warn_mask);
BOOL func_020770B4(u32 dma, void *dst, u32 src, u32 len);
void func_02077168(CARDiCommon *c);
extern CARDiCommon cardi_common;
extern CARDiRomState cardi_rom_base;


static inline BOOL CARDi_IsNotITCM(const void *dst, u32 len)
{
    return ((u32)dst + len <= 0x01FF8000) || ((u32)dst >= 0x02000000);
}


static inline BOOL CARDi_IsNotDTCM(const void *dst, u32 len)
{
    return ((u32)dst + len <= (u32)OS_GetDTCMAddress()) || ((u32)dst >= (u32)OS_GetDTCMAddress() + 0x4000);
}


static inline BOOL CARDi_IsDmaTarget(u32 dma, const void *dst, u32 len)
{
    return (dma <= 3) && (len > 0) && (((u32)dst & 31) == 0) && CARDi_IsNotITCM(dst, len);
}


static inline BOOL CARDi_IsDmaDestination(u32 dma, const void *dst, u32 len)
{
    return CARDi_IsDmaTarget(dma, dst, len) && CARDi_IsNotDTCM(dst, len);
}


/*
 * sdk:      CARDi_IsRomDmaAvailable (libcard.TWL.HYB.a card_rom.o)
 */
BOOL func_020770B4(u32 dma, void *dst, u32 src, u32 len)
{
    return CARDi_IsDmaDestination(dma, dst, len) && (((src | len) & 0x1FF) == 0);
}


/*
 * sdk:      CARDi_ReadRomSyncCore (libcard.TWL.HYB.a card_rom.o)
 */
void func_02077168(CARDiCommon *c)
{
    (void)(*cardi_rom_base.read_func)(0, (void *)c->dst, c->src, c->len);
    CARDi_CheckPulledOutCore(CARDi_ReadRomIDCore());
    CARDi_RefreshRom(8);
    cardi_common.cmd->result = 0;
}
