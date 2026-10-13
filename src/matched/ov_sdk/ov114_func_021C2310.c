/*
 * function: ghttpPostSetAutoFree
 * address:  0x021C2310
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   ghiPostSetAutoFree  0x021C245C  arm  ov114
 *
 *
 * Null-guarded release of the object at `a`.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void ghiPostSetAutoFree(u8 *p, u32 v);

void ghttpPostSetAutoFree(u8 *a, u32 a1)
{
    if (a == 0)
        return;
    ghiPostSetAutoFree(a, a1);
}
