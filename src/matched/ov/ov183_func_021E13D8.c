/*
 * function: func_021E13D8
 * address: 0x021E13D8
 * packet: pkt_ov183_021E13D8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E1BA8 0x021E1BA8 thumb ov183
 *   BUTTON_MAN_UpdateSlots 0x02051C88 arm
 */
typedef int s32;
extern void func_021E1BA8(char *);
struct Ctx;
extern s32 BUTTON_MAN_UpdateSlots(struct Ctx *c);
s32 func_021E13D8(char *p)
{
    if (*(s32 *)(p + 0x234) == 0) {
        (*(s32 *)(p + 0x234))++;
    } else {
        func_021E1BA8(p);
        BUTTON_MAN_UpdateSlots(*(void **)(p + 0x294));
    }
    return 0;
}
