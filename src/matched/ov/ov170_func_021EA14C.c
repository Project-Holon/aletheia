/*
 * function: BOX2_SEQ_ScrollListToSlot
 * address:  0x021EA14C
 * packet:   pkt_ov170_021EA14C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_020077B8 0x020077B8 thumb
 *   BOX2_SEQ_Create 0x021EA1C0 thumb
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb
 *   BOX2_MAIN_SceneOpenBox 0x021E087C thumb
 */
#include "../include/Obj00000.h"
#include "../include/Obj23957.h"

typedef struct {
    int pad0;
    void *x4;
} Top;

extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern int func_020077B8(void *save, unsigned box);
extern void BOX2_SEQ_Create(void *p);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_MAIN_SceneOpenBox(unsigned char *p);

int BOX2_SEQ_ScrollListToSlot(unsigned char *p, unsigned i, int v)
{
    if (i >= 0x1E && i >= 0x24 && i != 0xFF) {
        unsigned k = p[0x19] + i - 0x24;
        if (k >= p[0x15])
            k -= p[0x15];
        if (k == p[0x14]) {
            GFL_USE_PlaySeDefaultVolume(0x557);
            return 0x15;
        }
        if (func_020077B8((*(Top * *)&((struct Obj00000 *)p)->f0)->x4, k) == 0) {
            GFL_USE_PlaySeDefaultVolume(0x557);
            return 0x15;
        }
    }
    ((struct Obj23957 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA17E = i;
    p[0x1A] = 2;
    ((struct Obj00000 *)p)->f28 = v;
    BOX2_SEQ_Create(p);
    return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_SceneOpenBox, 0x17);
}
