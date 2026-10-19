/*
 * function: SCRCMD_BufferSpeciesEntryName
 * address: 0x021AF918
 * packet: pkt_ov021_021AF918
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
 *   WORDSET_SetSlotFromMsg119 0x0201EEC4 thumb
 *   SCRCMD_BufferSpeciesNameCommon 0x021AF8D8 thumb
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

typedef struct {
    u8 pad[0x14];
    u8 *cur;
} Script;

extern void WORDSET_SetSlotFromMsg119();
int SCRCMD_BufferSpeciesEntryName(Script *a, u32 b);

int SCRCMD_BufferSpeciesEntryName(Script *a, u32 b) { return SCRCMD_BufferSpeciesNameCommon(a, b, WORDSET_SetSlotFromMsg119); }
