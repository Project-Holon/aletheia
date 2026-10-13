/*
 * function: func_021BD380
 * address: 0x021BD380
 * packet: pkt_ov099_021BD380
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BA928 0x021BA928 thumb ov099
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 */
#include "../include/Obj00008.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021BA928(void *);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void func_02039C68(struct Link *p, u32 lo, u32 hi);
int func_021BD380(char *p, int v)
{
    if (func_021BA928(p) != 0) {
        func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x11, 10);
        *(u32 *)&((struct Obj00008 *)p)->f1CC = 0x68;
    }
    return v;
}
