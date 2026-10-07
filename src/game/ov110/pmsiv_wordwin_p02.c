/*
 * file:     pmsiv_wordwin_p02.c
 * unit:     yes
 * function: func_021BF758, func_021BF784, func_021BF7A0, func_021BF7AC, func_021BF7B8, func_021BF7C4, func_021BF7D0, func_021BF7D4, func_021BF7E0, func_021BF7EC
 * address:  0x021BF758
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
 *   func_021B99A4 0x021B99A4 thumb ov110
 *   func_021BB1CC 0x021BB1CC thumb ov110
 *   func_021BEDC4 0x021BEDC4 thumb ov110
 *   func_021BEDE0  0x021BEDE0  thumb  ov110
 *   func_021BEDE4 0x021BEDE4 thumb ov110
 *   func_021BEDE8 0x021BEDE8 thumb ov110
 *   func_02024158  0x02024158  thumb
 *   func_021BB00C  0x021BB00C  thumb  ov110
 *   func_021BAFE4 0x021BAFE4 thumb ov110
 */
#include "../../matched/include/Obj08009.h"
#include "../../matched/include/Obj22392.h"
#include "../../matched/include/Obj22393.h"
#include "../../matched/include/Obj22394.h"
#include "../../matched/include/Obj22395.h"
#include "../../matched/include/Obj22396.h"
#include "../../matched/include/Obj13799.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

typedef signed char s8;

typedef int s32;

extern void func_021B99A4(u32,u32,u32,int);
extern int func_021BB1CC(u8 *p, u8 i, int c);
extern u32 func_021BEDC4(u8 *);
extern u32 func_021BEDE0(u8 *p);
extern u16 func_021BEDE4(u8 *);
extern u16 func_021BEDE8(u8 *);
extern u32 func_02024158(const u8 *p);
extern void func_021BB00C(void *p, void *q);
extern void func_021BAFE4(u32 p);
void func_021BF758(u8 *p,u32 a,int b);
u32 func_021BF784(u8 *p);
int func_021BF7A0(u8 *p);
unsigned func_021BF7AC(u8 *p);
unsigned func_021BF7B8(u8 *p);
u32 func_021BF7C4(u8 *p);
u32 func_021BF7D0(u8 *p);
void func_021BF7D4(u8 *p, void *q);
void func_021BF7E0(u8 *p);
void func_021BF7EC(const u8 *p,u16 *a,u16 *b);

void func_021BF758(u8 *p,u32 a,int b) {
    if(p[0x69]==0) func_021B99A4(((struct Obj08009 *)p)->f18,((struct Obj08009 *)p)->f4C,a,b);
    else func_021BB1CC(*(u8 * *)&((struct Obj08009 *)p)->f1C,a,b);
}

u32 func_021BF784(u8 *p) {
    if(((struct Obj22392 *)p)->f60!=0) return -1;
    return func_021BEDC4(p+0x54);
}

/*
 * Unblocked by matching func_021BEDE0 in ov110 (pkt_ov110_021BEDE0).
 */
int func_021BF7A0(u8 *p) { return func_021BEDE0(p + 0x54); }

unsigned func_021BF7AC(u8 *p) { return func_021BEDE4(p+0x54); }

/*
 * body: tail-forwards p+0x54 to EDE8, whose complete four-byte body is
 *   ldrh r0,[r0,#2]; bx lr. Widening that unsigned return preserves every bit.
 */
unsigned func_021BF7B8(u8 *p) { return func_021BEDE8(p+0x54); }

/*
 * Byte-correct but witness-blocked (MATCH).
 * +0008 ABS32 func_02024158          -> unresolved: 02024158 (arm, from name) has no witness outside 021BF7C4..021BF7D0
 */
u32 func_021BF7C4(u8 *p) { return func_02024158((const u8 *)(((struct Obj22393 *)p)->f0)); }


u32 func_021BF7D0(u8 *p) { return ((struct Obj22394 *)p)->f7C; }

void func_021BF7D4(u8 *p, void *q) { func_021BB00C(((struct Obj22395 *)p)->f1C, q); }

void func_021BF7E0(u8 *p) { func_021BAFE4((u32)(*(u8 * *)&((struct Obj22396 *)p)->f1C)); }

void func_021BF7EC(const u8 *p,u16 *a,u16 *b) {
    *a=*(const u16 *)&((struct Obj13799 *)p)->f54;
    *b=*(const u16 *)&((struct Obj13799 *)p)->f56;
}
