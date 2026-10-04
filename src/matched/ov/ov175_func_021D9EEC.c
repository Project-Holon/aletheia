/*
 * function: func_021D9EEC
 * address:  0x021D9EEC
 * packet:   pkt_021D9EEC
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_02039CB4  0x02039CB4  arm
 *
 * Flush partner of func_021D9ED4: sends the byte the object kept at
 *     +0x14 to 0x02039CB4 with the tick/state and line 0x24.
 */
#include "../include/Obj24327.h"

typedef unsigned long u32;

struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern unsigned int func_02039CB4(struct Link *tick, unsigned int value, unsigned int line);

void func_021D9EEC(char *obj)
{
    func_02039CB4((struct Link *)func_020399A8(), (unsigned char)((struct Obj24327 *)obj)->f14, 0x24);
}

