/*
 * file:     unit_021D93D8_p03.c
 * unit:     yes
 * function: func_021D96CC, func_021D96DC
 * address:  0x021D96CC
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
 *   func_021D9670   0x021D9670  thumb
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D96FC 0x021D96FC thumb ov093
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int);
extern void func_021D96FC(void *a, int b, int c);
/* 021D96CC stack-arg wrapper: func_021D9670(a, b, c, d, 0xd2) */ void func_021D96CC(int a, int b, int c, int d);
void func_021D96DC(int a,int b,int c);


/* 021D96CC  stack-arg wrapper: func_021D9670(a, b, c, d, 0xd2) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #0xd2; str r4, [sp]; bl func_021D9670; add sp, #4; pop {r3, r4, pc}.
 */
void func_021D96CC(int a, int b, int c, int d) { func_021D9670(a, b, c, d, 0xd2); }

void func_021D96DC(int a,int b,int c) { if(b==func_021D775C(2)) func_021D96FC((void *)a,b,c); }
