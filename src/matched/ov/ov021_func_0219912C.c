/*
 * function: FLDMMDL_ACMD_StepInit
 * address:  0x0219912C
 * packet:   pkt_ov021_0219912C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_InitMoveCmdWork  0x0216D6BC  thumb  ov010
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FLDMMDL_SetDirMove  0x0216D600  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_OnMoveBitMoveStart  0x0216DA70  thumb  ov010
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_SetGridOldX  0x0216D80C  thumb  ov010
 *   FLDMMDL_GetGridNowY  0x0216D854  thumb  ov010
 *   FLDMMDL_SetGridOldY  0x0216D818  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_SetGridOldZ  0x0216D824  thumb  ov010
 *   FLDMMDL_AddGridNowX  0x0216D848  thumb  ov010
 *   FLDMMDL_AddGridNowY  0x0216D860  thumb  ov010
 *   FLDMMDL_AddGridNowZ  0x0216D87C  thumb  ov010
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { int x, y, z; } Vec;
extern void *FLDMMDL_InitMoveCmdWork(int a0, int a1, int a2);
extern void FLDMMDL_SetDirDispCheckPause(int a0, int a1);
extern int FLDMMDL_SetDirMove(int a0, u16 a1);
extern void FLDMMDL_SetDrawStatus(void *p, u16 v);
extern void FLDMMDL_OnMoveBitMoveStart(void *a0);
extern int FLDMMDL_GetGridNowX(void *p);
extern u32 FLDMMDL_SetGridOldX(u32, u32);
extern int FLDMMDL_GetGridNowY(void *p);
extern u32 FLDMMDL_SetGridOldY(u32, u32);
extern int FLDMMDL_GetGridNowZ(void *p);
extern u32 FLDMMDL_SetGridOldZ(u32, u32);
extern void FLDMMDL_AddGridNowX(char *p, short v);
extern void FLDMMDL_AddGridNowY(char *p, short v);
extern void FLDMMDL_AddGridNowZ(char *p, short v);
extern u32 FLDMMDL_IncAcmdSeq(u32);

void FLDMMDL_ACMD_StepInit(u32 a, Vec *b, u32 c, u32 d, u32 e, u8 f)
{
    u32 *q;

    q = FLDMMDL_InitMoveCmdWork(a, 16, c);
    q[0] = e;
    *(Vec *)(q + 1) = *b;
    FLDMMDL_SetDirDispCheckPause(a, (u16)c);
    FLDMMDL_SetDirMove(a, (u16)d);
    FLDMMDL_SetDrawStatus((void *)a, f);
    FLDMMDL_OnMoveBitMoveStart((void *)a);
    FLDMMDL_SetGridOldX(a, FLDMMDL_GetGridNowX((void *)a));
    FLDMMDL_SetGridOldY(a, FLDMMDL_GetGridNowY((void *)a));
    FLDMMDL_SetGridOldZ(a, FLDMMDL_GetGridNowZ((void *)a));
    if (b->x < 0) {
        FLDMMDL_AddGridNowX((char *)a, -1);
    } else if (b->x > 0) {
        FLDMMDL_AddGridNowX((char *)a, 1);
    }
    if (b->y < 0) {
        FLDMMDL_AddGridNowY((char *)a, -1);
    } else if (b->y > 0) {
        FLDMMDL_AddGridNowY((char *)a, 1);
    }
    if (b->z < 0) {
        FLDMMDL_AddGridNowZ((char *)a, -1);
    } else if (b->z > 0) {
        FLDMMDL_AddGridNowZ((char *)a, 1);
    }
    FLDMMDL_IncAcmdSeq(a);
}
