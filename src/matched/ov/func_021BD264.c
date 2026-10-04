/*
 * function: func_021BD264
 * address:  0x021BD264
 * packet:   pkt_021BD264
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pattern-generated from the ov021 family.
 *
 * symbols:
 *   func_020437AC  0x020437AC  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
struct Obj020437AC;
extern void func_020437AC(struct Obj020437AC *p);

void func_021BD264(u8 *p)
{
    u32 v = *(u32 *)(p + 8);
    if (v != 0) {
        func_020437AC((struct Obj020437AC *)v);
        *(u32 *)(p + 8) = 0;
    }
}
