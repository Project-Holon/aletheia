/*
 * function: TP_Init
 * address:  0x0208A924
 * packet:   pkt_0208A924
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      TP_Init (libspi.TWL.HYB.a tp.o)
 *
 * symbols:
 *   PXI_Init                       0x02088498  arm
 *   PXI_IsCallbackReady            0x020885EC  arm
 *   PXI_SetFifoRecvCallback        0x020885A0  arm
 *   TPi_TpCallback                 0x0208A6B0  arm
 *   g_02152FA4                     0x02152FA4  data
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

void PXI_Init(void);
BOOL PXI_IsCallbackReady(int fifotag, int proc);
void PXI_SetFifoRecvCallback(int fifotag, void (*callback)(int tag, u32 data, BOOL err));
void TPi_TpCallback(int tag, u32 data, BOOL err);

void TP_Init(void)
{
    if (tpState.initial) {
        return;
    }
    tpState.initial = 1;

    PXI_Init();

    tpState.index = 0;
    tpState.callback = 0;
    tpState.samplingBufs = 0;
    tpState.state = 0;
    tpState.calibrate_flg = 0;
    tpState.command_flg = 0;
    tpState.err_flg = 0;

    while (!PXI_IsCallbackReady(6, 1)) {
    }
    PXI_SetFifoRecvCallback(6, TPi_TpCallback);
}
