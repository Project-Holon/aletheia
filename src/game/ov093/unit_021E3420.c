/*
 * file:     unit_021E3420.c
 * unit:     yes
 * function: func_021E3420, func_021E34A8, func_021E34B4, func_021E34FC, func_021E354C, func_021E357C, func_021E3594, func_021E35A0, func_021E35F0, func_021E3648, func_021E36A4, func_021E36BC, func_021E36C8, func_021E36F4
 * address:  0x021E3420
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   BTL_EVENT_GetVar   0x021D775C  thumb ov093
 *   BTLV_CORE_CheckEitherSlotPair   0x021E86E8  thumb ov093
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   BTL_POKEPARAM_GetItem   0x021D5B40  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021C8838   0x021C8838  thumb ov093
 *   func_021C8860   0x021C8860  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 *   func_021E8624  0x021E8624  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   BTLV_CORE_EventRedirectMove  0x021E8744  thumb  ov093
 *   BTLV_CORE_EventCounterMove  0x021E8798  thumb  ov093
 *   BTLV_CORE_EventQueueMoveNotice  0x021E8804  thumb  ov093
 *   BTL_EVENT_RemoveFactor   0x021D7040  thumb
 *   d_021F2F18     0x021F2F18  data   ov093  a4
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   d_021F2E38     0x021F2E38  data   ov093  a4
 *   data_021F2824 0x021F2824 data a4
 *   d_021F2A98     0x021F2A98  data   ov093  a4
 */
#include "../../matched/include/Obj12158.h"
#include "../../matched/include/Obj10083.h"

struct QI;
struct S;
struct Node;
struct Unk021D62A8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

int BTL_EVENT_GetVar(int a);
int BTLV_CORE_CheckEitherSlotPair(void *a, int b, int c);
void *func_021C7CF4(int *p, int i);
u16 BTL_POKEPARAM_GetItem(struct QI *p);
void *func_021C88A4(char *p, int a, int b);
void func_021C8838(void *p, int a, int b);
void func_021C8860(struct S *p, unsigned int a);
void func_021C88C8(void *a, void *b);
extern int func_021E8624(int a, int b);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern int func_021B9A24(unsigned int a, unsigned int b);
extern void BTLV_CORE_EventRedirectMove(int a, void *b, int c, int d);
extern void BTLV_CORE_EventCounterMove(int u, void *a, int b, int d);
extern void BTLV_CORE_EventQueueMoveNotice(int a, void *b, int c, int d);
extern void BTL_EVENT_RemoveFactor(struct Node *n);
extern u32 WAZA_TOOL_GetFlag(u16 id, u32 bit);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
void func_021E3420(void *a, int b, int c);
int *func_021E34A8(int *p);
void func_021E34B4(int u, void *p, int key, int o);
void func_021E34FC(int u, void *p, int key, int *o);
void func_021E3544(int a, int b, int c, int d);
void func_021E354C(int u, void *a, int b, int c);
void func_021E357C(struct Node *a, int b, int c);
int *func_021E3594(int *p);
void func_021E35A0(int u, void *p, int key, int *o);
void func_021E35F0(int u, void *p, int key, int *o);
void func_021E3648(void *u, void *p, int key, int *o);
void func_021E36A4(struct Node *a, int b, int c);
int *func_021E36BC(int *p);
void func_021E36C8(int u, void *a, int b, int *p);
void func_021E36F4(void *a, void *b, int c, int *d);
u32 *func_021E37B4(u32 *p);
extern int d_021F2F18[];
extern int d_021F2E38[];
extern u32 data_021F2824[];
extern int d_021F2A98[];




/*
 * Gate on BTL_EVENT_GetVar(3), then BTLV_CORE_CheckEitherSlotPair(b,c,(u8)BTL_EVENT_GetVar(6))
 * must be zero and the (u16) of BTL_POKEPARAM_GetItem(func_021C7CF4(b,k)) non-zero.
 * Record #0x20 carries k, a zero halfword and a three-string tail (c, k and
 * that halfword).
 */
void func_021E3420(void *a, int b, int c)
{
    u8 k;
    u16 v;
    u8 *p;

    if (c != BTL_EVENT_GetVar(3))
        return;
    k = (u8)BTL_EVENT_GetVar(6);
    if (BTLV_CORE_CheckEitherSlotPair((void *)b, c, k) != 0)
        return;
    v = (u16)(int)BTL_POKEPARAM_GetItem(func_021C7CF4((int *)b, k));
    if (v == 0)
        return;
    p = func_021C88A4((char *)b, 0x20, c);
    ((struct Obj12158 *)p)->f6 = k;
    ((struct Obj12158 *)p)->f4 = 0;
    func_021C8838(p + 0xc, 2, 0x41a);
    func_021C8860((struct S *)(p + 0xc), c);
    func_021C8860((struct S *)(p + 0xc), k);
    func_021C8860((struct S *)(p + 0xc), v);
    func_021C88C8((void *)b, p);
}




int *func_021E34A8(int *p)
{
    *p = 5;
    return d_021F2F18;
}




