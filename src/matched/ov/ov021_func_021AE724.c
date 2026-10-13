/*
 * function: EVENT_TRAINER_EYE_StepDone
 * address: 0x021AE724
 * packet: pkt_ov021_021AE724
 * region: ov021
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov021/scrcmd_screeneffects.c and filed here.
 */

typedef unsigned int   u32;
int EVENT_TRAINER_EYE_StepDone(u32 *p);

int EVENT_TRAINER_EYE_StepDone(u32 *p) { p[1] = 1; return 0; }
