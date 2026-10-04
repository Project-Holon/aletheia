/*
 * function: func_021C6A90
 * address:  0x021C6A90
 * packet:   pkt_ov021_021C6A90
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204762C  0x0204762C  arm
 *   func_02047788  0x02047788  arm
 *   func_02047738  0x02047738  arm
 *   func_02047504  0x02047504  arm
 *   func_02082C60  0x02082C60  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec;
extern void func_0204762C(struct Rec *p);
extern int func_02047788(int *p);
extern void func_02047738(struct Rec *p);
extern void func_02047504(struct Rec *p);
extern void func_02082C60(void *p, int v, int n);

void func_021C6A90(u32 *p, u8 *q)
{
    u32 t;
    int i;

    if (p + 0x12) {
        for (i = 0; i < q[0x28]; i++)
            func_0204762C((struct Rec *)p[0x12 + i]);
    }
    if (p[0x11] != 0) {
        t = func_02047788((int *)p[0x11]);
        func_02047738((struct Rec *)p[0x11]);
        func_02047504((struct Rec *)t);
    }
    func_02082C60(p, 0, 0x68);
}
