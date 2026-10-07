/*
 * file:     irc_ranking_p05.c
 * unit:     yes
 * function: func_021B80AC, func_021B80B0, func_021B80BC, func_021B80D0, func_021B8304, func_021B838C, func_021B8408, func_021B84C4, func_021B84D0
 * address:  0x021B80AC
 * region:   ov106
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B7FF4  0x021B7FF4  thumb  ov106
 *   func_021B7F74 0x021B7F74 thumb ov106
 *   func_021B7FEC 0x021B7FEC thumb ov106
 *   func_02082BCC 0x02082BCC arm
 *   func_021B8D8C 0x021B8D8C thumb ov106
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_021B8AD0 0x021B8AD0 thumb ov106
 *   func_020490F4 0x020490F4 arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0204ACEC 0x0204ACEC arm
 *   func_02049238 0x02049238 arm
 *   func_021B87B0 0x021B87B0 thumb ov106
 *   func_020450F0 0x020450F0 arm
 *   func_02040618 0x02040618 arm
 *   func_021B8524 0x021B8524 thumb ov106
 *   func_021B8648 0x021B8648 thumb ov106
 *   func_021B8690 0x021B8690 thumb ov106
 *   func_020056A0 0x020056A0 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_020452E8 0x020452E8 arm
 *   func_021B89F4 0x021B89F4 thumb ov106
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_021B8B4C 0x021B8B4C thumb ov106
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021B8A6C 0x021B8A6C thumb ov106
 */
#include "../../matched/include/Obj05281.h"
#include "../../matched/include/Obj02814.h"
#include "../../matched/include/Obj01710.h"
#include "../../matched/include/Obj22262.h"
#include "../../matched/include/Obj22263.h"

struct GfFont;
struct WordSet;
struct Descriptor;
struct Node;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16_021B80AC;

typedef signed char s8;

typedef unsigned int u32;

typedef int s32;

typedef short s16_021B80B0;

typedef signed short s16_021B80D0;

typedef signed short s16_021B838C;

typedef signed short s16_021B8408;

typedef short s16_021B84C4;

typedef signed short s16_021B84D0;

extern void *func_021B7FF4(void **p);
/* Both callback callees ignore entry arguments, but the original explicitly supplies them. */
extern void func_021B7F74(u8 *);
extern void func_021B7FEC(u8 *);
extern void func_02082BCC(void *,int,int);
extern u32 func_021B8D8C(u8 *);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_021B8AD0(u8 *,u8 *,u16);
extern void *func_020490F4(u32 id, u32 heap);
extern int func_0201BC3C(void);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_02049238(void *);
extern void func_021B87B0(u8 *,const u8 *,void *,u32,u32,void *,u32,void *,void *,s16_021B80D0,s16_021B80D0,u16);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_021B8524(u8 *);
extern void func_021B8648(u8 *);
extern void func_021B8690(void *unused, u8 *p);
extern u32 func_020056A0(void (*)(void),void *,u32);
extern void func_02030EAC(struct Node *n);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_021B89F4(u8 *);
extern void func_0204ADA4(u32 i);
extern void func_021B8B4C(void *);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_0201D83C(void *ptr);
extern void func_020061E4(u32 a);
extern void func_021B8A6C(u8 *,int);
void func_021B80AC(void);
void *func_021B80B0(u8 *p);
void func_021B80BC(void *a,u8 *p);
void func_021B80D0(u8 *p,u32 a1,u8 a2,u8 a3,u8 s0,u32 s1,void *s2,void *s3,u8 *s4,u16 heap);
void func_021B8304(u8 *p);
void func_021B838C(u8 *p);
void func_021B8408(u8 *p,s16_021B8408 delta);
s16_021B84C4 func_021B84C4(u8 *p);
int func_021B84D0(u8 *p);


void func_021B80AC(void) { }

/*
 * Unblocked by matching func_021B7FF4 in ov106 (pkt_ov106_021B7FF4).
 */
void *func_021B80B0(u8 *p) { return func_021B7FF4((void **)(p + 0x10)); }

void func_021B80BC(void *a,u8 *p) { func_021B7F74(p); func_021B7FEC(p+16); }

/*
 * note 2026-10-05 (final push G8L9): closed. The two zero stores at +0x556/+0x558 are written with
 *   literal 0 and `m = 0;` comes after them, just before the clamp. With `m = 0;` before the calls the
 *   zero joins the clamp's phi web, so -40 was derived from the held 1 (`subs r7,#0x29`) and 1 won the
 *   block-constant register over 0x20. With the literal zero stores the zero stays a plain constant
 *   and -40 is built fresh (`movs r1,#0; subs r1,#0x28`) while 0x20 keeps r7.
 */
