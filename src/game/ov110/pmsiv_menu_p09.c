/*
 * file:     pmsiv_menu_p09.c
 * unit:     yes
 * function: func_021BCC88, func_021BCCA8, func_021BCD44, func_021BCD80, func_021BCDE0, func_021BCDFC, func_021BCE30, func_021BCE48, func_021BCE54, func_021BCE70, func_021BCEA0, func_021BCEBC, func_021BCEE4, func_021BCF18, func_021BCF38
 * address:  0x021BCC88
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
 *   func_021BCAD8 0x021BCAD8 thumb ov110
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B878 0x0204B878 arm
 *   func_021BF6E4 0x021BF6E4 thumb ov110
 *   func_0204B898 0x0204B898 arm
 *   func_021BD470 0x021BD470 thumb ov110
 *   func_021BD0F8 0x021BD0F8 thumb ov110
 *   func_021BD448 0x021BD448 thumb ov110
 *   d_021C38DF 0x021C38DF data a1
 *   d_021C38D4 0x021C38D4 data a1
 *   func_021BF824 0x021BF824 thumb ov110
 *   func_020282AC 0x020282AC thumb
 *   func_021BF7FC 0x021BF7FC thumb ov110
 *   func_021BF808 0x021BF808 thumb ov110
 *   func_021BF6DC 0x021BF6DC thumb ov110
 *   func_021BCFBC 0x021BCFBC thumb ov110
 *   func_021BCFF0 0x021BCFF0 thumb ov110
 *   func_0204B98C 0x0204B98C arm
 *   func_020282A4 0x020282A4 thumb
 */
#include "../../matched/include/Obj00295.h"
#include "../../matched/include/Obj13784.h"
#include "../../matched/include/Obj06389.h"
#include "../../matched/include/Obj01144.h"
#include "../../matched/include/Obj10278.h"
#include "../../matched/include/Obj06390.h"

struct Obj;
struct T;
struct Actor;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16_021BCC88;

typedef unsigned int u32;

typedef struct { u8 pad[0x70]; void *items[8]; } Object;

typedef signed short s16_021BCD44;

typedef signed short s16_021BCDE0;

typedef short s16_021BCE48;

typedef signed char s8;

typedef int s32;

extern void func_021BCAD8(void *);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern int func_021BF6E4(u8 *p);
extern u16 func_0204B898(struct Obj *p);
extern void func_021BD470(u8 *p, int i);
extern void func_021BD0F8(u8 *p, int i, int flag);
extern void func_021BD448(u8 *p, int i);
extern int func_021BF824(u8 *);
extern void func_020282AC(struct T *p, u16 *a1, u32 a2, u32 a3, u16 a4);
extern u8 func_021BF7FC(u8 *p);
extern int func_021BF808(u8 *);
extern u8 func_021BF6DC(u8 *);
extern void func_021BCFBC(char *p, u32 index, int value);
extern u32 func_021BCFF0(char *,u32);
extern u32 func_0204B98C(struct Actor *a);
extern void func_020282A4(struct Obj *obj);
void func_021BCC88(u8 *p);
void func_021BCCA8(Object *p);
void func_021BCD44(u8 *p);
void func_021BCD80(u8 *p);
void func_021BCDE0(u8 *p);
int func_021BCDFC(char *p);
void func_021BCE24(void *p);
int func_021BCE30(char *p);
void func_021BCE48(void *p, int a1, int a2);
void func_021BCE54(char *p);
int func_021BCE70(char *p);
void func_021BCEA0(char *p);
int func_021BCEBC(char *p);
void func_021BCEE4(char *p,u32 mode);
void func_021BCF18(void *p,int mode);
int func_021BCF38(char *p,u32 mode);
extern const u8 d_021C38DF[],d_021C38D4[];

void func_021BCC88(u8 *p)
{
    func_021BCAD8(p);
    func_0204B3DC(((struct Obj00295 *)p)->f28, 1);
    func_0204B878(((struct Obj00295 *)p)->f28, 1);
    ((struct Obj00295 *)p)->f2C = 0;
}

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

/*
 * Reads r0 after BF824 and supplies p+4; preserve return and visible argument.
 */
