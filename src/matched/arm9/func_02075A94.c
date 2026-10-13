/*
 * function: func_02075A94
 * address:  0x02075A94
 * packet:   pkt_02075794
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNS_SndStrmFreeChannel  0x02073898  arm
 */

struct SndObj2 {
    char pad[0x128];
    int ref_count;
};

struct X;
extern void NNS_SndStrmFreeChannel(struct X *x);

void func_02075A94(struct SndObj2 *obj)
{
    if (obj->ref_count != 0) {
        if (--obj->ref_count == 0) {
            NNS_SndStrmFreeChannel((struct X *)obj);
        }
    }
}
