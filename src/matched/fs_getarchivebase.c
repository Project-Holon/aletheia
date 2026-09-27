/*
 * function: FS_GetArchiveBase
 * address:  0x0207A78C
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *
 * Original (12 bytes, no relocation):
 *   ldr r0, [r0, #0x20]
 *   ldr r0, [r0]
 *   bx  lr
 *
 * FSArchive.field_20 is a pointer to a header whose first word is the
 * archive base, so two chained loads.
 */

typedef unsigned int u32;

void *FS_GetArchiveBase(void *arc)
{
    u32 **p = (u32 **)((char *)arc + 0x20);
    return (void *)**p;
}
