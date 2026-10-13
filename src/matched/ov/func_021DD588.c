/*
 * function: BTL_ITEM_RecoverHpPercentOfMaxHp
 * address:  0x021DD588
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_ITEM_RecoverHpPercentOfMaxHp   0x021DD588  thumb ov093
 *   BTL_EVENT_GetVar   0x021D775C  thumb ov093
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   func_021D59B4   0x021D59B4  thumb ov093
 *   BTL_HANDLER_ITEM_GetParam   0x021DCFF8  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021C8838   0x021C8838  thumb ov093
 *   func_021C8860   0x021C8860  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 *   BTL_EVENT_GetFactorKey   0x021D70A8  thumb ov093
 *   func_0209C2B0   0x0209C2B0  arm
 *
 * Gate on BTL_EVENT_GetVar(2); the 0xe count of func_021D59B4(func_021C7CF4(b,c))
 * times the (u8) of BTL_HANDLER_ITEM_GetParam(a, 2) goes to the ARM helper at 0x0209C2B0,
 * whose result is the record's +4 halfword.  a and m go on the stack because
 * all four saved registers are live.
 */
#include "../include/Obj12151.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int BTL_EVENT_GetVar(int a);
void *func_021C7CF4(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
int BTL_HANDLER_ITEM_GetParam(int a, int b);
void *func_021C88A4(char *p, int a, int b);
void func_021C8838(void *p, int a, int b);
struct S;
void func_021C8860(struct S *p, unsigned int a);
void func_021C88C8(void *a, void *b);
struct QQ;
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
int func_0209C2B0(int a, int b);

void BTL_ITEM_RecoverHpPercentOfMaxHp(void *a, int b, int c)
{
    void *p;
    int m;
    u8 v;

    if (c != BTL_EVENT_GetVar(2))
        return;
    m = func_021D59B4(func_021C7CF4((int *)b, c), 0xe);
    v = (u8)BTL_HANDLER_ITEM_GetParam((int)a, 2);
    p = func_021C88A4((char *)b, 5, c);
    ((struct Obj12151 *)p)->f6 = c;
    ((struct Obj12151 *)p)->f4 = func_0209C2B0(m * v, 0x64);
    func_021C8838((u8 *)p + 8, 2, 0xe3 << 2);
    func_021C8860((struct S *)((u8 *)p + 8), c);
    func_021C8860((struct S *)((u8 *)p + 8), BTL_EVENT_GetFactorKey(a));
    func_021C88C8((void *)b, p);
}
