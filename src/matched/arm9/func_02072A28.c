/*
 * function: NNS_SndWaveOutInit
 * address:  0x02072A28
 * packet:   pkt_020729C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned int u32;

struct Struct0214DEC0 {
    u32 field0;
    u32 field4;
    u32 field8;
};

void NNS_SndWaveOutInit(void)
{
    struct Struct0214DEC0 *p = (struct Struct0214DEC0 *)0x0214DEC0;
    p->field8 = 0;
    p->field0 = 0;
    p->field4 = 0;
}
