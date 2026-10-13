/*
 * file:     nns_snd_fader.c
 * unit:     yes
 * function: NNSi_SndFaderSet, NNS_SndFaderGet, NNS_SndFaderUpdate, NNS_SndFaderIsFinished
 * address:  0x02075BAC
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Under ../2.0/sp2 the zero for step is stored after the duration store, as the
 * image does. NNS_SndFaderGet reads only r0, so it takes one parameter.
 *
 * symbols:
 *   _s32_div_f      0x0209C0A4  arm
 */
typedef unsigned int u32;
typedef signed int s32;

typedef struct SndFader {
    s32 start;
    s32 target;
    s32 step;
    s32 duration;
} SndFader;

void NNSi_SndFaderSet(SndFader *fader, u32 target, u32 duration);
s32 NNS_SndFaderGet(SndFader *fader);
void NNS_SndFaderUpdate(SndFader *fader);
int NNS_SndFaderIsFinished(SndFader *fader);

void NNSi_SndFaderSet(SndFader *fader, u32 target, u32 duration)
{
    fader->start = NNS_SndFaderGet(fader);
    fader->target = target;
    fader->duration = duration;
    fader->step = 0;
}


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
