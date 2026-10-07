/*
 * file:     unit_021BF050_p29.c
 * unit:     yes
 * function: func_021C27DC, func_021C27E0, func_021C27E8, func_021C27F8
 * address:  0x021C27DC
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203EFC8  0x0203EFC8  arm
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

typedef struct {
    char pad[0x17];
    u8 f17;
} S_021C27DC;

typedef struct {
    char pad[0x1B];
    u8 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1;
} S_021C27E0;

typedef struct {
    char pad[0x1B];
    u8 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1;
} S_021C27E8;

extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
void func_021C27DC(S_021C27DC *s, u8 v);
int func_021C27E0(S_021C27E0 *s);
void func_021C27E8(S_021C27E8 *s, u8 v);
BOOL func_021C27F8(char *p, char *q);


/*
 * Byte setter at +0x17, the pair of func_021C27D8.
 */
void func_021C27DC(S_021C27DC *s, u8 v)
{
    s->f17 = v;
}


/*
 * One-bit field at bit 1 of the byte at +0x1B: an `unsigned char` bitfield
 * container, which is why the read is `ldrb` + `lsls #0x1e` + `lsrs #0x1f`.
 */
int func_021C27E0(S_021C27E0 *s)
{
    return s->b1;
}


void func_021C27E8(S_021C27E8 *s, u8 v)
{
    s->b1 = v;
}


/*
 * True when the arm9 comparison of the two blocks, 0x0E and 8 bytes in, answers 0.
 */
BOOL func_021C27F8(char *p, char *q)
{
    if (func_0203EFC8((const u8 *)(p + 0xE), (const u8 *)(q + 8), 6) == 0) {
        return 1;
    }

    return 0;
}
