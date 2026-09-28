/*
 * function: TPi_TpCallback
 * address:  0x0208A6B0
 * packet:   pkt_0208A6B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libspi tp.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  The fatal
 * default arm is a goto to a block after the shared error tail: written as
 * `OS_Terminate(); return;` inside the switch it lands before the tail.
 *
 * symbols:
 *   g_02152FA4                     0x02152FA4  data
 *   OS_Terminate                   0x02088234  arm
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int BOOL;

typedef void (*TPRecvCallback)(int command, int result, u16 index);

typedef struct TPData {
    u16 x;
    u16 y;
    u16 touch;
    u16 validity;
} TPData;

typedef union TPRawData {
    struct {
        u32 x:12;
        u32 y:12;
        u32 touch:1;
        u32 validity:2;
        u32 :5;
    };
    u16 halfs[2];
} TPRawData;

/* tp.o .bss: TP_Init's static `initial` at +0, tpState at +4 */
typedef struct TpBss {
    u16 initial;
    TPRecvCallback callback;
    TPData buf;
    u16 index;
    TPData *samplingBufs;
    u16 bufSize;
    u8 pad1a[0x36 - 0x1a];
    u16 state;
    u16 err_flg;
    volatile u16 command_flg;
} TpBss;

extern TpBss g_02152FA4;
#define tpState g_02152FA4

extern void OS_Terminate(void);

static inline void TPi_ReadRaw(TPData *data)
{
    TPRawData raw;

    raw.halfs[0] = ((volatile u16 *)0x02FFFFAA)[0];
    raw.halfs[1] = ((volatile u16 *)0x02FFFFAA)[1];
    data->x = (u16)raw.x;
    data->y = (u16)raw.y;
    data->touch = (u8)raw.touch;
    data->validity = (u8)raw.validity;
}

void TPi_TpCallback(int tag, u32 data, BOOL err)
{
    u16 result;
    u16 command;

    result = (u16)(data & 0xFFFF);
    command = (u16)((result & 0x7F00) >> 8);

    if (err) {
        tpState.err_flg |= (u16)(1 << command);
        if (tpState.callback) {
            tpState.callback(command, 4, 0);
        }
        return;
    }

    if (command == 0x10) {
        tpState.index++;
        if (tpState.index >= tpState.bufSize) {
            tpState.index = 0;
        }
        TPi_ReadRaw(&tpState.samplingBufs[tpState.index]);
        if (tpState.callback) {
            tpState.callback(command, 0, (u8)tpState.index);
        }
        return;
    }

    if (!(data & 0x1000000)) {
        return;
    }

    switch ((u8)result) {
    case 0:
        switch (command) {
        case 0:
            TPi_ReadRaw(&tpState.buf);
            tpState.state = 0;
            break;
        case 1:
            tpState.state = 2;
            break;
        case 2:
            tpState.state = 0;
            break;
        }
        tpState.command_flg &= (u16)~(1 << command);
        if (tpState.callback) {
            tpState.callback(command, 0, 0);
        }
        return;
    case 4:
        result = 3;
        break;
    case 2:
        result = 1;
        break;
    case 3:
        result = 2;
        break;
    case 1:
    default:
        goto terminate;
    }

    tpState.err_flg |= (u16)(1 << command);
    tpState.command_flg &= (u16)~(1 << command);
    if (tpState.callback) {
        tpState.callback(command, (u8)result, 0);
    }
    return;

terminate:
    OS_Terminate();
}
