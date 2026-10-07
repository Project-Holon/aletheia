/*
 * file:     pmsiv_wordwin_p07.c
 * unit:     yes
 * function: func_021BFB58, func_021BFB7C, func_021BFBA0
 * address:  0x021BFB58
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BC898 0x021BC898 thumb ov110
 *   func_021BC868 0x021BC868 thumb ov110
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02040588 0x02040588 arm
 */
#include "../../matched/include/Obj22402.h"
#include "../../matched/include/Obj22403.h"
#include "../../matched/include/Obj13800.h"

struct Obj;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef struct { unsigned char plane:5; unsigned char effect:1; unsigned char rest:2; } Wnd;

extern int func_021BC898(u8 *p);
extern void func_021BC868(u8 *p, int a, int b, int start, int end, int frames);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_02040588(unsigned char which, unsigned char enable);
int func_021BFB58(u8 *p);
void func_021BFB7C(u8 *p);
int func_021BFBA0(u8 *p);

/*
 * note: two trailing zero alignment bytes.
 */
int func_021BFB58(u8 *p) {
    if(((struct Obj22402 *)p)->f88==0) {
        if(func_021BC898(p+0x4c)) return 1;
        else return 0;
    } else return 1;
}

void func_021BFB7C(u8 *p) {
    ((struct Obj22403 *)p)->f88=0;
    func_021BC868(p+0x4c,4,63,124,0,12);
}

static inline void outside(int wnd,int effect) {
    unsigned tmp=*(volatile u16 *)0x0400004a & ~0x3f;
    tmp|=wnd;
    if(effect) tmp|=0x20;
    *(volatile u16 *)0x0400004a=tmp;
}

static inline void visible(int window) {
    *(volatile unsigned *)0x04000000=(*(volatile unsigned *)0x04000000 & ~0xe000) | (window<<13);
}

int func_021BFBA0(u8 *p) {
    int i;
    if(((struct Obj13800 *)p)->f88==0) {
    if(func_021BC898(p+0x4c)) {
        for(i=0;i<10;i++) func_0204B3DC(*(void **)(p+0x20+4*i),0);
        func_02040588(2,0);
        outside(((Wnd *)(p+0x8c))->plane,((Wnd *)(p+0x8c))->effect);
        visible(((struct Obj13800 *)p)->f90);
        return 1;
    }
    } else return 1;
    return 0;
}
