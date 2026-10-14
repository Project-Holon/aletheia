/*
 * function: BR_BTN_DATA_Create
 * address: 0x021FB5E4
 * packet: pkt_ov186_021FB5E4
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BR_BTN_DATA_Fill 0x021FB644 thumb ov186
 *   d_022007F0 0x022007F0 data a4
 *   d_02200D28 0x02200D28 data a1
 */
extern const unsigned short d_022007F0[][6];
extern char d_02200D28[];
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *, int, int);
extern void BR_BTN_DATA_Fill(char *ctx);
void *BR_BTN_DATA_Create(int *ctx, int heap)
{
    int total = 0;
    int i;
    int *result;
    for (i = 0; i < 12; i++) total += d_022007F0[i][0];
    result = func_02030734(heap, total * 24 + 4, 0, d_02200D28, 0x429);
    MI_CpuFill8(result, 0, total * 24 + 4);
    *result = *ctx;
    BR_BTN_DATA_Fill((char *)result);
    return result;
}
