/*
 * function: NAMEIN_GRAPHIC_Delete
 * address: 0x021F168C
 * packet: pkt_ov194_021F168C
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PROF_WORD_Delete 0x021F5354 thumb ov194
 *   NAMEIN_GRAPHIC_DeleteTcbl 0x021F3ED0 thumb ov194
 *   NAMEIN_GRAPHIC_DeleteMsgBox 0x021F3D54 thumb ov194
 *   NAMEIN_GRAPHIC_DeleteGrid 0x021F31B8 thumb ov194
 *   NAMEIN_GRAPHIC_DeleteMembers 0x021F4D78 thumb ov194
 *   NAMEIN_GRAPHIC_DeleteInputField 0x021F1F7C thumb ov194
 *   NAMEIN_GRAPHIC_ClearCallback 0x021F4608 thumb ov194
 *   NAMEIN_GRAPHIC_DeleteIconActor 0x021F42A0 thumb ov194
 *   NAMEIN_GRAPHIC_DeleteActors 0x021F1968 thumb ov194
 *   NAMEIN_GRAPHIC_UpdateBg 0x021F1878 thumb ov194
 *   NAMEIN_GRAPHIC_DeleteDisplay 0x021F4B84 thumb ov194
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 */
#include "../include/Obj02908.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void PROF_WORD_Delete(u8 *);
extern void NAMEIN_GRAPHIC_DeleteTcbl(u8 *);
extern void NAMEIN_GRAPHIC_DeleteMsgBox(u8 *);
extern void NAMEIN_GRAPHIC_DeleteGrid(u8 *);
struct PrintSys;
struct Rec;
struct S020315D4;
struct U16Vec;
struct WordSet;
extern void STRBUF_Delete(struct U16Vec *vec);
extern void NAMEIN_GRAPHIC_DeleteMembers(u8 *);
extern void NAMEIN_GRAPHIC_DeleteInputField(u8 *);
extern void NAMEIN_GRAPHIC_ClearCallback(void *p);
extern void NAMEIN_GRAPHIC_DeleteIconActor(u8 *);
extern void NAMEIN_GRAPHIC_DeleteActors(u8 *);
extern int NAMEIN_GRAPHIC_UpdateBg(void *a0);
extern void BMP_OAM_DeleteSys(void *);
extern void NAMEIN_GRAPHIC_DeleteDisplay(unsigned char *p);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void func_020315D4(struct S020315D4 *p);
extern void GFL_HEAP_DeleteChecked(u32);
int NAMEIN_GRAPHIC_Delete(void *a,u32 b,u32 c,u8 *d)
{
    PROF_WORD_Delete(*(u8 * *)&((struct Obj02908 *)d)->f2CC);
    NAMEIN_GRAPHIC_DeleteTcbl(d+596);
    NAMEIN_GRAPHIC_DeleteMsgBox(d+560);
    NAMEIN_GRAPHIC_DeleteGrid(d+252);
    STRBUF_Delete(((struct Obj02908 *)d)->f2D0);
    NAMEIN_GRAPHIC_DeleteMembers(*(u8 * *)&((struct Obj02908 *)d)->f22C);
    NAMEIN_GRAPHIC_DeleteInputField(d+104);
    NAMEIN_GRAPHIC_ClearCallback(d+672);
    NAMEIN_GRAPHIC_DeleteIconActor(d+612);
    NAMEIN_GRAPHIC_DeleteActors(d+4);
    NAMEIN_GRAPHIC_UpdateBg(d+100);
    BMP_OAM_DeleteSys(((struct Obj02908 *)d)->f2C0);
    NAMEIN_GRAPHIC_DeleteDisplay(((struct Obj02908 *)d)->f0);
    WORDSET_DeleteStrbufED04(((struct Obj02908 *)d)->f2BC);
    MSGDATA_Delete(((struct Obj02908 *)d)->f2B8);
    PRINTSYS_QUE_Clear(((struct Obj02908 *)d)->f2B4);
    PRINTSYS_QUE_Delete(((struct Obj02908 *)d)->f2B4);
    GF_FONT_Delete(((struct Obj02908 *)d)->f2B0);
    func_020315D4(a);
    GFL_HEAP_DeleteChecked(30);
    return 1;
}
