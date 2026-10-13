/*
 * unit: yes
 * function: func_021E7B98, func_021E7C6C
 * address: 0x021E7B98
 * packet: pkt_ov093_021E7B98
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_GetItem 0x021D5B40 thumb ov093
 *   func_0202136C 0x0202136C thumb
 *   BTLV_CORE_CheckPartySlotPair 0x021E869C thumb ov093
 *   BTL_POKEPARAM_GetSpecies 0x021D5444 thumb ov093
 *   func_021E8638 0x021E8638 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   d_021F2AE8 0x021F2AE8 data a4
 */
#include "../include/Obj07837.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int);
extern void *func_021C7CF4(int *p, int i);
struct QI;
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern u32 func_0202136C(u16);
extern int BTLV_CORE_CheckPartySlotPair(void *a, int b);
struct QF;
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
extern int func_021E8638(int, int);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *, int, int);
struct S;
extern void func_021C8860(struct S *, u32);
extern void func_021C88C8(void *a, void *b);
extern int d_021F2AE8[];

void func_021E7B98(int a, int b, int c)
{
    u8 k;
    void *x;
    u16 h;
    u8 *p;
    if (c == BTL_EVENT_GetVar(3)) {
        k = BTL_EVENT_GetVar(6);
        x = func_021C7CF4((int *)b, k);
        h = (int)BTL_POKEPARAM_GetItem(func_021C7CF4((int *)b, c));
        if (h != 0 && func_0202136C(h) == 0 && (int)BTL_POKEPARAM_GetItem(x) == 0
            && BTLV_CORE_CheckPartySlotPair((void *)b, c) == 0 && BTLV_CORE_CheckPartySlotPair((void *)b, k) == 0
            && func_021E8638(BTL_POKEPARAM_GetSpecies(x), h) == 0) {
            p = func_021C88A4((char *)b, 0x20, c);
            p[6] = c;
            ((struct Obj07837 *)p)->f4 = 0;
            func_021C88C8((void *)b, p);
            p = func_021C88A4((char *)b, 0x20, c);
            p[6] = k;
            ((struct Obj07837 *)p)->f4 = h;
            func_021C8838(p + 12, 2, 0x457);
            func_021C8860((struct S *)(p + 12), k);
            func_021C8860((struct S *)(p + 12), c);
            func_021C8860((struct S *)(p + 12), h);
            func_021C88C8((void *)b, p);
        }
    }
}

int *func_021E7C6C(int *p)
{
    *p = 2;
    return d_021F2AE8;
}
