/*
 * file:     comm_player_p20.c
 * unit:     yes
 * function: func_021693B4, func_021693BC, func_021693C4, func_021693CC, func_021693D4, func_0216940C
 * address:  0x021693B4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj19037.h"
#include "../../matched/include/Obj19038.h"
#include "../../matched/include/Obj19039.h"
#include "../../matched/include/Obj19040.h"
#include "../../matched/include/Obj05901.h"
#include "../../matched/include/Obj12385.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct V3 {
    u32 a, b, c;
} V3;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
u32 f0;
u32 f4;
u32 f8;
u32 fc;
u16 f10;
u16 pad;
} Entry;

typedef struct {
u8 pad0[0x9c];
Entry *table;
u32 f_a0;
u16 count;
} Obj;

void func_021693B4(char *p, int v);
void func_021693BC(char *p);
void func_021693C4(char *p, int v);
void func_021693CC(char *p);
void func_021693D4(u8 *base, u8 *src, u32 idx);
void func_0216940C(Obj *o, u32 i);


/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from ov021 func_0218CEE4.
 */
void func_021693B4(char *p, int v)
{
    ((struct Obj19037 *)p)->f94 = v;
}


/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from ov021 func_0218D05C.
 */
void func_021693BC(char *p)
{
    ((struct Obj19038 *)p)->f94 = 0;
}


void func_021693C4(char *p, int v)
{
    ((struct Obj19039 *)p)->f98 = v;
}


void func_021693CC(char *p)
{
    ((struct Obj19040 *)p)->f98 = 0;
}


/*
 * Unlabelled leaf (blocker of ov021 func_0218C4A0).  Stores a 0x14-byte
 * record (word, 12 bytes, halfword) into entry idx of the table at +0x9C.
 */
void func_021693D4(u8 *base, u8 *src, u32 idx)
{
    *(u32 *)(*(u8 * *)&((struct Obj05901 *)base)->f9C + idx * 0x14) = ((struct Obj12385 *)src)->f0;
    *(V3 *)(*(u8 * *)&((struct Obj05901 *)base)->f9C + idx * 0x14 + 4) = *(V3 *)(src + 4);
    *(u16 *)(*(u8 * *)&((struct Obj05901 *)base)->f9C + idx * 0x14 + 0x10) = ((struct Obj12385 *)src)->f10;
}


/*
 * Reset the 0x14-byte entry `i` of the table at +0x9c.
 *
 * Addresses are Black-image addresses.
 */
void func_0216940C(Obj *o, u32 i)
{
Entry *e;
if (i == 0xffffffff)
return;
if (i >= o->count)
return;
o->table[i].f0 = 0xffffffff;
e = &o->table[i];
e->f4 = 0;
e->f8 = 0;
e->fc = 0;
*(u16 *)((u8 *)&o->table[i] + 0x10) = 0;
}
