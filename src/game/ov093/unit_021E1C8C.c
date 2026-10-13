/*
 * file:     unit_021E1C8C.c
 * unit:     yes
 * function: func_021E1C8C, func_021E1D14, func_021E1D20, func_021E1D78, func_021E1D9C, func_021E1DC0, func_021E1DCC, func_021E1DF4, func_021E1E10, func_021E1E38
 * address:  0x021E1C8C
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
 *   BTL_POKEPARAM_TestTurnFlag  0x021D5BB0  thumb  ov093
 *   func_021C804C  0x021C804C  thumb  ov093
 *   BTL_ACTION_GetFightMove  0x021D8340  thumb  ov093
 *   WAZA_TOOL_IsDamaging  0x0201C314  thumb
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_021C8010  0x021C8010  thumb  ov093
 *   func_021C8290  0x021C8290  thumb  ov093
 *   func_021C831C  0x021C831C  thumb  ov093
 *   func_021C830C  0x021C830C  thumb  ov093
 *   BTLV_CORE_EventScaleDamage  0x021E8860  thumb  ov093
 *   d_021F2C48     0x021F2C48  data   ov093  a4
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   d_021F2C60     0x021F2C60  data   ov093  a4
 *   d_021F24FC     0x021F24FC  data   ov093  a4
 */
struct UtilWork;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
extern int BTL_POKEPARAM_TestTurnFlag(struct UtilWork *p, u32 n);
extern int func_021C804C(int a, int b, u32 *out);
extern u32 BTL_ACTION_GetFightMove(u32 *m);
extern u32 WAZA_TOOL_IsDamaging(void *p);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern void func_021C8838(void *p, int a, int b);
extern int func_021B9A24(unsigned int a, unsigned int b);
extern int func_021C8010(u8 *p, unsigned int v);
extern int func_021C8290(u8 *p, int a, int b, void *item);
extern void func_021C831C(u8 *p, int v);
extern unsigned int func_021C830C(u8 *p);
extern void BTLV_CORE_EventScaleDamage(int a);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C88B4(void *a, int k, int b);
void func_021E1C8C(int u, int a, int b);
int *func_021E1D14(int *p);
void func_021E1D20(int u, int a, int b);
void func_021E1D78(int a, void *b, int c);
void func_021E1D9C(int u, void *a, int b);
int *func_021E1DC0(int *p);
void func_021E1DCC(int u, int a, int b);
void func_021E1DF4(int u, void *a, int b);
void func_021E1E10(int u, int a, int b);
int *func_021E1E38(int *p);
extern int d_021F2C48[];
extern int d_021F2C60[];
extern int d_021F24FC[];



/*
 * The 12-byte tail (movs r1,#3; str r1,[r0]; ldr r0,[pc]; bx lr; .word) is an
 * unlabelled follower stub, not part of this function.
 * Lever: q = func_021C7CF4(...) bound to a local before `ok = 0` keeps the
 * `movs r4, #0` between the argument setup and the BTL_POKEPARAM_TestTurnFlag call.
 */
void func_021E1C8C(int u, int a, int b)
{
    u32 buf;
    u8 k;
    int ok;
    void *q;
    u32 m;

    if (b == BTL_EVENT_GetVar(3)) {
        k = BTL_EVENT_GetVar(4);
        q = func_021C7CF4((int *)a, k);
        ok = 0;
        if (BTL_POKEPARAM_TestTurnFlag(q, 3) == 0) {
            if (func_021C804C(a, k, &buf) != 0 && (m = BTL_ACTION_GetFightMove(&buf)) != 0 && WAZA_TOOL_IsDamaging((void *)m) != 0)
                ok = 1;
        }
        if (ok == 0) {
            if ((m = BTL_ACTION_GetFightMove(&buf)) == 0 || WAZA_TOOL_IsDamaging((void *)m) == 0) {
                if (BTL_EVENT_OverwriteVar(0x40, 1) != 0)
                    func_021C8838((void *)BTL_EVENT_GetVar(0x3f), 1, 0x47);
            }
        }
    }
}



int *func_021E1D14(int *p)
{
    *p = 3;
    return d_021F2C48;
}



void func_021E1D20(int u, int a, int b)
{
    u32 x;
    u8 k;

    if (func_021C804C(a, b, &x) != 0) {
        k = BTL_EVENT_GetVar(6);
        if (func_021B9A24(k, b) == 0) {
            func_021C8010((u8 *)a, k);
            func_021C8010((u8 *)a, b);
            if (func_021C8290((u8 *)a, b, k, 0) == 0)
                func_021C831C((u8 *)a, b);
        }
    }
}





void func_021E1D78(int a, void *b, int c)
{
    if (c == BTL_EVENT_GetVar(3) && func_021C830C(b))
        BTL_EVENT_OverwriteVar(81, 1);
}




void func_021E1D9C(int u, void *a, int b)
{
    if (b == BTL_EVENT_GetVar(3)) {
        if (func_021C830C(a) != 0)
            BTLV_CORE_EventScaleDamage(2);
    }
}


int *func_021E1DC0(int *p)
{
    *p = 3;
    return d_021F2C60;
}


void func_021E1DCC(int u, int a, int b)
{
    u8 *s;

    if (b == BTL_EVENT_GetVar(3)) {
        s = func_021C88A4((char *)a, 0x13, b);
        s[4] = b;
        func_021C88C8((void *)a, s);
    }
}




void func_021E1DF4(int u, void *a, int b)
{
    if (b == BTL_EVENT_GetVar(2))
        func_021C88B4(a, 0x3b, b);
}




void func_021E1E10(int u, int a, int b)
{
    u8 *s;

    if (b == BTL_EVENT_GetVar(2)) {
        s = func_021C88A4((char *)a, 0x13, b);
        s[4] = b;
        func_021C88C8((void *)a, s);
    }
}


int *func_021E1E38(int *p)
{
    *p = 1;
    return d_021F24FC;
}
