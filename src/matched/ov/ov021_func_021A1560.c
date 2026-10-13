/*
 * function: FIELD_SUBSCREEN_InitPowerOnoff
 * address:  0x021A1560
 * packet:   pkt_ov021_021A1560
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02034AC4  0x02034AC4  arm
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   REPORT_Create  0x021EFEC0  thumb  ov035
 *   abs_id_23      0x00000023  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern unsigned char abs_id_23[];
extern int func_02034AC4(int);
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *REPORT_Create(int a0, int a1, void *a2);

void FIELD_SUBSCREEN_InitPowerOnoff(u32 *p)
{
    func_02034AC4((int)abs_id_23);
    p[8] = (u32)REPORT_Create((int)p, (int)FIELDMAP_GetGameSystem((void *)p[5]), (void *)0x70);
}
