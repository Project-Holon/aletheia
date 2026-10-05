/*
 * function: func_021F94F8
 * address: 0x021F94F8
 * packet: pkt_ov132_021F94F8
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05: picks the selected slot among four and resets the state word.
 * The first loop passes a literal 0 to func_021FA558. Earlier drafts passed the
 * counter-zero local j, which folded to movs. With the literal 0, mwcc copies it
 * from the zero-valued register that the second loop starts from (j = count).
 * See docs/idioms/a-copy-of-the-counter-before-the-loop-label-is-a-stored-zero.md.
 * symbols:
 *   func_021FA558 0x021FA558 thumb ov132
 *   func_021FA56C 0x021FA56C thumb ov132
 */
typedef unsigned char u8;
extern void func_021FA558(char *, int, int);
extern void func_021FA56C(char *, u8);
void func_021F94F8(char *p)
{
    u8 count, i, j, selected, index;
    if (*(int *)(p + 0xEC) != 1) return;
    count = 0;
    i = 0;
    for (; i < 4; i++) func_021FA558(*(char **)(p + 0xB8), i, 0);
    func_021FA56C(*(char **)(p + 0xB8), 255);
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
        func_021FA558(*(char **)(p + 0xB8), index, 1);
    } else if ((index = *(u8 *)(p + 0xF0)) < 4) {
        *(u8 *)(p + 0xF1) = index;
        func_021FA558(*(char **)(p + 0xB8), index, 1);
    } else if (count == 1) {
        *(u8 *)(p + 0xF2) = selected;
        func_021FA56C(*(char **)(p + 0xB8), selected);
    } else {
        for (j = 0; j < 4; j = (u8)(j + 1)) {
            if (*(u8 *)(p + 0xF3 + j) == 0)
                func_021FA558(*(char **)(p + 0xB8), j, 1);
        }
    }
    *(int *)(p + 0xEC) = 0;
}
