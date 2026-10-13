/*
 * function: FLDEFF_NAMIPOKE_Delete
 * address:  0x021ACA5C
 * packet:   pkt_021ACA5C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Pattern-generated from the ov021 family.
 *
 * symbols:
 *   FLDEFF_NAMIPOKE_FreeResources  0x021ACB0C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
struct X;
extern void FLDEFF_NAMIPOKE_FreeResources(struct X *x);
extern u32 func_020307B0(void *p);

void FLDEFF_NAMIPOKE_Delete(u32 a, u8 *p)
{
    FLDEFF_NAMIPOKE_FreeResources((struct X *)p);
    func_020307B0(p);
}
