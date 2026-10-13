/*
 * function: FLDMMDL_ACMD_RunCmdStep
 * address:  0x02197F20
 * packet:   pkt_ov021_02197F20
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte-correct (2026-10-01).  Sole blocker: the ABS32 pool word for the
 * ov021 table is a data start that another overlay mapped over the same
 * window also starts an object at, so the symbols hint is contested.  No C
 * change needed to promote.
 *
 * 2026-10-01: the own-overlay data hint is dropped from symbols: so the
 *   own-window rule (code running in ov021 can only see ov021's bytes in its
 *   window) fixes the overlay; with the hint the tool refused it as contested.
 *
 * symbols:
 *   FLDMMDL_CheckStatusBit  0x0216D55C  thumb  ov010
 *   d_021D624C     0x021D624C  data  a4
 *   d_021D5F58     0x021D5F58  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern int FLDMMDL_CheckStatusBit(int a0, int a1);
extern int (**const d_021D624C[])(u32);
extern int (**const d_021D5F58[])(u32);

int FLDMMDL_ACMD_RunCmdStep(u32 a, u32 b, u32 c)
{
    if (FLDMMDL_CheckStatusBit(a, 0x2000) != 0) {
        return d_021D624C[b][c](a);
    }
    return d_021D5F58[b][c](a);
}
