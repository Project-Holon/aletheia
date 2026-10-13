/*
 * function: PMSIV_MENU_SetItemAnim
 * address: 0x021BD0F8
 * packet: pkt_ov110_021BD0F8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: integer table-base arithmetic forms table+i*2 before adding flag;
 * gPmsivMenuItemAnimSeq[i*2+flag] combined the two indices first (11 concrete bytes differed).
 * symbols:
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   gPmsivMenuItemAnimSeq 0x021C38DF data a1
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern const u8 gPmsivMenuItemAnimSeq[];
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
void PMSIV_MENU_SetItemAnim(u8 *p,int i,int flag)
{
    CLACT_SetActorAnimSeq(*(void **)(p+i*4+0x70),*(u8 *)((u32)gPmsivMenuItemAnimSeq+i*2+flag));
}
