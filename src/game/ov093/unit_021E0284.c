/*
 * file:     unit_021E0284.c
 * unit:     yes
 * function: func_021E0284, func_021E02C0, func_021E02DC, func_021E0354, func_021E0394, func_021E03D8, func_021E03E8, func_021E03F8, func_021E0434, func_021E045C, func_021E0468, func_021E050C
 * address:  0x021E0284
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
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   func_021C7EC4  0x021C7EC4  thumb  ov093
 *   data_021F3030  0x021F3030  data
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_EVENT_AddFactor  0x021D6F0C  thumb  ov093
 *   BTL_EVENT_FindFactor  0x021D732C  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTL_EVENT_FindNextFactor  0x021D7360  thumb  ov093
 *   BTL_EVENT_GetFactorWork  0x021D70B4  thumb  ov093
 *   BTL_EVENT_RemoveFactor  0x021D7040  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetMoveCount  0x021D5448  thumb  ov093
 *   BTL_POKEPARAM_GetMoveId  0x021D54C0  thumb  ov093
 *   WAZA_TOOL_GetType  0x0201C1C8  thumb
 *   BTL_POKEPARAM_HasType  0x021D5814  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 *   BTLV_CORE_PackByteTwice  0x021E8CF0  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F261C     0x021F261C  data   ov093  a4
 *   d_021F2414     0x021F2414  data   ov093  a4
 */
#include "../../matched/include/Obj13503.h"

struct Node;
struct QQ;
struct QG;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Handler { u16 key; int (*fn)(u32 *out); };

struct Node {
    struct Node *prev;
    struct Node *next;
    u32 f8;
    u32 fC;
    int id;
    u32 prio;
    u32 serial : 16;
    u32 f16 : 8;
    u32 b24 : 1;
    u32 mark : 1;
    u32 b26 : 1;
    u32 busy : 1;
    u32 b28 : 1;
    u32 b29 : 1;
    u32 b30 : 1;
    u32 b31 : 1;
    u8 f1C[0x1C];
    u16 key;
    u8 sub;
    u8 kind;
};

struct NodeList { u32 serial; struct Node *head; u32 used; struct Node *pool[0x84]; };

extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_MultiplyVar(int key, int m);
extern u32 func_021C7EC4(u8 *p);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern struct Node *BTL_EVENT_AddFactor(int id, u32 key, int pri, u32 sub_pri, u8 sub, u32 f8, u16 f16);
extern struct Node *BTL_EVENT_FindFactor(int id, int sub);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern struct Node *BTL_EVENT_FindNextFactor(struct Node *n);
extern u32 BTL_EVENT_GetFactorWork(u8 *p, int i);
extern void BTL_EVENT_RemoveFactor(struct Node *n);
extern void *func_021C7CF4(int *p, int i);
extern u8 BTL_POKEPARAM_GetMoveCount(struct QG *p);
extern u16 BTL_POKEPARAM_GetMoveId(u8 *p, int i);
extern u8 WAZA_TOOL_GetType(void *p);
extern int BTL_POKEPARAM_HasType(void *q, int k);
extern void *func_021C88A4(char *p, int a, int b);
extern u32 BTL_CALC_Random(u32 range);
extern int BTLV_CORE_PackByteTwice(int a);
extern void func_021C88C8(void *a, void *b);
void func_021E0284(int a, void *b, int c, int *d, u8 e);
void func_021E02C0(int a, int b, int c, int *d);
int func_021E02DC(u8 *a, u16 key, u32 sub_pri);
int func_021E0354(int sub, int key, u8 *found);
void func_021E0394(u8 *a, int b);
void func_021E03D8(u8 *a, int b);
int func_021E03E8(void *n, u32 *q);
void func_021E03F8(int a, int b);
void func_021E0434(u8 *p);
int *func_021E045C(int *p);
void func_021E0468(void *a, void *b, int c);
int *func_021E050C(int *p);
extern const struct Handler data_021F3030[0x102];
extern struct NodeList data_021F3CB0;
extern int d_021F261C[];
extern int d_021F2414[];






void func_021E0284(int a, void *b, int c, int *d, u8 e)
{
    if (c == BTL_EVENT_GetVar(3) && e == BTL_EVENT_GetVar(22)) {
        if (*d == 1 || func_021C7EC4(b))
            BTL_EVENT_MultiplyVar(49, 6 << 10);
    }
}






