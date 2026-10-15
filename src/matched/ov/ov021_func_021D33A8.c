/*
 * function: FIELD_PALACE_SYS_Create
 * address:  0x021D33A8
 * packet:   pkt_ov021_021D33A8
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Recursive MATCH unblocker: target named by the parked ov021 FIELDMAP_SeqCreateSubsystems
 * (+0110 region) and part of the field_palace_sys.c tree
 * (layout/file_anchors.txt row 021D33DC -> 0x021DE6D4).  Allocates a 0xc-byte
 * record through the debug allocator, fills two words and a zero, and hands
 * it to FIELD_PALACE_SYS_SetupPalTable.
 *
 * symbols:
 *   GFL_HEAP_Alloc    0x02030734  arm
 *   FIELD_PALACE_SYS_SetupPalTable   0x021D33FC  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09759.h"

typedef unsigned short u16;
typedef unsigned int u32;

typedef unsigned char  u8;
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void FIELD_PALACE_SYS_SetupPalTable(u8 *a0, u16 a1, u16 a2);

void *FIELD_PALACE_SYS_Create(u16 heapId, void *a1, void *a2, u16 a3)
{
    void *p = GFL_HEAP_Alloc(heapId, 0xc, 1, (const char *)0x021DE6D4, 0x43);

    ((struct Obj09759 *)p)->f0 = (u32)a1;
    ((struct Obj09759 *)p)->f4 = (u32)a2;
    ((struct Obj09759 *)p)->f8 = 0;
    FIELD_PALACE_SYS_SetupPalTable(p, a3, heapId);
    return p;
}
