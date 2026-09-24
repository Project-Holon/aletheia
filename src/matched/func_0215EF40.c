/*
 * function: func_0215EF40
 * address:  0x0215EF40
 * packet:   pkt_0215EF40
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stamp the fixed id on the record, then hand three of the record's own
 * fields to the overlay pair call.
 *
 * symbols:
 *   func_02165534   0x02165534  thumb  ov010
 *   func_021D1C24   0x021D1C24  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02165534(int);
extern void func_021D1C24(int, int, unsigned);

void func_0215EF40(void *a0, void *a1)
{
    func_02165534(0x1C0);
    func_021D1C24(*(int *)((char *)a1 + 8), *(int *)((char *)a1 + 0x10),
                 (u8)*(u16 *)a0);
}

