/*
 * function: func_021BCCA8
 * address: 0x021BCCA8
 * packet: pkt_ov110_021BCCA8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BF6E4 0x021BF6E4 thumb ov110
 *   func_0204B898 0x0204B898 arm
 *   func_021BD470 0x021BD470 thumb ov110
 *   func_021BD0F8 0x021BD0F8 thumb ov110
 *   func_021BD448 0x021BD448 thumb ov110
 *   d_021C38DF 0x021C38DF data a1
 *   d_021C38D4 0x021C38D4 data a1
 */
#include "../include/Obj13784.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u8 pad[0x70]; void *items[8]; } Object;
extern int func_021BF6E4(u8 *p);
struct Obj;
extern u16 func_0204B898(struct Obj *p);
extern void func_021BD470(u8 *p, int i);
extern void func_021BD0F8(u8 *p, int i, int flag);
extern void func_021BD448(u8 *p, int i);
extern const u8 d_021C38DF[],d_021C38D4[];
void func_021BCCA8(Object *p) {
    int old,new;
    int selected;
    int i;
    int state;
    old=-1; new=-1;
    selected=func_021BF6E4(((struct Obj13784 *)p)->f4);
    for(i=1;i<=5;i++) {
        state=func_0204B898(p->items[i]);
        if(state==d_021C38DF[i*2+1]) { old=i; break; }
    }
    for(i=0;i<5;i++) {
        if(i==selected) { new=d_021C38D4[i]; break; }
    }
    if(old>=0 && old!=new) func_021BD470((u8 *)p,old);
    for(i=0;i<5;i++) func_021BD0F8((u8 *)p,d_021C38D4[i],i==selected);
    if(new>=0 && old!=new) func_021BD448((u8 *)p,new);
}
