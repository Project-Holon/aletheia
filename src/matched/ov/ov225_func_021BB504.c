/*
 * function: MANUAL_COMMON_DeleteDialogStep
 * address: 0x021BB504
 * packet: pkt_ov225_021BB504
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MANUAL_COMMON_DeleteDialogWindows 0x021BB50C thumb ov225
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void MANUAL_COMMON_DeleteDialogWindows(char *);
void MANUAL_COMMON_DeleteDialogStep(char *p) { MANUAL_COMMON_DeleteDialogWindows(p); }
