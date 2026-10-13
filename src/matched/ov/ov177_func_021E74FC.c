/*
 * function: func_021E74FC
 * address: 0x021E74FC
 * packet: pkt_ov177_021E74FC
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   CLACT_DeleteActor  0x0204B3B4  arm  arm9
 */
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
void func_021E74FC(char *p)
{
    int i;
    for (i = 9; i < 14; i++) {
        if (*(void **)(p + i * 4 + 0x16c) != 0) {
            CLACT_DeleteActor(*(void **)(p + i * 4 + 0x16c));
            *(void **)(p + i * 4 + 0x16c) = 0;
        }
    }
}
