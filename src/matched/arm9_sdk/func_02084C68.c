/*
 * function: func_02084C68
 * address:  0x02084C68
 * packet:   pkt_02084C68
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FSi_HasEnoughSpaceToCreateUserFile (libfs.TWL.HYB.a fs_sysareaex.o)
 *
 * symbols:
 *   FSi_HasEnoughSpaceInFreeArea  0x02084C1C  arm
 */

struct _FSFreeAreaSize;

extern int func_02084C1C(struct _FSFreeAreaSize *freesize, char *path, unsigned long size, int bSysApp);

int func_02084C68(struct _FSFreeAreaSize *freesize, char *path, unsigned long size)
{
    return func_02084C1C(freesize, path, size, 0);
}
