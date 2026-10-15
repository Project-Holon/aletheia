/*
 * function: WIFILOGIN_MSG_StepFinish
 * address:  0x021D630C
 * packet:   pkt_021D630C
 * region:   ov115
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   WIFILOGIN_MSG_RunStep  0x021D6134  thumb  ov115
 */

typedef unsigned int   u32;
u32 WIPE_SYS_EndCheck(void);
void WIFILOGIN_MSG_RunStep(void *a0, int a1, int a2);

void WIFILOGIN_MSG_StepFinish(void *a0)
{
    if (WIPE_SYS_EndCheck())
        WIFILOGIN_MSG_RunStep(a0, 0, 0x221);
}
