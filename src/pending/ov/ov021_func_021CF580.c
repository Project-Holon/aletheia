/*
 * function: func_021CF580
 * address:  0x021CF580
 * packet:   pkt_ov021_021CF580
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH*
 *
 * Blocked: abs_id_4b and abs_id_4d (pool ABS32 words 0x4B, 0x4D) have no
 * witness outside the range (evidence class: none / literal only).  A plain
 * constant would be a movs, so these are symbol relocations.
 *
 * symbols:
 *   func_021CF564  0x021CF564  thumb  ov021
 *   abs_id_4b      0x0000004B  data
 *   abs_id_4d      0x0000004D  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_021CF564(void *r, u32 id);
extern char abs_id_4b[];
extern char abs_id_4d[];

void func_021CF580(void *r)
{
    func_021CF564(r, (u32)abs_id_4b);
    func_021CF564(r, (u32)abs_id_4d);
}
