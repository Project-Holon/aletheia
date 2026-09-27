/*
 * function: FS_IsArchiveTableLoaded
 * address:  0x0207A7A8
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
 * Original (20 bytes, no relocation):
 *   ldr  r0, [r0, #0x14]
 *   tst  r0, #4
 *   movne r0, #1
 *   moveq r0, #0
 *   bx   lr
 *
 * Tests bit 2 of the word at offset 0x14 of FSArchive and returns it as a
 * 0/1 BOOL, hence the tst + conditional moves rather than a bare and.
 */

typedef unsigned int u32;

int FS_IsArchiveTableLoaded(void *arc)
{
    u32 flag = *(u32 *)((char *)arc + 0x14);
    return (flag & 4) ? 1 : 0;
}
