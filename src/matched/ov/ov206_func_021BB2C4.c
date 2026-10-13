/*
 * function: func_021BB2C4
 * address: 0x021BB2C4
 * packet: pkt_ov206_021BB2C4
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 */
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
void func_021BB2C4(char *p, int i)
{
    CLACT_DeleteActor(*(void **)(p + i * 4 + 0xac));
}
