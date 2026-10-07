/*
 * file:     unit_021D832C_p01.c
 * unit:     yes
 * function: func_021D8358, func_021D8394
 * address:  0x021D8358
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef enum { ZERO=0 } Bits;

struct B { u32 kind:4; u32 sub:3; u32 val:3; u32 flag:1; u32 rest:21; };

void func_021D8358(u32 *p,u32 id,u32 sub,u32 val);
void func_021D8394(struct B *p,u32 sub,u32 val);

void func_021D8358(u32 *p,u32 id,u32 sub,u32 val) { Bits t=ZERO; t &=~15; t|=2; t &=~0x7fff80; t|=(u16)id<<7; t &=~0x70; t|=(sub&7)<<4; t &=~0x7f800000; t|=(val&255)<<23; *p=t; }

 void func_021D8394(struct B *p,u32 sub,u32 val) { struct B t={0}; t.kind=3; t.sub=sub; t.val=val; t.flag=0; *p=t; }
