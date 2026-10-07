/*
 * file:     manual_common_p04.c
 * unit:     yes
 * function: func_021BAABC, func_021BAE2C, func_021BAFF8, func_021BB034, func_021BB044, func_021BB05C, func_021BB074, func_021BB088, func_021BB1F4, func_021BB258, func_021BB2B4, func_021BB308, func_021BB31C, func_021BB3FC, func_021BB400, func_021BB458, func_021BB4F8, func_021BB504, func_021BB50C, func_021BB53C
 * address:  0x021BAABC
 * region:   ov225
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02035C08 0x02035C08 arm
 *   func_020355C4 0x020355C4 arm
 *   func_020355D8 0x020355D8 arm
 *   func_02028218 0x02028218 thumb
 *   func_020362DC 0x020362DC arm
 *   func_0203633C 0x0203633C arm
 *   func_020061E4 0x020061E4 thumb
 *   func_0202822C 0x0202822C thumb
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_02035CB8 0x02035CB8 arm
 *   func_02035D20 0x02035D20 arm
 *   func_0202843C 0x0202843C thumb
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0202815C 0x0202815C thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_0202804C 0x0202804C thumb
 *   func_02027FEC 0x02027FEC thumb
 *   func_02028178 0x02028178 thumb
 *   func_02045808 0x02045808 arm
 *   func_02030734 0x02030734 arm
 *   file_021BC038 0x021BC038 data a1
 *   func_020056A0 0x020056A0 thumb
 *   func_021BA068 0x021BA068 thumb ov225
 *   func_02030EAC  0x02030EAC  arm
 *   func_020307B0  0x020307B0  arm
 *   func_021B9FBC 0x021B9FBC thumb ov225
 *   func_021BA158 0x021BA158 thumb ov225
 *   func_021BA154 0x021BA154 thumb ov225
 *   func_02028230 0x02028230 thumb
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020499D4 0x020499D4 arm
 *   func_02027F60 0x02027F60 thumb
 *   sub_02041B6C 0x02041B6C arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_02028148 0x02028148 thumb
 *   func_02027FD8 0x02027FD8 thumb
 *   d_021BBF9C 0x021BBF9C data a4
 */
#include "../../matched/include/Obj00074.h"
#include "../../matched/include/Obj26201.h"
#include "../../matched/include/Obj26202.h"
#include "../../matched/include/Obj26203.h"
#include "../../matched/include/Obj26204.h"
#include "../../matched/include/Obj26205.h"
#include "../../matched/include/Obj26206.h"
#include "../../matched/include/Obj26207.h"
#include "../../matched/include/Obj26208.h"
#include "../../matched/include/Obj26209.h"
#include "../../matched/include/Obj26210.h"
#include "../../matched/include/Obj26211.h"
#include "../../matched/include/Obj26212.h"
#include "../../matched/include/Obj26213.h"
#include "../../matched/include/Obj26214.h"
#include "../../matched/include/Obj26217.h"
#include "../../matched/include/Obj26218.h"
#include "../../matched/include/Obj26219.h"
#include "../../matched/include/Obj26220.h"
#include "../../matched/include/Obj26221.h"
#include "../../matched/include/Obj26222.h"
#include "../../matched/include/Obj26223.h"
#include "../../matched/include/Obj26224.h"
#include "../../matched/include/Obj26225.h"
#include "../../matched/include/Obj26226.h"
#include "../../matched/include/Obj05574.h"
#include "../../matched/include/Obj26227.h"
#include "../../matched/include/Obj26228.h"
#include "../../matched/include/Obj26229.h"
#include "../../matched/include/Obj26230.h"
#include "../../matched/include/Obj00691.h"
#include "../../matched/include/Obj26231.h"
#include "../../matched/include/Obj26232.h"
#include "../../matched/include/Obj26233.h"
#include "../../matched/include/Obj26234.h"
#include "../../matched/include/Obj26235.h"
#include "../../matched/include/Obj26239.h"
#include "../../matched/include/Obj01596.h"
#include "../../matched/include/Obj26240.h"
#include "../../matched/include/Obj26241.h"
#include "../../matched/include/Obj26242.h"
#include "../../matched/include/Obj26243.h"
#include "../../matched/include/Obj26244.h"
#include "../../matched/include/Obj26245.h"
#include "../../matched/include/Obj26246.h"
#include "../../matched/include/Obj26247.h"
#include "../../matched/include/Obj26248.h"
#include "../../matched/include/Obj26249.h"
#include "../../matched/include/Obj26250.h"
#include "../../matched/include/Obj26251.h"
#include "../../matched/include/Obj14809.h"
#include "../../matched/include/Obj26253.h"
#include "../../matched/include/Obj00740.h"

