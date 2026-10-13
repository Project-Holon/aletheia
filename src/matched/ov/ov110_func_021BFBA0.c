/*
 * function: PMSIV_WORDWIN_FinishClose
 * address: 0x021BFBA0
 * packet: pkt_ov110_021BFBA0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 0x021BFBD8 reads WINOUT; 0x021BFBFC reads DISPCNT.
 * symbols:
 *   PMSIV_FADE_IsBlendDone 0x021BC898 thumb ov110
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   func_02040588 0x02040588 arm
 */
#include "../include/Obj13800.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { unsigned char plane:5; unsigned char effect:1; unsigned char rest:2; } Wnd;
typedef unsigned int   u32;
struct Obj;
extern int PMSIV_FADE_IsBlendDone(u8 *p);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void func_02040588(unsigned char which, unsigned char enable);
static inline void outside(int wnd,int effect) {
    unsigned tmp=*(volatile u16 *)0x0400004a & ~0x3f;
    tmp|=wnd;
    if(effect) tmp|=0x20;
    *(volatile u16 *)0x0400004a=tmp;
}
static inline void visible(int window) {
    *(volatile unsigned *)0x04000000=(*(volatile unsigned *)0x04000000 & ~0xe000) | (window<<13);
}
int PMSIV_WORDWIN_FinishClose(u8 *p) {
    int i;
    if(((struct Obj13800 *)p)->f88==0) {
    if(PMSIV_FADE_IsBlendDone(p+0x4c)) {
        for(i=0;i<10;i++) CLACT_SetActorDrawEnable(*(void **)(p+0x20+4*i),0);
        func_02040588(2,0);
        outside(((Wnd *)(p+0x8c))->plane,((Wnd *)(p+0x8c))->effect);
        visible(((struct Obj13800 *)p)->f90);
        return 1;
    }
    } else return 1;
    return 0;
}
