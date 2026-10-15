/*
 * function: NNSi_SndFaderReset
 * address:  0x02075B94
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

void NNSi_SndFaderReset(struct LerpObj *obj)
{
    obj->target = 0;
    obj->start = 0;
    obj->duration = 0;
    obj->step = 0;
}
