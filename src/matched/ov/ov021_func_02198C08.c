/*
 * function: FLDMMDL_ACMD_WalkTableInit
 * address:  0x02198C08
 * packet:   pkt_ov021_02198C08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_InitMoveCmdWork  0x0216D6BC  thumb  ov010
 *   FLDMMDL_MOVE_UpdateGridPosDir  0x02163E7C  thumb  ov010
 *   FLDMMDL_SetDirAll  0x0216D60C  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *FLDMMDL_InitMoveCmdWork(int a0, int a1, int a2);
extern void FLDMMDL_MOVE_UpdateGridPosDir(int a, int b);
extern int FLDMMDL_SetDirAll(int a0, int a1);
extern u32 FLDMMDL_SetDrawStatus(u32, u32);
extern void *FLDMMDL_SetMoveBit(void *p, u32 v);
extern u32 FLDMMDL_IncAcmdSeq(u32);

void FLDMMDL_ACMD_WalkTableInit(u32 a, u32 b, u32 c, u32 d)
{
    u16 *p;

    p = FLDMMDL_InitMoveCmdWork(a, 8, c);
    p[0] = b;
    p[1] = d;
    p[2] = c;
    FLDMMDL_MOVE_UpdateGridPosDir(a, ((b << 16) >> 16));
    FLDMMDL_SetDirAll(a, (u16)b);
    FLDMMDL_SetDrawStatus(a, d);
    FLDMMDL_SetMoveBit((void *)a, 32);
    FLDMMDL_IncAcmdSeq(a);
}
