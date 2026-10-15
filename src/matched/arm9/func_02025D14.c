/*
 * function: CURSOR_MOVE_Delete
 * address:  0x02025D14
 * packet:   pkt_02025D14
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf: a bare tail call to GFL_HEAP_FreeMemory with no arguments.
 * `ldr r3,[pc,#0]; bx r3` (the pool word names 0x02030164).  Disasm.py did
 * not label it because it has no prologue; the live bytes decode as Thumb.
 *
 * symbols:
 *   CURSOR_MOVE_Delete  0x02025D14  thumb
 *   GFL_HEAP_FreeMemory  0x02030164  arm
 */

typedef unsigned int   u32;
extern u32 GFL_HEAP_FreeMemory(void *p);

u32 CURSOR_MOVE_Delete(void *a0)
{
    return GFL_HEAP_FreeMemory(a0);
}
