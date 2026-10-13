/*
 * function: WIPE_SYS_MainPanel
 * address:  0x02022390
 * packet:   pkt_02022390
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   WIPE_SYS_CallPattern  0x020223AC  thumb
 */

typedef unsigned int u32;

extern u32 WIPE_SYS_CallPattern(void *p);

void WIPE_SYS_MainPanel(u32 *obj, void *arg)
{
    if (*obj != 0) {
        if (WIPE_SYS_CallPattern(arg) == 1) {
            *obj = 0;
        }
    }
}
