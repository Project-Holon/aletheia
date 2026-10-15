/*
 * function: SNDEXi_PreProcessForShutterSound
 * address:  0x02704858
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DAT_02150fec  0x02150fec  data twl
 *   DAT_02734450  0x02734450  data twl
 *   OS_InitMessageQueue  0x02085D94  arm twl
 *   func_02085E50  0x02085E50  arm twl
 *   OSi_IsCodecTwlMode  0x02087B20  arm twl
 *   SyncCallback  0x02704B58  arm twl
 *   SendCommand  0x02704B74  arm twl
 *   CheckState  0x02704C5C  arm twl
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

extern u32 DAT_02150fec[];
extern State DAT_02734450;
extern void OS_InitMessageQueue(void *, void *, u32);
extern void func_02085E50(void *, void *, u32);
extern u32 OSi_IsCodecTwlMode(void);
void SyncCallback(u32 a0, void *a1);
u32 SendCommand(u32 a0, u8 a1);
u32 CheckState(void);
void SetSndexWork(Cb a0, void *a1, void *a2, u32 a3);

u32 SNDEXi_PreProcessForShutterSound(void) {
    u32 result;
    u32 buf[1];
    u32 q[8];
    if (OSi_IsCodecTwlMode() == 0) {
        return 4;
    }
    if (DAT_02150fec[1] == 0) {
        return 4;
    }
    if (DAT_02734450.state != 4) {
        result = CheckState();
        if (result != 0) {
            return result;
        }
    } else if (DAT_02734450.state == 5) {
        return 3;
    }
    OS_InitMessageQueue(q, buf, 1);
    SetSndexWork(SyncCallback, q, 0, 0xfb);
    if (SendCommand(DAT_02734450.f58, 0) == 0) {
        return 5;
    }
    func_02085E50(q, &result, 1);
    return result;
}
