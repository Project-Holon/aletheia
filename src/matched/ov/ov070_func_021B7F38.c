/*
 * function: ITEMMENU_CompareSortEntries
 * address:  0x021B7F38
 * packet:   pkt_ov070_021B7F38
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf: MATH_QSort comparator over 8-byte entries, ordering by
 * the unsigned key word at +4. Its only reference is the pool word
 * 0x021B7F39 in ITEMMENU_SortPocket.
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Ent {
    u16 id;
    u16 count;
    u32 key;
} Ent;

int ITEMMENU_CompareSortEntries(Ent *a, Ent *b)
{
    if (a->key == b->key)
        return 0;
    if (a->key > b->key)
        return 1;
    return -1;
}
