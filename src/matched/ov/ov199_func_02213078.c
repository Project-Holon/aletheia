/*
 * function: func_02213078
 * address: 0x02213078
 * packet: pkt_ov199_02213078
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   d_02213D04 0x02213D04 data ov199 a1
 */
extern void *func_02030734(int, unsigned int, int, const char *, int);
extern void func_02082BCC(void *, int, unsigned int);
extern const char d_02213D04[];
void *func_02213078(void *unused, int heap, char *p)
{
    unsigned int *work = func_02030734(heap, 0x1c, 0, d_02213D04, 0x5dc);
    func_02082BCC(work, 0, 0x1c);
    work[0] = (unsigned int)(p + 4);
    work[3] = *(unsigned int *)(p + 0x30);
    work[4] = *(unsigned int *)(p + 0x34);
    work[5] = (unsigned int)(p + 0x7d4);
    work[6] = (unsigned int)(p + 0x8a8);
    if (*(int *)(p + 0x1c) == 1)
        work[1] = 1;
    else
        work[1] = 0;
    return work;
}
