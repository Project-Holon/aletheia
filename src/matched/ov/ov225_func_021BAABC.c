/*
 * function: func_021BAABC
 * address: 0x021BAABC
 * packet: pkt_ov225_021BAABC
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Lever: capture scrollbar helper result, store x then y; direct y-store
 * before x-store changes all four coordinate write blocks (28 bytes).
 * symbols:
 *   func_021BAFF8 0x021BAFF8 thumb ov225
 *   func_02035C08 0x02035C08 arm
 *   func_021BB05C 0x021BB05C thumb ov225
 *   func_021BB044 0x021BB044 thumb ov225
 *   func_020355C4 0x020355C4 arm
 *   func_020355D8 0x020355D8 arm
 *   func_021BB034 0x021BB034 thumb ov225
 *   func_02028218 0x02028218 thumb
 *   func_020362DC 0x020362DC arm
 *   func_0203633C 0x0203633C arm
 *   func_020061E4 0x020061E4 thumb
 *   func_0202822C 0x0202822C thumb
 *   func_021BB074 0x021BB074 thumb ov225
 *   func_021BB088 0x021BB088 thumb ov225
 *   func_021BB258 0x021BB258 thumb ov225
 *   func_0204B404 0x0204B404 arm
 */
#include "../include/Obj00074.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
struct State {u16 a,b,count,c;void *data;u16 top,selected;};
struct Obj;struct Vec2 {short x,y;};
extern void func_021BAFF8(u8 *);
extern int func_02035C08(const void *);
extern u16 func_021BB05C(u16 **),func_021BB044(u16 **),func_021BB034(u16 **),func_021BB074(u16 **);
extern u8 func_020355C4(void);
extern void func_020355D8(u8);
extern void func_02028218(struct Obj *obj, u32 a);
extern void func_0202822C(char *p, int v);
extern u32 func_020362DC(void),func_0203633C(void);
extern void func_020061E4(u32);
extern void func_021BB088(char *);
extern u16 func_021BB258(void *,u16,u16);
extern void func_0204B404(struct Obj *,const struct Vec2 *,u32);
#define S (*(struct State **)p)
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
