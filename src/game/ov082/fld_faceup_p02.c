/*
 * file:     fld_faceup_p02.c
 * unit:     yes
 * function: func_021F5578, func_021F558C
 * address:  0x021F5578
 * region:   ov082
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02189A60 0x02189A60 thumb ov021
 *   func_021F5648 0x021F5648 thumb ov082
 */
#include "../../matched/include/Obj13225.h"

typedef unsigned char u8;

extern void **func_02189A60(u8 *p);
extern void func_021F5648(int p, void *w);
void func_021F5578(u8 *p);
void func_021F558C(u8 *p);

void func_021F5578(u8 *p) { void *w = *func_02189A60(p); func_021F5648((int)p, w); }

void func_021F558C(u8 *p) { u8 *w = *func_02189A60(p); ((struct Obj13225 *)w)->f1C=0; ((struct Obj13225 *)w)->f74=1; }
