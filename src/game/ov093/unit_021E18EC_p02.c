/*
 * file:     unit_021E18EC_p02.c
 * unit:     yes
 * function: func_021E198C, func_021E199C
 * address:  0x021E198C
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

/* 021E198C shifted 4-arg wrapper -> func_021E1A2C(..., 0x2) */ void func_021E198C(int a, int b, int c, int d);
void func_021E199C(int a, int b, int c, int d);


/* 021E198C  shifted 4-arg wrapper -> func_021E1A2C(..., 0x2) */
void func_021E198C(int a, int b, int c, int d)
{
    func_021E1A2C(b, c, d, 0x2);
}


/*
 * Wrapper family member; the body is the hand-checked shape of the family's first instance with only the member's constants substituted, per the family uniformity assertion in o36/report.md.
 */
void func_021E199C(int a, int b, int c, int d) { func_021E1AA4(b, c, d, 2, 2 << 12); }
