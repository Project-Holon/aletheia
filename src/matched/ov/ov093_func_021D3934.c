/*
 * function: BTL_CLIENT_CmdMemberIn
 * address:  0x021D3934
 * packet:   pkt_ov093_021D3934
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B9AEC  0x021B9AEC  thumb  ov093
 *   func_021B9C10  0x021B9C10  thumb  ov093
 *   func_021B9BF0  0x021B9BF0  thumb  ov093
 *   BTL_POKEPARAM_StartTurnThreshold  0x021D63EC  thumb  ov093
 *   BTL_POKEPARAM_ReloadAndResetEffects  0x021D6580  thumb  ov093
 */
#include "../include/Obj07795.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern char *func_021B9AEC(char *p, int i);
struct S2;
extern void func_021B9C10(u32 *p, int a, int b);
extern u32 func_021B9BF0(struct S2 *p, u32 i);
extern void BTL_POKEPARAM_StartTurnThreshold(u8 *p, u16 n);
extern void BTL_POKEPARAM_ReloadAndResetEffects(void *p);

int BTL_CLIENT_CmdMemberIn(char *a, int b, u32 *s)
{
    u8 x;
    u8 y;
    char *l;
    void *e;

    x = ((struct Obj07795 *)a)->f13C;
    y = ((struct Obj07795 *)a)->f140;
    l = func_021B9AEC(*(char * *)&((struct Obj07795 *)a)->f4, (u8)(((struct Obj07795 *)a)->f138));
    if (x != y)
        func_021B9C10((u32 *)l, x, y);
    e = (void *)func_021B9BF0((struct S2 *)l, x);
    BTL_POKEPARAM_StartTurnThreshold(e, s[3]);
    BTL_POKEPARAM_ReloadAndResetEffects(e);
    return 1;
}
