/*
 * function: FIELD_EFFECT_CreateObjectMgr
 * address:  0x021ABFFC
 * packet:   pkt_ov021_021ABFFC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_021DE018     0x021DE018  data  ov021  a1
 */
#include "../include/Obj07511.h"

typedef unsigned short u16;

typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern char d_021DE018[];

char *FIELD_EFFECT_CreateObjectMgr(u16 heap, int b, int cnt)
{
    char *p;

    p = (char *)func_02030734(heap, 0x10, 1, d_021DE018, 0x23a);
    ((struct Obj07511 *)p)->f0 = cnt;
    ((struct Obj07511 *)p)->f4 = heap;
    ((struct Obj07511 *)p)->f8 = func_02030734(heap, cnt * 0xd4, 1, d_021DE018, 0x23e);
    ((struct Obj07511 *)p)->fC = b;
    return p;
}
