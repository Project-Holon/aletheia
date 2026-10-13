/*
 * file:     unit_02078C28.c
 * function: FS_GetLength, FS_ChangeDir
 * address:  0x02078C28
 * packet:   pkt_02078C28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *   func_02077F44  0x02077F44  arm
 */

typedef unsigned int   u32;
struct FSFile;
extern u32 func_02078A94(struct FSFile *file);
extern int func_02077F44(const char *path);
int FS_ChangeDir(const char *path);
u32 FS_GetLength(struct FSFile *file){ return func_02078A94(file); }

int FS_ChangeDir(const char *path)
{
    return func_02077F44(path);
}
