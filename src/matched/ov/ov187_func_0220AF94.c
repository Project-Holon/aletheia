/*
 * function: BR_MAIN_Exit
 * address:  0x0220AF94
 * packet:   pkt_0220AF94
 * region:   ov187
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STRBUF_Delete   0x02045808  arm
 *   func_020315D4   0x020315D4  arm
 *   GFL_HEAP_DeleteChecked   0x020306F0  arm
 *   BR_MAIN_FreeSceneManager   0x0220B0CC  thumb
 *   BATTLE_REC_FreeWork   0x0200B424  thumb
 *
 * Tear down the four table slots at p+0x1780 when p+0x17C4 is set, then
 *   release the channel.
 */
#include "../include/Obj24882.h"


struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
extern void BR_MAIN_FreeSceneManager(int *);
extern void BATTLE_REC_FreeWork(void);

int BR_MAIN_Exit(int a, int b, int c, char *p)
{
    int i;
    if (((struct Obj24882 *)p)->f17C4 != 0) {
        for (i = 0; i < 4; i++) {
            int v = *(int *)(p + 0x1780 + i * 4);
            if (v != 0)
                STRBUF_Delete((struct U16Vec *)v);
        }
    }
    BR_MAIN_FreeSceneManager((int *)p);
    BATTLE_REC_FreeWork();
    func_020315D4((struct S020315D4 *)a);
    GFL_HEAP_DeleteChecked(0x59);
    return 1;
}
