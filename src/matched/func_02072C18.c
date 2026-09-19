/*
 * function: func_02072C18
 * address:  0x02072C18
 * packet:   pkt_02072A44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct S { u32 f0; u32 f4; u32 f8; };
extern void func_02089638(u32, u32, u32);

void func_02072C18(struct S *s, u32 v)
{
    if (s->f8 == 0) return;
    func_02089638(1 << s->f0, v, 0);
}
