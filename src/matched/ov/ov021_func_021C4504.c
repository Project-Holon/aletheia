/*
 * function: func_021C4504
 * address:  0x021C4504
 * packet:   pkt_ov021_021C4504
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Maps a species to its base form via the evolution table (species below
 * 0x289).
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02048F74(void *dst, u32 archive_id, u32 member, u32 mode, u32 *size_out);

u16 func_021C4504(u16 sp)
{
    u16 v;

    if (sp >= 0x289)
        return sp;
    func_02048F74(&v, 0x14, sp, 0, (u32 *)2);
    return v;
}
