/*
 * function: func_021E7CD0
 * address: 0x021E7CD0
 * packet: pkt_ov177_021E7CD0
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   CLACT_DeleteActor  0x0204B3B4  arm  arm9
 */
typedef struct { char pad[0x68]; void *obj[5]; } Work;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
void func_021E7CD0(Work *p)
{
    int i;
    for (i = 0; i < 5; i++) {
        if (p->obj[i] != 0) {
            CLACT_DeleteActor(p->obj[i]);
            p->obj[i] = 0;
        }
    }
}
