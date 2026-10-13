/*
 * function: SNDEXi_PostProcessForShutterSound
 * address:  0x02704940
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
 *   func_02087B20  0x02087B20  arm twl
 *   SendCommand  0x02704B74  arm twl
 *   SetSndexWork  0x02704D48  arm twl
 */

typedef unsigned int u32;
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
extern u32 func_02087B20(void);
u32 SendCommand(u32 a0, u8 a1);
void SetSndexWork(Cb a0, void *a1, void *a2, u32 a3);

u32 SNDEXi_PostProcessForShutterSound(Cb a0, void *a1) {
    u32 r;
    if (func_02087B20() == 0 || DAT_02734450.state != 4) {
        return 4;
    }
    r = 5;
    DAT_02734450.state = 5;
    SetSndexWork(a0, a1, 0, 0xfc);
    if (SendCommand(DAT_02734450.f58, 0) != 0) {
        r = 0;
    }
    return r;
}
