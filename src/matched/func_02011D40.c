/*
 * function: func_02011D40
 * address:  0x02011D40
 * packet:   pkt_02010BB8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_020056A0   0x020056A0  thumb
 *   func_02011D34  0x02011D34  thumb
 *   g_02146248     0x02146248  data
 *
 * Allocates 0x7F bytes off heap 0 through sub_020056A0.c's allocator
 * wrapper, tagged with func_02011D34's own address (the SDK debug-tag
 * convention: the tag is the calling site, here literally the sibling
 * debug-marker function's address), discards the result, and bumps
 * g_02146248's +4 counter. See unit_02011D28.c's header for the sibling
 * func_02011D7C and the documented near miss on this increment.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02011D40.c \
 *       --func func_02011D40 --addr 0x02011D40 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

struct G02146248 {
    u32 unk00;
    u32 unk04;
};

extern void *sub_020056A0(u32 a, u32 b, u32 c);
extern void  func_02011D34(void);
extern struct G02146248 g_02146248;

void func_02011D40(void)
{
    sub_020056A0((u32)func_02011D34, 0, 0x7f);
    g_02146248.unk04 += 1;
}
