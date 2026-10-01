/*
 * function: func_021D04A4
 * address:  0x021D04A4
 * packet:   pkt_ov021_021D04A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Blocked: d_021DB934 (u32 table indexed by e->fC) is contested: another
 * overlay in the window starts an object at 0x021DB934 and this function has
 * no overlay_id site, so the ABS32 word stays wildcarded.
 *
 * symbols:
 *   d_021DB934     0x021DB934  data  ov021  a4
 *   func_020061E4  0x020061E4  thumb
 *   func_021AC1E0  0x021AC1E0  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *func_021AC1E0(void *a);
extern void func_020061E4(int);
extern int d_021DB934[];

void func_021D04A4(void *a)
{
    u8 *e;

    if (a != 0) {
        e = func_021AC1E0(a);
        *(u16 *)(e + 0x1a) = 1;
        func_020061E4(d_021DB934[*(u32 *)(e + 0xc)]);
    }
}
