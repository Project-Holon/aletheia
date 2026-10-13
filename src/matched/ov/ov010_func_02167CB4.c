/*
 * function: BSUBWAY_COMM_SendData
 * address:  0x02167CB4
 * packet:   pkt_ov010_02167CB4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200FB24  0x0200FB24  thumb
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_SendToHandle  0x0203D3A8  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;


typedef struct Obj {
    u8 pad00[0x12];
    u16 h12;
    u8 pad14[0x668 - 0x14];
    u8 b668[0x1C];
} Obj;

extern u32 func_0200FB24(void);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);

int BSUBWAY_COMM_SendData(Obj *o)
{
    u16 h;

    if (func_0200FB24() != 0)
        return 1;
    h = o->h12;
    if (h >= 0x2C08)
        return 1;
    if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), h, 0x46, (u32)o->b668) == 1)
        return 1;
    return 0;
}
