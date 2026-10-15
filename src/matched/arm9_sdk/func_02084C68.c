/*
 * function: OS_LockByWord
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
 *   OSi_DoLockByWord  0x02084C1C  arm
 */

struct _FSFreeAreaSize;

extern int OSi_DoLockByWord(struct _FSFreeAreaSize *freesize, char *path, unsigned long size, int bSysApp);

int OS_LockByWord(struct _FSFreeAreaSize *freesize, char *path, unsigned long size)
{
    return OSi_DoLockByWord(freesize, path, size, 0);
}
