/*
 * function: FLDMMDL_ACMD_CheckAnimePaused
 * address:  0x02197C9C
 * packet:   pkt_02197C9C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FLDMMDL_CheckMoveBitMovePause  0x0216DB10  thumb  ov010
 *   FLDMMDL_CheckMoveBitAcmd  0x0216DC4C  thumb  ov010
 *   FLDMMDL_CheckStatusBit  0x0216D55C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int FLDMMDL_CheckStatusBit(int a0, int a1);
extern int FLDMMDL_CheckMoveBitMovePause(void *a0);
extern int FLDMMDL_CheckMoveBitAcmd(void *a0);

int FLDMMDL_ACMD_CheckAnimePaused(u32 a)
{
if (FLDMMDL_CheckMoveBitMovePause((void *)a) != 0) {
    if (FLDMMDL_CheckMoveBitAcmd((void *)a) == 0) {
        return 1;
    }
}
if (FLDMMDL_CheckStatusBit(a, 16) != 0) {
    return 1;
}
return 0;
}

