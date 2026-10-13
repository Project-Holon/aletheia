/*
 * function: UNION_SUBDISP_StartLineHighlight
 * address: 0x021F0ED8
 * packet: pkt_ov031_021F0ED8
 * region: ov031
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   UNION_SUBDISP_FindHighlightSlot 0x021F0E64 thumb ov031
 */
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { u16 cnt; u8 idx; u8 pad; } Slot;
typedef struct A A;
typedef struct B B;
extern Slot *UNION_SUBDISP_FindHighlightSlot(A *, B *, int);
int UNION_SUBDISP_StartLineHighlight(A *a, B *b, int idx)
{
    Slot *p;
    p = UNION_SUBDISP_FindHighlightSlot(a, b, idx);
    if (!p)
        return 0;
    p->cnt = 0x5a;
    p->idx = idx;
    return 1;
}
