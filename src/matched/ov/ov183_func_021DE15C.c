/*
 * function: BR_CODEIN_ListSetActorAnim
 * address: 0x021DE15C
 * packet: pkt_ov183_021DE15C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021E3358 0x021E3358 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u32 d_021E3358[];
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
void BR_CODEIN_ListSetActorAnim(char *p, u32 value)
{
    u8 temp = value;
    int i;
    int j;
    if (temp != 0) {
        for (;;) {
            if (temp == 0) break;
            temp /= 10;
        }
    }
    for (i = 0; i < 4; i++) CLACT_SetActorAnimSeq(*(void **)(p + i * 4 + 4), 0);
    for (j = 0; j < 4; j++)
        CLACT_SetActorAnimSeq(*(void **)(p + (3 - j) * 4 + 4), value % d_021E3358[j + 1] / d_021E3358[j]);
}
