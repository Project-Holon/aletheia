/*
 * function: BOX2_UI_ConfirmSlotB
 * address: 0x021EE9F4
 * packet: pkt_ov170_021EE9F4
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020260E4 0x020260E4 thumb
 *   BOX2_UI_UpdateCursor 0x021EE408 thumb ov170
 *   BOX2_UI_SelectSlot 0x021EE754 thumb ov170
 */
typedef unsigned char  u8;
struct Sound;
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void BOX2_UI_UpdateCursor(char *, int);
extern void BOX2_UI_SelectSlot(unsigned char *, unsigned);
#define WORK(p) (*(char **)((p) + 0x2c))
void BOX2_UI_ConfirmSlotB(char *p, unsigned r)
{
    if (r - 0x25 <= 1) {
        func_020260E4(*(void **)(WORK(p) + 0x70), 0x24);
        r = 0x24;
    } else if (r - 0x28 <= 2) {
        func_020260E4(*(void **)(WORK(p) + 0x70), *(unsigned *)(WORK(p) + 0xa168));
        r = *(unsigned *)(WORK(p) + 0xa168);
    } else {
        BOX2_UI_UpdateCursor(p, r);
    }
    BOX2_UI_SelectSlot((unsigned char *)p, r);
    *(unsigned *)(WORK(p) + 0xa168) = r;
}
