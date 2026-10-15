/*
 * function: WF2DMAP_SCENE_CreateTextOam
 * address: 0x021DA454
 * packet: pkt_ov129_021DA454
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Expand each coordinate base at its read; binding the base to a
 * pointer local swaps r2/r3 and leaves six bytes different.
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   BMP_Create 0x02043678 arm
 *   func_0201D304 0x0201D304 thumb
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   BMP_OAM_Create 0x020255A0 thumb
 *   BMP_OAM_UploadChars 0x020257D0 thumb
 *   BMP_Delete 0x020437AC arm
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 */
#include "../include/Obj08141.h"
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
struct Param { void *bmp; s16 x,y; u32 f8,fc; u8 f10,f11; u16 f12; u32 f14; };
struct Bmp;
struct Grid;
struct MsgBank;
struct Obj;
struct Obj020437AC;
struct Rec;
struct StrObj;
struct Sys;
struct U16Vec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void PRINTSYS_PrintColor(void *,s16,s16,void *,void *,u16);
extern struct Grid *BMP_OAM_Create(struct Sys *sys, const struct Param *param);
extern void BMP_OAM_UploadChars(struct Obj *o);
extern void BMP_Delete(struct Obj020437AC *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 MSGDATA_Delete(struct Rec *rec);
void WF2DMAP_SCENE_CreateTextOam(u8 *p, int i, int a2, int a3, int a4)
{
    void *bank,*msg,*bmp;
    struct Param q;
    s16 y;
    u16 x;
    int zero=0;
    bank=func_02045B38(0,2,25,50);
    msg=func_02045EC0(bank,i+3);
    bmp=BMP_Create(10,2,32,50);
    PRINTSYS_PrintColor(bmp,(80-(int)func_0201D304(msg,*(u32 *)&((struct Obj08141 *)p)->f314,0))/2,0,msg,((struct Obj08141 *)p)->f314,0x3dc0);
    x=(p+(i+22)*4)[0x29a]+20;
    y=((p+(i+22)*4)[0x298]+(p+(i+22)*4)[0x299])/2;
    q.bmp=bmp;
    q.x=x;
    q.y=y-7;
    q.f8=((struct Obj08141 *)p)->f264;
    q.fc=zero;
    q.f10=zero;
    q.f11=zero;
    q.f12=zero;
    q.f14=zero;
    *(void **)(p+0x304+i*4)=BMP_OAM_Create(((struct Obj08141 *)p)->f300,&q);
    BMP_OAM_UploadChars(*(void **)(p+0x304+i*4));
    BMP_Delete(bmp);
    STRBUF_Delete(msg);
    MSGDATA_Delete(bank);
}
