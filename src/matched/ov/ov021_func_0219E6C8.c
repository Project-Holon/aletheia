/*
 * function: FLDMMDL_RAIL_SetGridPosByDir
 * address:  0x0219E6C8
 * packet:   pkt_ov021_0219E6C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysGetNogridMapper  0x0216D530  thumb  ov010
 *   FIELD_NOGRID_MAPPER_GetRailMan  0x021BB480  thumb  ov021
 *   FLDMMDL_RAIL_GetNextLocation  0x0219E2F4  thumb  ov021
 *   ZONEDATA_DirToRailKey  0x0201441C  thumb
 *   FIELD_RAIL_StepLocation  0x021B7C90  thumb  ov021
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_SetGridOldX  0x0216D80C  thumb  ov010
 *   FLDMMDL_GetGridNowY  0x0216D854  thumb  ov010
 *   FLDMMDL_SetGridOldY  0x0216D818  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_SetGridOldZ  0x0216D824  thumb  ov010
 *   FLDMMDL_SetGridNowX  0x0216D844  thumb  ov010
 *   FLDMMDL_SetGridNowY  0x0216D85C  thumb  ov010
 *   FLDMMDL_SetGridNowZ  0x0216D874  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

struct Mgr;
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern void *FLDMMDL_SysGetNogridMapper(void *p);
extern void *FIELD_NOGRID_MAPPER_GetRailMan(void *p);
extern void FLDMMDL_RAIL_GetNextLocation(void *o, void *out);
extern u8 ZONEDATA_DirToRailKey(int i);
extern int FIELD_RAIL_StepLocation(struct Mgr *m, void *r, void *key, void *q);
extern int FLDMMDL_GetGridNowX(void *p);
extern void FLDMMDL_SetGridOldX();
extern int FLDMMDL_GetGridNowY(void *p);
extern void FLDMMDL_SetGridOldY();
extern int FLDMMDL_GetGridNowZ(void *p);
extern void FLDMMDL_SetGridOldZ();
extern void FLDMMDL_SetGridNowX(void *p, short v);
extern void FLDMMDL_SetGridNowY(void *p, int v);
extern void FLDMMDL_SetGridNowZ(int a0, int a1);

void FLDMMDL_RAIL_SetGridPosByDir(u32 o, u16 id)
{
    u32 h;
    s32 v[3];
    u32 a[2];

    h = (u32)FIELD_NOGRID_MAPPER_GetRailMan(FLDMMDL_SysGetNogridMapper(FLDMMDL_GetMmdlSys((void *)o)));
    FLDMMDL_RAIL_GetNextLocation((void *)o, a);
    FIELD_RAIL_StepLocation((struct Mgr *)h, a, (void *)ZONEDATA_DirToRailKey(id), v);
    FLDMMDL_SetGridOldX(o, FLDMMDL_GetGridNowX((void *)o));
    FLDMMDL_SetGridOldY(o, FLDMMDL_GetGridNowY((void *)o));
    FLDMMDL_SetGridOldZ(o, FLDMMDL_GetGridNowZ((void *)o));
    FLDMMDL_SetGridNowX((void *)o, (v[0] >> 4) / 4096);
    FLDMMDL_SetGridNowY((void *)o, (s16)((v[1] >> 4) / 4096));
    FLDMMDL_SetGridNowZ((u32)o, (s16)((v[2] >> 4) / 4096));
}
