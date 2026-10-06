/*
 * function: func_021FB5E4
 * address: 0x021FB5E4
 * packet: pkt_ov186_021FB5E4
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021FB644 0x021FB644 thumb ov186
 *   d_022007F0 0x022007F0 data a4
 *   d_02200D28 0x02200D28 data a1
 */
extern const unsigned short d_022007F0[][6];
extern char d_02200D28[];
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, int, int);
extern void func_021FB644(char *ctx);
void *func_021FB5E4(int *ctx, int heap)
{
    int total = 0;
    int i;
    int *result;
    for (i = 0; i < 12; i++) total += d_022007F0[i][0];
    result = func_02030734(heap, total * 24 + 4, 0, d_02200D28, 0x429);
    func_02082BCC(result, 0, total * 24 + 4);
    *result = *ctx;
    func_021FB644((char *)result);
    return result;
}
