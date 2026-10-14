/*
 * function: func_021FC8C8
 * address: 0x021FC8C8
 * packet: pkt_ov186_021FC8C8
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: u16 heap and const Config pointer restore scheduling; bounded permuter count-before-limit restores the clamp registers. Resource before font gives the original spill slots.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_02034714 0x02034714 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   BMP_Create 0x02043678 arm
 *   BMP_Clear 0x02043B5C arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   func_021FD860 0x021FD860 thumb ov186
 *   BR_RES_LoadSprite 0x021FBE54 thumb ov186
 *   BR_RES_GetSprite 0x021FC124 thumb ov186
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   func_021FCE60 0x021FCE60 thumb ov186
 *   func_021FCDA0 0x021FCDA0 thumb ov186
 *   func_021FCF90 0x021FCF90 thumb ov186
 *   func_021FD094 0x021FD094 thumb ov186
 *   func_021FD0B8 0x021FD0B8 thumb ov186
 *   func_021FCFE0 0x021FCFE0 thumb ov186
 *   func_021FD0A8 0x021FD0A8 thumb ov186
 *   func_021FD110 0x021FD110 thumb ov186
 *   d_02200D5C 0x02200D5C data a4
 *   d_02200D68 0x02200D68 data a4
 *   d_02200B0C 0x02200B0C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {int x,y;} Pair;
typedef struct {int x,y,z;} Triple;
typedef struct {u16 x,y,id;u8 flag,pad;} Request;
typedef struct {void *text;int id;} Item;
typedef struct {Item *list;u32 count;u8 x,y,width,height,palette,bg,spacing,pad;int mode;char *resources;u32 manager,cursor,other;u16 *selection;} Config;
typedef struct {u8 top,bottom,left,right;} Area;
typedef struct {Config cfg;u32 handles[4],descriptor;u16 selected,last,index,start,visible;u8 pad46[7],scroll,pad4e[2];void (*methods[3])(void);Area areas[10];u8 pad84[8];void *bitmaps[];} View;
extern const char d_02200D5C[],d_02200D68[];
extern const Pair d_02200B0C[];
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void MI_CpuFill8(void *,int,u32),func_02034714(const char *,u32,const char *);
extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);
struct Actor;
struct Cfg;
struct Descriptor;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_02041B6C(u32);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *,u32);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned int);
struct Bmp;
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void PRINTSYS_PrintColor(void *,short,short,void *,void *,u16);
extern void func_021FD860(char *,u32,const Pair *),BR_RES_LoadSprite(char *,u32,u32);
extern int BR_RES_GetSprite(char *,int,Triple *);
extern unsigned BR_RES_GetFont(char *p);
extern int func_021FCDA0(char *);
extern void func_021FCE60(char *,int);
extern int func_021FCF90(char *p, int change);
extern int func_021FD094(char *p);
extern void func_021FD0B8(char *p);
extern int func_021FCFE0(char *p, int step);
extern int func_021FD0A8(char *p);
extern void func_021FD110(char *p);
View *func_021FC8C8(const Config *cfg,u16 heap)
{
    Triple arrows,marks;
    Request arrow,mark;
    View *p;
    int size,mode,count;
    int limit;
    u16 resource;
    int font;
    int i;
    size=cfg->count*4+0x8c;
    p=func_02030734(heap,size,0,d_02200D5C,0x1a1);
    MI_CpuFill8(p,0,size);
    p->cfg=*cfg;
    p->selected=0;p->last=cfg->count;
    p->visible=cfg->height/cfg->spacing;
    count=cfg->count;
    limit=p->visible;
    if((int)limit>count) limit=count;
    p->visible=limit;
    if(cfg->selection) {p->start=cfg->selection[0];p->index=cfg->selection[1];}
    if(p->cfg.mode==0) {
        for(i=0;i<p->visible;i++) {
            if(i>=10) func_02034714(d_02200D68,0,d_02200D68);
            p->areas[i].left=p->cfg.x*8;
            p->areas[i].top=(p->cfg.y+i*p->cfg.spacing)*8;
            p->areas[i].right=(p->cfg.x+p->cfg.width)*8;
            p->areas[i].bottom=(p->cfg.y+(i+1)*p->cfg.spacing)*8;
        }
        if(i>=10) func_02034714(d_02200D68,0,d_02200D68);
        p->areas[i].left=255;p->areas[i].top=255;p->areas[i].right=255;p->areas[i].bottom=255;
        p->methods[0]=(void (*)(void))func_021FCF90;p->methods[1]=(void (*)(void))func_021FD094;p->methods[2]=(void (*)(void))func_021FD0B8;
    } else if(p->cfg.mode==1) {
        p->methods[0]=(void (*)(void))func_021FCFE0;p->methods[1]=(void (*)(void))func_021FD0A8;p->methods[2]=(void (*)(void))func_021FD110;
        if(p->cfg.cursor) func_021FD860((char *)p->cfg.cursor,5,&d_02200B0C[p->index]);
    }
    p->descriptor=BMP_WIN_Create(cfg->bg,cfg->x,cfg->y,cfg->width,cfg->height,cfg->palette,1);
    BMP_WIN_MakeScreen((struct Cfg *)p->descriptor);
    func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)p->descriptor));
    i=0;
    MI_CpuFill8(&arrow,0,8);
    if(cfg->bg<4) {
        BR_RES_LoadSprite(p->cfg.resources,7,heap);
        if(!BR_RES_GetSprite(p->cfg.resources,7,&arrows)) func_02034714(d_02200D68,0,d_02200D68);
        mode=0;
    } else {
        BR_RES_LoadSprite(p->cfg.resources,8,heap);
        if(!BR_RES_GetSprite(p->cfg.resources,8,&arrows)) func_02034714(d_02200D68,0,d_02200D68);
        mode=1;
    }
    arrow.x=128;arrow.flag=0;
    i=0;
    resource=mode;
    for(;i<2;i++) {
        if(cfg->mode==0) arrow.y=i==0?16:128;
        else arrow.y=i==0?64:184;
        arrow.id=i;
        p->handles[i]=(u32)CLACT_CreateActor((void *)cfg->manager,arrows.y,arrows.z,arrows.x,&arrow,resource,heap);
        CLACT_SetActorAutoAnim((struct Obj *)p->handles[i],1);CLACT_SetActorObjMode((struct Actor *)p->handles[i],1);
    }
    i=0;
    CLACT_SetActorDrawEnable((struct Obj *)p->handles[0],0);
    MI_CpuFill8(&mark,0,8);
    mark.y=72;mark.id=5;mark.flag=0;
    if(!BR_RES_GetSprite(p->cfg.resources,6,&marks)) func_02034714(d_02200D68,0,d_02200D68);
    for(i=2;i<4;i++) {
        mark.x=i==2?24:232;
        p->handles[i]=(u32)CLACT_CreateActor((void *)p->cfg.manager,marks.y,marks.z,marks.x,&mark,1,heap);
        CLACT_SetActorObjMode((struct Actor *)p->handles[i],1);
    }
    font=BR_RES_GetFont(p->cfg.resources);
    for(i=0;(u32)i<p->cfg.count;i++) {
        void *text;
        text=p->cfg.list[i].text;
        if(text) {
            p->bitmaps[i]=BMP_Create(p->cfg.width,p->cfg.spacing,32,heap);
            BMP_Clear(p->bitmaps[i],0);
            PRINTSYS_PrintColor(p->bitmaps[i],0,0,text,(void *)font,0x3da0);
        }
    }
    func_021FCE60((char *)p,p->start);
    if(cfg->count<p->visible) {
        p->scroll=0;CLACT_SetActorDrawEnable((struct Obj *)p->handles[0],0);CLACT_SetActorDrawEnable((struct Obj *)p->handles[1],0);
    } else {
        p->scroll=1;
        if(p->scroll) {
            if(p->start==0) CLACT_SetActorDrawEnable((struct Obj *)p->handles[0],0);
            else CLACT_SetActorDrawEnable((struct Obj *)p->handles[0],1);
            if(p->cfg.count==p->start+p->visible) CLACT_SetActorDrawEnable((struct Obj *)p->handles[1],0);
            else CLACT_SetActorDrawEnable((struct Obj *)p->handles[1],1);
        }
    }
    if(func_021FCDA0((char *)p)) for(i=2;i<4;i++) CLACT_SetActorAutoAnim((struct Obj *)p->handles[i],1);
    return p;
}
