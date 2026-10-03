/*
 * function: func_02213234
 * address: 0x02213234
 * packet: pkt_ov199_02213234
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
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, int, unsigned int);
extern const char d_02213D04[];
void *func_02213234(void *unused, int heap, char *p)
{
    unsigned int *work = func_02030734(heap, 0x1c, 0, d_02213D04, 0x6b2);
    func_02082BCC(work, 0, 0x1c);
    work[0] = *(unsigned int *)(p + 4);
    work[1] = 0;
    work[2] = 1;
    if (*(int *)(p + 0x24) != 0)
        work[4] = 0x12;
    return work;
}
