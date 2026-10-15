/*
 * function: ZKNSEARCH_MAIN_PlaceColumnActors2
 * address: 0x021BF89C
 * packet: pkt_ov210_021BF89C
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FRAME_LIST_GetScrollPos 0x021B93B8 thumb
 *   ZKNSEARCH_MAIN_SetActorVisible 0x021BEDF0 thumb
 *   ZKNSEARCH_MAIN_GetListIndexB 0x021BCEF0 thumb
 *   ZKNSEARCH_MAIN_SetActorSurfacePos 0x021BEE38 thumb
 */
#include "../include/Obj04619.h"
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
extern int FRAME_LIST_GetScrollPos(void *);
extern void ZKNSEARCH_MAIN_SetActorVisible(int p, int i, int v);
extern u32 ZKNSEARCH_MAIN_GetListIndexB(u32 a, u32 b);
extern void ZKNSEARCH_MAIN_SetActorSurfacePos(char *p, int idx, int a, short b, unsigned short c);

void ZKNSEARCH_MAIN_PlaceColumnActors2(char *p, u8 a, u8 b)
{
    u8 cur = (u8)FRAME_LIST_GetScrollPos(((struct Obj04619 *)p)->f1E0);
    u8 d;
    int y;

    ZKNSEARCH_MAIN_SetActorVisible((int)p, 9, 0);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 0xA, 0);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 0xB, 0);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 0xC, 0);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 0xD, 0);
    ZKNSEARCH_MAIN_SetActorVisible((int)p, 0xE, 0);
    if (a != 0xFF) {
        a = (u8)ZKNSEARCH_MAIN_GetListIndexB((u32)p, a);
        d = (u8)(a - cur < 0 ? -(a - cur) : a - cur);
        if (a < cur) {
            if (d <= 8) {
                ZKNSEARCH_MAIN_SetActorVisible((int)p, 0xB, 1);
                y = (8 - d) * 0x18 + 0xC;
                ZKNSEARCH_MAIN_SetActorSurfacePos(p, 0xB, 0x8C, (s16)y, 1);
                ZKNSEARCH_MAIN_SetActorVisible((int)p, 0xD, 1);
                ZKNSEARCH_MAIN_SetActorSurfacePos(p, 0xD, 0x8C, (s16)y, 1);
            }
        } else if (d <= 7) {
            ZKNSEARCH_MAIN_SetActorVisible((int)p, 9, 1);
            ZKNSEARCH_MAIN_SetActorSurfacePos(p, 9, 0x8C, (s16)(d * 0x18 + 0xC), 0);
        }
    }
    if (b != 0xFF) {
        b = (u8)ZKNSEARCH_MAIN_GetListIndexB((u32)p, b);
        d = (u8)(b - cur < 0 ? -(b - cur) : b - cur);
        if (b < cur) {
            if (d <= 8) {
                ZKNSEARCH_MAIN_SetActorVisible((int)p, 0xC, 1);
                y = (8 - d) * 0x18 + 0xC;
                ZKNSEARCH_MAIN_SetActorSurfacePos(p, 0xC, 0x8C, (s16)y, 1);
                ZKNSEARCH_MAIN_SetActorVisible((int)p, 0xE, 1);
                ZKNSEARCH_MAIN_SetActorSurfacePos(p, 0xE, 0x8C, (s16)y, 1);
            }
        } else if (d <= 7) {
            ZKNSEARCH_MAIN_SetActorVisible((int)p, 0xA, 1);
            ZKNSEARCH_MAIN_SetActorSurfacePos(p, 0xA, 0x8C, (s16)(d * 0x18 + 0xC), 0);
        }
    }
}
