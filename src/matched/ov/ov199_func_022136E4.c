/*
 * function: func_022136E4
 * address: 0x022136E4
 * packet: pkt_ov199_022136E4
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02031324 0x02031324 arm
 *   d_02213D04 0x02213D04 data ov199 a1
 */
extern void *func_02030734(int, unsigned int, int, const char *, int);
extern void func_02082BCC(void *, int, unsigned int);
extern void *func_02031324(int);
extern const char d_02213D04[];
void *func_022136E4(void *a, void *b, void *c, int heap)
{
    char *work = func_02030734(heap, 0x20, 0, d_02213D04, 0x846);
    func_02082BCC(work, 0, 0x20);
    *(void **)work = func_02031324(heap);
    *(void **)(work + 0xc) = c;
    *(void **)(work + 0x10) = a;
    *(void **)(work + 0x14) = b;
    *(unsigned short *)(work + 8) = heap;
    return work;
}
