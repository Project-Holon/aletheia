/*
 * function: FIELDMAP_SetupEdgeMarking
 * address:  0x02189154
 * packet:   pkt_ov021_02189154
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZONEDATA_GetAreaEdgeMarkType  0x020140E0  thumb
 *   ZONEDATA_IsRawZoneGroup121To13C  0x02013DB8  thumb
 *   ARC_TOOL_ReadMember  0x02048F4C  arm
 *   func_0207DCF8  0x0207DCF8  arm
 *   sEdgeMarkColors  0x021EE700  data  a4
 *   sEdgeMarkColorsHalf  0x021EE700  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u8 sEdgeMarkColors[];
extern u16 sEdgeMarkColorsHalf[];
struct Sub020140BCObj;
extern u8 ZONEDATA_GetAreaEdgeMarkType(struct Sub020140BCObj *p);
extern u32 ZONEDATA_IsRawZoneGroup121To13C(u32 a);
extern void ARC_TOOL_ReadMember(void *a, u32 b, u32 c);
extern void func_0207DCF8(void *a);

void FIELDMAP_SetupEdgeMarking(void *a, u32 b)
{
    u32 r = ZONEDATA_GetAreaEdgeMarkType(a);

    if (r == 0xFF) {
        *(volatile u16 *)0x04000060 = *(volatile u16 *)0x04000060 & 0xCFDF;
        return;
    }
    if (ZONEDATA_IsRawZoneGroup121To13C(b) != 0)
        *(volatile u16 *)0x04000060 = *(volatile u16 *)0x04000060 & 0xCFDF;
    else
        *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & 0xFFFFCFFF) | 0x20;
    ARC_TOOL_ReadMember(sEdgeMarkColors, 0xF, r);
    sEdgeMarkColorsHalf[7] = 0x4210;
    func_0207DCF8(sEdgeMarkColors);
}
