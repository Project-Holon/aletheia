/*
 * file:     unit_021E8270.c
 * unit:     yes
 * function: func_021E8270, func_021E82A0, func_021E82AC, func_021E8304, func_021E8310
 * address:  0x021E8270
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
 *   func_0689D0C8  0x0689D0C8  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   func_021C8288  0x021C8288  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F2814     0x021F2814  data   ov093  a4
 *   func_021C812C  0x021C812C  thumb  ov093
 *   func_021C8138  0x021C8138  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   func_021C83DC  0x021C83DC  thumb  ov093
 *   d_021F27E4     0x021F27E4  data   ov093  a4
 */
struct QQ;
struct S;
struct Q7;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern int func_021C8288(u8 *p);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);
extern u8 *func_021C812C(u8 *p);
extern u16 func_021C8138(struct Q7 *p);
extern int func_0689D0C8(int a, int b);
extern void BTL_EVENT_MultiplyVar(int a, int b);
extern void func_021C83DC(char *p, int x);
void func_021E8270(int a, void *b, int c);
int *func_021E82A0(int *p);
void func_021E82AC(void *a, void *b, int c);
int *func_021E8304(int *p);
void func_021E8310(void *a, void *b, int c);
extern int d_021F2814[];
extern int d_021F27E4[];


void func_021E8270(int a, void *b, int c)
{
    int v;

    if (c == BTL_EVENT_GetVar(3) && func_021C8288(b) == 1) {
        v = BTL_EVENT_GetVar(0x20);
        if (v == 1)
            v++;
        BTL_EVENT_OverwriteVar(0x20, v);
    }
}


int *func_021E82A0(int *p)
{
    *p = 1;
    return d_021F2814;
}


void func_021E82AC(void *a, void *b, int c)
{
    u8 *p;
    int v;

    if (c == BTL_EVENT_GetVar(3)) {
        if (BTL_EVENT_GetFactorKey(a) == 0x229)
            v = 0x35f;
        else
            v = 0x362;
        p = func_021C88A4(b, 4, c);
        func_021C8838(p + 4, 2, (u16)v);
        func_021C8860((struct S *)(p + 4), c);
        func_021C88C8(b, p);
    }
}


int *func_021E8304(int *p)
{
    *p = 1;
    return d_021F27E4;
}


void func_021E8310(void *a, void *b, int c)
{
    int m;
    int t;

    if (c == BTL_EVENT_GetVar(3)) {
        m = (int)func_021C812C(b);
        switch (BTL_EVENT_GetFactorKey(a)) {
        case 0x22e:
            t = 0x22f;
            break;
        case 0x22f:
            t = 0x22e;
            break;
        default:
            t = 0;
            break;
        }
        if (t != 0 && t == func_0689D0C8(m, func_021C8138(b))) {
            BTL_EVENT_MultiplyVar(0x31, 0x2000);
            func_021C83DC(b, 1);
        }
    }
}
