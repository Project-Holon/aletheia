/*
 * function: FLDEFF_ENCOUNT_Delete
 * address:  0x021AD7A0
 * packet:   pkt_021AD7A0
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
 *   FLDEFF_ENCOUNT_FreeResources  0x021ADA1C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
struct Q;
extern void FLDEFF_ENCOUNT_FreeResources(struct Q *a);
extern u32 func_020307B0(void *p);

void FLDEFF_ENCOUNT_Delete(u32 a, u8 *p)
{
    FLDEFF_ENCOUNT_FreeResources((struct Q *)p);
    func_020307B0(p);
}
