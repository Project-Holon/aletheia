/*
 * function: func_020637BC
 * address:  0x020637BC
 * packet:   pkt_020637BC
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Slot-occupied test of the func_0206380C accessor family: the word at
 * p[i] is not the sentinel -1.  The register-held sentinel tell
 * (docs/FRONTEND-PINS.md): the image materialises `mvn r0, #0` at
 * 0x020637C0 and compares `cmp r1, r0` at 0x020637C4; every dsi 1.x front
 * end folds the constant to `cmn r0, #1` (20 bytes, 12 out, ten spellings
 * measured by earlier lanes).  Under ../2.0/sp2 (also sp2p2, 2.0 base and
 * ../1.2/sp4) the same C is 24 bytes, 0 mismatches.
 */

typedef unsigned int u32;

int func_020637BC(const u32 *p, u32 i)
{
    return p[i] != 0xffffffff;
}
