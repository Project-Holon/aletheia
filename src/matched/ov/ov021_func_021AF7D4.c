/*
 * function: SCRCMD_BufferItemNameAlt
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
 *   WORDSET_Callback_EF4C 0x0201EF4C thumb
 *   SCRCMD_BufferEntryCommon 0x021AF794 thumb
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

typedef struct {
    u8 pad[0x14];
    u8 *cur;
} Script;

extern void WORDSET_Callback_EF4C();
int SCRCMD_BufferItemNameAlt(Script *a, u32 b);

int SCRCMD_BufferItemNameAlt(Script *a, u32 b) { return SCRCMD_BufferEntryCommon(a, b, WORDSET_Callback_EF4C); }
