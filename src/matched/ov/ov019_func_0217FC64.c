/*
 * function: func_0217FC64
 * address:  0x0217FC64
 * packet:   pkt_ov019_0217FC64
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The reload of out[1] before the last call is spelled with a volatile read.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_02047400  0x02047400  arm
 *   func_0204767C  0x0204767C  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02082BCC(void *p, u32 v, u32 n);
extern u32 func_02047400(u32 a, u32 b, u32 c);
extern u32 func_0204767C(u32 a, u32 b, u32 c);

void func_0217FC64(char *self, u32 *out, u32 a2, u16 a3, int flag)
{
    u32 *q;

    func_02082BCC(out, 0, 0x14);
    out[0] = a2;
    *(u16 *)((char *)out + 0x10) = a3;
    if (flag == 0) {
        q = (u32 *)(self + 0xc8);
    } else {
        q = (u32 *)(self + 0xcc);
    }
    out[1] = func_02047400(*q, 0, *q);
    out[3] = func_0204767C(*(volatile u32 *)&out[1], 0, 0);
}
