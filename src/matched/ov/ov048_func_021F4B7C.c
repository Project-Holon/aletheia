/*
 * function: GIMMICK_OBJ_ELBOARD_UpdateLine
 * address:  0x021F4B7C
 * packet:   pkt_ov048_021F4B7C
 * region:   ov048
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0218768C  0x0218768C  thumb  ov020
 *   G3D_SYSTEM_IncObjectAnimeFrame  0x020478B8  arm
 *   GIMMICK_OBJ_ELBOARD_StopLine  0x021F4BF0  thumb  ov048
 *   GIMMICK_OBJ_ELBOARD_StartLine  0x021F4B54  thumb  ov048
 */
#include "../include/Obj01678.h"

extern void func_0218768C(char *p);
extern int G3D_SYSTEM_IncObjectAnimeFrame(void *a, int idx, int amount);
extern void GIMMICK_OBJ_ELBOARD_StopLine(int *a);
extern void GIMMICK_OBJ_ELBOARD_StartLine(int *a);

void GIMMICK_OBJ_ELBOARD_UpdateLine(int *a, int *b, int c)
{
    int t;

    if (b[1] == 1) {
        func_0218768C((char *)b[3]);
        G3D_SYSTEM_IncObjectAnimeFrame((void *)b[4], *(unsigned short *)&b[5], c);
        t = b[6] + c;
        b[6] = t;
        if (b[7] < t) {
            if (b[2] != 1) {
                ((int *)a[3])[(((struct Obj01678 *)b)->f0 + 1) % *((unsigned char *)a + 2)] = 1;
                b[2] = 1;
            }
        }
        if (b[8] < b[6]) {
            GIMMICK_OBJ_ELBOARD_StopLine(b);
            return;
        }
    } else {
        if (((int *)a[3])[((struct Obj01678 *)b)->f0] == 1) {
            GIMMICK_OBJ_ELBOARD_StartLine(b);
            ((int *)a[3])[((struct Obj01678 *)b)->f0] = 0;
        }
    }
}
