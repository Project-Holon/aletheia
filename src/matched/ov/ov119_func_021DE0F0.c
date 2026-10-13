/*
 * function: func_021DE0F0
 * address:  0x021DE0F0
 * packet:   pkt_ov119_021DE0F0
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_SendToHandle  0x0203D3A8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021DDF74  0x021DDF74  thumb  ov119
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
struct Link;
extern void func_02039C68(struct Link *h, u32 a, u32 b);
extern void func_021D8E84(void *p, int next);
extern void func_021DDF74(char *p);

void func_021DE0F0(void *p)
{
    u8 cmd;
    cmd = 0xB;
    if (GFL_NET_SendToHandle((struct Entry *)((u32)GFL_NET_HANDLE_GetCurrentHandle()), 0xC00, 1, (u32)(&cmd)) != 0) {
        func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1C, 8);
        func_021D8E84(p, (int)func_021DDF74);
    }
}