void func_021E34B4(int u, void *p, int key, int o)
{
    u8 v = BTL_EVENT_GetVar(2);
    if (v == key) {
        if (func_021E8624((int)p, key) != 0) {
            BTL_EVENT_OverwriteVar(0x22, 0x1a);
            return;
        }
    } else if (func_021B9A24(key, v) == 0) {
        BTLV_CORE_EventRedirectMove(u, p, key, o);
    }
}






void func_021E34FC(int u, void *p, int key, int *o)
{
    u8 *q;
    if (key == BTL_EVENT_GetVar(3) && o[6] == 0) {
        q = func_021C88A4(p, 4, key);
        func_021C8838(q + 4, 2, 761);
        func_021C8860((struct S *)(q + 4), key);
        func_021C88C8(p, q);
        o[6] = 1;
    }
}






void func_021E3544(int a, int b, int c, int d)
{
    BTLV_CORE_EventCounterMove(a, (void *)b, c, d);
}






void func_021E354C(int u, void *a, int b, int c)
{
    if (b == BTL_EVENT_GetVar(2)) {
        if (BTL_EVENT_OverwriteVar(0x51, 1) != 0)
            BTLV_CORE_EventQueueMoveNotice(u, a, b, c);
    }
}






/* 021E357C  shape F3: gate on BTL_EVENT_GetVar(2) then BTL_EVENT_RemoveFactor */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r3, r4, r5, lr}; adds r5, r0, #0; movs r0, #2; adds r4, r2, #0; bl BTL_EVENT_GetVar; cmp r4, r0; bne loc_021E3592; adds r0, r5, #0; bl BTL_EVENT_RemoveFactor; pop {r3, r4, r5, pc}.
 */
void func_021E357C(struct Node *a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(2))
        BTL_EVENT_RemoveFactor(a);
}



int *func_021E3594(int *p)
{
    *p = 4;
    return d_021F2E38;
}



void func_021E35A0(int u, void *p, int key, int *o)
{
    u8 *q;
    if (key == BTL_EVENT_GetVar(3) && func_021E8624((int)p, key) == 0) {
        q = func_021C88A4(p, 4, key);
        func_021C8838(q + 4, 2, 751);
        func_021C8860((struct S *)(q + 4), key);
        func_021C88C8(p, q);
        o[6] = 1;
    }
}




void func_021E35F0(int u, void *p, int key, int *o)
{
    u8 t = BTL_EVENT_GetVar(3);
    if (t != key) {
        if (WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(0x12), 5) != 0) {
            if (BTL_POKEPARAM_HasSick(func_021C7CF4(p, key), 0x21) == 0) {
                if (BTL_EVENT_OverwriteVar(2, key) != 0) {
                    BTL_EVENT_OverwriteVar(4, key);
                    *o = 1;
                }
            }
        }
    }
}




void func_021E3648(void *u, void *p, int key, int *o)
{
    u8 *q;
    if (key == BTL_EVENT_GetVar(2) && *o != 0) {
        q = func_021C88A4(p, 4, key);
        func_021C8838(q + 4, 2, 754);
        func_021C8860((struct S *)(q + 4), key);
        func_021C8860((struct S *)(q + 4), BTL_EVENT_GetVar(3));
        func_021C88C8(p, q);
        BTL_EVENT_RemoveFactor(u);
    }
}



/* 021E36A4  shape F3: gate on BTL_EVENT_GetVar(2) then BTL_EVENT_RemoveFactor */
void func_021E36A4(struct Node *a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(2))
        BTL_EVENT_RemoveFactor(a);
}



int *func_021E36BC(int *p)
{
    *p = 2;
    return d_021F2A98;
}



void func_021E36C8(int u, void *a, int b, int *p)
{
    if (b == BTL_EVENT_GetVar(3))
        *p = (BTL_POKEPARAM_GetItem(func_021C7CF4(a, b)) != 0) ? 1 : 0;
}



/*
 * follower: 021E37B4 store-and-return stub included.
 */
void func_021E36F4(void *a, void *b, int c, int *d)
{
    u8 k;
    void *m;
    u8 *p;
    if (c != BTL_EVENT_GetVar(3)) return;
    if (BTL_POKEPARAM_GetItem(func_021C7CF4(b, c)) != 0) return;
    if (*d != 0) return;
    k = BTL_EVENT_GetVar(6);
    if (k == 31) return;
    m = func_021C7CF4(b, k);
    if (BTL_POKEPARAM_GetItem(m) == 0) return;
    if (BTLV_CORE_CheckEitherSlotPair(b, c, k) != 0) return;
    p = func_021C88A4(b, 36, c);
    p[4] = k;
    func_021C8838(p + 8, 2, 1057);
    func_021C8860((struct S *)(p + 8), c);
    func_021C8860((struct S *)(p + 8), k);
    func_021C8860((struct S *)(p + 8), BTL_POKEPARAM_GetItem(m));
    func_021C88C8(b, p);
    p = func_021C88A4(b, 58, c);
    ((struct Obj10083 *)p)->f0 |= 0x1000000;
    p[4] = 1;
    func_021C88C8(b, p);
}



u32 *func_021E37B4(u32 *p)
{
    *p = 1;
    return data_021F2824;
}
