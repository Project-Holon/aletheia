/*
 * function: func_021F9E50
 * address: 0x021F9E50
 * packet: pkt_ov132_021F9E50
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02050B80 0x02050B80 arm
 *   d_021FDCB0 0x021FDCB0 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void *func_02030734(unsigned, unsigned, int, const char *, u16);
extern void func_02050B80(unsigned);
extern const char d_021FDCB0[];
char *func_021F9E50(unsigned heap)
{
    u8 i = 0;
    char *p = func_02030734(heap, 0x24244, 0, d_021FDCB0, 76);
    *(u16 *)p = heap;
    func_02050B80(heap);
    for (; i < 8; i++)
        *(int *)(p + i * 0x4848 + 4) = 0;
    return p;
}
