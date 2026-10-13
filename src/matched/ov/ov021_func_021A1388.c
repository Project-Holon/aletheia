/*
 * function: FIELD_SUBSCREEN_ExitUnion
 * address:  0x021A1388
 * packet:   pkt_ov021_021A1388
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   UNION_SUBDISP_Delete  0x021EFFE8  thumb  ov031
 *   func_02034A5C  0x02034A5C  arm
 *   abs_id_1f      0x0000001F  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern unsigned char abs_id_1f[];
extern void UNION_SUBDISP_Delete(u32 *p);
extern void func_02034A5C(int handle);

void FIELD_SUBSCREEN_ExitUnion(u32 *p)
{
    UNION_SUBDISP_Delete((u32 *)p[8]);
    func_02034A5C((int)abs_id_1f);
}
