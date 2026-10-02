/*
 * function: func_02014184
 * address:  0x02014184
 * packet:   pkt_02014184
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Fills a 0x1C-byte record: live flag 1, id, slot -1, count, two cleared
 * fields and three caller words.  Filed as the call witness for the ov021
 * script dispatcher 0x021CA5C4.  The slot field is s16: -1 is then derived
 * from the live flag's 1 (`subs r1, r4, #2`); a u16 field loads 0xFFFF from
 * the pool.
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct {
    u32 live;
    u16 id;
    s16 slot;
    s16 count;
    u16 pad;
    u32 zero;
    u32 a;
    u32 b;
    u32 c;
} Rec1C;

void func_02014184(Rec1C *r, u16 id, s16 count, u32 a, u32 b, u32 c)
{
    r->live = 1;
    r->id = id;
    r->slot = -1;
    r->count = count;
    r->pad = 0;
    r->zero = 0;
    r->a = a;
    r->b = b;
    r->c = c;
}
