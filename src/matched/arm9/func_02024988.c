/*
 * function: PMS_WORD_GetSaveData
 * address:  0x02024988
 * packet:   pkt_02024768
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

struct Sub020071CCCtrl;
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, unsigned int id);
void *PMS_WORD_GetSaveData(int a0)
{
    return func_020071CC((struct Sub020071CCCtrl *)a0, 0x27);
}
