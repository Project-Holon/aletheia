/*
 * function: ISS_SWITCH_SYS_CreateSets
 * address:  0x0202C148
 * packet:   pkt_0202C148
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Build the unit table of a block: n = ARC_TOOL_GetArchiveFileCount(0x93) members, the
 * count stored at +4, an n-word pointer array allocated from heapId at +8
 * (file word 0x020A7758, line 0x13A), then one unit per slot from
 * ISS_SWITCH_SET_Create(heapId), initialised by ISS_SWITCH_SET_Load(unit, i, heapId).
 *
 * What closed it (wave 17, from 17 out): heapId is a u16 PARAMETER.  With
 * a u32 heapId 1.1p1 hoists the heapId reload and the file pool word above
 * the `strb` of the count; narrowed, its home store `str r1, [sp, #4]`
 * sits at the front of the prologue and the image's order falls out
 * (docs/idioms/a-narrow-parameter-pins-its-home-store-to-the-front-of-the-prologue.md).
 * The callee prototypes take the same u16 heap id.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SWITCH_SYS_CreateSets.c \
 *       --func ISS_SWITCH_SYS_CreateSets --addr 0x0202C148 --cc 1.1p1 --thumb
 *
 * symbols:
 *   ISS_SWITCH_SET_Create  0x0202C2EC  thumb
 *   ISS_SWITCH_SET_Load  0x0202C318  thumb
 *   ARC_TOOL_GetArchiveFileCount  0x02049030  arm
 */
#include "../include/Obj04107.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 ARC_TOOL_GetArchiveFileCount(u32 a);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 ISS_SWITCH_SET_Create(void *heap);
extern void  ISS_SWITCH_SET_Load(u8 *unit, u32 i, u16 heapId);

void ISS_SWITCH_SYS_CreateSets(u8 *p, u16 heapId)
{
    u32 i;
    int n;

    n = ARC_TOOL_GetArchiveFileCount(0x93);
    p[4] = (u8)n;
    ((struct Obj04107 *)p)->f8 = (u32)func_02030734(heapId, (u32)(n << 2), 0,
                                         (const void *)0x020A7758, 0x13a);
    for (i = 0; (int)i < n; i++) {
        u8 *r = (u8 *)ISS_SWITCH_SET_Create((void *)heapId);
        ISS_SWITCH_SET_Load(r, i, heapId);
        *(u32 *)(((struct Obj04107 *)p)->f8 + (i << 2)) = (u32)r;
    }
}
