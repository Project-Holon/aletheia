/*
 * function: BTL_ITEM_FlavorHeal
 * address:  0x021DD7B8
 * packet:   pkt_ov093_021DD7B8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   BTL_HANDLER_ITEM_GetParam  0x021DCFF8  thumb  ov093
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   BTL_POKEPARAM_GetMon  0x021D5844  thumb  ov093
 *   POKE_TOOL_GetNatureStatMod  0x020189D0  thumb
 *   BTL_CALC_MakeSickContFromKind  0x021D7DC0  thumb  ov093
 */
#include "../include/Obj07817.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
extern void *func_021C88A4(char *p, int a, int b);
extern int BTL_HANDLER_ITEM_GetParam(int a, int b);
struct QQ;
extern int BTL_CALC_DivideMaxHpMin1(u8 *p, u32 k);
extern void func_021C8838(void *l, int a, int b);
struct S;
extern void func_021C8860(struct S *l, u32 v);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern void func_021C88C8(void *a, void *b);
extern void *BTL_POKEPARAM_GetMon(void *m);
extern int POKE_TOOL_GetNatureStatMod(void *m, int b);
extern void BTL_CALC_MakeSickContFromKind(int a, void *b, void *out);

void BTL_ITEM_FlavorHeal(int a, u8 *b, int c, int *d, int e)
{
    void *m;
    u8 *p;
    if (*d == 0 && c == BTL_EVENT_GetVar(2)) {
        m = func_021C7CF4((int *)b, c);
        p = func_021C88A4((char *)b, 5, c);
        p[6] = c;
        *(u16 *)&((struct Obj07817 *)p)->f4 = BTL_CALC_DivideMaxHpMin1(m, BTL_HANDLER_ITEM_GetParam(a, 2));
        func_021C8838(p + 8, 2, 908);
        func_021C8860((struct S *)(p + 8), c);
        func_021C8860((struct S *)(p + 8), BTL_EVENT_GetFactorKey((void *)a));
        func_021C88C8(b, p);
        if (POKE_TOOL_GetNatureStatMod(BTL_POKEPARAM_GetMon(m), e) == -1) {
            p = func_021C88A4((char *)b, 0xc, c);
            p[0xf] = c;
            ((struct Obj07817 *)p)->f4 = 6;
            BTL_CALC_MakeSickContFromKind(6, m, p + 8);
            func_021C88C8(b, p);
        }
        *d = 1;
    }
}
