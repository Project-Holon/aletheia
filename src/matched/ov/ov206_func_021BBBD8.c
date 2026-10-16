/*
 * function: ZUKAN_INFO_DeleteActorPair
 * address: 0x021BBBD8
 * packet: pkt_ov206_021BBBD8
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 */
typedef struct S {
    char pad0[0x174];
    void *a[2];
    char padx[0xc];
    void *b[2];
    int sel;
} S;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
typedef unsigned int   u32;
extern void CLACT_ReleaseCharacter(u32 i);
void ZUKAN_INFO_DeleteActorPair(S *p, int i)
{
    if (p->b[i] != 0) {
        CLACT_DeleteActor(p->b[i]);
        CLACT_ReleaseCharacter((u32)p->a[i]);
        p->b[i] = 0;
    }
}
