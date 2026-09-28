/*
 * function: func_02084CEC
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
 */

struct _FSFreeAreaSize;

extern int func_02084C78(struct _FSFreeAreaSize *freesize, char *path, unsigned long size, int bSysApp);

int func_02084CEC(struct _FSFreeAreaSize *freesize, char *path, unsigned long size)
{
    return func_02084C78(freesize, path, size, 0);
}
