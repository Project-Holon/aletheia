/*
 * function: func_021BA764
 * address:  0x021BA764
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Halfword pointer one past index i in the table whose address the word at
 * +0xC of the second word of t holds.  The index is scaled after the +1,
 * which is why the listing is `adds r0, r1, #1; lsls r0, r0, #1`.
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

u16 *func_021BA764(T *t, int i)
{
    Q *q = (Q *)*(u32 **)&t->f04;

    return (u16 *)((u8 *)q->table + (i + 1) * 2);
}
