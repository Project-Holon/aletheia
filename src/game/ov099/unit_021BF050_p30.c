/*
 * file:     unit_021BF050_p30.c
 * unit:     yes
 * function: func_021C2850, func_021C285C, func_021C2864
 * address:  0x021C2850
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
 *   func_02087C6C 0x02087C6C arm
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32;

typedef signed short   s16;

typedef int BOOL;

typedef struct {
    char pad[0x1B];
    u8 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1;
} S;

typedef signed char    s8;

typedef signed long    s32;

extern void func_02087C6C(void *);
void func_021C2850(char *p);
int func_021C285C(S *s);
void func_021C2864(S *s, u8 v);

void func_021C2850(char *p) { func_02087C6C(p + 0xe); }


/*
 * One-bit field at bit 4 of the byte at +0x1B (`lsls #0x1b; lsrs #0x1f`).
 */
int func_021C285C(S *s)
{
    return s->b4;
}


/*
 * One-bit field at bit 4 of the byte at +0x1B, from a byte argument.
 */
void func_021C2864(S *s, u8 v)
{
    s->b4 = v;
}
