/*
 * function: TP_RequestAutoSamplingStartAsync
 * address:  0x0208AC0C
 * packet:   pkt_0208AC0C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      TP_RequestAutoSamplingStartAsync (libspi.TWL.HYB.a tp.o)
 *
 * symbols:
 *   OS_DisableInterrupts           0x02087988  arm
 *   OS_RestoreInterrupts           0x0208799C  arm
 *   PXI_SendWordByFifo             0x02088610  arm
 *   g_02152FA4                     0x02152FA4  data
 *
 * The send result is tested through a u8 cast (tst #0xff); a BOOL or u8
 * return type alone gives cmp #0.
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed short s16;
typedef int BOOL;

typedef void (*TPRecvCallback)(int command, int result, u16 index);

typedef struct TPData {
    u16 x;
    u16 y;
    u16 touch;
    u16 validity;
} TPData;

typedef struct TPCalibrateParam {
    s16 x0;
    s16 y0;
    s16 xDotSize;
    s16 yDotSize;
} TPCalibrateParam;

typedef struct TPiCalibrateParam {
    long x0;
    long xDotSize;
    long xDotSizeInv;
    long y0;
    long yDotSize;
    long yDotSizeInv;
} TPiCalibrateParam;

/* tp.o .bss: TP_Init's static `initial` at +0, tpState (56 bytes) at +4.
   The object addresses both from the section base. */
typedef struct TpBss {
    u16 initial;
    TPRecvCallback callback;
    TPData buf;
    u16 index;
    u16 frequence;
    TPData *samplingBufs;
    u16 bufSize;
    TPiCalibrateParam calibrate;
    u16 calibrate_flg;
    u16 state;
    u16 err_flg;
    volatile u16 command_flg;
} TpBss;

extern TpBss g_02152FA4;
#define tpState g_02152FA4

u32 OS_DisableInterrupts(void);
u32 OS_RestoreInterrupts(u32 state);
int PXI_SendWordByFifo(int fifotag, u32 data, BOOL err);

static inline BOOL TPi_SendAutoStart(u16 vcount, u8 frequence)
{
    if (PXI_SendWordByFifo(6, 0x02000000 | 0x100 | frequence, 0) < 0) {
        return 0;
    }
    if (PXI_SendWordByFifo(6, 0x01000000 | 0x10000 | vcount, 0) < 0) {
        return 0;
    }
    return 1;
}

void TP_RequestAutoSamplingStartAsync(u16 vcount, u16 frequence, TPData samplingBufs[], u16 bufSize)
{
    u32 enabled;
    u32 i;

    tpState.samplingBufs = samplingBufs;
    tpState.index = 0;
    tpState.frequence = frequence;
    tpState.bufSize = bufSize;
    for (i = 0; i < bufSize; i++) {
        tpState.samplingBufs[i].touch = 0;
    }

    enabled = OS_DisableInterrupts();
    if (!(u8)TPi_SendAutoStart(vcount, frequence)) {
        (void)OS_RestoreInterrupts(enabled);
        tpState.err_flg |= 2;
        if (tpState.callback) {
            tpState.callback(1, 4, 0);
        }
        return;
    }
    tpState.command_flg |= 2;
    tpState.err_flg &= ~2;
    (void)OS_RestoreInterrupts(enabled);
}
