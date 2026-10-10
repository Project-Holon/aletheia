/*
 * function: func_021AFC18
 * address: 0x021AFC18
 * packet: pkt_ov021_021AFC18
 * region: ov021
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov021/scrcmd_screeneffects.c and filed here.
 *
 * symbols:
 *   func_0201F0F8 0x0201F0F8 thumb
 *   func_021AFBEC 0x021AFBEC thumb
 */

typedef unsigned char  u8;

typedef struct {
    char pad[0x14];
    u8 *cur;
} Ctx_021AFBEC;

extern void func_0201F0F8();
int func_021AFC18(Ctx_021AFBEC *a, int b);

int func_021AFC18(Ctx_021AFBEC *a, int b) { return func_021AFBEC(a, b, func_0201F0F8); }
