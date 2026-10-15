/*
 * function: HALL_OF_FAME_CreateTrainerPlates
 * address: 0x021B79F4
 * packet: pkt_ov180_021B79F4
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_Create 0x02043678 arm
 *   BMP_OAM_Create 0x020255A0 thumb
 *   BMP_OAM_SetEnabled 0x02025774 thumb
 *   BMP_Clear 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_0201D304 0x0201D304 thumb
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   func_02008534 0x02008534 thumb
 *   func_0200864C 0x0200864C thumb
 *   func_02008650 0x02008650 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   HALL_OF_FAME_PrintToPlate 0x021B77DC thumb ov180
 */
#include "../include/Obj00350.h"
#include "../include/Obj24494.h"
#include "../include/Obj24495.h"
#include "../include/Obj24496.h"
#include "../include/Obj24497.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed short s16;
struct Bmp; struct Sys; struct Grid; struct CharBuf; struct MsgBank; struct StrObj;
struct WordSet; struct Player; struct PlayTime;
typedef struct { void *bmp; s16 x,y; u32 f8,fc; u8 f10,f11; u16 f12; u32 f14; } Param;
typedef struct { struct Grid *grid; struct Bmp *bmp; } Holder;
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
struct Param;
struct Sub0200852CObj;
struct U16Vec;
extern struct Grid *BMP_OAM_Create(struct Sys *sys, const struct Param *param);
extern void BMP_OAM_SetEnabled(u8 *,u32);
extern void BMP_Clear(struct CharBuf *,u8);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 func_0201D304(struct StrObj *,u32,u32);
extern void WORDSET_SetSlotMyStatus(struct WordSet *,u32,void *);
extern void WORDSET_CopyTaggedText(struct WordSet *,void *,void *);
extern u16 func_02008534(const struct Sub0200852CObj *obj);
extern u16 func_0200864C(const struct PlayTime *);
extern u8 func_02008650(const struct PlayTime *);
extern void WORDSET_SetSlotNumber(struct WordSet *,u32,u32,u32,u32,u32);
extern void HALL_OF_FAME_PrintToPlate(u8 *p, int n, void *w, void *s, int x, int y);
void HALL_OF_FAME_CreateTrainerPlates(char *p) {
    Param d;
    Holder *h;
    struct StrObj *str;
    u32 width;
    d.f8=((struct Obj00350 *)p)->f90F0; d.fc=0; d.f10=4; d.f11=0; d.f12=0xffff;
    h=(Holder *)(p+0x9130); d.f14=0;
    h->bmp=BMP_Create(32,2,32,141);
    d.bmp=h->bmp; d.x=0; d.y=16;
    *(struct Grid * *)&((struct Obj00350 *)p)->f9130=BMP_OAM_Create(*(struct Sys * *)&((struct Obj00350 *)p)->f911C,(const struct Param *)(&d));
    BMP_OAM_SetEnabled(*(u8 **)(p+0x9130),0);
    BMP_Clear(*(struct CharBuf * *)&((struct Obj00350 *)p)->f9134,0);
    str=func_02045EC0(*(struct MsgBank * *)&((struct Obj00350 *)p)->f9038,4);
    width=func_0201D304(str,*(u32 *)&((struct Obj00350 *)p)->f9030,0);
    HALL_OF_FAME_PrintToPlate((u8 *)p,2,((struct Obj00350 *)p)->f9030,str,(256-width)/2,0);
    STRBUF_Delete((struct U16Vec *)str);
    h=(Holder *)(p+0x9138);
    h->bmp=BMP_Create(32,2,32,141);
    d.bmp=h->bmp; d.x=0; d.y=160;
    *(struct Grid * *)&((struct Obj00350 *)p)->f9138=BMP_OAM_Create(*(struct Sys **)(p+0x911c),(const struct Param *)(&d));
    BMP_OAM_SetEnabled(*(u8 **)(p+0x9138),0);
    BMP_Clear(*(struct CharBuf * *)&((struct Obj00350 *)p)->f913C,0);
    str=func_02045EC0(*(struct MsgBank **)(p+0x9038),5);
    WORDSET_SetSlotMyStatus(*(struct WordSet * *)&((struct Obj00350 *)p)->f903C,0,((struct Obj24494 *)(*(char * *)&((struct Obj00350 *)p)->f0))->f4);
    WORDSET_CopyTaggedText(*(struct WordSet **)(p+0x903c),((struct Obj00350 *)p)->f9040,str);
    HALL_OF_FAME_PrintToPlate((u8 *)p,3,((struct Obj00350 *)p)->f9030,*(struct StrObj * *)&((struct Obj00350 *)p)->f9040,8,0);
    STRBUF_Delete((struct U16Vec *)str);
    str=func_02045EC0(*(struct MsgBank **)(p+0x9038),6);
    WORDSET_SetSlotNumber(*(struct WordSet **)(p+0x903c),0,func_02008534((const struct Sub0200852CObj *)(*(struct Player * *)&((struct Obj24495 *)(*(char * *)&((struct Obj00350 *)p)->f0))->f4)),5,2,1);
    WORDSET_CopyTaggedText(*(struct WordSet **)(p+0x903c),((struct Obj00350 *)p)->f9040,str);
    HALL_OF_FAME_PrintToPlate((u8 *)p,3,((struct Obj00350 *)p)->f9030,*(struct StrObj **)(p+0x9040),92,0);
    STRBUF_Delete((struct U16Vec *)str);
    str=func_02045EC0(*(struct MsgBank **)(p+0x9038),7);
    WORDSET_SetSlotNumber(*(struct WordSet **)(p+0x903c),0,func_0200864C(*(struct PlayTime * *)&((struct Obj24496 *)(*(char * *)&((struct Obj00350 *)p)->f0))->f8),3,0,1);
    WORDSET_SetSlotNumber(*(struct WordSet **)(p+0x903c),1,func_02008650(*(struct PlayTime * *)&((struct Obj24497 *)(*(char * *)&((struct Obj00350 *)p)->f0))->f8),2,2,1);
    WORDSET_CopyTaggedText(*(struct WordSet **)(p+0x903c),((struct Obj00350 *)p)->f9040,str);
    HALL_OF_FAME_PrintToPlate((u8 *)p,3,((struct Obj00350 *)p)->f9030,*(struct StrObj **)(p+0x9040),200,0);
    STRBUF_Delete((struct U16Vec *)str);
}
