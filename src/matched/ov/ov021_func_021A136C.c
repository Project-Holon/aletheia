/*
 * function: FIELD_SUBSCREEN_InitUnion
 * address:  0x021A136C
 * packet:   pkt_ov021_021A136C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034AC4  0x02034AC4  arm
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   UNION_SUBDISP_Create  0x021EFEC0  thumb  ov031
 *   abs_id_1f      0x0000001F  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern unsigned char abs_id_1f[];
extern int func_02034AC4(int);
extern void *FIELDMAP_GetGameSystem(void *p);
extern u32 *UNION_SUBDISP_Create(void *a);

void FIELD_SUBSCREEN_InitUnion(u32 *p)
{
    func_02034AC4((int)abs_id_1f);
    p[8] = (u32)UNION_SUBDISP_Create(FIELDMAP_GetGameSystem((void *)p[5]));
}
