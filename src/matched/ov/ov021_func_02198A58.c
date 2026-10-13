/*
 * function: FLDMMDL_ACMD_FallInit
 * address:  0x02198A58
 * packet:   pkt_ov021_02198A58
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_InitMoveCmdWork  0x0216D6BC  thumb  ov010
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern u32 *FLDMMDL_InitMoveCmdWork(u32, u32);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void FLDMMDL_SetDrawStatus(void *p, u16 v);
extern void FLDMMDL_IncAcmdSeq(u8 *p);

int FLDMMDL_ACMD_FallInit(u32 a)
{
    u32 *p;

    p = FLDMMDL_InitMoveCmdWork(a, 8);
    p[0] = 0x140000;
    p[1] = 0xFFFF0000;
    GFL_USE_PlaySeDefaultVolume(0x676);
    FLDMMDL_SetDrawStatus((void *)a, 0);
    FLDMMDL_IncAcmdSeq((u8 *)a);
    return 1;
}
