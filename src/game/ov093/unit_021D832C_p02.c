/*
 * file:     unit_021D832C_p02.c
 * unit:     yes
 * function: func_021D83C4, func_021D83E0, func_021D83FC, func_021D8414
 * address:  0x021D83C4
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

struct B { u32 kind:4; u32 pad:6; u32 flag:1; u32 rest:21; };

void func_021D83C4(u32 *p);
int func_021D83E0(struct B *p);
void func_021D83FC(u32 *p,u32 sub);
void func_021D8414(u32 *p);
void func_021D8424(u32 *p);

void func_021D83C4(u32 *p) { Bits t=ZERO; t &=~15; t|=3; t &=~0x380; t|=0x400; *p=t; }

 int func_021D83E0(struct B *p) { if(p->kind==3 && p->flag==1) return 1; return 0; }

/*
 * follower: Existing pkt_ov093_021D8414 covers 021D8414 and 021D8424.
 */
void func_021D83FC(u32 *p,u32 sub) { Bits t=ZERO; t &=~15; t|=6; t &=~0x70; t|=(sub&7)<<4; *p=t; }

/*
 * follower: 0x021D8424 is a 14-byte read-modify-write and return leaf with two padding bytes.
 */
void func_021D8414(u32 *p)
{
    *p = (*p & ~15) | 4;
}

void func_021D8424(u32 *p)
{
    *p = (*p & ~15) | 5;
}
