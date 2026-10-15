/*
 * function: DSPi_ReadProcessImage
 * address:  0x027053D4
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   FS_ReadFile  0x02078B70  arm  arm9
 *   FS_SeekFile  0x02078B44  arm  arm9
 */

typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;
typedef struct FileRec {
    u32 pad[5];
    void *file;
} FileRec;
extern s32 FS_SeekFile(void *file, u32 a, u32 b);
extern s32 FS_ReadFile(void *file, void *buf, s32 len);
u32 DSPi_ReadProcessImage(FileRec *p, u32 a, void *buf, s32 len)
{
    u32 ok = 0;
    if (FS_SeekFile(p->file, a, 0)) {
        s32 n = FS_ReadFile(p->file, buf, len);
        if (len == n) {
            ok = 1;
        }
    }
    return ok;
}
