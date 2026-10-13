/*
 * function: OEKAKI_SetQuitButtonPressed
 * address: 0x021852F4
 * packet: pkt_ov023_021852F4
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 */
typedef unsigned short u16;
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
void OEKAKI_SetQuitButtonPressed(void *p, int flag)
{
    if (flag == 1)
        CLACT_SetActorAnimSeq(p, 9);
    else
        CLACT_SetActorAnimSeq(p, 1);
}
