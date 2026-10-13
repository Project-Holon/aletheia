/*
 * file:     unit_021E1478.c
 * unit:     yes
 * function: func_021E1478, func_021E14B4, func_021E14C0, func_021E14D8
 * address:  0x021E1478
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
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   d_021F26EC     0x021F26EC  data   ov093  a4
 *   d_021F256C     0x021F256C  data   ov093  a4
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
void func_021E1478(int a, void *p, int id);
int *func_021E14B4(int *p);
void func_021E14C0(int a, int b, int c);
int *func_021E14D8(int *p);
/* 021E14C0  shape F1: gate on BTL_EVENT_GetVar(3) */
extern int d_021F26EC[];
extern int d_021F256C[];


void func_021E1478(int a, void *p, int id)
{
    int v;
    u16 w;
    u8 t;
    if (id == BTL_EVENT_GetVar(3)) {
        t = BTL_EVENT_GetVar(4);
        v = func_021D59B4(func_021C7CF4(p, t), 13);
        w = v / 2;
        if (w == 0) w = 1;
        BTL_EVENT_OverwriteVar(0x37, w);
    }
}


int *func_021E14B4(int *p)
{
    *p = 1;
    return d_021F26EC;
}


/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #3; adds r4, r2, #0; bl BTL_EVENT_GetVar; cmp r4, r0; bne loc_021E14D6; movs r0, #0x37; movs r1, #0x28; bl BTL_EVENT_OverwriteVar; pop {r4, pc}.
 */
void func_021E14C0(int a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(3))
        BTL_EVENT_OverwriteVar(0x37, 0x28);
}


int *func_021E14D8(int *p)
{
    *p = 1;
    return d_021F256C;
}
