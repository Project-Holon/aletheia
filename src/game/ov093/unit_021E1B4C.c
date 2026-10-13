/*
 * file:     unit_021E1B4C.c
 * unit:     yes
 * function: func_021E1B4C, func_021E1BC8, func_021E1BD4, func_021E1BF8, func_021E1C40, func_021E1C4C, func_021E1C80
 * address:  0x021E1B4C
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
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetMoveCount  0x021D5448  thumb  ov093
 *   BTL_POKEPARAM_GetMoveId  0x021D54C0  thumb  ov093
 *   BTL_POKEPARAM_GetMoveUsedFlag  0x021D54E0  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   d_021F2978     0x021F2978  data   ov093  a4
 *   d_021F24DC     0x021F24DC  data   ov093  a4
 *   d_021F24B4     0x021F24B4  data   ov093  a4
 */
struct QG;
struct Unk021D62A8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
extern u8 BTL_POKEPARAM_GetMoveCount(struct QG *p);
extern u16 BTL_POKEPARAM_GetMoveId(u8 *p, int i);
extern u32 BTL_POKEPARAM_GetMoveUsedFlag(u8 *p, u32 i);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
void func_021E1B4C(int a, void *p, int id);
int *func_021E1BC8(int *p);
void func_021E1BD4(int a, int b, int c);
void func_021E1BF8(int a, void *p, int id);
int *func_021E1C40(int *p);
void func_021E1C4C(int a, void *p, int id);
int *func_021E1C80(int *p);
extern int d_021F2978[];
extern int d_021F24DC[];
extern int d_021F24B4[];



void func_021E1B4C(int a, void *p, int id)
{
    void *q;
    u8 n;
    u8 i;
    u8 cnt;
    int flag;
    if (id == BTL_EVENT_GetVar(2)) {
        q = func_021C7CF4(p, id);
        n = BTL_POKEPARAM_GetMoveCount(q);
        cnt = 0;
        flag = 0;
        for (i = 0; i < n; i++) {
            if (BTL_POKEPARAM_GetMoveId(q, i) == 0x183) {
                flag = 1;
            } else if (BTL_POKEPARAM_GetMoveUsedFlag(q, i)) {
                cnt++;
            }
        }
        if (flag == 0 || n < 2 || cnt < n - 1)
            BTL_EVENT_OverwriteVar(0x22, 0x1a);
    }
}



int *func_021E1BC8(int *p)
{
    *p = 2;
    return d_021F2978;
}



void func_021E1BD4(int a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(2) && BTL_EVENT_GetVar(34) == 2)
        BTL_EVENT_OverwriteVar(65, 1);
}




void func_021E1BF8(int a, void *p, int id)
{
    int two = 2;
    void *q;
    int k;
    if (id == BTL_EVENT_GetVar(2)) {
        q = func_021C7CF4(p, id);
        k = 0x22;
        if (BTL_EVENT_GetVar(k) == 2) {
            BTL_EVENT_OverwriteVar(k, 0);
            return;
        }
        if (BTL_POKEPARAM_HasSick(q, two) == 0)
            BTL_EVENT_OverwriteVar(k, 0x1a);
    }
}


int *func_021E1C40(int *p)
{
    *p = 1;
    return d_021F24DC;
}


void func_021E1C4C(int a, void *p, int id)
{
    u8 t;
    if (id == BTL_EVENT_GetVar(3)) {
        t = BTL_EVENT_GetVar(4);
        if (BTL_POKEPARAM_HasSick(func_021C7CF4(p, t), 2) == 0)
            BTL_EVENT_OverwriteVar(0x40, 1);
    }
}


int *func_021E1C80(int *p)
{
    *p = 1;
    return d_021F24B4;
}
