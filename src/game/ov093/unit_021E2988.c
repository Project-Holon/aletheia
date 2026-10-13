/*
 * file:     unit_021E2988.c
 * unit:     yes
 * function: func_021E2988, func_021E29E8, func_021E2A38, func_021E2A80
 * address:  0x021E2988
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
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   WAZA_TOOL_GetPower  0x0201C1D8  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   d_021F2564     0x021F2564  data   ov093  a4
 *   BTL_POKEPARAM_GetHpRatioFixed  0x021D5C44  thumb  ov093
 *   BTL_CALC_MulRatioMin1  0x021D7B2C  thumb  ov093
 *   d_021F24AC     0x021F24AC  data   ov093  a4
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   d_021F244C     0x021F244C  data   ov093  a4
 *   BTL_POKEPARAM_GetMon  0x021D5844  thumb  ov093
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   d_021F241C     0x021F241C  data  ov093  a4
 */
struct QQ;
struct Rat;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern u16 WAZA_TOOL_GetPower(void *p);
extern int BTL_EVENT_OverwriteVar(int key, u32 v);
extern int BTL_POKEPARAM_GetHpRatioFixed(struct Rat *p);
extern u32 BTL_CALC_MulRatioMin1(u32 a, u32 b);
extern void BTL_EVENT_MultiplyVar(int a, int b);
extern void *BTL_POKEPARAM_GetMon(void *m);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
void func_021E2988(void *a, void *b, int c);
int *func_021E29DC(int *p);
void func_021E29E8(int a, void *b, int c);
int *func_021E2A2C(int *p);
void func_021E2A38(int a, void *b, int c);
int *func_021E2A74(int *p);
void func_021E2A80(int u, void *p, int k);
u8 *func_021E2AC0(int *p);
extern int d_021F2564[];
extern int d_021F24AC[];
extern int d_021F244C[];
extern u8 d_021F241C[];


void func_021E2988(void *a, void *b, int c)
{
    void *m;
    u32 x;
    u32 y;
    u32 r;
    u32 t;

    if (c == BTL_EVENT_GetVar(3)) {
        m = func_021C7CF4(b, c);
        x = func_021D59B4(m, 0xD);
        y = func_021D59B4(m, 0xE);
        t = WAZA_TOOL_GetPower((void *)BTL_EVENT_GetFactorKey(a));
        r = t * x / y;
        if (r == 0)
            r = 1;
        BTL_EVENT_OverwriteVar(0x30, r);
    }
}


int *func_021E29DC(int *p)
{
    *p = 1;
    return d_021F2564;
}


void func_021E29E8(int a, void *b, int c)
{
    u32 r;

    if (c == BTL_EVENT_GetVar(3)) {
        r = BTL_CALC_MulRatioMin1(0x78, BTL_POKEPARAM_GetHpRatioFixed(func_021C7CF4(b, (u8)BTL_EVENT_GetVar(4)))) / 100;
        if (r == 0)
            r = 1;
        BTL_EVENT_OverwriteVar(0x30, r);
    }
}


int *func_021E2A2C(int *p)
{
    *p = 1;
    return d_021F24AC;
}


void func_021E2A38(int a, void *b, int c)
{
    if (c == BTL_EVENT_GetVar(3)) {
        if (BTL_POKEPARAM_GetHpRatioFixed(func_021C7CF4(b, (u8)BTL_EVENT_GetVar(4))) <= 0x32 << 12)
            BTL_EVENT_MultiplyVar(0x31, 4 << 11);
    }
}


int *func_021E2A74(int *p)
{
    *p = 1;
    return d_021F244C;
}


void func_021E2A80(int u, void *p, int k)
{
    u32 v;
    if (k == BTL_EVENT_GetVar(3)) {
        v = (u32)(POKE_TOOL_GetPartyValue(BTL_POKEPARAM_GetMon(func_021C7CF4(p, k)), 9, 0) * 10) / 25;
        if (v == 0)
            v = 1;
        BTL_EVENT_OverwriteVar(0x30, v);
    }
}


u8 *func_021E2AC0(int *p)
{
    *p = 1;
    return d_021F241C;
}
