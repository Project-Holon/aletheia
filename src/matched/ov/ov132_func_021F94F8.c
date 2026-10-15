/*
 * function: STA_ACTING_UpdateSelection
 * address: 0x021F94F8
 * packet: pkt_ov132_021F94F8
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05: picks the selected slot among four and resets the state word.
 * The first loop passes a literal 0 to STA_ACT_AUDIENCE_SetSlotValue. Earlier drafts passed the
 * counter-zero local j, which folded to movs. With the literal 0, mwcc copies it
 * from the zero-valued register that the second loop starts from (j = count).
 * See docs/idioms/a-copy-of-the-counter-before-the-loop-label-is-a-stored-zero.md.
 * symbols:
 *   STA_ACT_AUDIENCE_SetSlotValue 0x021FA558 thumb ov132
 *   STA_ACT_AUDIENCE_SetHighlight 0x021FA56C thumb ov132
 */
typedef unsigned char u8;
extern void STA_ACT_AUDIENCE_SetSlotValue(char *, int, int);
extern void STA_ACT_AUDIENCE_SetHighlight(char *, u8);
void STA_ACTING_UpdateSelection(char *p)
{
    u8 count, i, j, selected, index;
    if (*(int *)(p + 0xEC) != 1) return;
    count = 0;
    i = 0;
    for (; i < 4; i++) STA_ACT_AUDIENCE_SetSlotValue(*(char **)(p + 0xB8), i, 0);
    STA_ACT_AUDIENCE_SetHighlight(*(char **)(p + 0xB8), 255);
    *(u8 *)(p + 0xF1) = 4;
    *(u8 *)(p + 0xF2) = 4;
    for (j = count; j < 4; j = (u8)(j + 1)) {
        if (*(int *)(p + 0x94 + j * 4) != 0) {
            selected = j;
            count = (u8)(count + 1);
        }
    }
    index = *(u8 *)(p + 0x11C);
    if (index < 4) {
        *(u8 *)(p + 0xF1) = index;
        STA_ACT_AUDIENCE_SetSlotValue(*(char **)(p + 0xB8), index, 1);
    } else if ((index = *(u8 *)(p + 0xF0)) < 4) {
        *(u8 *)(p + 0xF1) = index;
        STA_ACT_AUDIENCE_SetSlotValue(*(char **)(p + 0xB8), index, 1);
    } else if (count == 1) {
        *(u8 *)(p + 0xF2) = selected;
        STA_ACT_AUDIENCE_SetHighlight(*(char **)(p + 0xB8), selected);
    } else {
        for (j = 0; j < 4; j = (u8)(j + 1)) {
            if (*(u8 *)(p + 0xF3 + j) == 0)
                STA_ACT_AUDIENCE_SetSlotValue(*(char **)(p + 0xB8), j, 1);
        }
    }
    *(int *)(p + 0xEC) = 0;
}
