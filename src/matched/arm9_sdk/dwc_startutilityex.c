/*
 * function: FS_TryLoadTable
 * address:  0x0207ACB4
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   FS_LoadArchiveTables   0x0207A5C8  arm
 *   d_02150DA8      0x02150DA8  data  a4
 *
 * Original (32 bytes):
 *   mov  r3, r0
 *   mov  r2, r1
 *   ldr  r0, [pc, #8]   ; &d_02150DA8
 *   ldr  ip, [pc, #8]   ; 0x0207A5C8
 *   mov  r1, r3
 *   bx   ip
 *
 * FS_LoadArchiveTables(&d_02150DA8, p0, p1).
 */

extern void FS_LoadArchiveTables(void *arc, void *mem, void *size);
extern char d_02150DA8;

void FS_TryLoadTable(void *a0, void *a1)
{
    FS_LoadArchiveTables(&d_02150DA8, a0, a1);
}
