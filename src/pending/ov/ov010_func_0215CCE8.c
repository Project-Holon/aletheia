/*
 * function: func_0215CCE8
 * address:  0x0215CCE8
 * packet:   pkt_ov010_0215CCE8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Blocker: ABS32 func_021543BC (ov003 callback, unlabelled leaf, no witness).
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_020124AC  0x020124AC  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_021543BC  0x021543BC  thumb  ov003
 *   ov003_id       0x00000003  data
 */

typedef unsigned int u32;

typedef struct { u32 a; u32 b; } Arg;

extern void *func_0215A5F4(void *);
extern void *func_0215A5DC(void *);
extern int func_02159B10(void *, void *);
extern void *func_0201210C(void *);
extern void *func_020124AC(void *, u32, void *, Arg *);
extern void func_0215897C(void *, void *);
extern void func_021543BC(void);
extern char ov003_id[];

int func_0215CCE8(void *a, void *b)
{
    Arg arg;
    void *t = func_0215A5F4(b);
    void *h = func_0215A5DC(b);
    u32 k = !func_02159B10(a, b) ? 1 : 2;
    arg.a = (u32)func_0201210C(h);
    arg.b = k;
    func_0215897C(t, func_020124AC(h, (u32)ov003_id, (void *)func_021543BC, &arg));
    return 1;
}
