/*
 * function: FS_GetLength
 * address:  0x02078C28
 * packet:   pkt_02078C28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   FS_GetFileLength  0x02078A94  arm
 */

typedef unsigned int   u32;
struct FSFile;
extern u32 FS_GetFileLength(struct FSFile *file);
u32 FS_GetLength(struct FSFile *a0){ return FS_GetFileLength(a0); }
