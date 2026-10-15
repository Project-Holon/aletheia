/*
 * function: BR_BTN_CreateObject
 * address: 0x021FB3BC
 * packet: pkt_ov186_021FB3BC
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: parameter a declared u16 (u8 also EXACT); a narrow parameter pins its home store to the front of the prologue, see docs/idioms/a-narrow-parameter-pins-its-home-store-to-the-front-of-the-prologue.md. 2026-10-05 wave P12 lane A5: the older draft (docs/notes/pkt_ov186_021FB3BC.c.txt) was only wrong here.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   BMP_Create 0x02043678 arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   BMP_OAM_Create 0x020255A0 thumb
 *   BMP_OAM_UploadChars 0x020257D0 thumb
 *   BMP_OAM_SetObjMode 0x0202597C thumb
 *   d_02200D1C 0x02200D1C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef struct { s16 x,y;u16 f4;u8 f6,f7; } Point;
typedef struct { void *bmp;s16 x,y;u32 f8,fc;u8 f10,f11;u16 f12;u32 f14; } Param;
typedef struct { void *actor,*grid,*bmp;u32 fC,b,a; } Obj;
typedef struct { u32 x,y,z; } Triple;
struct Actor;
struct Grid;
struct Obj;
struct Param;
struct Sys;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *,int,u32);
extern struct Obj *CLACT_CreateActor(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
struct Bmp;
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
extern void PRINTSYS_PrintColor(void *,s16,s16,void *,void *,u16);
extern struct Grid *BMP_OAM_Create(struct Sys *sys, const struct Param *param);
extern void BMP_OAM_UploadChars(struct Obj *o);
extern void BMP_OAM_SetObjMode(u8 *,u32);
extern const char d_02200D1C[];
Obj *BR_BTN_CreateObject(const Point *pt,void *data,u16 a,u32 b,u32 c,void *owner,void *font,const Triple *triple,u16 heap)
{
    Param param;
    const Triple *config;
    u32 value;
    Obj *p;
    value=b;config=triple;
    p=func_02030734(heap,24,0,d_02200D1C,0xA3B);
    MI_CpuFill8(p,0,24);
    p->a=a;p->b=value;
    p->actor=CLACT_CreateActor((void *)c,config->y,config->z,config->x,pt,value,heap);
    CLACT_SetActorObjMode(p->actor,1);
    p->bmp=BMP_Create(p->a>>3,2,32,heap);
    PRINTSYS_PrintColor(p->bmp,1,0,data,font,0x3DA0);
    MI_CpuFill8(&param,0,24);
    param.bmp=p->bmp;
    param.x=pt->x+32;param.y=pt->y-8;
    param.f8=config->z;param.f10=pt->f6-1;param.f12=value;
    param.f14=value;param.f11=pt->f7;param.fc=1;
    p->grid=BMP_OAM_Create(owner,(const struct Param *)(&param));
    BMP_OAM_UploadChars(p->grid);
    BMP_OAM_SetObjMode(p->grid,1);
    return p;
}

