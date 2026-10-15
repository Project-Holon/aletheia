/*
 * function: FIELDMAP_ProcExit
 * address:  0x02187FE8
 * packet:   pkt_ov021_02187FE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_Delete  0x021880A4  thumb  ov021
 *   GAMESYSTEM_SetFieldMap  0x02012110  thumb
 *   func_020315D4  0x020315D4  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 */

void FIELDMAP_Delete(int *p);
struct Ctx;
void GAMESYSTEM_SetFieldMap(struct Ctx *p, void *v);
struct Proc;
void func_020315D4(struct Proc *p);
void GFL_HEAP_DeleteChecked(unsigned int heap);

int FIELDMAP_ProcExit(int a, int unused, int b, int *c)
{
    FIELDMAP_Delete((int *)(*c));
    GAMESYSTEM_SetFieldMap((void *)b, 0);
    func_020315D4((struct Proc *)a);
    GFL_HEAP_DeleteChecked(0x96);
    GFL_HEAP_DeleteChecked(0x92);
    GFL_HEAP_DeleteChecked(0x93);
    GFL_HEAP_DeleteChecked(0x89);
    GFL_HEAP_DeleteChecked(0x50);
    GFL_HEAP_DeleteChecked(0x70);
    GFL_HEAP_DeleteChecked(0x15);
    return 1;
}
