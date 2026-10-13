/*
 * function: BSUBWAY_RECORD_LIST_StateFadeOutWait
 * address: 0x021B9F08
 * packet: pkt_ov069_021B9F08
 * region: ov069
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two bytes of alignment padding follow.
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 */
#include "../include/Obj20658.h"
extern unsigned WIPE_SYS_EndCheck(void);
int BSUBWAY_RECORD_LIST_StateFadeOutWait(char *p)
{
    if (WIPE_SYS_EndCheck()) {
        ((struct Obj20658 *)p)->f158 = 0;
        return 0;
    }
    return 1;
}
