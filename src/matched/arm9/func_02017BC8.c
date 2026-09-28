/*
 * function: func_02017BC8
 * address:  0x02017BC8
 * packet:   pkt_020179B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Three "rows" of a dialog/UI record: for each row index below 3, read the
 * three fields at +0x37/+0x3B/+0x3F and write the copies back at
 * +0x36/+0x3A/+0x3E (the field before each), then clear the three
 * single-byte fields at 0x39/0x3D/0x41.
 *
 * The loop counter is the function's own second parameter -- there is no
 * initialiser, the entry test is `cmp r4, #3 / bhs` straight off the
 * argument, and the back edge is `cmp r4, #3 / blo`, so the source is
 * `for (; i < 3; i++)` over an unsigned i, not a local counter.
 *
 * The u16/u8 shift pairs are the destination widths of the three temporaries
 * (`lsls #16 / lsrs #16` versus `lsls #24 / lsrs #24` for a u8), which is
 * what fixes the return type of sub_02017E1C as wider than both.  The first
 * temporary is live across the other two reads and spills to the `push`
 * home area (`str r0, [sp]` / `ldr r2, [sp]`), which is why r3 is in the
 * push list without being read anywhere.
 *
 * EXACT*: the listing extent runs to 136 bytes because the follower at
 * 0x02017C50 saves no lr and carries no label.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02017BC8.c \
 *       --func func_02017BC8 --addr 0x02017BC8 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 sub_02017E1C(u8 *p, u32 idx, u32 def);
extern void sub_02017E40(u8 *p, u32 idx, u32 val);

void func_02017BC8(u8 *p, u32 i)
{
    for (; i < 3; i++) {
        u16 a = sub_02017E1C(p, i + 0x37, 0);
        u8  b = sub_02017E1C(p, i + 0x3b, 0);
        u8  c = sub_02017E1C(p, i + 0x3f, 0);

        sub_02017E40(p, i + 0x36, a);
        sub_02017E40(p, i + 0x3a, b);
        sub_02017E40(p, i + 0x3e, c);
    }
    sub_02017E40(p, 0x39, 0);
    sub_02017E40(p, 0x3d, 0);
    sub_02017E40(p, 0x41, 0);
}
