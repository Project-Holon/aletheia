/*
 * function: OS_UnlockByWord
 * address:  0x02084CEC
 * packet:   pkt_02084CEC
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
 *   FSi_HasEnoughSpaceInFreeArea  0x02084C78  arm
 *   OSi_DoUnlockByWord  0x02084C78  arm
 */

struct _FSFreeAreaSize;

extern int OSi_DoUnlockByWord(struct _FSFreeAreaSize *freesize, char *path, unsigned long size, int bSysApp);

int OS_UnlockByWord(struct _FSFreeAreaSize *freesize, char *path, unsigned long size)
{
    return OSi_DoUnlockByWord(freesize, path, size, 0);
}
