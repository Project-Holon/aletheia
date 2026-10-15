/*
 * function: OS_TryLockByWord
 * address:  0x02084D68
 * packet:   pkt_02084D68
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
 *   FSi_HasEnoughSpaceInFreeArea  0x02084CFC  arm
 *   OSi_DoTryLockByWord  0x02084CFC  arm
 */

struct _FSFreeAreaSize;

extern int OSi_DoTryLockByWord(struct _FSFreeAreaSize *freesize, char *path, unsigned long size, int bSysApp);

int OS_TryLockByWord(struct _FSFreeAreaSize *freesize, char *path, unsigned long size)
{
    return OSi_DoTryLockByWord(freesize, path, size, 0);
}
