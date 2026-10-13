/*
 * function: UNION_SUBDISP_SyncKnobAndScroll
 * address: 0x021F0C34
 * packet: pkt_ov031_021F0C34
 * region: ov031
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   UNION_SUBDISP_SetScrollFromKnob 0x021F0C60 thumb ov031
 *   UNION_SUBDISP_SetKnobFromScroll 0x021F0CEC thumb ov031
 */
typedef struct B B;
extern void UNION_SUBDISP_SetScrollFromKnob(B *, B *);
extern void UNION_SUBDISP_SetKnobFromScroll(char *, B *);
void UNION_SUBDISP_SyncKnobAndScroll(char *a, unsigned char *b)
{
    if (b[0x31] == 1)
        UNION_SUBDISP_SetScrollFromKnob((B *)b, (B *)(a + 0x30e0));
    else
        UNION_SUBDISP_SetKnobFromScroll((char *)b, (B *)(a + 0x30e0));
}
