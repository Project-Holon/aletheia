/*
 * function: func_02013C70
 * address:  0x02013C70
 * packet:   pkt_02013C70
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  data_table - 0x0209E010 is named in the image only by the
 *           pool word inside this eight-byte range, so the `literal`
 *           class has no outside witness and no cut moves one there.
 *           Same finding as src/matched/unit_02013C10.c's header.
 *
 * symbols:
 *   tbl_0209E010  0x0209E010  data
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02013C70.c \
 *       --func func_02013C70 --addr 0x02013C70 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern u8   tbl_0209E010[];
extern void func_02013B10(u32 a, u8 *p, u32 b);

void func_02013C70(u32 a)
{
    func_02013B10(a, tbl_0209E010, 0xb);
}
