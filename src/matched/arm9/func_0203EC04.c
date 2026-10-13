/*
 * function: GFL_NET_LOWER_DATA_SendChunk
 * address:  0x0203EC04
 * packet:   pkt_0203EA9C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_021469F4      0x021469F4  data
 */

typedef unsigned char u8;
extern int *g_021469F4;
typedef signed int     s32;
struct Entry;
extern struct Entry *func_0203996C(s32 idx);
struct Entry;
extern struct Entry *func_020399A8(void);
typedef unsigned int   u32;
extern u32 func_0203D4D0(u32 entry, u32 mask, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
u32 GFL_NET_LOWER_DATA_SendChunk(int a0)
{
    int a = *(int *)((char *)g_021469F4 + 0x2c);
    int b = *(int *)((char *)g_021469F4 + 0x20);
    int c = *(int *)((char *)g_021469F4 + 0x44);
    int v = b + c;
    int t;
    if (a == 1)
        t = (int)func_0203996C(0xff);
    else
        t = (int)func_020399A8();
    return func_0203D4D0(t, *(u8 *)((char *)g_021469F4 + 0x28), 0xe, a0, v, 0, 1, 1);
}
