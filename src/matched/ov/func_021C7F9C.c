/*
 * function: FIELDSKILL_MAPEFF_Delete
 * address:  0x021C7F9C
 * packet:   pkt_021C7F9C
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
 *   FIELDSKILL_MAPEFF_FreeFlash  0x021C7FF0  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void FIELDSKILL_MAPEFF_FreeFlash(void *p);
extern u32 func_020307B0(void *p);

void FIELDSKILL_MAPEFF_Delete(u8 *p)
{
    FIELDSKILL_MAPEFF_FreeFlash(p);
    func_020307B0(p);
}
