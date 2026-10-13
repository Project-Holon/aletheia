/*
 * function: FIELD_PLACE_NAME_Delete
 * address:  0x021BC424
 * packet:   pkt_ov021_021BC424
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLACE_NAME_SaveZoneToSave  0x021BD0FC  thumb  ov021
 *   FIELD_PLACE_NAME_FreePaletteFile  0x021BC6B4  thumb  ov021
 *   FIELD_PLACE_NAME_DeleteLetters  0x021BC7F8  thumb  ov021
 *   FIELD_PLACE_NAME_DeleteMessage  0x021BD068  thumb  ov021
 *   FIELD_PLACE_NAME_DeleteBmpOamSys  0x021BC9AC  thumb  ov021
 *   FIELD_PLACE_NAME_DeleteClactUnit  0x021BC7B0  thumb  ov021
 *   FIELD_PLACE_NAME_ReleaseClactPalette  0x021BC788  thumb  ov021
 *   FIELD_PLACE_NAME_DeleteClactRenderer  0x021BC748  thumb  ov021
 *   FIELD_PLACE_NAME_DeleteWordSet  0x021BD040  thumb  ov021
 *   FIELD_PLACE_NAME_DeleteMsgData  0x021BD054  thumb  ov021
 *   FIELD_PLACE_NAME_DeleteBmpWin  0x021BD07C  thumb  ov021
 *   FIELD_PLACE_NAME_FreeBgChars  0x021BC704  thumb  ov021
 *   FIELD_PLACE_NAME_DeleteArcHandle  0x021BC824  thumb  ov021
 *   func_020403F4  0x020403F4  arm
 *   FIELD_PLACE_NAME_FreeWork  0x021BCFD8  thumb  ov021
 */

typedef unsigned int   u32;
extern int FIELD_PLACE_NAME_SaveZoneToSave(u32 a);
extern void FIELD_PLACE_NAME_FreePaletteFile(int a);
extern void FIELD_PLACE_NAME_DeleteLetters(int a);
typedef unsigned char  u8;
extern void FIELD_PLACE_NAME_DeleteMessage(u8 *p);
extern void FIELD_PLACE_NAME_DeleteBmpOamSys(int a);
extern void FIELD_PLACE_NAME_DeleteClactUnit(u8 *p);
extern void FIELD_PLACE_NAME_ReleaseClactPalette(u8 *p);
extern void FIELD_PLACE_NAME_DeleteClactRenderer(u8 *p);
extern void FIELD_PLACE_NAME_DeleteWordSet(int a);
extern void FIELD_PLACE_NAME_DeleteMsgData(u8 *p);
extern void FIELD_PLACE_NAME_DeleteBmpWin(int a);
extern void FIELD_PLACE_NAME_FreeBgChars(int a);
extern void FIELD_PLACE_NAME_DeleteArcHandle(u8 *p);
extern void func_020403F4(u32 i);
extern void FIELD_PLACE_NAME_FreeWork(int a);

void FIELD_PLACE_NAME_Delete(u32 a)
{
    FIELD_PLACE_NAME_SaveZoneToSave(a);
    FIELD_PLACE_NAME_FreePaletteFile(a);
    FIELD_PLACE_NAME_DeleteLetters(a);
    FIELD_PLACE_NAME_DeleteMessage((u8 *)a);
    FIELD_PLACE_NAME_DeleteBmpOamSys(a);
    FIELD_PLACE_NAME_DeleteClactUnit((u8 *)a);
    FIELD_PLACE_NAME_ReleaseClactPalette((u8 *)a);
    FIELD_PLACE_NAME_DeleteClactRenderer((u8 *)a);
    FIELD_PLACE_NAME_DeleteWordSet(a);
    FIELD_PLACE_NAME_DeleteMsgData((u8 *)a);
    FIELD_PLACE_NAME_DeleteBmpWin(a);
    FIELD_PLACE_NAME_FreeBgChars(a);
    FIELD_PLACE_NAME_DeleteArcHandle((u8 *)a);
    func_020403F4(3);
    FIELD_PLACE_NAME_FreeWork(a);
}
