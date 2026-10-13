/*
 * function: FLDMMDL_ACMD_HopInit
 * address:  0x02199888
 * packet:   pkt_ov021_02199888
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_InitMoveCmdWork  0x0216D6BC  thumb  ov010
 *   _s32_div_f     0x0209C0A4  arm
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
#include "../include/Obj04222.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
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

void FLDMMDL_ACMD_HopInit(u32 a, int b, u32 c, u32 d, u8 e, u8 f, u8 g, u8 h, u8 i)
{
    u8 *q;
    int dir;

    dir = 1;
    q = FLDMMDL_InitMoveCmdWork(a, 16, c);
    q[0] = e;
    ((struct Obj04222 *)q)->f4 = b;
    q[2] = g;
    q[1] = h;
    q[3] = i;
    ((struct Obj04222 *)q)->fE = 0x1000 / q[0];
    FLDMMDL_SetDirDispCheckPause(a, (u16)c);
    FLDMMDL_SetDirMove(a, (u16)d);
    FLDMMDL_SetDrawStatus((void *)a, f);
    FLDMMDL_OnMoveBitMoveStart((void *)a);
    FLDMMDL_SetGridOldX(a, FLDMMDL_GetGridNowX((void *)a));
    FLDMMDL_SetGridOldY(a, FLDMMDL_GetGridNowY((void *)a));
    FLDMMDL_SetGridOldZ(a, FLDMMDL_GetGridNowZ((void *)a));
    if (b != 0) {
        switch (g) {
        case 0:
            if (b < 0)
                dir = -1;
            FLDMMDL_AddGridNowX((char *)a, dir);
            break;
        case 1:
            if (b < 0)
                dir = -1;
            FLDMMDL_AddGridNowY((char *)a, dir * 2);
            break;
        case 2:
            if (b < 0)
                dir = -1;
            FLDMMDL_AddGridNowZ((char *)a, dir);
            break;
        }
    }
    FLDMMDL_IncAcmdSeq(a);
}
