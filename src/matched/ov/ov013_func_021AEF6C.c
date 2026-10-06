/*
 * function: func_021AEF6C
 * address:  0x021AEF6C
 * packet:   pkt_ov013_021AEF6C
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Start the microphone module: allocate the 0x1A4C-byte work block (G)
 * and its sample buffer on first use, fill the auto-sampling parameter
 * block at G+0x1A20, open the sound channel at G+0x19B8 with
 * func_021AEB7C as its callback, then start the worker from a 0x20-byte
 * parameter block on the stack (callback func_021AED08 in state 3,
 * func_021AED30 otherwise).
 *
 * symbols:
 *   d_021B3C80     0x021B3C80  data  ov013
 *   func_02156F5C  0x02156F5C  thumb  ov009
 *   func_02082BCC  0x02082BCC  arm
 *   func_021AEB20  0x021AEB20  thumb  ov013
 *   func_0202EB0C  0x0202EB0C  thumb
 *   func_02073838  0x02073838  arm
 *   func_02073AD0  0x02073AD0  arm
 *   func_020738C0  0x020738C0  arm
 *   func_021AEB7C  0x021AEB7C  thumb  ov013
 *   func_02034714  0x02034714  arm
 *   func_0216B838  0x0216B838  arm  ov009
 *   func_021AED08  0x021AED08  thumb  ov013
 *   func_021AED30  0x021AED30  thumb  ov013
 *   func_021B370C  0x021B370C  arm  ov013
 *   func_021B0C64  0x021B0C64  arm  ov013
 *   func_021AF124  0x021AF124  thumb  ov013
 *   func_021B0D08  0x021B0D08  arm  ov013
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct WorkerParam {
    void *state;
    int mode;
    int one;
    u8 kind;
    void *buf;
    u32 size;
    void (*cb)(void);
    int zero;
} WorkerParam;

typedef struct MicAutoParam {
    int type;
    void *buffer;
    u32 size;
    u32 rate;
    int loop;
    void *callback;
    void *arg;
} MicAutoParam;

typedef struct Work {
    u8 ring[0x880];
    void *f880;
    u8 f884[0x1984 - 0x884];
    int f1984;
    u8 f1988[0x19A8 - 0x1988];
    int f19A8;
    int f19AC;
    u16 f19B0;
    u8 pad19B2[0x19B8 - 0x19B2];
    u8 f19B8[0x1A1C - 0x19B8];
    int f1A1C;
    MicAutoParam mic;
    u8 pad1A3C[0x1A4B - 0x1A3C];
    u8 f1A4B;
} Work;

extern Work *d_021B3C80;

extern u32 func_02156F5C(u32 a, u32 b, u32 c);
extern void func_02082BCC(void *p, int v, u32 n);
extern void func_021AEB20(void);
extern u32 func_0202EB0C(void);
extern int func_02073838(u8 *o, int n, u8 *src);
typedef signed int     s32;
struct Slot;
extern void func_02073AD0(struct Slot *s, s32 v);
extern int func_020738C0(void *ch, int fmt, void *buf, u32 len, int rate,
                         int x, void (*cb)(void), void *arg);
extern void func_021AEB7C(int mode, u32 n, void **bufs, u32 size, int unused, u32 arg6);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u8 func_0216B838(void);
extern void func_021AED08(int unused, int code, void *p);
extern void func_021AED30(int a, int code, u32 *p);
extern void func_021B370C(WorkerParam *p);
extern int func_021B0C64(int x);
extern void func_021AF124(void);
extern void func_021B0D08(int x);

void func_021AEF6C(void *heap, int arg1, int mode)
{
    WorkerParam param;
    u8 vals[3] = {0, 0, 0};

    if (d_021B3C80 == 0) {
        d_021B3C80 = (Work *)func_02156F5C((u32)heap, sizeof(Work), 0x20);
        func_02082BCC(d_021B3C80, 0, sizeof(Work));
        d_021B3C80->f880 = (void *)func_02156F5C((u32)heap, mode * 0x23C0 + 0x20, 0x20);
        d_021B3C80->f1984 = 0;
        func_021AEB20();
    }
    d_021B3C80->mic.type = 3;
    d_021B3C80->mic.buffer = d_021B3C80;
    d_021B3C80->mic.size = 0x880;
    if (func_0202EB0C() == 0) {
        d_021B3C80->mic.rate = 0x1040;
    } else {
        d_021B3C80->mic.rate = 0x1001;
    }
    d_021B3C80->mic.loop = 1;
    d_021B3C80->mic.callback = 0;
    d_021B3C80->mic.arg = 0;
    d_021B3C80->f1A4B = 1;
    func_02073838(d_021B3C80->f19B8, 1, vals);
    func_02073AD0((struct Slot *)d_021B3C80->f19B8, 0);
    if (func_020738C0(d_021B3C80->f19B8, 1, d_021B3C80->f884, 0x880,
                      func_0202EB0C() ? 0x40 : 0x41, 2, (void (*)(void))func_021AEB7C,
                      d_021B3C80) == 0) {
        func_02034714((void *)0x021B3C20, 0, (void *)0x021B3C20);
    }
    d_021B3C80->f19AC = 0;
    d_021B3C80->f1A1C = 0;
    d_021B3C80->f19A8 = param.one = 1;
    param.state = d_021B3C80->f1988;
    param.mode = mode;
    param.kind = func_0216B838();
    if (param.kind == -1) {
        func_02034714((void *)0x021B3C20, 0, (void *)0x021B3C20);
    }
    if (d_021B3C80->f19A8 == 3) {
        param.cb = (void (*)(void))func_021AED08;
    } else {
        param.cb = (void (*)(void))func_021AED30;
    }
    param.zero = 0;
    param.buf = d_021B3C80->f880;
    param.size = mode * 0x23C0 + 0x20;
    func_021B370C(&param);
    d_021B3C80->f19B0 = 0;
    func_021B0C64(arg1);
    func_021AF124();
    func_021B0D08(1);
}
