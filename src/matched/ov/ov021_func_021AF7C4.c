/*
 * function: SCRCMD_BufferItemName
 * address: 0x021AF7C4
 * packet: pkt_ov021_021AF7C4
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
 *   func_0201EF40 0x0201EF40 thumb
 *   SCRCMD_BufferEntryCommon 0x021AF794 thumb
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

typedef struct {
    u8 pad[0x14];
    u8 *cur;
} Script;

extern void func_0201EF40();
int SCRCMD_BufferItemName(Script *a, u32 b);

int SCRCMD_BufferItemName(Script *a, u32 b) { return SCRCMD_BufferEntryCommon(a, b, func_0201EF40); }
