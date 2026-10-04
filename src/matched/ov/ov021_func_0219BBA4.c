/*
 * function: func_0219BBA4
 * address:  0x0219BBA4
 * packet:   pkt_ov021_0219BBA4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D5A8  0x0216D5A8  thumb  ov010
 *   func_0216D590  0x0216D590  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_021AE884  0x021AE884  thumb  ov021
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 */

typedef unsigned int u32;

typedef unsigned short u16;
typedef unsigned char  u8;
struct Ctx;
struct Rec;
extern u32 func_0216D5A8(u8 *p);
extern u16 func_0216D590(void *p);
extern void *func_0216D67C(void *a0);
extern int func_021AE884(int a);
extern int func_0216DD1C(struct Ctx *c, struct Rec **out, u32 *iter);

int func_0219BBA4(int a)
{
    int out;
    u32 iter;
    u32 kind;
    int r7;
    int r6;
    int r5;

    iter = 0;
    kind = func_0216D5A8((u8 *)a);
    r7 = func_0216D590((void *)a);
    r6 = (int)func_0216D67C((void *)a);
    r5 = func_021AE884(a);
    switch (kind) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 20:
        while (func_0216DD1C((struct Ctx *)r6, (struct Rec **)(&out), &iter) == 1) {
            if (a != out && r7 == func_0216D590((void *)out) && r5 == func_021AE884(out)) {
                return out;
            }
        }
        break;
    }
    return 0;
}
