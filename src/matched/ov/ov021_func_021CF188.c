/*
 * function: COMM_ENTRY_GetRosterBuffer
 * address: 0x021CF188
 * packet: pkt_ov021_021CF188
 * region: ov021
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov021/trial_house.c and filed here.
 *
 * symbols:
 *   COMM_ENTRY_MENU_GetNameBuffer 0x021CEAF8 thumb ov021
 */

typedef unsigned int   u32;
extern void *COMM_ENTRY_MENU_GetNameBuffer(void *p);
void *COMM_ENTRY_GetRosterBuffer(u32 a, void *b);

void *COMM_ENTRY_GetRosterBuffer(u32 a, void *b) { return COMM_ENTRY_MENU_GetNameBuffer(b); }
