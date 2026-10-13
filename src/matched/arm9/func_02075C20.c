/*
 * function: NNS_SndFaderIsFinished
 * address:  0x02075C20
 * packet:   pkt_02075794
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

struct LerpObj {
    int start;
    int target;
    int step;
    int duration;
};

int NNS_SndFaderIsFinished(struct LerpObj *obj)
{
    if (obj->step >= obj->duration) {
        return 1;
    }
    return 0;
}
