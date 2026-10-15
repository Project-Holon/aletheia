/*
 * packet: pkt_ov115_021D5984
 * region: ov115
 * function: func_021D5984
 * address: 0x021D5984
 * isa: thumb
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * status: EXACT
 * ABI: DD60 and its forwarding chain ignore the live r0 from45088;
 *   45B38 explicitly truncates its third argument to16 at this call.
 * symbols:
 *   sub_02030734 0x02030734 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   GF_FONT_ResetTextColor 0x0201DD60 thumb
 *   TCBL_Create 0x0203101C arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   GF_FONT_Create_EC64 0x0201EC64 thumb
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   func_021D5FA0 0x021D5FA0 thumb ov115
 *   func_021D5FC4 0x021D5FC4 thumb ov115
 *   func_0201F5DC 0x0201F5DC thumb
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   d_021D6628 0x021D6628 data a4
 */
#include "../include/Obj00531.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Tcbl;
struct U16Vec;
struct GfFont;
struct MsgBank;
struct WordSet;
struct R;
extern const char d_021D6628[];
extern void *sub_02030734(u32,u32,int,const char *,u16);
extern void BMP_WIN_Init(u16);
extern void GF_FONT_ResetTextColor(void);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 PRINTSYS_QUE_Create(void *);
extern struct U16Vec *STRBUF_Create(u32,u32);
extern struct GfFont *GF_FONT_Create(int,int,int,int,u32);
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *GF_FONT_Create_EC64(u32);
extern struct R *APP_TASKMENU_RES_Create(u16,u16,u32,u32,u16);
extern u32 func_021D5FA0(u32);
extern u32 func_021D5FC4(u32);
extern void *func_0201F5DC(void *,u32,u32,u32);
extern void ARC_UTIL_UploadPaletteFromArchiveWhole(u32,u32,u32,u32,u32,u16);

u8 *func_021D5984(u32 heap, u32 bank, u32 mode)
{
    u8 *p;
    u32 sel;
    p = sub_02030734(heap, 132, 1, d_021D6628, 135);
    ((struct Obj00531 *)p)->f4C = heap;
    ((struct Obj00531 *)p)->f50 = mode;
    BMP_WIN_Init(((struct Obj00531 *)p)->f4C);
    GF_FONT_ResetTextColor();
    *(struct Tcbl * *)&((struct Obj00531 *)p)->f44 = TCBL_Create(((struct Obj00531 *)p)->f4C, ((struct Obj00531 *)p)->f4C, 1, 0);
    ((struct Obj00531 *)p)->f48 = PRINTSYS_QUE_Create((void *)((struct Obj00531 *)p)->f4C);
    *(struct U16Vec * *)&((struct Obj00531 *)p)->f28 = STRBUF_Create(400, ((struct Obj00531 *)p)->f4C);
    *(struct GfFont * *)&((struct Obj00531 *)p)->f24 = GF_FONT_Create(23, 0, 0, 0, ((struct Obj00531 *)p)->f4C);
    *(struct MsgBank * *)&((struct Obj00531 *)p)->f1C = MSGDATA_CreateFromArchive(0, 2, (u16)bank, ((struct Obj00531 *)p)->f4C);
    *(struct WordSet * *)&((struct Obj00531 *)p)->f20 = GF_FONT_Create_EC64(((struct Obj00531 *)p)->f4C);
    *(struct R * *)&((struct Obj00531 *)p)->f70 = APP_TASKMENU_RES_Create(5, 9, *(u32 *)&((struct Obj00531 *)p)->f24, ((struct Obj00531 *)p)->f48, ((struct Obj00531 *)p)->f4C);
    ((struct Obj00531 *)p)->f0 = func_0201F5DC((void *)func_021D5FA0(((struct Obj00531 *)p)->f50), 12, 0, ((struct Obj00531 *)p)->f4C);
    ((struct Obj00531 *)p)->f4 = func_0201F5DC((void *)func_021D5FC4(((struct Obj00531 *)p)->f50), 12, 0, ((struct Obj00531 *)p)->f4C);
    sel = 0;
    if (((struct Obj00531 *)p)->f50 == 0) sel = 4;
    ARC_UTIL_UploadPaletteFromArchiveWhole(23, 5, sel, 352, 32, ((struct Obj00531 *)p)->f4C);
    return p;
}
