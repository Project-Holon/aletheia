/*
 * function: EVENT_TRAINER_EYE_Run
 * address:  0x021AE72C
 * packet:   pkt_ov021_021AE72C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sTrainerEyeStepFuncs  0x021D9348  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct S { u32 f0; u32 f4; } S;
typedef int (*StepFn)(S *s);

extern StepFn sTrainerEyeStepFuncs[];

int EVENT_TRAINER_EYE_Run(S *s)
{
    while (sTrainerEyeStepFuncs[s->f0](s) == 1)
        ;
    if (s->f4 == 1)
        return 1;
    return 0;
}
