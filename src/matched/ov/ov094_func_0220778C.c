/*
 * function: func_0220778C
 * address: 0x0220778C
 * packet: pkt_ov094_0220778C
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero bytes at 0220785A align the next function.
 * lever: indexed entries in the owning structure retain per-field bases;
 *   a raw offset or cast Entry array caches the element and is 138/144 bytes.
 * symbols:
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 */
typedef struct {
    void *f40, *f44, *f48, *f4c, *f50, *f54;
    unsigned int f58, f5c, f60, f64, f68, f6c, f70, f74, f78, f7c;
    char pad[0x40];
} Entry;
typedef struct { char pad[0x40]; Entry entries[8]; } Work;
extern void CLACT_ReleaseCharacter(unsigned int);
extern void CLACT_ReleaseCellAnim(unsigned int);
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
void func_0220778C(Work *p, int i)
{
    if (p->entries[i].f40 == 0)
        return;
    CLACT_ReleaseCharacter(p->entries[i].f58);
    CLACT_ReleaseCharacter(p->entries[i].f60);
    CLACT_ReleaseCharacter(p->entries[i].f68);
    CLACT_ReleaseCharacter(p->entries[i].f70);
    CLACT_ReleaseCellAnim(p->entries[i].f5c);
    CLACT_ReleaseCellAnim(p->entries[i].f64);
    CLACT_ReleaseCellAnim(p->entries[i].f6c);
    CLACT_ReleaseCellAnim(p->entries[i].f74);
    CLACT_DeleteActor(p->entries[i].f40);
    CLACT_DeleteActor(p->entries[i].f44);
    CLACT_DeleteActor(p->entries[i].f48);
    CLACT_DeleteActor(p->entries[i].f4c);
    CLACT_DeleteActor(p->entries[i].f54);
    p->entries[i].f40 = 0;
    p->entries[i].f44 = 0;
    p->entries[i].f48 = 0;
    p->entries[i].f4c = 0;
    p->entries[i].f54 = 0;
    if ((i & 1) == 0) {
        CLACT_ReleaseCharacter(p->entries[i].f78);
        CLACT_ReleaseCellAnim(p->entries[i].f7c);
    }
    if (p->entries[i].f50 != 0) {
        CLACT_DeleteActor(p->entries[i].f50);
        p->entries[i].f50 = 0;
    }
}
