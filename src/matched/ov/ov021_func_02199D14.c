/*
 * function: FLDMMDL_ACMD_DashLeft2F
 * address:  0x02199D14
 * packet:   pkt_ov021_02199D14
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
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { u16 a; u16 b; u32 c; u32 d; } S12;
extern S12 *FLDMMDL_InitMoveCmdWork(u32, u32);
extern void FLDMMDL_MOVE_UpdateGridPosDir(int a, int b);
extern void FLDMMDL_SetDrawStatus(void *p, u16 v);
extern void FLDMMDL_IncAcmdSeq(u32);

int FLDMMDL_ACMD_DashLeft2F(u32 a)
{
    S12 *p = FLDMMDL_InitMoveCmdWork(a, 12);
    p->a = 12;
    p->b = 2;
    p->c = 2;
    p->d = 0x8000;
    FLDMMDL_MOVE_UpdateGridPosDir((u32)a, (u16)p->c);
    FLDMMDL_SetDrawStatus((void *)a, p->a);
    FLDMMDL_IncAcmdSeq(a);
    return 1;
}
