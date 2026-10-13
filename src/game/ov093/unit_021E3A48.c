/*
 * file:     unit_021E3A48.c
 * unit:     yes
 * function: func_021E3A48, func_021E3A6C, func_021E3A78, func_021E3AC4, func_021E3AF0, func_021E3B08, func_021E3B14
 * address:  0x021E3A48
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
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021E3C5C  0x021E3C5C  thumb  ov093
 *   BTL_EVENT_RemoveFactor   0x021D7040  thumb
 *   d_021F2FC8     0x021F2FC8  data   ov093  a4
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetLastUsedMoveId  0x021D67A8  thumb  ov093
 *   d_021F284C     0x021F284C  data   a2
 *   d_021F2D58     0x021F2D58  data   ov093  a4
 */
struct S;
struct QL;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, unsigned int a);
extern void func_021C88C8(void *a, void *p);
extern void func_021E3C5C(void *a, int c, int d);
extern void *func_021C7CF4(int *p, int i);
extern u16 BTL_POKEPARAM_GetLastUsedMoveId(struct QL *p);
void func_021E3A48(int u, int a, int b);
int *func_021E3A6C(int *p);
void func_021E3A78(int u, void *a, int c, int *w);
void func_021E3AC4(int u, int a, int b, int *p);
void func_021E3AF0(int a, int b, int c);
int *func_021E3B08(int *p);
void func_021E3B14(int u, void *a, int c);
extern int d_021F2FC8[];
extern const u16 d_021F284C[];
extern int d_021F2D58[];



void func_021E3A48(int u, int a, int b)
{
    if (b == BTL_EVENT_GetVar(3)) {
        if (BTL_EVENT_GetVar(0x51) != 0)
            BTL_EVENT_OverwriteVar(0x3a, 2);
    }
}



int *func_021E3A6C(int *p)
{
    *p = 6;
    return d_021F2FC8;
}



void func_021E3A78(int u, void *a, int c, int *w)
{
    char *p;

    if (c == BTL_EVENT_GetVar(3)) {
        p = func_021C88A4(a, 4, c);
        func_021C8838(p + 4, 2, 0x1ff);
        func_021C8860((struct S *)(p + 4), c);
        func_021C88C8(a, p);
        w[6] = 1;
        func_021E3C5C(a, c, 0);
    }
}





void func_021E3AC4(int u, int a, int b, int *p)
{
    if (b == BTL_EVENT_GetVar(4)) {
        if (p[6] != 0) {
            if (BTL_EVENT_GetVar(0x51) != 0)
                BTL_EVENT_OverwriteVar(0x3a, 1);
        }
    }
}




/* 021E3AF0  shape F3: gate on BTL_EVENT_GetVar(2) then BTL_EVENT_RemoveFactor */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r3, r4, r5, lr}; adds r5, r0, #0; movs r0, #2; adds r4, r2, #0; bl BTL_EVENT_GetVar; cmp r4, r0; bne loc_021E3B06; adds r0, r5, #0; bl BTL_EVENT_RemoveFactor; pop {r3, r4, r5, pc}.
 */
void func_021E3AF0(int a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(2))
        BTL_EVENT_RemoveFactor(a);
}


int *func_021E3B08(int *p)
{
    *p = 4;
    return d_021F2D58;
}


void func_021E3B14(int u, void *a, int c)
{
    unsigned i;
    int r;
    u8 *p;

    if (c == BTL_EVENT_GetVar(3)) {
        r = BTL_POKEPARAM_GetLastUsedMoveId(func_021C7CF4(a, c));
        for (i = 0; i < 5; i++) {
            if (r == d_021F284C[i])
                return;
        }
        p = func_021C88A4(a, 0x26, c);
        p[4] = c;
        p[5] = 3;
        p[6] = 0;
        func_021C88C8(a, p);
    }
}
