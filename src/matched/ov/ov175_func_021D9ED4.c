/*
 * function: func_021D9ED4
 * address:  0x021D9ED4
 * packet:   pkt_021D9ED4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *
 * Stores the caller's word at +0x14 and forwards its low byte to
 *     0x02039C68 with the tick/state from 0x020399A8 and line 0x24.  The byte
 *     is re-read from the field after the first call, which is why the listing
 *     reloads +0x14.  func_021D9EEC is the same shape for the flush path.
 */
#include "../include/Obj14331.h"

typedef unsigned long u32;

struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern void func_02039C68(struct Link *p, unsigned int lo, unsigned int hi);

void func_021D9ED4(char *obj, u32 v)
{
    ((struct Obj14331 *)obj)->f14 = v;
    func_02039C68((struct Link *)func_020399A8(), (unsigned char)((struct Obj14331 *)obj)->f14, 0x24);
}

