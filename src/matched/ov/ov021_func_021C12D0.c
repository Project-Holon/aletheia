/*
 * function: func_021C12D0
 * address:  0x021C12D0
 * packet:   pkt_ov021_021C12D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Frees the resource buffer, then releases the handle.
 */

typedef unsigned int   u32;
struct S02030EE8;
extern u32 func_02030EE8(struct S02030EE8 *p);
extern u32 func_020307B0(void *p);
struct Node;
extern void func_02030EAC(struct Node *n);

void func_021C12D0(void *h)
{
    func_020307B0((void *)func_02030EE8(h));
    func_02030EAC(h);
}
