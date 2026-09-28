/*
 * function: FS_GetArchiveOffset
 * address:  0x0207A798
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
 * Original (16 bytes, no relocation):
 *   ldr r0, [r0, #0x20]
 *   ldr r0, [r0]
 *   add r0, r0, r1
 *   bx  lr
 *
 * The archive base plus a byte position.
 */

typedef unsigned int u32;

u32 FS_GetArchiveOffset(void *arc, u32 pos)
{
    u32 *p = *(u32 **)((char *)arc + 0x20);
    return *p + pos;
}
