/*
 * function: func_0221336C
 * address: 0x0221336C
 * packet: pkt_ov199_0221336C
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0201A918 0x0201A918 thumb
 *   d_02213D04 0x02213D04 data ov199 a1
 */
extern int func_0201A918(void);
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, int, unsigned int);
extern const char d_02213D04[];
void func_0221336C(char *p, int heap)
{
    int size;
    *(void **)(p + 0x28) = func_02030734(heap, func_0201A918() + 0xd4, 0, d_02213D04, 0x72d);
    size = func_0201A918() + 0xd4;
    func_02082BCC(*(void **)(p + 0x28), 0, size);
    *(void **)(p + 0x2c) = func_02030734(heap, func_0201A918() + 0xd4, 0, d_02213D04, 0x72f);
    size = func_0201A918() + 0xd4;
    func_02082BCC(*(void **)(p + 0x2c), 0, size);
}
