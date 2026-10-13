/*
 * function: FIELD_G3D_MAP_ClearPlacement
 * address:  0x0216940C
 * packet:   pkt_0216940C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reset the 0x14-byte entry `i` of the table at +0x9c.
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
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

void FIELD_G3D_MAP_ClearPlacement(Obj *o, u32 i)
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
