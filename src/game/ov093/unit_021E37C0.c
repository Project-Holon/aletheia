/*
 * file:     unit_021E37C0.c
 * unit:     yes
 * function: func_021E37C0, func_021E3904
 * address:  0x021E37C0
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
 *   data_021F2E58 0x021F2E58 data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_GetItem 0x021D5B40 thumb ov093
 *   BTL_POKEPARAM_GetSpecies 0x021D5444 thumb ov093
 *   BTLV_CORE_CheckPartySlotCondition 0x021E86C8 thumb ov093
 *   func_021E8638 0x021E8638 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 *   data_021F2878  0x021F2878  data   a1
 *   data_021F2879  0x021F2879  data   a1
 */
struct QF;
struct QI;
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int BTL_EVENT_GetVar(int);
extern void *func_021C7CF4(int *p, int i);
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
extern int BTLV_CORE_CheckPartySlotCondition(void *, int);
extern int func_021E8638(int, int);
extern u32 func_0202136C(u16 v);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *, int, int);
extern void func_021C8860(struct S *p, u32 val);
extern void func_021C88C8(void *, void *);
extern u32 BTL_CALC_Random(u32 range);
void func_021E37C0(void *a, void *b, int c);
u32 *func_021E38F8(u32 *p);
void func_021E3904(int u, void *p, int key, int *o);
extern u32 data_021F2E58[];
extern u8 data_021F2878[];
extern u8 data_021F2879[];

/*
 * follower: 021E38F8 store-and-return stub included.
 */
void func_021E37C0(void *a, void *b, int c)
{
    u8 k;
    void *m;
    void *n;
    u16 x;
    u16 y;
    int t;
    int u;
    u8 *p;
    if (c != BTL_EVENT_GetVar(3)) return;
    k = BTL_EVENT_GetVar(6);
    if (BTLV_CORE_CheckPartySlotCondition(b, c) != 0) return;
    m = func_021C7CF4(b, c);
    n = func_021C7CF4(b, k);
    x = (int)BTL_POKEPARAM_GetItem(m);
    y = (int)BTL_POKEPARAM_GetItem(n);
    if (x == 0 && y == 0) return;
    t = BTL_POKEPARAM_GetSpecies(m);
    u = BTL_POKEPARAM_GetSpecies(n);
    if (func_0202136C(x) != 0) return;
    if (func_0202136C(y) != 0) return;
    if (func_021E8638(t, y) != 0) return;
    if (func_021E8638(u, x) != 0) return;
    if (func_021E8638(t, x) != 0) return;
    if (func_021E8638(u, y) != 0) return;
    p = func_021C88A4(b, 36, c);
    p[4] = k;
    func_021C8838(p + 8, 2, 682);
    func_021C8860((struct S *)(p + 8), c);
    if (y != 0) {
        func_021C8838(p + 80, 2, 685);
        func_021C8860((struct S *)(p + 80), c);
        func_021C8860((struct S *)(p + 80), y);
    }
    if (x != 0) {
        func_021C8838(p + 44, 2, 685);
        func_021C8860((struct S *)(p + 44), k);
        func_021C8860((struct S *)(p + 44), x);
    }
    func_021C88C8(b, p);
}

u32 *func_021E38F8(u32 *p)
{
    *p = 4;
    return data_021F2E58;
}


void func_021E3904(int u, void *p, int key, int *o)
{
    u8 i;
    u8 v;
    u8 *q;
    if (key == BTL_EVENT_GetVar(2)) {
        v = BTL_CALC_Random(100);
        for (i = 0; i < 7; i++) {
            if (v < data_021F2878[i * 2])
                break;
        }
        *o = data_021F2879[i * 2];
        q = func_021C88A4(p, 4, key);
        func_021C8838(q + 4, 1, (u16)(i + 0x68));
        func_021C88C8(p, q);
    }
}
