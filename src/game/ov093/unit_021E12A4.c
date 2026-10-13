/*
 * file:     unit_021E12A4.c
 * unit:     yes
 * function: func_021E12A4, func_021E1314, func_021E1320, func_021E1354, func_021E1404, func_021E1410, func_021E1434, func_021E146C
 * address:  0x021E12A4
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
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   func_021C7ED8  0x021C7ED8  thumb  ov093
 *   BTL_POKEPARAM_GetMon  0x021D5844  thumb  ov093
 *   BTL_CALC_MakeSickContFromKind  0x021D7DC0  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTLV_CORE_SetSlotValue  0x021E8B28  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   d_021F2918     0x021F2918  data   ov093  a4
 *   BTL_POKEPARAM_TestContFlag  0x021D5BDC  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   d_021F2D98     0x021F2D98  data   ov093  a4
 *   d_021F25A4     0x021F25A4  data   ov093  a4
 */
struct QF;
struct QQ;
union U;
struct S;
struct UtilWork;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef enum { K_SIX = 6 } K;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
extern int func_021C7ED8(u8 *p, int i);
extern void *BTL_POKEPARAM_GetMon(void *m);
extern void BTL_CALC_MakeSickContFromKind(int a, void *b, void *out);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern void BTLV_CORE_SetSlotValue(union U *p, u16 v);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 val);
extern int BTL_POKEPARAM_TestContFlag(struct UtilWork *p, u32 n);
extern void BTL_EVENT_MultiplyVar(int key, s32 m);
void func_021E12A4(int unused, void *q, int id);
int *func_021E1314(int *p);
void func_021E1320(void *a, int b, int c);
void func_021E1354(void *a, void *unused, int id);
int *func_021E1404(int *p);
void func_021E1410(int a, int b, int c);
void func_021E1434(int a, void *p, int id);
int *func_021E146C(int *p);
extern int d_021F2918[];
extern int d_021F2D98[];
extern int d_021F25A4[];



/*
 * Lever: the constant 6 lives in r5 across the calls (movs r5,#6 before the
 * BTL_POKEPARAM_GetMon bl); an int local folds it into each use, an enum local keeps it.
 */
void func_021E12A4(int unused, void *q, int id)
{
    void *m;
    u32 n;
    K a;
    int b;
    u32 out;

    if (id == BTL_EVENT_GetVar(3)) {
        m = func_021C7CF4(q, id);
        if (BTL_POKEPARAM_GetSpecies(m) == 0x1b9) {
            n = func_021C7ED8(q, id);
            if (n != 0) {
                a = K_SIX;
                BTL_POKEPARAM_GetMon(m);
                if (n > 2)
                    b = 0x1e;
                else
                    b = 10;
                BTL_CALC_MakeSickContFromKind(a, m, &out);
                BTL_EVENT_OverwriteVar(0x1d, a);
                BTL_EVENT_OverwriteVar(0x1e, out);
                BTL_EVENT_OverwriteVar(0x26, b);
            }
        }
    }
}



int *func_021E1314(int *p)
{
    *p = 2;
    return d_021F2918;
}



void func_021E1320(void *a, int b, int c)
{
    int v;
    u16 n;

    if (c != BTL_EVENT_GetVar(3))
        return;
    n = BTL_EVENT_GetFactorKey(a);
    v = BTL_EVENT_GetVar(30);
    BTLV_CORE_SetSlotValue((union U *)(&v), n);
    BTL_EVENT_OverwriteVar(30, v);
}




void func_021E1354(void *a, void *unused, int id)
{
    void *p;
    u8 k;
    int v;

    if (id != BTL_EVENT_GetVar(3))
        return;
    if (BTL_EVENT_GetVar(0x1d) != 8)
        return;
    p = (void *)BTL_EVENT_GetVar(0x3f);
    k = BTL_EVENT_GetVar(4);
    switch (BTL_EVENT_GetFactorKey(a)) {
    case 0x23:
        v = 0x32a;
        break;
    case 0x14:
        v = 0x323;
        break;
    case 0x53:
        v = 0x33b;
        break;
    case 0x80:
        v = 0x331;
        break;
    case 0x148:
        v = 0x341;
        break;
    case 0x1cf:
        v = 0x33e;
        break;
    case 0xfa:
        v = 0x338;
        break;
    default:
        return;
    }
    func_021C8838(p, 2, v);
    func_021C8860(p, k);
    func_021C8860(p, id);
}


int *func_021E1404(int *p)
{
    *p = 4;
    return d_021F2D98;
}


void func_021E1410(int a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(3) && BTL_EVENT_GetVar(33) == 4)
        BTL_EVENT_OverwriteVar(66, 0);
}



void func_021E1434(int a, void *p, int id)
{
    int k;
    if (id == BTL_EVENT_GetVar(3)) {
        k = 4;
        if (BTL_POKEPARAM_TestContFlag(func_021C7CF4(p, (u8)BTL_EVENT_GetVar(4)), 4)) {
            BTL_EVENT_MultiplyVar(0x35, k << 11);
        }
    }
}


int *func_021E146C(int *p)
{
    *p = 1;
    return d_021F25A4;
}
