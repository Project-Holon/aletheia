/*
 * function: func_021E5F24
 * address: 0x021E5F24
 * packet: pkt_ov177_021E5F24
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
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_021E7270 0x021E7270 thumb ov177
 *   func_021E6F20 0x021E6F20 thumb ov177
 *   func_020407E8 0x020407E8 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 */
#include "../include/Obj00133.h"
#include "../include/Obj05464.h"
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
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_021E7270(char *);
extern void func_021E6F20(Work *,void *,void *,u16);
extern u32 func_020407E8(u32 layer);
extern void func_0204B404(void *,const Pt *,u16);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C724(void *,void *,short,short,void *,int,int);
extern void func_02045808(struct U16Vec *vec);
void func_021E5F24(char *p, int mode, void *mgr, void *print, int font, u16 a5)
{
    int i;
    void *s;
    int x;
    int base,layer1,secondary,layer2;
    Pt pos;
    func_02043B5C(func_02045770(((struct Obj00133 *)p)->f20),0);
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
        if(o)func_0204B404(o,&pos,*(unsigned *)(p+layer1));
        o=*(void **)(q+secondary);
        if(o) {
            pos.x+=12;pos.y+=8;
            func_0204B404(o,&pos,*(unsigned *)(p+layer2));
        }
    }
    switch(mode) {
    case 0:
        for(i=0;i<6;i++) {
            char *q;
            void *o;
            q=p+i*4;
            o=((struct Obj05464 *)q)->f1A8;
            if(o)func_0204B3DC(o,1);
            o=((struct Obj05464 *)q)->f16C;
            if(o)func_0204B3DC(o,1);
        }
        func_0204B3DC(((struct Obj00133 *)p)->f18C,1);
        s=func_02045EC0(mgr,17);
        func_0201C724(print,func_02045770(((struct Obj00133 *)p)->fB4),0,0,s,font,0x3c40);
        ((struct Obj00133 *)p)->fB8=1;
        break;
    case 1:
        for(i=0;i<6;i++) {
            char *q;
            void *o;
            q=p+i*4;
            o=((struct Obj05464 *)q)->f1A8;
            if(o)func_0204B3DC(o,1);
            o=((struct Obj05464 *)q)->f16C;
            if(o)func_0204B3DC(o,1);
        }
        func_0204B3DC(((struct Obj00133 *)p)->f18C,0);
        s=func_02045EC0(mgr,18);
        func_0201C724(print,func_02045770(((struct Obj00133 *)p)->fB4),0,0,s,font,0x3c40);
        ((struct Obj00133 *)p)->fB8=1;
        break;
    case 2:
        for(i=0;i<6;i++) {
            char *q;
            void *o;
            q=p+i*4;
            o=((struct Obj05464 *)q)->f1A8;
            if(o)func_0204B3DC(o,0);
            o=((struct Obj05464 *)q)->f16C;
            if(o)func_0204B3DC(o,0);
        }
        func_0204B3DC(((struct Obj00133 *)p)->f18C,0);
        s=func_02045EC0(mgr,19);
        func_0201C724(print,func_02045770(((struct Obj00133 *)p)->fB4),0,0,s,font,0x3c40);
        ((struct Obj00133 *)p)->fB8=1;
        break;
    }
    func_02045808(s);
}
