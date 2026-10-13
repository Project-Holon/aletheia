/*
 * function: GFL_NET_QUEUE_RemoveNext
 * address:  0x020369F8
 * packet:   pkt_020369F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * blocker:  str_020A79EC (string) -- no witness outside 020369F8..02036A50;
 *           the file string at 0x020A79C4 is not NUL-terminated immediately
 *           before this message, so the `string` class refuses. Every concrete
 *           byte of the body reproduces.
 * symbols:
 *   str_020A79C4  0x020A79C4  data
 *   str_020A79EC  0x020A79EC  data
 *   func_02034714 0x02034714  arm
 *   GFL_NET_QUEUE_PopList 0x020366FC  arm
 */
#include "../include/Obj11349.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern const u8 str_020A79C4[];
extern const u8 str_020A79EC[];
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 GFL_NET_QUEUE_PopList(u32 *p);

void GFL_NET_QUEUE_RemoveNext(u8 *p)
{
    if (((struct Obj11349 *)p)->f10 != 0) {
        ((struct Obj11349 *)p)->f10 = 0;
        return;
    }
    if (GFL_NET_QUEUE_PopList((u32 *)p) != 0) {
        return;
    }
    if (GFL_NET_QUEUE_PopList((u32 *)(p + 8)) != 0) {
        return;
    }
    func_02034714((const char *)str_020A79C4, 0x12f, (const char *)str_020A79EC);
}
