/*
 * function: RESEARCH_LIST_ComputeCenterScroll
 * address: 0x021BBBE4
 * packet: pkt_ov217_021BBBE4
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: non-strict min/max ternaries retain the original ble/bge branches.
 * symbols:
 *   RESEARCH_LIST_GetScrollMin 0x021BC3D4 thumb ov217
 *   RESEARCH_LIST_GetScrollMax 0x021BC3E0 thumb ov217
 *   RESEARCH_LIST_GetRowBase 0x021BBF1C thumb ov217
 *   RESEARCH_LIST_StartScrollAnim 0x021BC2CC thumb ov217
 */
typedef unsigned char u8;
extern unsigned RESEARCH_LIST_GetScrollMin(void);
extern unsigned RESEARCH_LIST_GetScrollMax(void);
extern unsigned RESEARCH_LIST_GetRowBase(unsigned, unsigned);
extern void RESEARCH_LIST_StartScrollAnim(void *, unsigned, unsigned, unsigned);
void RESEARCH_LIST_ComputeCenterScroll(u8 *p)
{
    int center, target, start, end;
    center = (int)(RESEARCH_LIST_GetScrollMin() + RESEARCH_LIST_GetScrollMax()) / 2;
    target = RESEARCH_LIST_GetRowBase((unsigned)p, p[0x32]) * 8;
    if (center < target) {
        start = RESEARCH_LIST_GetScrollMax();
        end = (target - center) + RESEARCH_LIST_GetScrollMax();
    } else {
        start = RESEARCH_LIST_GetScrollMin();
        end = RESEARCH_LIST_GetScrollMin() - (center - target);
    }
    RESEARCH_LIST_StartScrollAnim(p, start, end, ((start >= end ? start : end) - (start <= end ? start : end)) / 3);
}
