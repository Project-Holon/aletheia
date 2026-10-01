/*
 * function: func_021D325C
 * address:  0x021D325C
 * packet:   pkt_ov021_021D325C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct St021D325C {
    u16 kind;
    u16 pad2;
    u32 a;
    u32 b;
    u32 c;
    u32 d;
} St021D325C;

void func_021D325C(St021D325C *p, u32 a, u32 b, u32 c, u32 d)
{
    p->kind = 2;
    p->a = a;
    p->b = b;
    p->c = c;
    p->d = d;
}
