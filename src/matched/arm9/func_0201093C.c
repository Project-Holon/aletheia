/*
 * function: func_0201093C
 * address:  0x0201093C
 * packet:   pkt_0201058C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201093C.c \
 *       --func func_0201093C --addr 0x0201093C --thumb --cc 1.1p1
 *
 * symbols:
 *   GAME_DATA_SaveStart  0x02012DAC  thumb
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 */
#include "../include/Obj15613.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct Link *h, u32 a, u32 b);
extern int GAME_DATA_SaveStart(int a0);
extern void func_02010888(u8 *p, u32 v);
extern void func_02010964(u8 *p);

void func_0201093C(u8 *p)
{
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x71, 8) != 0) {
        GAME_DATA_SaveStart(((struct Obj15613 *)p)->fC);
        func_02010888(p, (u32)func_02010964);
    }
}
