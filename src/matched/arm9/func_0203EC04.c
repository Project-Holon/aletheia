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
 *   GFL_NET_HANDLE_GetNetHandle  0x0203996C  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_SendDataMask  0x0203D4D0  arm
 */

typedef unsigned char u8;
extern int *g_021469F4;
typedef signed int     s32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetNetHandle(s32 idx);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
extern u32 GFL_NET_SendDataMask(u32 entry, u32 mask, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
u32 GFL_NET_LOWER_DATA_SendChunk(int a0)
{
    int a = *(int *)((char *)g_021469F4 + 0x2c);
    int b = *(int *)((char *)g_021469F4 + 0x20);
    int c = *(int *)((char *)g_021469F4 + 0x44);
    int v = b + c;
    int t;
    if (a == 1)
        t = (int)GFL_NET_HANDLE_GetNetHandle(0xff);
    else
        t = (int)GFL_NET_HANDLE_GetCurrentHandle();
    return GFL_NET_SendDataMask(t, *(u8 *)((char *)g_021469F4 + 0x28), 0xe, a0, v, 0, 1, 1);
}
