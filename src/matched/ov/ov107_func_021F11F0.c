/*
 * function: MB_COMM_SYS_SendMessage
 * address:  0x021F11F0
 * packet:   pkt_ov107_021F11F0
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   GFL_NET_HANDLE_GetNetHandle  0x0203996C  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_SendData  0x0203D3F8  arm
 */

typedef struct {
    unsigned int f00;
    unsigned char f04;
} Ov107Msg;

typedef signed int     s32;
typedef unsigned int   u32;
struct Entry;
u32 GFL_NET_IsParentAid(void);
struct Entry *GFL_NET_HANDLE_GetNetHandle(s32 idx);
struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
u32 GFL_NET_SendData(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

int MB_COMM_SYS_SendMessage(void *p, unsigned char kind, unsigned int val)
{
    Ov107Msg msg;
    void *obj;

    if (GFL_NET_IsParentAid() == 1) {
        obj = GFL_NET_HANDLE_GetNetHandle(0xFF);
    } else {
        obj = GFL_NET_HANDLE_GetCurrentHandle();
    }
    msg.f04 = kind;
    msg.f00 = val;
    return GFL_NET_SendData((u32)obj, 0xFF, 0x400, 8, (u32)(&msg), 1, 0, 0);
}
