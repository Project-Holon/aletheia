/*
 * function: func_021BE7F0
 * address: 0x021BE7F0
 * packet: pkt_ov203_021BE7F0
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021C3CF0 0x021C3CF0 data a1
 *   d_021C0348 0x021C0348 data a4
 */
#include "../include/Obj14588.h"
#include "../include/Obj25319.h"
typedef struct Entry { int x; unsigned short id, pad; int flag; } Entry;
extern const char d_021C3CF0[];
extern unsigned d_021C0348[];
extern void *func_02030734(unsigned, unsigned, int, const char *, unsigned short);
void *func_021BE7F0(unsigned heap)
{
    char *ctx;
    Entry *entries;
    char *extra;
    int i;
    ctx = func_02030734(heap, 16, 1, d_021C3CF0, 0xab);
    entries = func_02030734(heap, 72, 1, d_021C3CF0, 0xac);
    extra = func_02030734(heap, 16, 1, d_021C3CF0, 0xad);
    for (i = 0; i < 6; i++) {
        entries[i].x = 160;
        entries[i].flag = 0;
    }
    ((struct Obj25319 *)extra)->f8 = d_021C0348;
    *(Entry * *)&((struct Obj14588 *)ctx)->f0 = entries;
    *(char * *)&((struct Obj14588 *)ctx)->f8 = extra;
    return ctx;
}
