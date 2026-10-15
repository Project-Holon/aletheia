/*
 * function: SNDEXi_SetIirFilterAsync
 * address:  0x027044F8
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DAT_02734450  0x02734450  data twl
 *   OS_SpinWaitSysCycles  0x02087A04  arm twl
 *   OSi_IsCodecTwlMode  0x02087B20  arm twl
 *   SendCommandEx  0x02704BE0  arm twl
 *   CheckState  0x02704C5C  arm twl
 *   SetSndexWork  0x02704D48  arm twl
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef void (*Cb)(u32, void *);

typedef struct {
    u32 pad0;
    u32 busy;
    u32 pad8;
    volatile u32 state;
    u32 pad10;
    u32 pad14;
    u32 f18;
    void (*f1c)(void);
    u32 f20;
    u32 pad24;
    u32 pad28;
    Cb f2c;
    void *f30;
    u32 pad34;
    u32 pad38;
    void (*f3c)(void);
    u32 f40;
    u32 pad44;
    u32 pad48;
    Cb f4c;
    void *f50;
    void *f54;
    u8 f58;
} State;

extern State DAT_02734450;
extern void OS_SpinWaitSysCycles(u32);
extern u32 OSi_IsCodecTwlMode(void);
u32 SendCommandEx(u32 a0, u32 a1);
u32 CheckState(void);
void SetSndexWork(Cb a0, void *a1, void *a2, u32 a3);

#define WAIT_IDLE() \
    do { \
        OS_SpinWaitSysCycles(0x82dc); \
        while (CheckState() != 0) { \
            OS_SpinWaitSysCycles(0x82dc); \
        } \
    } while (0)

u32 SNDEXi_SetIirFilterAsync(u32 a0, u16 *a1, Cb a2, void *a3) {
    u32 r;
    if (DAT_02734450.busy != 0) {
        return 3;
    }
    DAT_02734450.busy = 1;
    if (OSi_IsCodecTwlMode() == 0) {
        DAT_02734450.busy = 0;
        return 4;
    }
    r = CheckState();
    if (r != 0) {
        DAT_02734450.busy = 0;
        return r;
    }
    SetSndexWork(0, 0, 0, 0xc1);
    if (SendCommandEx(DAT_02734450.f58, (u16)a0) == 0) {
        DAT_02734450.busy = 0;
        return 5;
    }
    WAIT_IDLE();
    SetSndexWork(0, 0, 0, 0xc2);
    if (SendCommandEx(DAT_02734450.f58, a1[0]) == 0) {
        DAT_02734450.busy = 0;
        return 5;
    }
    WAIT_IDLE();
    SetSndexWork(0, 0, 0, 0xc3);
    if (SendCommandEx(DAT_02734450.f58, a1[1]) == 0) {
        DAT_02734450.busy = 0;
        return 5;
    }
    WAIT_IDLE();
    SetSndexWork(0, 0, 0, 0xc4);
    if (SendCommandEx(DAT_02734450.f58, a1[2]) == 0) {
        DAT_02734450.busy = 0;
        return 5;
    }
    WAIT_IDLE();
    SetSndexWork(0, 0, 0, 0xc5);
    if (SendCommandEx(DAT_02734450.f58, a1[3]) == 0) {
        DAT_02734450.busy = 0;
        return 5;
    }
    WAIT_IDLE();
    SetSndexWork(0, 0, 0, 0xc6);
    if (SendCommandEx(DAT_02734450.f58, a1[4]) == 0) {
        DAT_02734450.busy = 0;
        return 5;
    }
    WAIT_IDLE();
    SetSndexWork(a2, a3, 0, 0xc7);
    if (SendCommandEx(DAT_02734450.f58, 0) == 0) {
        DAT_02734450.busy = 0;
        return 5;
    }
    return 0;
}
