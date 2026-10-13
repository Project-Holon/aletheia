/*
 * function: func_021DC1A0
 * address:  0x021DC1A0
 * packet:   pkt_021DC1A0
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm
 *   GFL_NET_SendData  0x0203D3F8  arm
 *   POKE_REGULATION_GetDataSize  0x0201A918  thumb
 *
 * Sends through the eight-argument link routine with arguments (link, flag, 0x2401, size + 0xd4, data, 1, 1, 1); size is 0x0201A918's constant.
 */

typedef unsigned char u8;
typedef unsigned long u32;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern u32 GFL_NET_SendData(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern int POKE_REGULATION_GetDataSize(void);

u32 func_021DC1A0(char *obj, u32 data)
{
    u32 busy = GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle()));
    int flag = 1;

    if (busy != 0)
        flag = 0;
    return GFL_NET_SendData((u32)GFL_NET_HANDLE_GetCurrentHandle(), (u8)flag, 0x2401, POKE_REGULATION_GetDataSize() + 0xd4, data, 1, 1, 1);
}
