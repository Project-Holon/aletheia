/*
 * file:     btl_server_p115.c
 * unit:     yes
 * function: func_021CBF60, func_021CBF70, func_021CBF80
 * address:  0x021CBF60
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
 *   func_021CC350   0x021CC350  thumb
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

/* 021CBF60 stack-arg wrapper: func_021CC350(a, b, c, d, 0x3) */ void func_021CBF60(int a, int b, int c, int d);
/* 021CBF70 stack-arg wrapper: func_021CC350(a, b, c, d, 0x1) */ void func_021CBF70(int a, int b, int c, int d);
/* 021CBF80 stack-arg wrapper: func_021CC350(a, b, c, d, 0x6) */ void func_021CBF80(int a, int b, int c, int d);


/* 021CBF60  stack-arg wrapper: func_021CC350(a, b, c, d, 0x3) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #3; str r4, [sp]; bl func_021CC350; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CBF60(int a, int b, int c, int d) { func_021CC350(a, b, c, d, 0x3); }


/* 021CBF70  stack-arg wrapper: func_021CC350(a, b, c, d, 0x1) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #1; str r4, [sp]; bl func_021CC350; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CBF70(int a, int b, int c, int d) { func_021CC350(a, b, c, d, 0x1); }


/* 021CBF80  stack-arg wrapper: func_021CC350(a, b, c, d, 0x6) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #6; str r4, [sp]; bl func_021CC350; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CBF80(int a, int b, int c, int d) { func_021CC350(a, b, c, d, 0x6); }
