/*
 * file:     unit_021D93D8_p01.c
 * unit:     yes
 * function: func_021D9418, func_021D9460
 * address:  0x021D9418
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
 *   func_021D9648  0x021D9648  thumb  ov093
 *   func_021D96DC  0x021D96DC  thumb  ov093
 *   func_021D96FC  0x021D96FC  thumb  ov093
 *   func_021D76BC   0x021D76BC  thumb
 *   func_021D775C   0x021D775C  thumb
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D9648(int, int, int);
extern void func_021D96DC(int, int, int);
extern void func_021D96FC(void *a, int b, int c);
void func_021D9418(int a, int b, int c, int *out);
void func_021D9440(int a, int b, int c);
void func_021D9450(int a, int b, int c);
/* 021D9460 shape F1: gate on func_021D775C(2) */ void func_021D9460(int a, int b, int c);


void func_021D9418(int a, int b, int c, int *out)
{
    int r;

    r = func_021D9648(b, c, 2);
    *out = r;
    if (r == 0)
        *out = func_021D9648(b, c, 0xe);
}


void func_021D9440(int a, int b, int c)
{
    func_021D96DC(b, c, 2);
}


void func_021D9450(int a, int b, int c)
{
    func_021D96FC((void *)b, c, 2);
}


/* 021D9460  shape F1: gate on func_021D775C(2) */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #2; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021D9476; movs r0, #0x41; movs r1, #1; bl func_021D76BC; pop {r4, pc}.
 */
void func_021D9460(int a, int b, int c)
{
    if (c == func_021D775C(2))
        func_021D76BC(0x41, 1);
}
