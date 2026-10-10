/*
 * function: func_021AF7D4
 * address: 0x021AF7D4
 * packet: pkt_ov021_021AF7D4
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
 *   func_0201EF4C 0x0201EF4C thumb
 *   func_021AF794 0x021AF794 thumb
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

typedef struct {
    u8 pad[0x14];
    u8 *cur;
} Script;

extern void func_0201EF4C();
int func_021AF7D4(Script *a, u32 b);

int func_021AF7D4(Script *a, u32 b) { return func_021AF794(a, b, func_0201EF4C); }
