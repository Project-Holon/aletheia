/*
 * function: func_021D48F0
 * address:  0x021D48F0
 * packet:   pkt_ov117_021D48F0
 * region:   ov117
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D4820  0x021D4820  thumb  ov117
 *   MCSS_GetPosition  0x02015C30  thumb
 *   MCSS_SetPosition  0x02015C48  thumb
 *   MCSS_ResetVanishFlag  0x02015EB0  thumb
 *   MCSS_SetVanishFlag  0x02015EA0  thumb
 *   MCSS_ResetAnmStopFlag  0x02015E4C  thumb
 *   func_021E12AC  0x021E12AC  thumb  ov119
 *   func_021E1098  0x021E1098  thumb  ov119
 *   func_021E36D8  0x021E36D8  thumb  ov119
 *   func_020307B0  0x020307B0  arm
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021DFC68  0x021DFC68  thumb  ov119
 *   func_021D4BF4  0x021D4BF4  thumb  ov117
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00982.h"

typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;

typedef struct {
    s32 x, y, z;
} Vec;

extern void func_021D4820(u8 *p);
extern void MCSS_GetPosition(void *p, u32 *out);
extern void MCSS_SetPosition(void *p, u32 *src);
extern void MCSS_ResetVanishFlag(void *p);
extern void MCSS_SetVanishFlag(void *p);
extern void MCSS_ResetAnmStopFlag(void *p);
extern int func_021E12AC(char *p);
extern void func_021E1098(char *p);
extern void func_021E36D8(void *p, int a);
extern u32 func_020307B0(void *p);
extern void func_021D8E84(void *p, int next);
extern void func_021DFC68(void *p, int a1);
extern void func_021D4BF4(u8 *p);

#define FRAME (*(s32 *)(p + 0xF2C))
#define OBJ(i) (((u32 *)(p + 0x844))[i])
#define SLOT0 (*(u32 *)(p + 0x85C))

void func_021D48F0(u8 *p)
{
    Vec v;

    if (FRAME == 10) {
        func_021D4820(p);
    }
    if (((struct Obj00982 *)p)->f11ED == 0 && FRAME == 6) {
        MCSS_GetPosition((void *)OBJ(0), (u32 *)(&v));
        MCSS_SetPosition((void *)OBJ(2), (u32 *)(&v));
        MCSS_ResetVanishFlag((void *)OBJ(2));
        MCSS_SetVanishFlag((void *)OBJ(0));
        MCSS_ResetAnmStopFlag((void *)OBJ(2));
        *(u32 *)SLOT0 = OBJ(2);
    }
    if (FRAME > 0xC8 && func_021E12AC((char *)p) != 0) {
        func_021E1098((char *)p);
        if (((struct Obj00982 *)p)->f11ED == 0) {
            func_021E36D8(p, 0);
            OBJ(0) = OBJ(2);
            OBJ(2) = 0;
        }
        if (SLOT0 != 0) {
            func_020307B0((void *)SLOT0);
            SLOT0 = 0;
        }
        func_021D8E84(p, (int)func_021D4BF4);
    }
    func_021DFC68((void *)SLOT0, (int)p);
}
