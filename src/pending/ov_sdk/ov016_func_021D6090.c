/*
 * function: DWCi_GXlInvisible
 * address:  0x021D6090
 * packet:   pkt_ov016_021D6090
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * symbols:
 *   (none)
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(graphics.o), symbol DWCi_GXlInvisible (name and
 * prototype from the vendor object DWARF). Callee of endScene2 (sceneoptmovconfi). No
 * relocations: both window registers are cast constants.
 *
 * blocker: DIFF, same allocator issue as DWCi_GXlVisible (0x021D603C): the two volatile
 * reads and the ~plane scratch land in a different register set under dsi/1.1p1 than under
 * the 4.0.0.1025 object stamp. Left as a documented near miss.
 */
typedef unsigned int u32;

void DWCi_GXlInvisible(int lcd, int plane)
{
    if (lcd == 1) {
        u32 a = *(volatile u32 *)0x04001000;
        u32 b = *(volatile u32 *)0x04001000;
        *(volatile u32 *)0x04001000 =
            (b & ~0x1f00u) | ((~plane & ((a & 0x1f00u) >> 8)) << 8);
    } else {
        u32 a = *(volatile u32 *)0x04000000;
        u32 b = *(volatile u32 *)0x04000000;
        *(volatile u32 *)0x04000000 =
            (b & ~0x1f00u) | ((~plane & ((a & 0x1f00u) >> 8)) << 8);
    }
}
