/*
 * function: WORLDTRADE_SUBLCD_UpdateSlotPalettes
 * address: 0x021FFB20
 * packet: pkt_ov135_021FFB20
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: signed offset locals b then a, with two literal assignments each,
 * reproduce the dead stack stores; compound updates reverse the first pair.
 * note 2026-10-05 (wave D9r lane 131): removed the 2 dead first assignments
 * (`a = 0xE5C;` before `a = 0xEA0;`; `b = 0x302;` before `b = 0x32E;`). Game
 * code has no line table, so these were stand-ins. The plain single
 * assignment gives EXACT in --lang c99 and --lang c: the output bytes do not
 * change. Older text in this header that asks for the double assignment is
 * superseded.
 *
 * symbols:
 *   WORLDTRADE_SUBLCD_LoadSlotPalette 0x021FFC8C thumb ov135
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void WORLDTRADE_SUBLCD_LoadSlotPalette(u8 **p, u8 *q, int k, int n, int a4);
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
void WORLDTRADE_SUBLCD_UpdateSlotPalettes(u8 *p, int count, int flag)
{
    int i;
    int b, a;
    if (count != 0 && flag == 1) GFL_USE_PlaySeDefaultVolume(0x676);
    a = 0xEA0;
    b = 0x32E;
    for (i = 0; i < 7; i++) {
        if (i < count) {
            WORLDTRADE_SUBLCD_LoadSlotPalette((u8 **)(p + 0xE5C), *(void **)(p + a), i, *(u8 *)(p + i * 0x128 + b), *(u8 *)(p + i * 0x128 + 0x302));
            if (flag != 0) CLACT_SetActorAnimSeq((struct Obj *)(*(u32 *)(p + i * 4 + 0xD10)), i * 4 + 14);
            else CLACT_SetActorAnimSeq((struct Obj *)(*(u32 *)(p + i * 4 + 0xD10)), i * 4 + 17);
            CLACT_SetActorDrawEnable((struct Obj *)*(u32 *)(p + i * 4 + 0xD10), 1);
        } else {
            CLACT_SetActorDrawEnable((struct Obj *)*(u32 *)(p + i * 4 + 0xD10), 0);
        }
    }
}
