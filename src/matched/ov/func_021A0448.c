/*
 * function: FIELD_LIGHT_Delete
 * address:  0x021A0448
 * packet:   pkt_021A0448
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pattern-generated from the ov021 family.
 *
 * symbols:
 *   FIELD_LIGHT_Dummy  0x021A07B0  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void FIELD_LIGHT_Dummy(void);
extern u32 func_020307B0(void *p);

void FIELD_LIGHT_Delete(u8 *p)
{
    FIELD_LIGHT_Dummy();
    func_020307B0(p);
}
