/*
 * function: func_021DBAC0
 * address:  0x021DBAC0
 * packet:   pkt_021DBAC0
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DBF0C  0x021DBF0C  thumb
 *   func_020307B0  0x020307B0  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021DBF0C(void *);
extern void func_020307B0(void *);

void func_021DBAC0(u8 *p)
{
    func_021DBF0C(p);
    func_020307B0(p);
}
