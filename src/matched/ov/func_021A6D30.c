/*
 * function: FIELDMAP_CTRL_NOGRID_WORK_Destroy
 * address:  0x021A6D30
 * packet:   pkt_021A6D30
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
 *   FIELDMAP_GetCtrlWork  0x02188CA4  thumb  ov021
 *   FIELDMAP_CTRL_NOGRID_WORK_FreeWork  0x021A6D9C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern u32 FIELDMAP_GetCtrlWork(u8 *p);
extern void FIELDMAP_CTRL_NOGRID_WORK_FreeWork(void);

void FIELDMAP_CTRL_NOGRID_WORK_Destroy(u8 *a0)
{
    FIELDMAP_GetCtrlWork(a0);
    FIELDMAP_CTRL_NOGRID_WORK_FreeWork();
}
