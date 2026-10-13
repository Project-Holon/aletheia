/*
 * function: ENCEFF_StartModelScene
 * address:  0x021F52D8
 * packet:   pkt_ov076_021F52D8
 * region:   ov076
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns the func_020122C0 handle (r0 stays live to the epilogue, which
 * pushes the -1 / flag temporaries into r1).
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetEncEff  0x02189A08  thumb  ov021
 *   ENCEFF_AllocWork  0x021CF52C  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   ENCEFF_ModelSceneEventMain  0x021F5334  thumb  ov076
 */
typedef unsigned int u32;

struct Ctx;
struct Desc;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetEncEff(unsigned char *p);
extern u32 *ENCEFF_AllocWork(u32 *p, int size, int heap);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int ENCEFF_ModelSceneEventMain(void *task, int *st);

void *ENCEFF_StartModelScene(void *a, u32 b, u32 c, u32 d, int e)
{
    u32 *w;
    void *h;

    w = ENCEFF_AllocWork((u32 *)FIELDMAP_GetEncEff((unsigned char *)((int)GAMESYSTEM_GetFieldMap(a))), 0x44, 0x50);
    h = func_020122C0(a, 0, ENCEFF_ModelSceneEventMain, 0);
    w[1] = b;
    w[0xB] = c;
    w[0xC] = d;
    w[0x10] = -1;
    if (e != 0) {
        w[0xD] = 0xC;
    } else {
        w[0xD] = 3;
    }
    return h;
}
