/*
 * function: func_021D5B10
 * address: 0x021D5B10
 * packet: pkt_ov123_021D5B10
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02034714 0x02034714 arm
 *   d_021DAA40 0x021DAA40 data ov123 a1
 *   d_021DAA54 0x021DAA54 data ov123 a1
 *   g_021DAC20 0x021DAC20 data ov123 a4
 */
typedef unsigned short u16;
extern char d_021DAA40[], d_021DAA54[];
extern char *g_021DAC20;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02034714(const char *expr, u32 line, const char *file);
char *func_021D5B10(int heap,int size)
{
    char *p;
    p=func_02030734(heap,0xd4,1,d_021DAA40,0x88);
    if (g_021DAC20) func_02034714(d_021DAA54,0,d_021DAA54);
    g_021DAC20=p;
    *(void **)(p+0xb8)=func_02030734(heap,size+0x40,0,d_021DAA40,0x8c);
    *(int *)(p+0xbc)=size;
    return p;
}
