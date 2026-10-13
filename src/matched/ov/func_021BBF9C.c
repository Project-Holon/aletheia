/*
 * function: FLDEFF_REFLECT_Delete
 * address:  0x021BBF9C
 * packet:   pkt_021BBF9C
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
 *   FLDEFF_REFLECT_DeleteResource  0x021BBFB4  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void FLDEFF_REFLECT_DeleteResource(void *p);
extern u32 func_020307B0(void *p);

void FLDEFF_REFLECT_Delete(u32 a, u8 *p)
{
    FLDEFF_REFLECT_DeleteResource(p);
    func_020307B0(p);
}
