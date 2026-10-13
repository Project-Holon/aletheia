/*
 * function: FLDMMDL_IsMovedPosObjCode
 * address:  0x0216E5FC
 * packet:   pkt_ov010_0216E5FC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * True for kind 0x6D and 0x2003..0x2005. The range test must be written
 * as `(u16)(id + 0xDFFD) <= 2`: `id >= 0x2003 && id <= 0x2005` keeps two
 * compares, `(u16)(id - 0x2003)` pools 0x2003 and subtracts.
 */

typedef unsigned short u16;

int FLDMMDL_IsMovedPosObjCode(u16 id)
{
    if (id == 0x6D || (u16)(id + 0xDFFD) <= 2)
        return 1;
    return 0;
}
