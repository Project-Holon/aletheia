/*
 * function: WORLDTRADE_SUBLCD_UpdateSlotAnims
 * address: 0x021FFBC8
 * packet: pkt_ov135_021FFBC8
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 021FFC16..021FFC18 is two-byte zero alignment padding.
 * symbols:
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   WORLDTRADE_SUBLCD_GetSlotAnimBase 0x021FFBC0 thumb ov135
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern int WORLDTRADE_SUBLCD_GetSlotAnimBase(int);
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
void WORLDTRADE_SUBLCD_UpdateSlotAnims(u8 *p)
{
    int i;
    for (i = 0; i < 7; i++) {
        if (*(u32 *)(p + i * 4 + 0xD10) != 0) {
            int a;
            a = CLACT_GetActorAnimSeq((struct Obj *)(*(u32 *)(p + i * 4 + 0xD10)));
            if (a != WORLDTRADE_SUBLCD_GetSlotAnimBase(i) + 1) {
                if (CLACT_GetActorDrawEnable((struct Obj *)(*(u32 *)(p + i * 4 + 0xD10))) != 0) {
                    CLACT_SetActorAnimSeq((struct Obj *)(*(u32 *)(p + i * 4 + 0xD10)), WORLDTRADE_SUBLCD_GetSlotAnimBase(i) + 1);
                }
            }
        }
    }
}
