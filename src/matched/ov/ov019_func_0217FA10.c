/*
 * function: func_0217FA10
 * address:  0x0217FA10
 * packet:   pkt_ov019_0217FA10
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_020477A4  0x020477A4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02082BCC(void *p, u32 v, u32 n);
extern u32 func_02047400(u32 a, u32 b, u32 c);
extern u32 func_02047564(u32 a, u32 b, u32 c);
extern u32 func_0204767C(u32 a, u32 *b, u32 c);
extern void func_020477A4(u32 a, u32 b);

void func_0217FA10(char *self, u32 *out, u32 a2, u16 a3)
{
    func_02082BCC(out, 0, 0x14);
    out[0] = a2;
    *(u16 *)((char *)out + 0x10) = a3;
    out[1] = func_02047400(*(u32 *)(self + 0x14), 0, *(u32 *)(self + 0x14));
    out[2] = func_02047564(out[1], *(u32 *)(self + 0x18), 0);
    out[3] = func_0204767C(out[1], &out[2], 1);
    func_020477A4(out[3], 0);
}
