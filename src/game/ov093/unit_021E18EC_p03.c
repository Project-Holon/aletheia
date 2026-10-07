/*
 * file:     unit_021E18EC_p03.c
 * unit:     yes
 * function: func_021E19C0, func_021E19D0, func_021E19E0
 * address:  0x021E19C0
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
 *   func_021E19F8   0x021E19F8  thumb
 *   func_021E1A2C   0x021E1A2C  thumb
 *   func_021E1AA4   0x021E1AA4  thumb  ov093
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { u32 f0; u8 pad[60]; } E64;

/* 021E19C0 shifted 4-arg wrapper -> func_021E19F8(..., 0x0) */ void func_021E19C0(int a, int b, int c, int d);
/* 021E19D0 shifted 4-arg wrapper -> func_021E1A2C(..., 0x0) */ void func_021E19D0(int a, int b, int c, int d);
void func_021E19E0(int a, int b, int c, int d);


/* 021E19C0  shifted 4-arg wrapper -> func_021E19F8(..., 0x0) */
void func_021E19C0(int a, int b, int c, int d)
{
    func_021E19F8(b, c, d, 0x0);
}


/* 021E19D0  shifted 4-arg wrapper -> func_021E1A2C(..., 0x0) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; adds r0, r1, #0; adds r1, r2, #0; adds r2, r3, #0; movs r3, #0; bl func_021E1A2C; pop {r3, pc}.
 */
void func_021E19D0(int a, int b, int c, int d)
{
    func_021E1A2C(b, c, d, 0x0);
}


/*
 * Wrapper family member; the body is the hand-checked shape of the family's first instance with only the member's constants substituted, per the family uniformity assertion in o36/report.md.
 */
void func_021E19E0(int a, int b, int c, int d) { func_021E1AA4(b, c, d, 0, 6 << 10); }
