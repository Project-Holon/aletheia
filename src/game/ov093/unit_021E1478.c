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
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   d_021F26EC     0x021F26EC  data   ov093  a4
 *   d_021F256C     0x021F256C  data   ov093  a4
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern int func_021D76BC(int key, u32 val);
void func_021E1478(int a, void *p, int id);
int *func_021E14B4(int *p);
void func_021E14C0(int a, int b, int c);
int *func_021E14D8(int *p);
/* 021E14C0  shape F1: gate on func_021D775C(3) */
extern int d_021F26EC[];
extern int d_021F256C[];


void func_021E1478(int a, void *p, int id)
{
    int v;
    u16 w;
    u8 t;
    if (id == func_021D775C(3)) {
        t = func_021D775C(4);
        v = func_021D59B4(func_021C7CF4(p, t), 13);
        w = v / 2;
        if (w == 0) w = 1;
        func_021D76BC(0x37, w);
    }
}


int *func_021E14B4(int *p)
{
    *p = 1;
    return d_021F26EC;
}


/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #3; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021E14D6; movs r0, #0x37; movs r1, #0x28; bl func_021D76BC; pop {r4, pc}.
 */
void func_021E14C0(int a, int b, int c)
{
    if (c == func_021D775C(3))
        func_021D76BC(0x37, 0x28);
}


int *func_021E14D8(int *p)
{
    *p = 1;
    return d_021F256C;
}
