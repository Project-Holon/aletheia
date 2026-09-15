/*
 * function: func_02075C08
 * address:  0x02075C08
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

void func_02075C08(struct LerpObj *obj)
{
    if (obj->step < obj->duration) {
        obj->step++;
    }
}
