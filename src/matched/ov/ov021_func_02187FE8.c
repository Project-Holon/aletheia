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
 *   func_020306F0  0x020306F0  arm
 */

void FIELDMAP_Delete(int *p);
struct Ctx;
void GAMESYSTEM_SetFieldMap(struct Ctx *p, void *v);
struct S020315D4;
void func_020315D4(struct S020315D4 *p);
void func_020306F0(unsigned int heap);

int FIELDMAP_ProcExit(int a, int unused, int b, int *c)
{
    FIELDMAP_Delete((int *)(*c));
    GAMESYSTEM_SetFieldMap((void *)b, 0);
    func_020315D4((struct S020315D4 *)a);
    func_020306F0(0x96);
    func_020306F0(0x92);
    func_020306F0(0x93);
    func_020306F0(0x89);
    func_020306F0(0x50);
    func_020306F0(0x70);
    func_020306F0(0x15);
    return 1;
}
