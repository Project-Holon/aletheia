/*
 * function: ghttpSetRootCAList
 * address:  0x021C2344
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   ghiEncyptorSetRootCAList  0x021C1184  arm  ov114
 *
 *
 * ov114 tail-call thunk via `ldr ip,pool; bx ip`.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void ghiEncyptorSetRootCAList(void);

void ghttpSetRootCAList(void)
{
    ghiEncyptorSetRootCAList();
}
