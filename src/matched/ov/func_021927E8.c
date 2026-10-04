/*
 * function: func_021927E8
 * address:  0x021927E8
 * packet:   pkt_021927E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clears the leading byte and tail calls on the word at +4.
 *
 * symbols:
 *   func_020437AC  0x020437AC  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj020437AC;
extern void func_020437AC(struct Obj020437AC *p);

void func_021927E8(u32 *p)
{
    *(u8 *)p = 0;
    func_020437AC((struct Obj020437AC *)p[1]);
}
