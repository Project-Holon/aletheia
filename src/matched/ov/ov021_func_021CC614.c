/*
 * function: func_021CC614
 * address:  0x021CC614
 * packet:   pkt_ov021_021CC614
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * func_020120F4 takes the func_0215A5DC result as its argument (r0 still
 * holds it at the bl), as it does at every other caller; declaring it
 * void(void) was what shuffled the whole register assignment.
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0216530C  0x0216530C  thumb  ov010
 *   func_02165534  0x02165534  thumb  ov010
 *   func_021653C4  0x021653C4  thumb  ov010
 *   func_021656A0  0x021656A0  thumb  ov010
 *   func_021656D0  0x021656D0  thumb  ov010
 *   func_0216573C  0x0216573C  thumb  ov010
 *   func_02165604  0x02165604  thumb  ov010
 *   func_02165634  0x02165634  thumb  ov010
 *   func_0216566C  0x0216566C  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern unsigned int func_02159B10(void *a, void *b);
extern void *func_0215A5DC(void *a0);
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_0215A5F4(void *p);
extern void func_0216530C(u32 a);
extern void func_02165534(u32 a);
extern void func_021653C4(void);
extern void func_021656A0(void);
extern void func_021656D0(u8 a);
extern void func_0216573C(void);
extern void func_02165604(void);
extern void func_02165634(u32 a);
extern void func_0216566C(void);

int func_021CC614(u32 a, u32 b)
{
    u32 sel;
    u32 v;
    void *t;

    sel = func_02159B10((void *)a, (void *)b);
    v = func_02159B10((void *)a, (void *)b);
    t = func_0215A5DC((void *)b);
    func_020120F4(t);
    func_0201210C((void *)t);
    func_0215A5F4((void *)b);
    switch (sel) {
    case 0:
        func_0216530C(v);
        break;
    case 1:
        func_02165534(v);
        break;
    case 2:
        func_021653C4();
        break;
    case 3:
        func_021656A0();
        break;
    case 4:
        func_021656D0(v);
        break;
    case 5:
        func_0216573C();
        break;
    case 6:
        func_02165604();
        break;
    case 7:
        func_02165634(v);
        break;
    case 8:
        func_0216566C();
        break;
    }
    return 0;
}
