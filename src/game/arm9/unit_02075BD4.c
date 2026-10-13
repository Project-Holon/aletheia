/*
 * file:     unit_02075BD4.c
 * unit:     yes
 * function: NNS_SndFaderGet, NNS_SndFaderUpdate, NNS_SndFaderIsFinished
 * address:  0x02075BD4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   _s32_div_f      0x0209C0A4  arm
 */
typedef int s32;

typedef struct SndFader {
    s32 start;
    s32 target;
    s32 step;
    s32 duration;
} SndFader;

s32 NNS_SndFaderGet(SndFader *fader)
{
    if (fader->step >= fader->duration)
        return fader->target;
    return fader->start + (fader->target - fader->start) * fader->step / fader->duration;
}


void NNS_SndFaderUpdate(SndFader *fader)
{
    if (fader->step < fader->duration) {
        fader->step++;
    }
}


int NNS_SndFaderIsFinished(SndFader *fader)
{
    if (fader->step >= fader->duration) {
        return 1;
    }
    return 0;
}
