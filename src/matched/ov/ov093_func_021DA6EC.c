/*
 * function: BTL_ABILITY_SturdyBlockOneHitKo
 * address:  0x021DA6EC
 * packet:   pkt_ov093_021DA6EC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar   0x021D775C  thumb ov093
 *   BTL_EVENT_OverwriteVar   0x021D76BC  thumb ov093
 *   func_021C88B4   0x021C88B4  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021C8838   0x021C8838  thumb ov093
 *   func_021C8860   0x021C8860  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern int BTL_EVENT_GetVar(int a);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern void func_021C88B4(void *a, int k, int b);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 a);
extern void func_021C88C8(void *a, void *b);

void BTL_ABILITY_SturdyBlockOneHitKo(int a, int b, int c)
{
    u8 *p;
    int m = 4;

    if (c != BTL_EVENT_GetVar(4))
        return;
    if (BTL_EVENT_OverwriteVar(0x41, 1) == 0)
        return;
    func_021C88B4((void *)b, 2, c);
    p = func_021C88A4((char *)b, m, c);
    func_021C8838(p + 4, 2, 0xd2);
    func_021C8860((struct S *)(p + 4), c);
    func_021C88C8((void *)b, p);
    func_021C88B4((void *)b, 3, c);
}
