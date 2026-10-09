/*
 * file:     unit_021D832C.c
 * unit:     yes
 * function: func_021D8340, func_021D8358, func_021D8394, func_021D83C4, func_021D83E0, func_021D83FC, func_021D8414
 * address:  0x021D8340
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

struct B_021D8340 { u32 kind:4; u32 sub:3; u32 id:16; u32 rest:9; };

typedef enum { ZERO=0 } Bits;

struct B_021D8358 { u32 kind:4; u32 sub:3; u32 val:3; u32 flag:1; u32 rest:21; };

struct B { u32 kind:4; u32 pad:6; u32 flag:1; u32 rest:21; };

u32 func_021D8340(struct B_021D8340 *p);
void func_021D8358(u32 *p,u32 id,u32 sub,u32 val);
void func_021D8394(struct B_021D8358 *p,u32 sub,u32 val);
void func_021D83C4(u32 *p);
int func_021D83E0(struct B *p);
void func_021D83FC(u32 *p,u32 sub);
void func_021D8414(u32 *p);
void func_021D8424(u32 *p);


 u32 func_021D8340(struct B_021D8340 *p) { if(p->kind==1) return (u16)p->id; return 0; }



void func_021D8358(u32 *p,u32 id,u32 sub,u32 val) { Bits t=ZERO; t &=~15; t|=2; t &=~0x7fff80; t|=(u16)id<<7; t &=~0x70; t|=(sub&7)<<4; t &=~0x7f800000; t|=(val&255)<<23; *p=t; }



 void func_021D8394(struct B_021D8358 *p,u32 sub,u32 val) { struct B_021D8358 t={0}; t.kind=3; t.sub=sub; t.val=val; t.flag=0; *p=t; }


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
