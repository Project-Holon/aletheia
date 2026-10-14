/*
 * function: HALL_OF_FAME_CreateMonPlates
 * address: 0x021B7814
 * packet: pkt_ov180_021B7814
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: paired Grid/Bmp holder pointer formed before allocation preserves
 *   the destination across the call; direct raw stores were eight bytes short.
 * symbols:
 *   BMP_Create 0x02043678 arm
 *   BMP_OAM_Create 0x020255A0 thumb
 *   BMP_Clear 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   HALL_OF_FAME_PrintToPlate 0x021B77DC thumb ov180
 */
#include "../include/Obj00547.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed short s16;
struct Bmp; struct Sys; struct Grid; struct CharBuf; struct MsgBank; struct U16Vec;
typedef struct { void *bmp; s16 x,y; u32 f8,fc; u8 f10,f11; u16 f12; u32 f14; } Param;
typedef struct { struct Grid *grid; struct Bmp *bmp; } Holder;
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
struct Param;
extern struct Grid *BMP_OAM_Create(struct Sys *sys, const struct Param *param);
extern void BMP_Clear(struct CharBuf *,u8);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void STRBUF_Delete(struct U16Vec *);
extern void HALL_OF_FAME_PrintToPlate(u8 *p, int n, void *w, void *s, int x, int y);
void HALL_OF_FAME_CreateMonPlates(char *p) {
    Param d;
    struct U16Vec *s;
    Holder *h;
    d.f8=*(u32 *)&((struct Obj00547 *)p)->f90F0; d.fc=0;
    d.f10=4; d.f11=0; d.f12=0xffff; d.f14=0;
    h=(Holder *)(p+0x9120);
    h->bmp=BMP_Create(22,2,32,141);
    d.bmp=h->bmp; d.x=-184; d.y=16;
    *(struct Grid * *)&((struct Obj00547 *)p)->f9120=BMP_OAM_Create(*(struct Sys * *)&((struct Obj00547 *)p)->f911C,(const struct Param *)(&d));
    BMP_Clear(*(struct CharBuf * *)&((struct Obj00547 *)p)->f9124,0);
    s=func_02045EC0(*(struct MsgBank * *)&((struct Obj00547 *)p)->f9038,0);
    HALL_OF_FAME_PrintToPlate((u8 *)p,0,((struct Obj00547 *)p)->f9030,s,12,0);
    STRBUF_Delete(s);
    h=(Holder *)(p+0x9128);
    h->bmp=BMP_Create(22,2,32,141);
    d.bmp=h->bmp; d.x=264; d.y=160;
    *(struct Grid * *)&((struct Obj00547 *)p)->f9128=BMP_OAM_Create(*(struct Sys * *)&((struct Obj00547 *)p)->f911C,(const struct Param *)(&d));
}
