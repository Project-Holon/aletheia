/*
 * function: func_021D6CF4
 * address: 0x021D6CF4
 * packet: pkt_ov121_021D6CF4
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_02030734 0x02030734 arm
 *   func_02050C04 0x02050C04 arm
 *   d_021DFB80 0x021DFB80 data ov121 a1
 */
extern void func_02082BCC(void *, int, int);
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02050C04(void *, int, int, int);
extern const char d_021DFB80[];
void func_021D6CF4(int *p, int heap)
{
    void *v;
    func_02082BCC(p, 0, 16);
    p[3] = 1;
    v = func_02030734(heap, 0x4800, 0, d_021DFB80, 0x482);
    p[2] = (int)v;
    p[0] = (int)func_02050C04(v, 0x4800, 1, heap);
}
