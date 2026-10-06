/*
 * function: func_02022D78
 * address:  0x02022D78
 * packet:   pkt_02022D70
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker func_02029488.c is now a manifest entry (matched class)
 *
 * Releases the object the node's first word points at and clears the slot.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02022D78.c \
 *       --func func_02022D78 --addr 0x02022D78 --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 func_020307B0(void *p);

void func_02022D78(u8 *p)
{
    func_020307B0(*(void **)p);
    *(u32 *)p = 0;
}
