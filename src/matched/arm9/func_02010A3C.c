/*
 * function: func_02010A3C
 * address:  0x02010A3C
 * packet:   pkt_0201058C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status: EXACT*
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010A3C.c \
 *       --func func_02010A3C --addr 0x02010A3C --thumb --cc 1.1p1
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern unsigned int func_02039CB4(struct Link *p, unsigned int lo, unsigned int hi);
extern void func_02010888(u8 *p, u32 v);

void func_02010A3C(u8 *p)
{
    if (func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x74, 8) != 0) {
        func_02010888(p, 0);
    }
}
