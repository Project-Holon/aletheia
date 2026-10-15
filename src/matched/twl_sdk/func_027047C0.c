/*
 * function: SNDEXi_SetIirFilter
 * address:  0x027047C0
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
 *   OS_InitMessageQueue  0x02085D94  arm twl
 *   func_02085E50  0x02085E50  arm twl
 *   SNDEXi_SetIirFilterAsync  0x027044F8  arm twl
 *   SyncCallback  0x02704B58  arm twl
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

extern u32 DAT_02150fec[];
extern void OS_InitMessageQueue(void *, void *, u32);
extern void func_02085E50(void *, void *, u32);
u32 SNDEXi_SetIirFilterAsync(u32 a0, u16 *a1, Cb a2, void *a3);
void SyncCallback(u32 a0, void *a1);

u32 SNDEXi_SetIirFilter(u32 a0, u16 *a1) {
    u32 result;
    u32 buf[1];
    u32 q[8];
    if (DAT_02150fec[1] == 0) {
        return 4;
    }
    OS_InitMessageQueue(q, buf, 1);
    result = SNDEXi_SetIirFilterAsync(a0, a1, SyncCallback, q);
    if (result == 0) {
        func_02085E50(q, &result, 1);
    }
    {
        State *s = (State *)0x02734450;
        s->f18 = 0;
        s->busy = 0;
    }
    return result;
}
