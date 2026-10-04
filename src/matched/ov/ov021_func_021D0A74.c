/*
 * function: func_021D0A74
 * address:  0x021D0A74
 * packet:   pkt_ov021_021D0A74
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0201A954  0x0201A954  thumb
 *
 * The 0x124 store is written in each arm of the mode test (cross-jumped
 * into one tail) and the 0x12C store after it: that puts the two stores in
 * different blocks when constants are derived, so the second offset is
 * rematerialised (`movs #0x4b; lsls`) instead of `adds r0,#8`.
 * Extent runs into func_021D0AB8 (filed separately).
 */

typedef unsigned int u32;

typedef signed int     s32;
struct Party;
void func_0201A954(struct Party *p, s32 capacity);

void func_021D0A74(int *p, u32 mode)
{
    if (p == 0) {
        return;
    }
    if (mode <= 1) {
        int y;
        if (mode == 0) {
            y = 0;
            p[0x49] = 3;
        } else {
            y = 1;
            p[0x49] = 4;
        }
        p[0x4B] = y;
    } else {
        p[0x4B] = 0;
        p[0x49] = 3;
    }
    func_0201A954((struct Party *)p[0x4A], p[0x49]);
}
