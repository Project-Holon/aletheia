/*
 * function: GFL_NET_ERR_IsActive
 * address:  0x02010054
 * packet:   pkt_02010054
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     TwlSDK libctrdg.TWL.HYB.thumb.a(ctrdg_task.o) CTRDGi_IsTaskAvailable;
 *           reads the task-available flag at 0x0214617C.
 *
 * symbols:
 *   gNetErrWork  0x0214617C  data
 */

typedef struct {
    void *bg1Char;
} NetErrWork;
#define gNetErrWork (*(NetErrWork *)0x0214617C)

int GFL_NET_ERR_IsActive(void)
{
    if (gNetErrWork.bg1Char != 0) {
        return 1;
    }
    return 0;
}
