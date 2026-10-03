/*
 * function: func_0207A9C8
 * address:  0x0207A9C8
 * packet:   pkt_0207A9C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FSi_OnRomReadDone (fs_proc_rom.o)
 *
 * symbols:
 *   CARD_IsPulledOut                 0x020774b0 arm
 *   FS_NotifyArchiveAsyncEnd         0x02078734 arm
 */

typedef struct FSArchive FSArchive;

typedef enum FSResult {
    FS_RESULT_SUCCESS = 0,
    FS_RESULT_FAILURE,
    FS_RESULT_BUSY,
    FS_RESULT_CANCELED,
    FS_RESULT_UNSUPPORTED,
    FS_RESULT_ERROR,
    FS_RESULT_PROC_ASYNC = 0x100
} FSResult;

extern void *func_020774B0(void);
extern void func_02078734(FSArchive *arc, FSResult ret);

static void func_0207A9C8(void *arg)
{
    func_02078734((FSArchive *)arg, func_020774B0() ? FS_RESULT_ERROR : FS_RESULT_SUCCESS);
}