void func_021B80D0(u8 *p,u32 a1,u8 a2,u8 a3,u8 s0,u32 s1,void *s2,void *s3,u8 *s4,u16 heap) {
    void *arc;
    int i;
    int m;
    i = 0;
    func_02082BCC(p,0,0x59C);
    *(u32 *)(p+0x54C) = s1;
    *(u8 *)(p+0x548) = a1;
    *(u8 *)(p+0x549) = a2;
    *(u8 *)(p+0x54A) = a3;
    *(u8 *)(p+0x54B) = s0;
    *(u8 **)(p+0x550) = s4;
    *(u16 *)(p+0x554) = func_021B8D8C(s4);
    *(struct GfFont **)(p+0x570) = func_0201D7EC(23,0,0,1,heap);
    *(void **)(p+0x574) = s3;
    *(struct WordSet **)(p+0x588) = func_0201EC64(heap);
    func_021B8AD0(p+8,(u8 *)s1,heap);
    arc = func_020490F4(7,heap);
    *(int *)p = func_0204ACEC(arc,func_0201BC3C(),0,0x20,heap);
    *(int *)(p+4) = func_0204ACEC(arc,func_0201BC3C(),1,0x20,heap);
    func_02049238(arc);
    for (i = 0; i < func_021B8D8C(s4); i++) {
        func_021B87B0(p+0x188+i*32,s4+4+i*16,s2,*(u32 *)p,*(u32 *)(p+4),*(void **)(p+0x574),*(u32 *)(p+0x570),*(void **)(p+0x588),p+8,i*24+0x52,i*24-0x70,heap);
    }
    *(u32 *)(p+0x568) = func_020450F0(a2,0,0,0x20,0x20,14,1);
    *(u32 *)(p+0x56C) = func_020450F0(s0,0,0,0x20,0x20,14,1);
    *(s16_021B80D0 *)(p+0x564) = -40;
    *(s16_021B80D0 *)(p+0x566) = 24;
    func_02040618(*(u8 *)(p+0x548),3,*(s16_021B80D0 *)(p+0x564));
    func_02040618(*(u8 *)(p+0x549),3,*(s16_021B80D0 *)(p+0x564));
    func_02040618(*(u8 *)(p+0x54A),3,*(s16_021B80D0 *)(p+0x566));
    func_02040618(*(u8 *)(p+0x54B),3,*(s16_021B80D0 *)(p+0x566));
    *(u16 *)(p+0x556) = 0;
    *(u16 *)(p+0x558) = 0;
    m = 0;
    *(u16 *)(p+0x55A) = *(u16 *)(p+0x554) * 24 - 0x120;
    if (*(s16_021B80D0 *)(p+0x55A) > 0) m = *(s16_021B80D0 *)(p+0x55A);
    *(u16 *)(p+0x55A) = m;
    func_021B8524(p);
    func_021B8648(p);
    *(u32 *)(p+0x58C) = func_020056A0((void (*)(void))func_021B8690,p,0);
}

void func_021B8304(u8 *p) {
    int i;
    func_02030EAC(((struct Obj05281 *)p)->f58C);
    for(i=0;i<2;i++)func_020452E8(*(void **)((u8 *)((u32 *)p+i)+0x568));
    for(i=0;i<func_021B8D8C(*(u8 * *)&((struct Obj05281 *)p)->f550);i++)func_021B89F4(p+0x188+i*32);
    func_0204ADA4((u32)(((struct Obj05281 *)p)->f0));
    func_0204ADA4((u32)(((struct Obj05281 *)p)->f4));
    func_021B8B4C(p+8);
    func_0201ED04(((struct Obj05281 *)p)->f588);
    func_0201D83C(((struct Obj05281 *)p)->f570);
    func_02082BCC(p,0,0x59c);
}

void func_021B838C(u8 *p) {
    int value;
    if(((struct Obj02814 *)p)->f594==0)return;
    ((struct Obj02814 *)p)->f594=0;
    value=((struct Obj02814 *)p)->f556;
    if(value%24==0) {
        if(((struct Obj02814 *)p)->f55C!=value/24)func_020061E4(1605);
        ((struct Obj02814 *)p)->f55C=((struct Obj02814 *)p)->f556/24;
        ((struct Obj02814 *)p)->f564=-40;
        ((struct Obj02814 *)p)->f566=24;
        func_021B8524(p);
        ((struct Obj02814 *)p)->f590=1;
    } else ((struct Obj02814 *)p)->f598=1;
}

void func_021B8408(u8 *p,s16_021B8408 delta) {
    int old,next;
    int i;
    old=((struct Obj01710 *)p)->f556;
    next=old+delta;
    if(((struct Obj01710 *)p)->f558>next) {
        ((struct Obj01710 *)p)->f556=((struct Obj01710 *)p)->f558;
        ((struct Obj01710 *)p)->f55E=0;
    } else if(((struct Obj01710 *)p)->f55A<next) {
        ((struct Obj01710 *)p)->f556=((struct Obj01710 *)p)->f55A;
        ((struct Obj01710 *)p)->f55E=0;
    } else {
        if(old/24!=next/24 && old%24!=0) {
            if(delta>=0)delta=delta-next%24;
            else delta=delta+(24-next%24);
        }
        ((struct Obj01710 *)p)->f556+=delta;
        ((struct Obj01710 *)p)->f55E=delta;
    }
    for(i=0;i<((struct Obj01710 *)p)->f554;i++)func_021B8A6C(p+0x188+i*32,((struct Obj01710 *)p)->f556);
    ((struct Obj01710 *)p)->f594=1;
}


s16_021B84C4 func_021B84C4(u8 *p) { return ((struct Obj22262 *)p)->f556; }

/*
 * volatile: count halfword re-read at 0x021B84D6 and 0x021B84F4.
 */
int func_021B84D0(u8 *p) {
    int i;
    int found;
    found=0;
    i=0;
    for (; i<*(volatile u16 *)&((struct Obj22263 *)p)->f554; i++) {
        if ((*(u8 **)(p+0x188+i*32))[13] != 0) {found=1; break;}
    }
    if(found) return (s16_021B84D0)(24*i);
    return -1;
}
