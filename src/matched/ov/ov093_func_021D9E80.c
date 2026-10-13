/*
 * function: HAND_TOKUSEI_RoughSkinOnDamageReaction
 * address:  0x021D9E80
 * packet:   pkt_ov093_021D9E80
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar   0x021D775C  thumb ov093
 *   WAZA_TOOL_GetFlag   0x0201BEB8  thumb
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   BTL_POKEPARAM_IsFainted   0x021D5B68  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   BTL_CALC_DivideMaxHpMin1   0x021D7B74  thumb ov093
 *   func_021C8838   0x021C8838  thumb ov093
 *   func_021C8860   0x021C8860  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 */
#include "../include/Obj10059.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern int BTL_EVENT_GetVar(int a);
extern u32 WAZA_TOOL_GetFlag(u16 id, u32 bit);
extern void *func_021C7CF4(int *p, int i);
extern int BTL_POKEPARAM_IsFainted(void *p);
extern void *func_021C88A4(char *p, int a, int b);
extern int BTL_CALC_DivideMaxHpMin1(u8 *p, u32 k);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 val);
extern void func_021C88C8(void *a, void *b);

void HAND_TOKUSEI_RoughSkinOnDamageReaction(int a, int b, int c)
{
    u8 *p;
    u8 k;
    void *m;

    if (c != BTL_EVENT_GetVar(4))
        return;
    if (BTL_EVENT_GetVar(0x46) != 0)
        return;
    if (WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(0x12), 0) == 0)
        return;
    k = BTL_EVENT_GetVar(3);
    m = func_021C7CF4((int *)b, k);
    if (BTL_POKEPARAM_IsFainted(m) != 0)
        return;
    p = func_021C88A4((char *)b, 7, c);
    ((struct Obj10059 *)p)->f0 |= 4 << 21;
    ((struct Obj10059 *)p)->f6 = k;
    ((struct Obj10059 *)p)->f4 = BTL_CALC_DivideMaxHpMin1(m, 8);
    func_021C8838(p + 0xc, 2, 0x1ae);
    func_021C8860((struct S *)(p + 0xc), k);
    func_021C88C8((void *)b, p);
}
