/*
 * function: FIELDMAP_Delete
 * address:  0x021880A4
 * packet:   pkt_ov021_021880A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZONEDATA_DeleteAreaData  0x020140B4  thumb
 *   func_020307B0  0x020307B0  arm
 *   GAMESYSTEM_SetFieldMap  0x02012110  thumb
 *   GFL_NET_WM_ICON_SetDefaultPos  0x020371AC  arm
 */

typedef unsigned int   u32;
struct Ctx;
u32 ZONEDATA_DeleteAreaData(void *a);
u32 func_020307B0(void *p);
void GAMESYSTEM_SetFieldMap(struct Ctx *p, void *v);
void GFL_NET_WM_ICON_SetDefaultPos(unsigned short a, unsigned int b);

void FIELDMAP_Delete(int *p)
{
    int q = p[1];
    ZONEDATA_DeleteAreaData((void *)p[3]);
    func_020307B0(p);
    GAMESYSTEM_SetFieldMap((void *)q, 0);
    GFL_NET_WM_ICON_SetDefaultPos(0, 0);
}
