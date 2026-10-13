/*
 * function: func_021D4664
 * address:  0x021D4664
 * packet:   pkt_ov117_021D4664
 * region:   ov117
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D4240  0x021D4240  thumb  ov117
 *   func_021DFC68  0x021DFC68  thumb  ov119
 *   func_021D4480  0x021D4480  thumb  ov117
 *   func_021E71F0  0x021E71F0  thumb  ov119
 *   func_021E7208  0x021E7208  thumb  ov119
 *   func_021E64B8  0x021E64B8  thumb  ov119
 *   func_021E4888  0x021E4888  thumb  ov119
 *   func_021E2680  0x021E2680  thumb  ov119
 *   func_021D4484  0x021D4484  thumb  ov117
 *   func_021D8AA8  0x021D8AA8  thumb  ov119
 *   func_021D8FA4  0x021D8FA4  thumb  ov119
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   PM_VOICE_GetPerapVoiceSave  0x02006CAC  thumb
 *   PM_VOICE_Play  0x02006984  thumb
 *   func_020307B0  0x020307B0  arm
 *   MCSS_GetPosition  0x02015C30  thumb
 *   func_021DFD24  0x021DFD24  thumb  ov119
 *   func_021DFBB4  0x021DFBB4  thumb  ov119
 *   func_021E36C8  0x021E36C8  thumb  ov119
 *   MCSS_SetAnmStopFlag  0x02015E04  thumb
 *   MCSS_SetVanishFlag  0x02015EA0  thumb
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021D48F0  0x021D48F0  thumb  ov117
 *   d_021D5220     0x021D5220  data
 *   d_021D53D0     0x021D53D0  data
 *   d_021D5600     0x021D5600  data
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj05323.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed char s8;
typedef int s32;

typedef struct {
    s32 x, y, z;
} Vec;

extern void func_021D4240(s8 *fade);
extern void func_021DFC68(void *p, int a1);
extern int func_021D4480(int);
extern void func_021E71F0(void *p, int a);
extern void func_021E7208(void *p, int a);
extern void func_021E64B8(void *p);
extern void func_021E4888(char *p);
extern void func_021E2680(char *p);
extern void func_021D4484(u8 *p, u32 v);
extern int func_021D8AA8(void *);
extern void *func_021D8FA4(void *, int);
extern u32 POKE_TOOL_GetPartyValue(void *, u32, u32);
extern void PM_VOICE_GetPerapVoiceSave(void **out);
extern u32 PM_VOICE_Play(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
extern u32 func_020307B0(void *p);
extern void MCSS_GetPosition(void *p, u32 *out);
extern void func_021DFD24(u32 *p);
extern void *func_021DFBB4(void *a0, void *a1, void *a2, void *a3, u16 heapId);
extern void func_021E36C8(void *p, int a, int b, void *mon, int c);
extern void MCSS_SetAnmStopFlag(void *p);
extern void MCSS_SetVanishFlag(void *p);
extern void func_021D8E84(void *p, int next);
extern void func_021D48F0(u8 *p);
extern const u8 d_021D5220[];
extern const u8 d_021D53D0[];
extern u8 d_021D5600[];

#define FRAME (*(s32 *)(p + 0xF2C))
#define OBJ(i) (((u32 *)(p + 0x844))[i])
#define HEAP (*(u16 *)(p + 0x5F4))
#define SLOT0 (*(u32 *)(p + 0x85C))

void func_021D4664(u8 *p)
{
    void *mon;
    u32 a;
    u32 b;
    Vec v1;
    Vec v2;
    u32 buf;

    func_021D4240(*(s8 * *)&((struct Obj05323 *)p)->f818);
    func_021DFC68((void *)(((struct Obj05323 *)p)->f85C), (int)p);
    func_021DFC68((void *)(((struct Obj05323 *)p)->f860), (int)p);
    if (FRAME > func_021D4480(0x2A)) {
        func_021E71F0(p, 0x11);
        func_021E7208(p, 0);
        func_021E64B8(p);
        func_021E4888((char *)p);
        func_021E2680((char *)p);
        func_021D4484(p, 0);
        mon = func_021D8FA4(p, func_021D8AA8(p));
        POKE_TOOL_GetPartyValue(mon, 7, 0);
        if (POKE_TOOL_GetPartyValue(mon, 0x4C, 0) == 0) {
            a = POKE_TOOL_GetPartyValue(mon, 0xAB, 0);
            b = POKE_TOOL_GetPartyValue(mon, 0x6F, 0);
            PM_VOICE_GetPerapVoiceSave((void **)(&buf));
            PM_VOICE_Play(a, b, 0x40, 0, 0, 0, 0, (u32)(&buf));
        }
        if (SLOT0 != 0) {
            func_020307B0((void *)SLOT0);
            SLOT0 = 0;
        }
        if (((struct Obj05323 *)p)->f11ED == 0) {
            MCSS_GetPosition((void *)OBJ(0), (u32 *)(&v1));
            func_021DFD24((u32 *)SLOT0);
            if (((struct Obj05323 *)p)->f11EF != 0) {
                SLOT0 = (u32)func_021DFBB4((void *)OBJ(0), (void *)0x14, &v1, d_021D5600, HEAP);
            } else {
                SLOT0 = (u32)func_021DFBB4((void *)OBJ(0), (void *)0x12, &v1, (void *)d_021D5220, HEAP);
            }
            func_021E36C8(p, 2, 0, func_021D8FA4(p, func_021D8AA8(p)), 1);
            MCSS_SetAnmStopFlag((void *)OBJ(2));
            MCSS_SetVanishFlag((void *)OBJ(2));
        } else {
            MCSS_GetPosition((void *)OBJ(0), (u32 *)(&v2));
            func_021DFD24((u32 *)SLOT0);
            if (((struct Obj05323 *)p)->f11EF != 0) {
                SLOT0 = (u32)func_021DFBB4((void *)OBJ(0), (void *)0x14, &v2, d_021D5600, HEAP);
            } else {
                SLOT0 = (u32)func_021DFBB4((void *)OBJ(0), (void *)0x28, &v2, (void *)d_021D53D0, HEAP);
            }
        }
        func_021D8E84(p, (int)func_021D48F0);
    }
}
