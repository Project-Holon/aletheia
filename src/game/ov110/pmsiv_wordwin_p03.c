/*
 * file:     pmsiv_wordwin_p03.c
 * unit:     yes
 * function: func_021BF7FC, func_021BF808, func_021BF814, func_021BF824, func_021BF82C
 * address:  0x021BF7FC
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
 *   func_021BB1C0  0x021BB1C0  thumb  ov110
 *   func_021BAFDC  0x021BAFDC  thumb  ov110
 *   func_021BB1CC 0x021BB1CC thumb ov110
 *   func_021BF680  0x021BF680  thumb  ov110
 */
#include "../../matched/include/Obj22399.h"
#include "../../matched/include/Obj22400.h"
#include "../../matched/include/Obj22401.h"
#include "../../matched/include/Obj00012.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef unsigned int u32;

typedef int s32;

extern u8 func_021BB1C0(u8 *p);
extern u8 func_021BAFDC(u8 *p);
extern int func_021BB1CC(u8 *p, u8 i, int c);
extern int func_021BF680(u8 *p);
u8 func_021BF7FC(u8 *p);
int func_021BF808(u8 *p);
void func_021BF814(u8 *p,u32 a,int b);
int func_021BF824(u8 *a0);
void func_021BF82C(u8 *p);

u8 func_021BF7FC(u8 *p) { return func_021BB1C0((u8 *)(((struct Obj22399 *)p)->f1C)); }

/*
 * Unblocked by matching func_021BAFDC in ov110 (pkt_ov110_021BAFDC).
 */
int func_021BF808(u8 *p) { return func_021BAFDC((u8 *)(((struct Obj22400 *)p)->f1C)); }

void func_021BF814(u8 *p,u32 a,int b) { func_021BB1CC(*(u8 * *)&((struct Obj22401 *)p)->f1C,a,b); }

int func_021BF824(u8 *a0) { return func_021BF680(a0); }

void func_021BF82C(u8 *p) {
    ((struct Obj00012 *)p)->f4C=0;
    ((struct Obj00012 *)p)->f4E=255;
    ((struct Obj00012 *)p)->f50=253;
}
