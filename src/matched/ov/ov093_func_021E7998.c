/*
 * unit:     yes
 * function: func_021E7998, func_021E79FC
 * address:  0x021E7998
 * packet:   pkt_ov093_021E7998
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * BTLV_CORE_MakeSlotKind2Index returns a one-word struct: that is the `push {r3,..}; sub sp, #4`
 * frame word (docs/idioms/an-unused-frame-word-is-a-callee-returning-a-one-word-struct.md).
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_FIELD_GetStaticSlotObject  0x021EF948  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   BTLV_CORE_MakeSlotKind2Index  0x021E8940  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F2684     0x021F2684  data   ov093  a4
 */
#include "../include/Obj13545.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct Word { u32 v; } Word;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_FIELD_GetStaticSlotObject(int k);
extern void *func_021C88A4(char *p, int a, int b);
extern Word BTLV_CORE_MakeSlotKind2Index(int k);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern int d_021F2684[];

void func_021E7998(int a, int b, int c)
{
    int k;
    u8 *p;

    if (c == BTL_EVENT_GetVar(3)) {
        k = 6;
        if (BTL_FIELD_GetStaticSlotObject(k) == 0) {
            p = func_021C88A4((char *)b, 0x1b, c);
            ((struct Obj13545 *)p)->f4 = k;
            *(Word *)(p + 8) = BTLV_CORE_MakeSlotKind2Index(5);
            func_021C8838(p + 0x10, 1, 0xb2);
            func_021C88C8((void *)b, p);
        } else {
            p = func_021C88A4((char *)b, 0x1c, c);
            ((struct Obj13545 *)p)->f4 = k;
            func_021C88C8((void *)b, p);
        }
    }
}

int *func_021E79FC(int *p)
{
    *p = 1;
    return d_021F2684;
}
