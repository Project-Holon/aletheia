/*
 * unit:     yes
 * function: func_02049DB4, func_02049DF4, func_02049E34, func_02049E74, func_02049EB4, func_02049EF4, func_02049F34, func_02049F78, func_02049FBC, func_02049FFC
 * address:  0x02049DB4
 * packet:   pkt_02049B90
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cell-actor binding helpers.  Each binds an actor of a given kind through
 * func_0204A1BC (kind table 1, 5-argument form) or func_0204A380 (kind
 * table 2, wrapper over func_0204A39C), runs the per-kind hook, and releases
 * the actor again when the hook fails.  func_02049F34 / func_02049F78 are
 * the 4-argument forms and pass 0 as the third argument.
 *
 * symbols:
 *   func_0204A1BC  0x0204A1BC  arm
 *   func_0204A380  0x0204A380  arm
 *   func_02062820  0x02062820  arm
 *   func_02062A00  0x02062A00  arm
 *   func_02062A4C  0x02062A4C  arm
 *   func_02062A98  0x02062A98  arm
 *   func_02062B30  0x02062B30  arm
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0204A1BC(u32 a0, u32 a1, u32 a2, u32 a3);
extern void *func_0204A380(u32 a0, u32 a1, u32 a2, u32 a3);
extern int   func_02062820(void *ptr, u32 val);
extern int   func_02062A00(void *ptr, u32 val);
extern int   func_02062A4C(void *ptr, u32 val);
extern int   func_02062A98(void *ptr, u32 val);
extern int   func_02062B30(void *ptr, u32 val);
extern void  func_020307B0(void *ptr);

void *func_02049DB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = func_0204A1BC(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_02062A4C(res, a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}

void *func_02049DF4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = func_0204A380(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_02062A4C(res, a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}

void *func_02049E34(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = func_0204A1BC(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_02062A00(res, a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}

void *func_02049E74(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = func_0204A380(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_02062A00(res, a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}

void *func_02049EB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = func_0204A1BC(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_02062B30(res, a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}

void *func_02049EF4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = func_0204A380(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_02062B30(res, a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}

void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3)
{
    void *res = func_0204A1BC(a0, a1, 0, a3);
    if (res != 0) {
        if (!func_02062A98(res, a2)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}

void *func_02049F78(u32 a0, u32 a1, u32 a2, u32 a3)
{
    void *res = func_0204A380(a0, a1, 0, a3);
    if (res != 0) {
        if (!func_02062A98(res, a2)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}

void *func_02049FBC(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = func_0204A1BC(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_02062820(res, a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}

void *func_02049FFC(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = func_0204A380(a0, a1, a2, a4);
    if (res != 0) {
        if (!func_02062820(res, a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}
