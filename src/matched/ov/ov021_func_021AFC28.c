/*
 * function: SCRCMD_BufferMapEntryNameB
 * address: 0x021AFC28
 * packet: pkt_ov021_021AFC28
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
 *   WORDSET_Callback_F124 0x0201F124 thumb
 *   SCRCMD_BufferByteEntryCommon 0x021AFBEC thumb
 */

typedef unsigned char  u8;

typedef struct {
    char pad[0x14];
    u8 *cur;
} Ctx_021AFBEC;

extern void WORDSET_Callback_F124();
int SCRCMD_BufferMapEntryNameB(Ctx_021AFBEC *a, int b);

int SCRCMD_BufferMapEntryNameB(Ctx_021AFBEC *a, int b) { return SCRCMD_BufferByteEntryCommon(a, b, WORDSET_Callback_F124); }
