/*
 * function: func_020738C0
 * address:  0x020738C0
 * packet:   pkt_020737C0
 * status:   EXACT
 * isa:      arm
 * compiler: ../2.0/sp2
 * symbols:
 *   func_02073AB4  0x02073AB4  arm
 *   func_0209C2B0  0x0209C2B0  arm
 *   func_020729C0  0x020729C0  arm
 *   func_02089660  0x02089660  arm
 *   func_02089540  0x02089540  arm
 *   func_020604AC  0x020604AC  arm
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   func_02073BF0  0x02073BF0  arm
 *   func_02073BE0  0x02073BE0  arm
 *   g_0214E934     0x0214E934  data
 *   g_0214E8E8     0x0214E8E8  data
 *
 * The sound object's start: tear down a running instance, size the per-slot
 * buffer (func_0209C2B0 is the divide), claim a hardware channel through
 * func_020729C0 (negative = none, answer 0), set up one PCM channel per slot
 * byte at +0x54 with its buffer address recorded in g_0214E934, arm the timer
 * func_02089540 with the callback func_02073BE0 (a 16-byte tail-call leaf,
 * filed EXACT alongside this so the pool word has a `matched` witness), link
 * the object into g_0214E8E8, latch the parameters, and prime one step of
 * func_02073BF0 with the frame count forced to 1 inside a
 * func_02087988/func_0208799C bracket.
 *
 * One lever: the first quotient is its own statement (`size = div(...);
 * size = (size * frames) << 5;`).  Folded into one expression the multiply
 * comes out `mul r0, fp, r0` instead of the image's `mul r1, r0, fp`.
 */
typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed   int  s32;

struct SlotDesc { u32 a; u32 b; };

struct SndObj {
    u8  pad_00[0x28];
    u32 f28;
    s32 flag0 : 1;
    u32 flag_hi : 31;
    u32 f30;
    s32 f34;
    u32 f38;
    u32 f3c;
    u32 f40;
    u32 f44;
    s32 f48;
    u32 f4c;
    s32 f50;
    u8  f54[4];
};

extern struct SlotDesc g_0214E934[];
extern u8 g_0214E8E8[];

extern void func_02073AB4(struct SndObj *o);
extern u32  func_0209C2B0(u32 a, s32 b);
extern s32  func_020729C0(void);
extern void func_02089660(u32 chan, int fmt, u32 data, int loopmode,
                          int a, int b, int vol, int pan, u32 period, int e);
extern void func_02089540(s32 chan, u32 a, u32 b, void (*cb)(void *), void *arg);
extern void func_020604AC(void *list, void *node);
extern u32  func_02087988(void);
extern void func_0208799C(u32 tok);
extern void func_02073BF0(struct SndObj *o, u32 arg);
extern void func_02073BE0(void *o);

int func_020738C0(struct SndObj *o, int fmt, u32 base, u32 len,
                  u32 rate, s32 frames, u32 cb, u32 ctx)
{
    u32 size;
    u32 period;
    int i;
    u32 tok;

    if (o->flag0) func_02073AB4(o);
    size = func_0209C2B0(len, o->f50 * (frames << 5));
    size = (size * frames) << 5;
    o->f30 = size;
    if (fmt == 1) size >>= 1;
    period = func_0209C2B0(rate * size, frames);
    o->f48 = func_020729C0();
    if (o->f48 < 0) return 0;
    for (i = 0; i < o->f50; i++) {
        u8 slot = o->f54[i];
        g_0214E934[slot].a = o->f30 * i + base;
        g_0214E934[slot].b = 0;
        func_02089660(slot, fmt, g_0214E934[slot].a, 1, 0, o->f30 >> 2,
                      0x7f, 0, rate << 5, 0x40);
    }
    func_02089540(o->f48, period, period, func_02073BE0, o);
    func_020604AC(g_0214E8E8, o);
    o->f28 = fmt;
    o->f34 = frames;
    o->f38 = cb;
    o->f3c = ctx;
    o->f40 = 0;
    o->f44 = 0;
    o->flag0 = 1;
    tok = func_02087988();
    o->f34 = 1;
    func_02073BF0(o, 0);
    o->f34 = frames;
    func_0208799C(tok);
    return 1;
}
