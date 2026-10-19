/*
 * function: P_STA_RIBBON_DrawRow
 * address: 0x021D91F0
 * packet: pkt_ov131_021D91F0
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_GetPixels 0x020437D4 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   WORDSET_Delete 0x0201ED04 thumb
 *   P_STA_OAM_TransferBitmap 0x021DBCF4 thumb ov131
 */
#include "../include/Obj06484.h"
#include "../include/Obj10516.h"
#include "../include/Obj10517.h"
#include "../include/Obj10518.h"
#include "../include/Obj23153.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Bmp;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern void MI_CpuCopy8(const void *,void *,u32);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void GF_FONT_SetTextColor(u32,u32,u32);
extern void PRINTSYS_Print(void *,s16,s16,void *,void *);
extern void GF_FONT_SetDefaultTextColor(void);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 WORDSET_Delete(struct WordSet *p);
extern void P_STA_OAM_TransferBitmap(u8 *p);
void P_STA_RIBBON_DrawRow(u8 *a,u8 *p,u8 *entry)
{
    u8 *record;
    u8 *pixels;
    void *text;
    void *buffer;
    void *object;
    void *source;
    record=p+0x138+((struct Obj06484 *)entry)->f0*8;
    if (((struct Obj10518 *)record)->f0!=1) return;
    pixels=*(u8 * *)&((struct Obj23153 *)(*(u8 * *)&((struct Obj10517 *)p)->f48))->f14;
    source=BMP_GetPixels(((struct Obj06484 *)entry)->fC);
    if (((struct Obj06484 *)entry)->f0==p[0x59]) pixels+=0x660;
    MI_CpuCopy8(pixels,source,0x660);
    text=func_02045EC0(((struct Obj10517 *)p)->f50,record[5]+160);
    buffer=STRBUF_Create(32,((struct Obj10516 *)a)->f0);
    object=WORDSET_CreateDefault(((struct Obj10516 *)a)->f0);
    WORDSET_SetSlotNumber(object,0,record[6],2,2,1);
    WORDSET_CopyTaggedText(object,buffer,text);
    GF_FONT_SetTextColor(1,2,0);
    PRINTSYS_Print(((struct Obj06484 *)entry)->fC,10,6,buffer,((struct Obj10516 *)a)->f80);
    GF_FONT_SetDefaultTextColor();
    STRBUF_Delete(text);
    STRBUF_Delete(buffer);
    WORDSET_Delete(object);
    P_STA_OAM_TransferBitmap(((struct Obj06484 *)entry)->f10);
}
