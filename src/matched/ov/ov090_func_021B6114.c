/*
 * function: PLIST_COMM_Update
 * address:  0x021B6114
 * packet:   pkt_ov090_021B6114
 * region:   ov090
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   GFL_NET_COMMAND_AddCommandTable  0x0203A574  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   gPartyListCommandTable     0x021B6228  data  a4
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void func_02039C68(struct Link *p, unsigned int lo, unsigned int hi);
struct Link;
extern unsigned int func_02039CB4(struct Link *p, unsigned int lo, unsigned int hi);
extern void GFL_NET_COMMAND_AddCommandTable(u32 a, u32 b, u32 c, u32 d);
extern u32 func_0200FB24(void);
extern u8 gPartyListCommandTable[];

void PLIST_COMM_Update(u8 *p)
{
    switch (p[0x62]) {
    case 0:
        func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 1, 0x2d);
        p[0x62] = 1;
        break;
    case 1:
        if (func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 1, 0x2d) == 1) {
            GFL_NET_COMMAND_AddCommandTable(0x2d00, (u32)gPartyListCommandTable, 1, (u32)p);
            p[0x62] = 2;
        }
        break;
    case 2:
        break;
    }
    if (func_0200FB24() != 0 && p[0x63] == 0)
        p[0x63] = 1;
}
