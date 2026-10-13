/*
 * function: FS_OpenFile
 * address:  0x02078C18
 * packet:   pkt_02078C18
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020789FC 0x020789FC arm
 */

typedef int BOOL;
typedef struct FSFile FSFile;
typedef unsigned long u32;
extern BOOL func_020789FC(FSFile *file, const char *path, u32 mode);

BOOL FS_OpenFile(FSFile *file, const char *path)
{
    return func_020789FC(file, path, 1);
}
