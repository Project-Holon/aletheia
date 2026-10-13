/*
 * function: FIELD_SUBSCREEN_Main
 * address:  0x021A0D68
 * packet:   pkt_ov021_021A0D68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_IsEventActive  0x02189A2C  thumb  ov021
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   d_021D872C  0x021D872C  data  a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02081.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

typedef struct {
    void (*init)(u32 *a, u32 prev);
    void (*update)(u32 *a, s32 flag);
    u32 f8;
    u32 fC;
    void (*exit)(u32 *a);
    u32 f14;
    u32 f18;
} Mode;

extern Mode d_021D872C[];
extern int FIELDMAP_IsEventActive(int *a);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 WIPE_SYS_EndCheck(void);

void FIELD_SUBSCREEN_Main(u32 *a)
{
    switch (a[2]) {
    case 0:
        d_021D872C[a[0]].update(a, FIELDMAP_IsEventActive((int *)a[5]) == 0);
        break;
    case 1:
        WIPE_SYS_Start((void *)4, 0, 0, 0, 1, 1, ((struct Obj02081 *)a)->fC);
        a[2] = 2;
        break;
    case 2:
        if (WIPE_SYS_EndCheck() == 1) {
            d_021D872C[a[0]].exit(a);
            d_021D872C[a[1]].init(a, a[0]);
            a[0] = a[1];
            a[2] = 4;
        }
        break;
    case 3:
        break;
    case 4:
        WIPE_SYS_Start((void *)4, 1, 1, 0, 1, 1, ((struct Obj02081 *)a)->fC);
        a[2] = 5;
        break;
    case 5:
        if (WIPE_SYS_EndCheck() == 1) {
            a[2] = 0;
        }
        d_021D872C[a[0]].update(a, FIELDMAP_IsEventActive((int *)a[5]) == 0);
        break;
    }
}
