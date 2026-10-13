/*
 * function: EVENT_TRAINER_EYE_StepDelay
 * address: 0x021AE5D4
 * packet: pkt_ov021_021AE5D4
 * region: ov021
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 *
 * Function with no listing label, matched inside src/game/ov021/fldeff_iwakudaki.c and filed here.
 */

typedef struct IwaTask {
    int state;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int cnt;
} IwaTask;

int EVENT_TRAINER_EYE_StepDelay(IwaTask *w)
{
    w->cnt++;
    if (w->cnt >= 30) {
        w->cnt = 0;
        w->state = 10;
    }
    return 0;
}
