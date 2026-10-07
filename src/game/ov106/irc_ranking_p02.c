/*
 * file:     irc_ranking_p02.c
 * unit:     yes
 * function: func_021B78AC, func_021B78B8, func_021B78CC, func_021B78D0
 * address:  0x021B78AC
 * region:   ov106
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj22257.h"
#include "../../matched/include/Obj13757.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef unsigned int u32;

typedef int s32;

typedef struct C C;

struct C { void (*callback)(C *, int *, int); int flag, value, arg; };

extern void func_02082BCC(void *, int, int);
void func_021B78AC(void *p);
void func_021B78B8(C *p);
u32 func_021B78CC(u8 *p);
void func_021B78D0(u8 *p, u32 v);

void func_021B78AC(void *p) { func_02082BCC(p, 0, 0x10); }

void func_021B78B8(C *p) { if (p->flag == 0) p->callback(p, &p->value, p->arg); }


u32 func_021B78CC(u8 *p) { return ((struct Obj22257 *)p)->f4; }


void func_021B78D0(u8 *p, u32 v) { ((struct Obj13757 *)p)->f0 = v; ((struct Obj13757 *)p)->f8 = 0; }
