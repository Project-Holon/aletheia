/*
 * file:     unit_021BA594_p03.c
 * unit:     yes
 * function: func_021BA764, func_021BA770
 * address:  0x021BA764
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32;

typedef signed short   s16;

typedef int BOOL;

typedef struct {
    u32 f00, f04;
} T;

typedef struct {
    char pad[0x0C];
    u16 *table;
} Q;

typedef signed char    s8;

typedef signed long    s32;

typedef struct {
    char pad[8];
    u8 f08;
    char pad2[3];
    u8 f0C;
    u8 f0D;
    u16 f0E;
    u8 f10;
} S;

u16 *func_021BA764(T *t, int i);
void func_021BA770(S *s);


/*
 * Halfword pointer one past index i in the table whose address the word at
 * +0xC of the second word of t holds.  The index is scaled after the +1,
 * which is why the listing is `adds r0, r1, #1; lsls r0, r0, #1`.
 */
u16 *func_021BA764(T *t, int i)
{
    Q *q = (Q *)*(u32 **)&t->f04;

    return (u16 *)((u8 *)q->table + (i + 1) * 2);
}


/*
 * Sets bit f0C of the byte at +0x08, then clears the four fields from +0x0C.
 */
void func_021BA770(S *s)
{
    s->f08 = (u8)(s->f08 | (u8)(1 << s->f0C));
    s->f0C = 0;
    s->f0D = 0;
    s->f0E = 0;
    s->f10 = 0;
}
