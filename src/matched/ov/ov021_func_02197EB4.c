/*
 * function: FLDMMDL_ACMD_RunCmds
 * address:  0x02197EB4
 * packet:   pkt_ov021_02197EB4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetAcmdCode  0x0216D7C4  thumb  ov010
 *   FLDMMDL_GetAcmdSeq  0x0216D7D4  thumb  ov010
 *   FLDMMDL_ACMD_RunCmdStep  0x02197F20  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern u16 FLDMMDL_GetAcmdCode(u8 *p);
extern u16 FLDMMDL_GetAcmdSeq(u8 *p);
extern int FLDMMDL_ACMD_RunCmdStep(u32, u32, u32);

void FLDMMDL_ACMD_RunCmds(u32 a)
{
    u32 r;

    do {
        r = FLDMMDL_GetAcmdCode((u8 *)a);
        if (r == 0xFF) {
            return;
        }
    } while (FLDMMDL_ACMD_RunCmdStep(a, r, FLDMMDL_GetAcmdSeq((u8 *)a)) != 0);
}
