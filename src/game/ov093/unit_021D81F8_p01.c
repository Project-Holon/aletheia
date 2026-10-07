/*
 * file:     unit_021D81F8_p01.c
 * unit:     yes
 * function: func_021D8230, func_021D8244
 * address:  0x021D8230
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj13452.h"

typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

struct B { u32 count; u8 val[4]; };

void func_021D8230(u8 *p);
void func_021D8244(struct B *p, int n);

void func_021D8230(u8 *p) { u32 i; for(i=0;i<4;i++) p[4+i]=4; ((struct Obj13452 *)p)->f0=0; }

void func_021D8244(struct B *p, int n) { u32 i; for(i=0;i<4;i++) { if(p->val[i]==n) return; if(p->val[i]==4) { p->val[i]=n; ++p->count; return; } } }
