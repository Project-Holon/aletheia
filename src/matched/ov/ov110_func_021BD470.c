/*
 * function: PMSIV_MENU_StopItemBlend
 * address: 0x021BD470
 * packet: pkt_ov110_021BD470
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
void PMSIV_MENU_StopItemBlend(u8 *p,int i)
{
    CLACT_SetActorPaletteOffset(*(void **)(p+i*4+0x70),6,1);
}
