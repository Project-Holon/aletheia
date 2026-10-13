/*
 * function: FIELD_CAMERA_SolveEyeMode
 * address:  0x0218E404
 * packet:   pkt_ov021_0218E404
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Mirror of FIELD_CAMERA_SolveTargetMode with the two halves swapped.
 *
 * symbols:
 *   FIELD_CAMERA_ApplyTargetArea  0x0218F1BC  thumb  ov021
 *   FIELD_CAMERA_ApplyEyeArea  0x0218F1DC  thumb  ov021
 *   FIELD_CAMERA_CalcOffsetPoint  0x0218E2B4  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00428.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef struct { int x, y, z; } V;

typedef unsigned int   u32;
extern void FIELD_CAMERA_ApplyTargetArea(u32 *a, u32 b);
extern void FIELD_CAMERA_ApplyEyeArea(u32 *a, u32 b);
extern void FIELD_CAMERA_CalcOffsetPoint(V *a, V *out, int i, int j, int e);

void FIELD_CAMERA_SolveEyeMode(u8 *a)
{
    int i;

    *(V *)(a + 0x3C) = *(V *)(a + 0x24);
    if (a[0xE9] != 0) {
        for (i = 0; i < a[0xE8]; i++) {
            FIELD_CAMERA_ApplyEyeArea((u32 *)(a + 0x88 + i * 0x18), (u32)(a + 0x3C));
        }
    }
    FIELD_CAMERA_CalcOffsetPoint((V *)(a + 0x3C), (V *)(a + 0x48), ((struct Obj00428 *)a)->f7A, ((struct Obj00428 *)a)->f78, ((struct Obj00428 *)a)->f7C);
    *(V *)(a + 0x54) = *(V *)(a + 0x48);
    if (a[0xE9] != 0) {
        for (i = 0; i < a[0xE8]; i++) {
            FIELD_CAMERA_ApplyTargetArea((u32 *)(a + 0x88 + i * 0x18), (u32)(a + 0x54));
        }
    }
}
