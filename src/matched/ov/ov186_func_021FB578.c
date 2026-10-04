/*
 * function: func_021FB578
 * address:  0x021FB578
 * packet:   pkt_021FB578
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204B800  0x0204B800  arm
 *   func_020259C4  0x020259C4  thumb
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Node;
extern void func_0204B800(struct Node *node, u32 val);
extern void func_020259C4(u8 *g, u32 a);

void func_021FB578(int *p, unsigned char b)
{
    func_0204B800((struct Node *)p[0], b);
    func_020259C4((u8 *)p[1], (unsigned char)(b - 1));
}
