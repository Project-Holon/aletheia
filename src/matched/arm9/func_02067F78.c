/*
 * function: NNS_G2dFontInitUTF16
 * address:  0x02067F78
 * packet:   pkt_02067BA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNS_G2dFontLoad    0x020698F8  arm
 *   NNSi_G2dReadCharUTF16    0x02069C00  arm

 * Blocking class: label.  Every concrete byte is right; both relocation sites are
 * unresolved and both for the same reason: the `bl NNS_G2dFontLoad` at 0x02067F88 is
 * the only branch to 0x020698F8 in the image, and the pool word that stores
 * 0x02069C00 as a value (+0x20) is the only reference to that address anywhere, so
 * neither `label` nor `literal` has a witness outside this file's 32 bytes.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void NNS_G2dFontLoad(u32 a, void *b);
extern u8 NNSi_G2dReadCharUTF16[];

void NNS_G2dFontInitUTF16(void *a, u32 b)
{
    NNS_G2dFontLoad(b, a);
    ((u32 *)a)[1] = (u32)NNSi_G2dReadCharUTF16;
}