void func_021BCD44(u8 *p)
{
    if (func_021BF824(*(u8 * *)&((struct Obj06389 *)p)->f4) != 0) {
        func_020282AC(((struct Obj06389 *)p)->f64, *(u16 * *)&((struct Obj06389 *)p)->f34, 8, 0x3545, 0x7b2c);
    } else {
        func_020282AC(((struct Obj06389 *)p)->f64, *(u16 * *)&((struct Obj06389 *)p)->f34, 14, 0x3545, 0x7b2c);
    }
}

void func_021BCD80(u8 *p) {
    if (func_021BF7FC(*(u8 * *)&((struct Obj01144 *)p)->f4))
        func_020282AC(((struct Obj01144 *)p)->f64,((struct Obj01144 *)p)->f34,8,0x3545,0x7b2c);
    else
        func_020282AC(((struct Obj01144 *)p)->f64,((struct Obj01144 *)p)->f34,14,0x3545,0x7b2c);
    if (func_021BF808(*(u8 * *)&((struct Obj01144 *)p)->f4))
        func_020282AC(((struct Obj01144 *)p)->f68,((struct Obj01144 *)p)->f38,8,0x3545,0x7b2c);
    else
        func_020282AC(((struct Obj01144 *)p)->f68,((struct Obj01144 *)p)->f38,14,0x3545,0x7b2c);
}

void func_021BCDE0(u8 *p)
{
    if (func_021BF6DC(*(u8 * *)&((struct Obj10278 *)p)->f4) == 1) func_021BCFBC((char *)p, 2, 1);
}

int func_021BCDFC(char *p) { if (func_021BF6DC(*(u8 * *)&((struct Obj06390 *)p)->f4)==1) { if (func_021BCFF0(p,2)) return 1; return 0; } return 1; }

void func_021BCE24(void *p) { func_021BD0F8(p,7,1); }

int func_021BCE30(char *p) { if (func_0204B98C(((struct Obj06390 *)p)->f8C)==0) return 1; return 0; }

void func_021BCE48(void *p, int a1, int a2) { func_021BD0F8(p, 7, 0); }

/*
 * Extent ends in two-byte alignment padding at 0x021BCE6E.
 */
void func_021BCE54(char *p) { if (func_021BF6DC(*(u8 * *)&((struct Obj10278 *)p)->f4)==1) func_021BCFBC(p,1,1); }

int func_021BCE70(char *p) { int result; if (func_021BF6DC(*(u8 * *)&((struct Obj06390 *)p)->f4)==1) { result=1; if (func_021BCFF0(p,1)) { func_020282A4(((struct Obj06390 *)p)->f68); return result; } } else { return 1; } return 0; }

/*
 * Extent ends in two-byte alignment padding at 0x021BCEBA.
 */
void func_021BCEA0(char *p) { if (func_021BF6DC(*(u8 * *)&((struct Obj10278 *)p)->f4)==1) func_021BCFBC(p,0,1); }

static inline int Check(char *p, int zero)
{
    u32 value;
    value = func_021BCFF0(p, zero);
    p = 0;
    if (value) p = (char *)1;
    return (int)p;
}

/*
 * extent: 38-byte function followed by two zero alignment bytes.
 * lever: inline helper reuses its dying pointer for the zero/one result;
 *   zero assignment remains explicit, and the allocator shares r4.
 */
int func_021BCEBC(char *p)
{
    if (func_021BF6DC(*(u8 * *)&((struct Obj06390 *)p)->f4)==1) {
        return Check(p, 0);
    }
    return 1;
}

/*
 * Extent ends in two-byte alignment padding at 0x021BCF16.
 */
void func_021BCEE4(char *p,u32 mode) { switch(mode) { case 0: func_021BCDE0((u8 *)p); break; case 1: func_021BCE24(p); break; case 2: func_021BCE54(p); break; case 3: func_021BCEA0(p); break; } }

void func_021BCF18(void *p,int mode) { switch(mode) { case 0: func_021BD0F8(p,0,1); break; case 1: func_021BD0F8(p,6,1); break; } }

int func_021BCF38(char *p,u32 mode) { switch(mode) { case 0: return func_021BCDFC(p); case 1: return func_021BCE30(p); case 2: return func_021BCE70(p); case 3: return func_021BCEBC(p); } return 1; }
