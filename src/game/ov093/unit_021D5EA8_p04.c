/*
 * file:     unit_021D5EA8_p04.c
 * unit:     yes
 * function: func_021D6314, func_021D631C
 * address:  0x021D6314
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

/* 021D6314 lsls r1,#2; adds r0,r0,r1; ldr r0,[r0,#0x1c] */ u32 func_021D6314(u8 *p, int i);
/* 021D631C adds r0,r0,r1; adds r0,#0xac; ldrb r0,[r0] */ u8 func_021D631C(u8 *p, int i);


/* 021D6314  lsls r1,#2; adds r0,r0,r1; ldr r0,[r0,#0x1c] */
/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: lsls r1, r1, #2; adds r0, r0, r1; ldr r0, [r0, #0x1c]; bx lr.
 */
u32 func_021D6314(u8 *p, int i) { return *(u32 *)(p + i * 4 + 0x1c); }


/* 021D631C  adds r0,r0,r1; adds r0,#0xac; ldrb r0,[r0] */
/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: adds r0, r0, r1; adds r0, #0xac; ldrb r0, [r0]; bx lr.
 */
u8 func_021D631C(u8 *p, int i) { return *(u8 *)(p + i + 0xac); }
