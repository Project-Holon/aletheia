/*
 * function: func_0216AC40
 * address:  0x0216AC40
 * packet:   pkt_ov010_0216AC40
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02012138  0x02012138  thumb
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_021664CC  0x021664CC  thumb  ov010
 *   func_0217C37C  0x0217C37C  thumb  ov018
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 lo : 6;
    u32 mid : 12;
    u32 hi : 6;
    u32 rest : 8;
} Bits;

extern void *func_0215A5DC(void *a0);
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02012138(const struct Ctx *p);
extern u16 func_0215A5CC(void *a0);
struct LinkRecord;
extern struct LinkRecord *func_021664CC(u16 heap, void *sys, u32 *start);
extern void func_0217C37C();
extern u32 func_020307B0(void *p);

int func_0216AC40(int a0, int a1)
{
    void *w;
    void *h;
    u8 *e;
    int key;

    w = func_0215A5DC((void *)a1);
    h = func_0201210C((void *)w);
    func_02012138(w);
    e = (u8 *)func_021664CC(func_0215A5CC((void *)a1), w, (u32 *)(&key));
    if (e != 0) {
        func_0217C37C(h, key, e, ((Bits *)(e + 0x50))->lo, ((Bits *)(e + 0x50))->hi);
        func_020307B0(e);
    }
    return 0;
}