#define S (*(struct State **)p)
struct Obj;
struct MsgBank;
struct U16Vec;
struct Node;
struct R;
struct PrintSys;
struct TaskMenuState;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned u32_021BAABC;

struct State {u16 a,b,count,c;void *data;u16 top,selected;};

struct Vec2 {short x,y;};

typedef unsigned u32_021BAE2C;

typedef short s16;

typedef unsigned int u32_021BAFF8;

typedef unsigned u32_021BB088;

struct Entry_021BB088 {void *resource;u16 tag,pad;u32_021BB088 flags;};

typedef unsigned int   u32_021BB308;

typedef unsigned int   u32_021BB31C;

typedef unsigned int   u32_021BB400;

struct Entry_021BB458 { void *resource; u16 tag; u16 pad; unsigned flags; };

typedef unsigned int   u32_021BB458;

typedef unsigned int u32_021BB4F8;

typedef unsigned int u32_021BB504;

typedef unsigned int u32_021BB50C;

typedef unsigned int   u32_021BB53C;

extern int func_02035C08(const void *);
extern u8 func_020355C4(void);
extern void func_020355D8(u8);
extern void func_02028218(struct Obj *obj, u32_021BAABC a);
extern void func_0202822C(char *p, int v);
extern u32_021BAABC func_020362DC(void),func_0203633C(void);
extern void func_020061E4(u32_021BAABC);
extern void func_0204B404(struct Obj *,const struct Vec2 *,u32_021BAABC);
extern u32_021BAE2C func_0204B3F4(struct Obj *);
extern u32_021BAE2C func_02035CB8(u32_021BAE2C *,u32_021BAE2C *),func_02035D20(u32_021BAE2C *,u32_021BAE2C *);
extern void func_0202843C(u8 *);
extern void func_0204B3DC(struct Obj *p, u32_021BB088 v);
extern void func_0202815C(void);
extern void *func_02045EC0(struct MsgBank *,u32_021BB088);
extern u32_021BB088 *func_0202804C(u32_021BB088 a0, u32_021BB088 a1, u32_021BB088 a2, u32_021BB088 a3, u8 a4, u8 a5, u32_021BB088 a6, u32_021BB088 a7, u16 a8);
extern u32_021BB088 func_02027FEC(u32_021BB088 a0, u32_021BB088 a1, u32_021BB088 a2, u32_021BB088 a3, u8 a4, u16 a5);
extern void func_02028178(u8 *);
extern void func_02045808(struct U16Vec *);
extern void *func_02030734(unsigned, unsigned, int, const char *, u16);
extern void *func_020056A0(unsigned, unsigned, unsigned);
extern void func_021BA068(char *, unsigned);
extern void func_02030EAC(struct Node *n);
extern u32_021BB308 func_020307B0(void *p);
extern void func_021B9FBC(char *);
extern unsigned func_021BA158(char *p);
extern unsigned func_021BA154(char *p);
extern u32_021BB31C func_02028230(u8 *p);
extern void func_02049B68(void *a, u32_021BB400 b, u32_021BB400 c, u32_021BB400 d, u32_021BB400 e, u16 f);
extern u32_021BB400 func_02049658(void *a, u32_021BB400 b, u32_021BB400 c, u32_021BB400 d, u32_021BB400 e, u32_021BB400 f, u16 g);
extern u32_021BB400 func_020499D4(void *a0, u32_021BB400 a1, u32_021BB400 a2, u32_021BB400 a3, u32_021BB400 a4, u32_021BB400 a5, u32_021BB400 a6, u16 a7);
extern struct R *func_02027F60(u16, u16, unsigned, unsigned, u16);
extern void sub_02041B6C(u32_021BB4F8);
extern void func_0201C6EC(struct PrintSys *);
extern void func_02028148(u8 *);
extern u32_021BB50C func_02027FD8(struct TaskMenuState *s);
int func_021BAABC(char *p);
int func_021BAE2C(char *p);
void func_021BAFF8(u8 *p);
u16 func_021BB034(u16 **p);
u16 func_021BB044(u16 **p);
u16 func_021BB05C(u16 **p);
u16 func_021BB074(u16 **p);
void func_021BB088(char *p);
u16 func_021BB1F4(void *p, u16 count, u16 value);
u16 func_021BB258(void *p, u16 count, u16 index);
char *func_021BB2B4(char *p, char *data);
void func_021BB308(char *p);
int func_021BB31C(char *p);
void func_021BB3FC(void *p);
void func_021BB400(char *p);
void func_021BB458(char *p);
void func_021BB4F8(char *a0);
void func_021BB504(char *p);
void func_021BB50C(char *p);
int func_021BB53C(char *p);
extern const char file_021BC038[];
extern const u8 d_021BBF9C[];

