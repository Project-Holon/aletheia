/*
 * function: CTRDGi_IsTaskAvailable_02010054
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
 */

typedef struct {
    void *bg1Char;
} NetErrWork;
#define g_0214617C (*(NetErrWork *)0x0214617C)

int CTRDGi_IsTaskAvailable_02010054(void)
{
    if (g_0214617C.bg1Char != 0) {
        return 1;
    }
    return 0;
}
