/*
 * function: FLDMMDL_ACMD_AnimeDash6FStart
 * address:  0x02198E60
 * packet:   pkt_02198E60
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 
 * Promoted from src/pending/: the blocker this file named is filed.
 * FLDMMDL_IncAcmdSeq (0x0216D7CC) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FLDMMDL_InitMoveCmdWork  0x0216D6BC  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void FLDMMDL_SetDrawStatus(void *p, u16 v);
extern void *FLDMMDL_InitMoveCmdWork(int a0, int a1, int a2);
extern u32 FLDMMDL_IncAcmdSeq(u32);

int FLDMMDL_ACMD_AnimeDash6FStart(u32 a, u32 b, u32 c, u32 d)
{
FLDMMDL_InitMoveCmdWork(a, 4, c);
FLDMMDL_SetDrawStatus((void *)a, 11);
FLDMMDL_IncAcmdSeq(a);
return 0;
}