int func_021BAABC(char *p)
{
    u8 rect[28];
    struct Vec2 delta[4];
    int hit;
    u16 count,last,y;
    func_021BAFF8(rect);
    hit=func_02035C08(rect);
    count=func_021BB05C((u16 **)p);
    last=func_021BB044((u16 **)p);
    if(func_020355C4()==0) {
        if(hit>=0 && hit<count) {
            func_020355D8(1);
            func_02028218(*(void **)(p+func_021BB034((u16 **)p)*4+0xc),0);
        }
    } else {
        if(func_020362DC()!=0 && !(func_020362DC()&2)) {
            func_020355D8(0);
            func_02028218(*(void **)(p+func_021BB034((u16 **)p)*4+0xc),1);
            ((struct Obj00074 *)p)->f8C=0;
            func_020061E4(0x548);
            return 0;
        }
    }
    if(func_020355C4()==0) {
        if(func_020362DC()&1) {
            func_0202822C(*(void **)(p+func_021BB034((u16 **)p)*4+0xc),1);
            func_020061E4(0x54c);
            return 1;
        }
        if(S->count>1) {
            if(func_0203633C()&0x40) {
                func_02028218(*(void **)(p+func_021BB034((u16 **)p)*4+0xc),0);
                if(S->selected>S->top) S->selected--;
                else if(S->count<=6) S->selected=S->count-1;
                else {
                    if(S->selected!=0) {
                        S->top--;
                        S->selected--;
                    } else {
                        S->top=func_021BB074((u16 **)p);
                        S->selected=S->count-1;
                    }
                    func_021BB088(p);
                    y=func_021BB258(p,(u16)(func_021BB074((u16 **)p)+1),S->top);
                    delta[3].x=240;
                    delta[3].y=y;
                    func_0204B404(*(struct Obj * *)&((struct Obj00074 *)p)->f5C,&delta[3],1);
                }
                func_02028218(*(void **)(p+func_021BB034((u16 **)p)*4+0xc),1);
                ((struct Obj00074 *)p)->f8C=0;
                func_020061E4(0x548);
            } else if(func_0203633C()&0x80) {
                func_02028218(*(void **)(p+func_021BB034((u16 **)p)*4+0xc),0);
                if(S->selected<last) S->selected++;
                else if(S->count<=6) S->selected=0;
                else {
                    if(S->selected<S->count-1) {
                        S->top++;
                        S->selected++;
                    } else {S->top=0;S->selected=0;}
                    func_021BB088(p);
                    y=func_021BB258(p,(u16)(func_021BB074((u16 **)p)+1),S->top);
                    delta[2].x=240;
                    delta[2].y=y;
                    func_0204B404(*(struct Obj * *)&((struct Obj00074 *)p)->f5C,&delta[2],1);
                }
                func_02028218(*(void **)(p+func_021BB034((u16 **)p)*4+0xc),1);
                ((struct Obj00074 *)p)->f8C=0;
                func_020061E4(0x548);
            } else if(func_0203633C()&0x220) {
                if(S->selected!=0) {
                    func_02028218(*(void **)(p+func_021BB034((u16 **)p)*4+0xc),0);
                    if(S->count<=6) S->selected=0;
                    else {
                        if(S->top>=6) {S->top-=6;S->selected-=6;}
                        else {S->top=0;if(S->selected>=6) S->selected-=6;else S->selected=0;}
                        func_021BB088(p);
                        y=func_021BB258(p,(u16)(func_021BB074((u16 **)p)+1),S->top);
                        delta[1].x=240;
                        delta[1].y=y;
                        func_0204B404(*(struct Obj * *)&((struct Obj00074 *)p)->f5C,&delta[1],1);
                    }
                    func_02028218(*(void **)(p+func_021BB034((u16 **)p)*4+0xc),1);
                    ((struct Obj00074 *)p)->f8C=0;
                    func_020061E4(0x548);
                }
            } else if(func_0203633C()&0x110) {
                if(S->selected<S->count-1) {
                    func_02028218(*(void **)(p+func_021BB034((u16 **)p)*4+0xc),0);
                    if(S->count<=6) S->selected=S->count-1;
                    else {
                        S->top+=6;
                        if(S->top>func_021BB074((u16 **)p)) S->top=func_021BB074((u16 **)p);
                        S->selected+=6;
                        if(S->selected>=S->count) S->selected=S->count-1;
                        func_021BB088(p);
                        y=func_021BB258(p,(u16)(func_021BB074((u16 **)p)+1),S->top);
                        delta[0].x=240;
                        delta[0].y=y;
                        func_0204B404(*(struct Obj * *)&((struct Obj00074 *)p)->f5C,&delta[0],1);
                    }
                    func_02028218(*(void **)(p+func_021BB034((u16 **)p)*4+0xc),1);
                    ((struct Obj00074 *)p)->f8C=0;
                    func_020061E4(0x548);
                }
            }
        }
    } else if(hit>=0 && hit<count) {
        S->selected=S->top+hit;
        func_02028218(*(void **)(p+func_021BB034((u16 **)p)*4+0xc),1);
        ((struct Obj00074 *)p)->f8C=0;
        func_0202822C(*(void **)(p+func_021BB034((u16 **)p)*4+0xc),1);
        func_020061E4(0x54c);
        return 1;
    }
    return 0;
}

