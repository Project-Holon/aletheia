/*
 * function: func_021B9B3C
 * address: 0x021B9B3C
 * packet: pkt_ov225_021B9B3C
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_0204A39C 0x0204A39C arm
 *   file 0x021BBFF4 data ov225 a1
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern char file[];
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void *func_0204A39C(void *, int, int, u32, u32 *);
void *func_021B9B3C(void *narc, u32 heap)
{
    void **p = func_02030734(heap, 16, 1, file, 0x9c);
    u32 size;
    p[0] = func_0204A39C(narc, 11, 0, heap, &size);
    p[1] = func_0204A39C(narc, 12, 0, heap, &size);
    p[2] = func_0204A39C(narc, 9, 0, heap, &size);
    p[3] = func_0204A39C(narc, 10, 0, heap, &size);
    return p;
}
