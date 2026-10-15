/*
 * function: FIELD_PLACE_NAME_Create
 * address:  0x021BC388
 * packet:   pkt_ov021_021BC388
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLACE_NAME_AllocWork  0x021BCF88  thumb  ov021
 *   FIELD_PLACE_NAME_InitWork  0x021BCFA4  thumb  ov021
 *   FIELD_PLACE_NAME_LoadZoneFromSave  0x021BD0E0  thumb  ov021
 *   FIELD_PLACE_NAME_CreateArcHandle  0x021BC810  thumb  ov021
 *   FIELD_PLACE_NAME_CreateWordSet  0x021BCFE0  thumb  ov021
 *   FIELD_PLACE_NAME_CreateMsgData  0x021BCFF0  thumb  ov021
 *   FIELD_PLACE_NAME_CreateMessage  0x021BD008  thumb  ov021
 *   FIELD_PLACE_NAME_SetHeapId  0x021BD098  thumb  ov021
 *   FIELD_MSGBG_GetFont  0x021904AC  thumb  ov021
 *   FIELD_PLACE_NAME_SetFont  0x021BD09C  thumb  ov021
 *   FIELD_PLACE_NAME_CreateClactRenderer  0x021BC730  thumb  ov021
 *   FIELD_PLACE_NAME_RegisterClactPalette  0x021BC75C  thumb  ov021
 *   FIELD_PLACE_NAME_CreateClactUnit  0x021BC794  thumb  ov021
 *   FIELD_PLACE_NAME_SetClactUnitRenderer  0x021BC7BC  thumb  ov021
 *   FIELD_PLACE_NAME_CreateBmpOamSys  0x021BC998  thumb  ov021
 *   FIELD_PLACE_NAME_CreateLetters  0x021BC7D4  thumb  ov021
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   FIELD_PLACE_NAME_LoadPaletteFile  0x021BC664  thumb  ov021
 *   FIELD_PLACE_NAME_AllocBgChars  0x021BC6E8  thumb  ov021
 *   FIELD_PLACE_NAME_CreateBmpWin  0x021BD01C  thumb  ov021
 *   FIELD_PLACE_NAME_SetState  0x021BCB9C  thumb  ov021
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
struct BgTemplate;
struct S;
extern void *FIELD_PLACE_NAME_AllocWork(int a);
extern void FIELD_PLACE_NAME_InitWork(int a, int b);
extern void FIELD_PLACE_NAME_LoadZoneFromSave(int a);
extern void FIELD_PLACE_NAME_CreateArcHandle(int a);
extern void FIELD_PLACE_NAME_CreateWordSet(int a);
extern void FIELD_PLACE_NAME_CreateMsgData(int a);
extern void FIELD_PLACE_NAME_CreateMessage(int a);
extern void FIELD_PLACE_NAME_SetHeapId(int a, int b);
extern u32 FIELD_MSGBG_GetFont(u8 *p);
extern void FIELD_PLACE_NAME_SetFont(u8 *p, u32 v);
extern void FIELD_PLACE_NAME_CreateClactRenderer(int a);
extern void FIELD_PLACE_NAME_RegisterClactPalette(int a);
extern void FIELD_PLACE_NAME_CreateClactUnit(int a);
extern void FIELD_PLACE_NAME_SetClactUnitRenderer(int a, int b);
extern void FIELD_PLACE_NAME_CreateBmpOamSys(int a);
extern void FIELD_PLACE_NAME_CreateLetters(int a);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void FIELD_PLACE_NAME_LoadPaletteFile(struct S *p);
extern void FIELD_PLACE_NAME_AllocBgChars(int a);
extern void FIELD_PLACE_NAME_CreateBmpWin(int a);
extern void FIELD_PLACE_NAME_SetState(void *p, int keep);

int FIELD_PLACE_NAME_Create(int a, int b, int c)
{
    int r4;

    r4 = (int)FIELD_PLACE_NAME_AllocWork(b);
    FIELD_PLACE_NAME_InitWork(r4, a);
    FIELD_PLACE_NAME_LoadZoneFromSave(r4);
    FIELD_PLACE_NAME_CreateArcHandle(r4);
    FIELD_PLACE_NAME_CreateWordSet(r4);
    FIELD_PLACE_NAME_CreateMsgData(r4);
    FIELD_PLACE_NAME_CreateMessage(r4);
    FIELD_PLACE_NAME_SetHeapId(r4, b);
    FIELD_PLACE_NAME_SetFont((u8 *)r4, FIELD_MSGBG_GetFont((u8 *)c));
    FIELD_PLACE_NAME_CreateClactRenderer(r4);
    FIELD_PLACE_NAME_RegisterClactPalette(r4);
    FIELD_PLACE_NAME_CreateClactUnit(r4);
    FIELD_PLACE_NAME_SetClactUnitRenderer(r4, 0);
    FIELD_PLACE_NAME_CreateBmpOamSys(r4);
    FIELD_PLACE_NAME_CreateLetters(r4);
    BG_SYS_InitBgLayer(3, (const struct BgTemplate *)0x021DE334, 0);
    FIELD_PLACE_NAME_LoadPaletteFile((struct S *)r4);
    FIELD_PLACE_NAME_AllocBgChars(r4);
    FIELD_PLACE_NAME_CreateBmpWin(r4);
    FIELD_PLACE_NAME_SetState((void *)r4, 0);
    return r4;
}
