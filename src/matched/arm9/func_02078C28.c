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
 */

typedef unsigned int   u32;
struct FSFile;
extern u32 func_02078A94(struct FSFile *file);
u32 FS_GetLength(struct FSFile *a0){ return func_02078A94(a0); }