/*
 * Lever: initialise offset after cursor clear, letting zero schedule at
 * that call's argument setup rather than before the touch-mode setter.
 */
int func_021BAE2C(char *p)
{
    u32_021BAE2C dragx,dragy;
    struct Vec2 drag;
    u32_021BAE2C clickx,clicky;
    struct Vec2 click;
    if(func_0204B3F4(*(struct Obj * *)&((struct Obj00074 *)p)->f5C)==0) return 0;
    if(((struct Obj00074 *)p)->f88) {
        if(func_02035CB8(&dragx,&dragy)) {
            int offset;
            u16 selection,end;
            func_020355D8(1);
            func_02028218(*(void **)(p+func_021BB034((u16 **)p)*4+0xc),0);
            offset=0;
            drag.x=240;
            if(dragy>=8) offset=dragy-8;
            drag.y=offset;
            if(drag.y<17) drag.y=17;
            else if(drag.y>135) drag.y=135;
            func_0204B404(*(struct Obj * *)&((struct Obj00074 *)p)->f5C,&drag,1);
            selection=func_021BB1F4(p,(u16)(func_021BB074((u16 **)p)+1),(u16)dragy);
            if(selection!=((struct Obj26201 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fC) {
                ((struct Obj26202 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fC=selection;
                end=func_021BB044((u16 **)p);
                if(((struct Obj00074 *)p)->f8C || ((struct Obj26203 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fE<((struct Obj26204 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fC || end<((struct Obj26205 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fE) {
                    ((struct Obj26207 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fE=((struct Obj26206 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fC;
                    ((struct Obj00074 *)p)->f8C=1;
                }
                func_021BB088(p);
                func_020061E4(0x548);
            }
        } else ((struct Obj00074 *)p)->f88=0;
        return 1;
    } else {
        if(func_02035D20(&clickx,&clicky) && clickx>=240 && clickx<=247 && clicky>=17 && clicky<=150) {
            int offset;
            u16 selection,end;
            func_020355D8(1);
            func_02028218(*(void **)(p+func_021BB034((u16 **)p)*4+0xc),0);
            offset=0;
            func_020061E4(0x548);
            ((struct Obj00074 *)p)->f88=1;
            click.x=240;
            if(clicky>=8) offset=clicky-8;
            click.y=offset;
            if(click.y<17) click.y=17;
            else if(click.y>135) click.y=135;
            func_0204B404(*(struct Obj * *)&((struct Obj00074 *)p)->f5C,&click,1);
            selection=func_021BB1F4(p,(u16)(func_021BB074((u16 **)p)+1),(u16)clicky);
            if(selection!=((struct Obj26208 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fC) {
                ((struct Obj26209 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fC=selection;
                end=func_021BB044((u16 **)p);
                if(((struct Obj00074 *)p)->f8C || ((struct Obj26210 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fE<((struct Obj26211 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fC || end<((struct Obj26212 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fE) {
                    ((struct Obj26214 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fE=((struct Obj26213 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fC;
                    ((struct Obj00074 *)p)->f8C=1;
                }
                func_021BB088(p);
            }
        }
        if(((struct Obj00074 *)p)->f88) return 1;
        return 0;
    }
}

void func_021BAFF8(u8 *p) { u8 i; for(i=0;i<6;i++) { p[i*4]=i*24+12; p[i*4+1]=(i+1)*24+11; p[i*4+2]=16; p[i*4+3]=239; } p[24]=255; p[25]=0; p[26]=0; p[27]=0; }


/*
 * Addresses are Black-image addresses.
 */
u16 func_021BB034(u16 **p)
{
    u16 *q = *p;
    return (u16)(q[7] - q[6] + 1);
}


u16 func_021BB044(u16 **p)
{
    u16 *q = *p;
    u16 a = (u16)(q[6] + 5);
    u16 b = q[2];
    if (a < b)
        return a;
    return (u16)(b - 1);
}


u16 func_021BB05C(u16 **p)
{
    return (u16)(func_021BB044(p) - (*p)[6] + 1);
}


u16 func_021BB074(u16 **p)
{
    u16 v = (*p)[2];
    if (v <= 6)
        return 0;
    return (u16)(v - 6);
}

void func_021BB088(char *p)
{
    struct Entry_021BB088 e;
    u8 first,last,i;
    u16 index,end;
    first=0;
    index=(u16)(((struct Obj26217 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fC-1);
    if (((struct Obj26218 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fC==0) {
        if (*(u8 * *)&((struct Obj00074 *)p)->fC) {
            func_0202843C(*(u8 * *)&((struct Obj00074 *)p)->fC);
            ((struct Obj00074 *)p)->f2C=0;
        }
        index=((struct Obj26219 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fC;
        first=1;
        func_0204B3DC(((struct Obj00074 *)p)->f60,0);
    }
    end=(u16)(func_021BB044((u16 **)p)+1);
    if (end>=((struct Obj26220 *)(*(char * *)&((struct Obj00074 *)p)->f0))->f4) end--;
    last=(u8)(first+end-index);
    for(i=last+1;i<=7;i++) {
        if (*(u8 **)(p+i*4+0xc)) {
            func_0202843C(*(u8 **)(p+i*4+0xc));
            *(u32_021BB088 *)(p+i*4+0x2c)=0;
        }
        func_0204B3DC(*(void **)(p+i*4+0x60),0);
    }
    for(i=first;i<=last;i++) {
        if (*(u8 **)(p+i*4+0xc)) func_0202815C();
        e.resource=func_02045EC0(*(struct MsgBank * *)&((struct Obj26221 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f20,*(u16 *)(*(char * *)&((struct Obj26222 *)(*(char * *)&((struct Obj00074 *)p)->f0))->f8+index*8+2));
        if(i==0 || i==7) e.tag=0x3da3; else e.tag=0x39e3;
        e.flags=0;
        if(((struct Obj00074 *)p)->f94)
            *(u32_021BB088 **)(p+i*4+0xc)=func_0202804C(*(u32_021BB088 *)&((struct Obj00074 *)p)->f8,(u32_021BB088)&e,2,(u8)(i*3),28,3,0,0,((struct Obj26223 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f4);
        else
            *(u32_021BB088 *)(p+i*4+0xc)=func_02027FEC(*(u32_021BB088 *)&((struct Obj00074 *)p)->f8,(u32_021BB088)&e,2,(u8)(i*3),28,((struct Obj26224 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f4);
        func_02028178(*(u8 **)(p+i*4+0xc));
        *(u32_021BB088 *)(p+i*4+0x2c)=1;
        func_02045808(e.resource);
        if (*(u32_021BB088 *)(*(char * *)&((struct Obj26225 *)(*(char * *)&((struct Obj00074 *)p)->f0))->f8+index*8+4)==0)
            func_0204B3DC(*(void **)(p+i*4+0x60),0);
        else if (*(u32_021BB088 *)(*(char * *)&((struct Obj26226 *)(*(char * *)&((struct Obj00074 *)p)->f0))->f8+index*8+4)==1)
            func_0204B3DC(*(void **)(p+i*4+0x60),1);
        index++;
    }
    ((struct Obj00074 *)p)->f94=1;
}

u16 func_021BB1F4(void *p, u16 count, u16 value)
{
    u16 index, upper, lower;
    if (count <= 1) index = 0;
    else if (value < 25) index = 0;
    else if (value >= 144) index = count - 1;
    else {
        for (index = 0; index < count; index++) {
            upper = (119 * (index + 1)) / count + 25;
            lower = (119 * index) / count + 25;
            if (lower <= value && value < upper) break;
        }
    }
    if (index >= count) index = 0;
    return index;
}

/*
 * lever: narrow the average to u16 before subtracting 8; minimum clamp returns directly.
 * extent: 90 compiled bytes followed by two zero alignment bytes at 021BB2B2.
 */
u16 func_021BB258(void *p, u16 count, u16 index)
{
    u16 result, low, high;
    if (index == 0) result = 17;
    else if (index == count - 1) result = 135;
    else {
        low = (119 * index) / count + 25;
        high = (119 * (index + 1)) / count + 25;
        result = (low + high) / 2;
        result -= 8;
    }
    if (result < 17) return 17;
    if (result > 135) result = 135;
    return result;
}

char *func_021BB2B4(char *p, char *data)
{
    char *q;
    q = func_02030734(((struct Obj26227 *)data)->f4, 32, 1, file_021BC038, 157);
    *(char * *)&((struct Obj05574 *)q)->f0 = p;
    ((struct Obj26228 *)p)->f4 = 1;
    *(char * *)&((struct Obj05574 *)q)->f4 = data;
    func_021BB400(q);
    func_021BB4F8(q);
    ((struct Obj05574 *)q)->f14 = func_020056A0((unsigned)func_021BB3FC, (unsigned)q, 1);
    ((struct Obj05574 *)q)->f18 = 0;
    q[0x1c] = -1;
    func_021BA068(*(char * *)&((struct Obj26229 *)(*(char * *)&((struct Obj05574 *)q)->f4))->f34, 0);
    return q;
}


void func_021BB308(char *p)
{
    func_02030EAC((struct Node *)(((struct Obj26230 *)p)->f14));
    func_020307B0(p);
}

/*
 * Tail: 021BB3FA alignment, existing matched follower 021BB3FC.
 * Lever: switch body order 1 then 0 preserves the shared store block.
 */
int func_021BB31C(char *p)
{
    int done = 0;
    u8 i;
    if (((struct Obj00691 *)p)->f1C==0) done=1;
    else if (((struct Obj00691 *)p)->f1C>0) {
        if (((struct Obj00691 *)p)->f1C==1) func_021BB504(p);
        --((struct Obj00691 *)p)->f1C;
    }
    if (((struct Obj00691 *)p)->f18==0 || ((struct Obj00691 *)p)->f18==2) {
        func_021B9FBC(*(char * *)&((struct Obj26231 *)(*(char * *)&((struct Obj00691 *)p)->f4))->f34);
        if (((struct Obj00691 *)p)->f18==0) {
            if (func_021BA158(*(char * *)&((struct Obj26232 *)(*(char * *)&((struct Obj00691 *)p)->f4))->f34)!=-1)
                ((struct Obj00691 *)p)->f18=2;
        } else {
            int result=func_021BA154(*(char * *)&((struct Obj26233 *)(*(char * *)&((struct Obj00691 *)p)->f4))->f34);
            if (result!=-1) {
                switch (result) {
                case 1: ((struct Obj26234 *)(*(char * *)&((struct Obj00691 *)p)->f0))->f4=1; break;
                case 0: ((struct Obj26235 *)(*(char * *)&((struct Obj00691 *)p)->f0))->f4=0; break;
                }
                ((struct Obj00691 *)p)->f18=1;
                ((struct Obj00691 *)p)->f1C=1;
            }
        }
    }
    if (((struct Obj00691 *)p)->f18==0 || ((struct Obj00691 *)p)->f18==3) {
        for (i=0;i<2;i++) func_02028178((u8 *)(*(char **)(p+0xc+i*4)));
        if (((struct Obj00691 *)p)->f18==0) {
            if (func_021BB53C(p)) ((struct Obj00691 *)p)->f18=3;
        } else {
            if (func_02028230((u8 *)(*(char **)(p+0xc+**(u8 * *)&((struct Obj00691 *)p)->f0*4)))) {
                unsigned value;
                if (**(u8 * *)&((struct Obj00691 *)p)->f0==0) value=2;
                else if (**(u8 * *)&((struct Obj00691 *)p)->f0==1) value=3;
                else goto finish;
                ((struct Obj26239 *)(*(char * *)&((struct Obj00691 *)p)->f0))->f4=value;
finish:
                ((struct Obj00691 *)p)->f18=1;
                ((struct Obj00691 *)p)->f1C=1;
            }
        }
    }
    return done;
}

void func_021BB3FC(void *p)
{
}

/*
 * extent: 86 compiled bytes followed by two zero alignment bytes at 021BB456.
 */
void func_021BB400(char *p)
{
    func_02049B68((void *)(((struct Obj26240 *)(*(char * *)&((struct Obj01596 *)p)->f4))->f24), 0, 4, 0, 64, ((struct Obj26241 *)(*(char * *)&((struct Obj01596 *)p)->f4))->f4);
    func_02049658((void *)(((struct Obj26242 *)(*(char * *)&((struct Obj01596 *)p)->f4))->f24), 2, 4, 0, 0, 0, ((struct Obj26243 *)(*(char * *)&((struct Obj01596 *)p)->f4))->f4);
    func_020499D4((void *)(((struct Obj26244 *)(*(char * *)&((struct Obj01596 *)p)->f4))->f24), 4, 4, 0, 0, 0, 0, ((struct Obj26245 *)(*(char * *)&((struct Obj01596 *)p)->f4))->f4);
    func_021BB458(p);
}

void func_021BB458(char *p)
{
    struct Entry_021BB458 entries[2];
    u8 i;
    *(struct R * *)&((struct Obj01596 *)p)->f8 = func_02027F60(5, 4, ((struct Obj26246 *)(*(char * *)&((struct Obj01596 *)p)->f4))->fC, ((struct Obj26247 *)(*(char * *)&((struct Obj01596 *)p)->f4))->f14, ((struct Obj26248 *)(*(char * *)&((struct Obj01596 *)p)->f4))->f4);
    entries[0].resource = func_02045EC0(*(struct MsgBank * *)&((struct Obj26249 *)(*(char * *)&((struct Obj01596 *)p)->f4))->f1C, 0);
    entries[0].tag = 0x39e3;
    entries[0].flags = 0;
    entries[1].resource = func_02045EC0(*(struct MsgBank * *)&((struct Obj26250 *)(*(char * *)&((struct Obj01596 *)p)->f4))->f1C, 1);
    entries[1].tag = 0x39e3;
    entries[1].flags = 0;
    for (i = 0; i < 2; i++) {
        *(unsigned *)(p + i * 4 + 0xc) = func_02027FEC(*(unsigned *)&((struct Obj01596 *)p)->f8, (unsigned)&entries[i], 1, (u8)((i + 1) * 3), 30, ((struct Obj26251 *)(*(char * *)&((struct Obj01596 *)p)->f4))->f4);
        func_02045808(entries[i].resource);
    }
    if (func_020355C4() == 0) func_02028218(*(struct Obj **)(p + *(u8 *)*(char * *)&((struct Obj01596 *)p)->f0 * 4 + 0xc), 1);
}

void func_021BB4F8(char *a0) { sub_02041B6C(4); }

void func_021BB504(char *p) { func_021BB50C(p); }

void func_021BB50C(char *p) { u8 i; func_0201C6EC(*(struct PrintSys * *)&((struct Obj26253 *)(*(char * *)&((struct Obj14809 *)p)->f4))->f14); for(i=0;i<2;i++) func_02028148(*(u8 **)(p+i*4+12)); func_02027FD8(*(struct TaskMenuState * *)&((struct Obj14809 *)p)->f8); sub_02041B6C(5); }

/*
 * Lever: unhinted BF9C data uses this function's own overlay region.
 */
int func_021BB53C(char *p)
{
    int hit=func_02035C08(d_021BBF9C);
    if(func_020355C4()==0) {
        if(hit>=0 && hit<=1) {
            func_020355D8(1);
            func_02028218(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),0);
        }
    } else {
        if(func_020362DC()!=0 && !(func_020362DC()&0x402)) {
            func_020355D8(0);
            func_02028218(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),1);
            func_020061E4(0x548);
            return 0;
        }
    }
    if(func_020355C4()==0) {
        if(func_020362DC()&1) {
            func_0202822C(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),1);
            func_020061E4(0x54c);
            return 1;
        } else if(func_0203633C()&0x40) {
            func_02028218(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),0);
            if(**(u8 * *)&((struct Obj00740 *)p)->f0==0) **(u8 * *)&((struct Obj00740 *)p)->f0=1; else **(u8 * *)&((struct Obj00740 *)p)->f0=0;
            func_02028218(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),1);
            func_020061E4(0x548);
        } else if(func_0203633C()&0x80) {
            func_02028218(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),0);
            if(**(u8 * *)&((struct Obj00740 *)p)->f0==1) **(u8 * *)&((struct Obj00740 *)p)->f0=0; else **(u8 * *)&((struct Obj00740 *)p)->f0=1;
            func_02028218(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),1);
            func_020061E4(0x548);
        } else if(func_0203633C()&0x220) {
            if(**(u8 * *)&((struct Obj00740 *)p)->f0==1) {
                func_02028218(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),0);
                **(u8 * *)&((struct Obj00740 *)p)->f0=0;
                func_02028218(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),1);
                func_020061E4(0x548);
            }
        } else if(func_0203633C()&0x110) {
            if(**(u8 * *)&((struct Obj00740 *)p)->f0==0) {
                func_02028218(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),0);
                **(u8 * *)&((struct Obj00740 *)p)->f0=1;
                func_02028218(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),1);
                func_020061E4(0x548);
            }
        }
    } else if(hit>=0 && hit<=1) {
        **(u8 * *)&((struct Obj00740 *)p)->f0=hit;
        func_02028218(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),1);
        func_0202822C(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),1);
        func_020061E4(0x54c);
        return 1;
    }
    return 0;
}
