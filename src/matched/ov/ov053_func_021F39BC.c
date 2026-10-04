/*
 * function: func_021F39BC
 * address: 0x021F39BC
 * packet: pkt_ov053_021F39BC
 * region: ov053
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02048F74 0x02048F74 arm
 */

typedef unsigned int   u32;
extern void func_02048F74(void *dst, u32 archive_id, u32 member, u32 mode, u32 *size_out);

void func_021F39BC(char *a)
{
    func_02048F74(a + 0x58, 0x94, 0, 0, (u32 *)12);
}
