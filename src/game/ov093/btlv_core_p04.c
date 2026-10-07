/*
 * file:     btlv_core_p04.c
 * unit:     yes
 * function: func_021E8CE0, func_021E8CF0, func_021E8CFC
 * address:  0x021E8CE0
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

/* 021E8CE0 ((a & 0xff) << 8) | (b & 0xff) as u16 */ u16 func_021E8CE0(u32 a, u32 b);
int func_021E8CF0(int a);
/* 021E8CFC asrs r0,r0,#8; lsls #0x18; lsrs #0x18 */ u8 func_021E8CFC(s32 v);


/* 021E8CE0  ((a & 0xff) << 8) | (b & 0xff) as u16 */
/*
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: lsls r0, r0, #0x18; lsrs r2, r0, #0x10; lsls r0, r1, #0x18; lsrs r0, r0, #0x18; orrs r0, r2; lsls r0, r0, #0x10; lsrs r0, r0, #0x10; bx lr.
 */
u16 func_021E8CE0(u32 a, u32 b) { return (u16)(((a & 0xff) << 8) | (b & 0xff)); }


int func_021E8CF0(int a)
{
    return func_021E8CE0(a, a);
}


/* 021E8CFC  asrs r0,r0,#8; lsls #0x18; lsrs #0x18 */
/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: asrs r0, r0, #8; lsls r0, r0, #0x18; lsrs r0, r0, #0x18; bx lr.
 */
u8 func_021E8CFC(s32 v) { return (u8)(v >> 8); }
