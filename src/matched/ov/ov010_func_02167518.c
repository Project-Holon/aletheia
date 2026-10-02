/*
 * function: func_02167518
 * address: 0x02167518
 * packet: pkt_ov010_02167518
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_02172A18 0x02172A18 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const char d_02172A18[];
extern void *func_02030734(u32, u32, int, const char *, u16);
void *func_02167518(int a, void *b, u16 heap, int c) {
    u8 *p;
    p = func_02030734(heap, 148, 1, d_02172A18, 97);
    p[142] = a;
    *(void **)p = b;
    *(u16 *)(p+140) = heap;
    p[144] = c;
    return p;
}
