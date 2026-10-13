/*
 * file:     unit_021E2ED4.c
 * unit:     yes
 * function: func_021E2ED4, func_021E2F48, func_021E2FB0, func_021E2FDC, func_021E2FE8, func_021E300C
 * address:  0x021E2ED4
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
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   func_021C83A0  0x021C83A0  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   d_021F2A18     0x021F2A18  data  ov093  a4
 *   func_021C8288  0x021C8288  thumb  ov093
 *   func_021C83DC  0x021C83DC  thumb  ov093
 *   BTL_POKEPARAM_TestContFlag  0x021D5BDC  thumb  ov093
 *   BTLV_CORE_EventScaleDamage  0x021E8860  thumb  ov093
 *   data_021F2464  0x021F2464  data   ov093  a4
 *   d_021F2A28     0x021F2A28  data   ov093  a4
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
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern u32 func_021C83A0(u8 *p, int i);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern int func_021C8288(u8 *p);
extern void func_021C83DC(char *p, int x);
extern int BTL_POKEPARAM_TestContFlag(struct UtilWork *p, u32 n);
extern void BTLV_CORE_EventScaleDamage(int n);
void func_021E2ED4(int u, void *p, int k);
u8 *func_021E2F3C(int *p);
void func_021E2F48(int u, void *p, int key);
void func_021E2FB0(int u, void *a, int b);
int *func_021E2FDC(int *p);
void func_021E2FE8(int u, int a, int b);
void func_021E300C(int u, void *p, int key);
u8 *func_021E3044(u32 *out);
extern u8 d_021F2A18[];
extern u8 data_021F2464[];
extern int d_021F2A28[];




void func_021E2ED4(int u, void *p, int k)
{
    u32 n;
    int v;
    if (k == BTL_EVENT_GetVar(3)) {
        n = func_021C83A0(p, BTL_POKEPARAM_GetPokeId(func_021C7CF4(p, (u8)BTL_EVENT_GetVar(4))));
        if (n >= 2000) {
            v = 0x78;
        } else if (n >= 1000) {
            v = 100;
        } else if (n >= 500) {
            v = 80;
        } else if (n >= 250) {
            v = 60;
        } else {
            v = 40;
            if (n < 100)
                v = 20;
        }
        BTL_EVENT_OverwriteVar(0x30, v);
    }
}




u8 *func_021E2F3C(int *p)
{
    *p = 2;
    return d_021F2A18;
}




void func_021E2F48(int u, void *p, int key)
{
    int two = 2;
    if (key == BTL_EVENT_GetVar(two)) {
        int s = func_021C8288(p);
        u8 v = BTL_EVENT_GetVar(0x16);
        int r = 0;
        switch (s) {
        case 1: v = 9; r = 1; break;
        case 2: v = 10; r = 4; break;
        case 4: v = 5; r = 3; break;
        case 3: v = 14; r = two; break;
        }
        BTL_EVENT_OverwriteVar(0x16, v);
        func_021C83DC(p, r);
    }
}



void func_021E2FB0(int u, void *a, int b)
{
    if (b == BTL_EVENT_GetVar(3)) {
        if (func_021C8288(a) != 0)
            BTL_EVENT_OverwriteVar(0x30, BTL_EVENT_GetVar(0x30) * 2);
    }
}


int *func_021E2FDC(int *p)
{
    *p = 2;
    return d_021F2A28;
}


void func_021E2FE8(int u, int a, int b)
{
    if (b == BTL_EVENT_GetVar(3)) {
        if (BTL_EVENT_GetVar(0x21) == 3)
            BTL_EVENT_OverwriteVar(0x42, 0);
    }
}



void func_021E300C(int u, void *p, int key)
{
    int k = 3;
    if (key == BTL_EVENT_GetVar(k)) {
        if (BTL_POKEPARAM_TestContFlag(func_021C7CF4(p, (u8)BTL_EVENT_GetVar(4)), k) != 0)
            BTLV_CORE_EventScaleDamage(2);
    }
}



u8 *func_021E3044(u32 *out)
{
    *out = 1;
    return data_021F2464;
}
