/*
 * function: NNS_SndWaveOutIsPlaying
 * address:  0x02072CC4
 * packet:   pkt_02072C40
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02089D6C 0x02089D6C  arm
 *   func_0208A07C 0x0208A07C  arm
 */

typedef unsigned int u32;

struct O {
    u32 f0;
    u32 pad04[1];
    u32 f8;
    u32 fc;
    u32 f10;
};

extern int func_02089D6C(u32 tag);
extern u32 func_0208A07C(void);

int NNS_SndWaveOutIsPlaying(struct O *o)
{
    u32 r;

    if (o->f8 == 0) return 0;
    if (o->fc == 0) {
        if (func_02089D6C(o->f10) == 0) return 1;
        o->fc = 1;
    }
    r = func_0208A07C();
    if (r & (1u << o->f0)) return 1;
    o->f8 = 0;
    return 0;
}
