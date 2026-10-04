/*
 * function: func_021C95D8
 * address:  0x021C95D8
 * packet:   pkt_ov021_021C95D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * The `adds r4, r6, #0` before the first loop is the second loop's counter
 * initialised to 0 and shared as the first loop's constant 0 argument; both
 * loops use one counter i. Callee widths from arm9 func_02048744.
 * symbols:
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_020477A4  0x020477A4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct G3dOwner;
struct G3dRec;
extern int func_021AC1AC(u32 a);
extern void func_021AC1CC(u32 a, u32 *b);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
extern void func_020477A4(u32 a, u16 b);

void func_021C95D8(u32 a, u32 *b)
{
    u32 *p = (u32 *)func_021AC1AC(a);
    int i;

    b[0] = p[0];
    func_021AC1CC(a, p + 1);
    b[5] = (u32)func_02047400((void *)(((u32 *)b[0])[1]), 0, (void *)(((u32 *)b[0])[1]));
    for (i = 0; i < 3; i++)
        b[2 + i] = (u32)func_02047564((struct G3dOwner *)b[5], (const struct G3dOwner *)(((u32 *)b[0])[2 + i]), 0);
    b[1] = (u32)func_0204767C(b[5], b + 2, 3);
    for (i = 0; i < 3; i++)
        func_020477A4(b[1], i);
}
