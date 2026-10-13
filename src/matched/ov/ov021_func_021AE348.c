/*
 * unit:     yes
 * function: EVENT_TRAINER_EYE_CheckSight, EVENT_TRAINER_EYE_CheckSightUp, EVENT_TRAINER_EYE_CheckSightDown, EVENT_TRAINER_EYE_CheckSightLeft, EVENT_TRAINER_EYE_CheckSightRight
 * address:  0x021AE348
 * packet:   pkt_ov021_021AE348
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sTrainerEyeSightFuncs  0x021D9338  data  a4
 * Addresses are Black-image addresses.
 * EVENT_TRAINER_EYE_CheckSight dispatches through the four-entry table at 0x021D9338,
 * whose entries are the four unlabelled leaves that follow it; the unit
 * covers the whole 232-byte run.
 */

typedef short s16;

typedef int (*CmpFn)(int, const s16 *, const s16 *);

extern CmpFn sTrainerEyeSightFuncs[];

int EVENT_TRAINER_EYE_CheckSight(int idx, int a, const s16 *p, const s16 *q)
{
    return sTrainerEyeSightFuncs[idx](a, p, q);
}

int EVENT_TRAINER_EYE_CheckSightUp(int a, const s16 *p, const s16 *q)
{
    if (p[0] == q[0] && p[1] == q[1] && q[2] < p[2] && q[2] >= p[2] - a)
        return p[2] - q[2];
    return -1;
}

int EVENT_TRAINER_EYE_CheckSightDown(int a, const s16 *p, const s16 *q)
{
    if (p[0] == q[0] && p[1] == q[1] && q[2] > p[2] && q[2] <= p[2] + a)
        return q[2] - p[2];
    return -1;
}

int EVENT_TRAINER_EYE_CheckSightLeft(int a, const s16 *p, const s16 *q)
{
    if (p[2] == q[2] && p[1] == q[1] && q[0] < p[0] && q[0] >= p[0] - a)
        return p[0] - q[0];
    return -1;
}

int EVENT_TRAINER_EYE_CheckSightRight(int a, const s16 *p, const s16 *q)
{
    if (p[2] == q[2] && p[1] == q[1] && q[0] > p[0] && q[0] <= p[0] + a)
        return q[0] - p[0];
    return -1;
}
