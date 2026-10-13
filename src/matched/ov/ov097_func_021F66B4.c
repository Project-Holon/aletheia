/*
 * function: VS_MULTI_LIST_StateSlideIn
 * address: 0x021F66B4
 * packet: pkt_ov097_021F66B4
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: byte-pointer object base keeps field addresses inline instead
 * of the integer-base spelling's extra loop-invariant address register.
 * symbols:
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   BGWINFRM_StartMove 0x0202CD64 thumb
 *   BGWINFRM_IsMoving 0x0202CE40 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   VS_MULTI_LIST_EnterWaitState 0x021F681C thumb ov097
 *   VS_MULTI_LIST_MoveSlotActors 0x021F7308 thumb ov097
 *   VS_MULTI_LIST_StartWipeOut 0x021F67F0 thumb ov097
 */
#include "../include/Obj00111.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
struct WinMgr;
struct PrintSys;
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern void BGWINFRM_StartMove(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
extern u32 BGWINFRM_IsMoving(struct WinMgr *mgr, u32 idx);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern int VS_MULTI_LIST_EnterWaitState(u8 *, int, int);
extern void VS_MULTI_LIST_MoveSlotActors(int a, unsigned b, int c);
extern int VS_MULTI_LIST_StartWipeOut(u8 *, int);
int VS_MULTI_LIST_StateSlideIn(u8 *p)
{
    u32 i;
    switch (((struct Obj00111 *)p)->f110) {
    case 0:
        if (PRINTSYS_QUE_IsFinished(((struct Obj00111 *)p)->f1C) == 0) break;
        if (*(int *)(*(int *)&((struct Obj00111 *)p)->f0 + 8) == 0) {
            for (i = 0; i < 3; i++) {
                BGWINFRM_StartMove(*(struct WinMgr * *)&((struct Obj00111 *)p)->f8, i + 3, -1, 0, 16);
                BGWINFRM_StartMove(*(struct WinMgr * *)&((struct Obj00111 *)p)->f8, i + 9, -1, 0, 16);
            }
        } else {
            for (i = 0; i < 3; i++) {
                BGWINFRM_StartMove(*(struct WinMgr * *)&((struct Obj00111 *)p)->f8, i, 1, 0, 16);
                BGWINFRM_StartMove(*(struct WinMgr * *)&((struct Obj00111 *)p)->f8, i + 6, 1, 0, 16);
            }
        }
        GFL_USE_PlaySeDefaultVolume(0x642);
        (((struct Obj00111 *)p)->f110)++;
    case 1:
        if (*(int *)(*(int *)&((struct Obj00111 *)p)->f0 + 8) == 0) {
            if (BGWINFRM_IsMoving(*(struct WinMgr * *)&((struct Obj00111 *)p)->f8, 3) == 0) {
                (((struct Obj00111 *)p)->f110)++;
                GFL_USE_PlaySeDefaultVolume(0x57a);
                return VS_MULTI_LIST_EnterWaitState(p, 0x80, 4);
            }
            VS_MULTI_LIST_MoveSlotActors((int)p, 3, -8);
        } else {
            if (BGWINFRM_IsMoving(*(struct WinMgr * *)&((struct Obj00111 *)p)->f8, 0) == 0) {
                (((struct Obj00111 *)p)->f110)++;
                GFL_USE_PlaySeDefaultVolume(0x57a);
                return VS_MULTI_LIST_EnterWaitState(p, 0x80, 4);
            }
            VS_MULTI_LIST_MoveSlotActors((int)p, 0, 8);
        }
        break;
    case 2:
        return VS_MULTI_LIST_StartWipeOut(p, 1);
    }
    return 4;
}
