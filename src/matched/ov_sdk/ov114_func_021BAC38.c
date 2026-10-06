/*
 * function: func_021BAC38
 * address:  0x021BAC38
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BAA1C  0x021BAA1C  arm  ov114
 *
 *
 * Nodes a fresh record into the +0x30 list when the +0x04 field is free.
 */

typedef unsigned char u8;
typedef unsigned int u32;
struct Node;
extern int func_021BAA1C(struct Node **head, int b, int c, int d);

int func_021BAC38(u32 *p, int a, int b, int c)
{
    if (p[1] != 0)
        return 0;
    return func_021BAA1C((struct Node **)((char *)p + 0x30), a, b, c);
}
