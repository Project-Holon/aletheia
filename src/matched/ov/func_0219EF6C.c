/*
 * function: FIELD_RAIL_LOADER_Delete
 * address:  0x0219EF6C
 * packet:   pkt_0219EF6C
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
 *   FIELD_RAIL_LOADER_Unload  0x0219EFFC  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern int FIELD_RAIL_LOADER_Unload(u32 a);
extern u32 func_020307B0(void *p);

void FIELD_RAIL_LOADER_Delete(u8 *p)
{
    FIELD_RAIL_LOADER_Unload((u32)p);
    func_020307B0(p);
}
