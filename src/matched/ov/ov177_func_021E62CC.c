/*
 * function: func_021E62CC
 * address: 0x021E62CC
 * packet: pkt_ov177_021E62CC
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05 (wave D9r lane 131): removed the 3 dead first assignments
 * (`layer1=0x240;` before `layer1=0x234;`; `layer2=0x240;` before
 * `layer2=0x234;` and 1 more). Game code has no line table, so these were
 * stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 *
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_021E7270 0x021E7270 thumb ov177
 *   func_021E6F20 0x021E6F20 thumb ov177
 *   func_020407E8 0x020407E8 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   func_02045EC0 0x02045EC0 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj00133.h"
#include "../include/Obj05465.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct {short x,y;} Pt;
typedef struct Work Work;
typedef unsigned int   u32;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Obj;
struct U16Vec;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void func_021E7270(char *);
extern void func_021E6F20(Work *,void *,void *,u16);
extern u32 func_020407E8(u32 layer);
extern void CLACT_AddActorSurfacePos(void *,const Pt *,u16);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
void func_021E62CC(char *p, int mode, void *mgr, void *print, int font, u32 a5)
{
    int i;
    void *s;
    int x;
    int base,layer1,secondary,layer2;
    Pt pos;
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj00133 *)p)->f28),0);
    i=0;
    func_021E7270(p);
    base=0x240;
    func_021E6F20((Work *)p,*(void **)(p+base),*(void **)(p+base-8),*(u16 *)(p+base-4));
    x=32-func_020407E8(*(u8 *)(p+base-16));
    layer1=0x234;
    layer2=0x234;
    secondary=0x1a8;
    base=0x16c;
    for(;i<6;i++) {
        void *o;
        char *q;
        pos.y=168;pos.x=x+i*32;
        q=p+i*4;
        o=*(void **)(q+base);
        if(o)CLACT_AddActorSurfacePos(o,&pos,*(unsigned *)(p+layer1));
        o=*(void **)(q+secondary);
        if(o) {
            pos.x+=12;pos.y+=8;
            CLACT_AddActorSurfacePos(o,&pos,*(unsigned *)(p+layer2));
        }
    }
    switch(mode) {
    case 0:
        for(i=0;i<6;i++) {
            char *q;
            void *o;
            q=p+i*4;
            o=((struct Obj05465 *)q)->f1A8;
            if(o)CLACT_SetActorDrawEnable(o,1);
            o=((struct Obj05465 *)q)->f16C;
            if(o)CLACT_SetActorDrawEnable(o,1);
        }
        CLACT_SetActorDrawEnable(((struct Obj00133 *)p)->f18C,1);
        s=func_02045EC0(mgr,17);
        PRINTSYS_PrintQueColor(print,(u32)BMP_WIN_GetBmp(((struct Obj00133 *)p)->fC4),0,0,(u32)s,font,0x3c40);
        ((struct Obj00133 *)p)->fC8=1;
        break;
    case 1:
        for(i=0;i<6;i++) {
            char *q;
            void *o;
            q=p+i*4;
            o=((struct Obj05465 *)q)->f1A8;
            if(o)CLACT_SetActorDrawEnable(o,1);
            o=((struct Obj05465 *)q)->f16C;
            if(o)CLACT_SetActorDrawEnable(o,1);
        }
        CLACT_SetActorDrawEnable(((struct Obj00133 *)p)->f18C,0);
        s=func_02045EC0(mgr,18);
        PRINTSYS_PrintQueColor(print,(u32)BMP_WIN_GetBmp(((struct Obj00133 *)p)->fC4),0,0,(u32)s,font,0x3c40);
        ((struct Obj00133 *)p)->fC8=1;
        break;
    case 2:
        for(i=0;i<6;i++) {
            char *q;
            void *o;
            q=p+i*4;
            o=((struct Obj05465 *)q)->f1A8;
            if(o)CLACT_SetActorDrawEnable(o,0);
            o=((struct Obj05465 *)q)->f16C;
            if(o)CLACT_SetActorDrawEnable(o,0);
        }
        CLACT_SetActorDrawEnable(((struct Obj00133 *)p)->f18C,0);
        s=func_02045EC0(mgr,19);
        PRINTSYS_PrintQueColor(print,(u32)BMP_WIN_GetBmp(((struct Obj00133 *)p)->fC4),0,0,(u32)s,font,0x3c40);
        ((struct Obj00133 *)p)->fC8=1;
        break;
    }
    STRBUF_Delete(s);
}