void func_021E02C0(int a, int b, int c, int *d)
{
    if (c == BTL_EVENT_GetVar(3) && *d == 1)
        *d = 2;
}





int func_021E02DC(u8 *a, u16 key, u32 sub_pri)
{
    u32 i;
    u8 sub;
    u8 found;
    u32 out;
    int r;
    for (i = 0; i < 0x102; i++) {
        if (key == data_021F3030[i].key) {
            sub = BTL_POKEPARAM_GetPokeId(a);
            found = 0;
            if (func_021E0354(sub, key, &found) != 0) {
                r = data_021F3030[i].fn(&out);
                if (r != 0) {
                    BTL_EVENT_AddFactor(0, key, 0, sub_pri, sub, r, out);
                    return 1;
                }
            }
            return 0;
        }
    }
    return 0;
}





int func_021E0354(int sub, int key, u8 *found)
{
    struct Node *n;
    u32 i = 0;
    for (n = BTL_EVENT_FindFactor(0, sub); n != 0; n = BTL_EVENT_FindNextFactor(n)) {
        if (key == BTL_EVENT_GetFactorKey((struct QQ *)n)) {
            *found = 1;
            return 0;
        }
        if (++i > 8) return 0;
    }
    return 1;
}






void func_021E0394(u8 *a, int b)
{
    void *n;
    void *next;

    n = BTL_EVENT_FindFactor(0, BTL_POKEPARAM_GetPokeId(a));
    while (n != 0) {
        next = BTL_EVENT_FindNextFactor(n);
        if (b == BTL_EVENT_GetFactorKey(n) && BTL_EVENT_GetFactorWork(n, 6) == 0) {
            BTL_EVENT_RemoveFactor(n);
        }
        n = next;
    }
}






/* 021E03D8  pass-through: second callee takes the first one's result */
void func_021E03D8(u8 *a, int b)
{
    func_021E03F8(BTL_POKEPARAM_GetPokeId(a), b);
}






int func_021E03E8(void *n, u32 *q)
{
    if (q[6] != 0) return 1;
    return 0;
}




void func_021E03F8(int a, int b)
{
    void *n = BTL_EVENT_FindFactor(0, a);

    while (n != 0) {
        if (b == BTL_EVENT_GetFactorKey(n)) {
            BTL_EVENT_RemoveFactor(n);
            n = BTL_EVENT_FindFactor(0, a);
        } else {
            n = BTL_EVENT_FindNextFactor(n);
        }
    }
}



void func_021E0434(u8 *p)
{
    int n = BTL_POKEPARAM_GetPokeId(p);
    void *a;

    while ((a = BTL_EVENT_FindFactor(0, n)) != 0)
        BTL_EVENT_RemoveFactor(a);
}


int *func_021E045C(int *p)
{
    *p = 1;
    return d_021F261C;
}


void func_021E0468(void *a, void *b, int c)
{
    u8 buf[4];
    void *q;
    u32 n;
    u16 i;
    u16 cnt;
    u32 v;
    char *p;

    if (c == BTL_EVENT_GetVar(3)) {
        q = func_021C7CF4(b, c);
        n = BTL_POKEPARAM_GetMoveCount(q);
        i = 0;
        cnt = 0;
        for (; i < n; i++) {
            v = BTL_POKEPARAM_GetMoveId(q, (u8)i);
            if (v != BTL_EVENT_GetFactorKey(a)) {
                v = WAZA_TOOL_GetType((void *)v);
                if (BTL_POKEPARAM_HasType(q, v) == 0) {
                    buf[cnt++] = v;
                }
            }
        }
        if (cnt != 0) {
            p = func_021C88A4(b, 0x14, c);
            ((struct Obj13503 *)p)->f4 = BTLV_CORE_PackByteTwice(buf[(u16)BTL_CALC_Random(cnt)]);
            ((struct Obj13503 *)p)->f6 = c;
            func_021C88C8(b, p);
        }
    }
}


/*
 * extent: 021E05C2 alignment padding.
 */
int *func_021E050C(int *p)
{
    *p = 1;
    return d_021F2414;
}
