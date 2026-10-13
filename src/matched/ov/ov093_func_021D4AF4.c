/*
 * function: BTL_NET_BeginSync
 * address: 0x021D4AF4
 * packet: pkt_ov093_021D4AF4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gBtlNet 0x021F3B88 data ov093 a4
 *   GFL_NET_HANDLE_SetUserInfo 0x0203A424 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct S { void *f00; u32 f04; u16 f08; u8 pad[5]; u8 f0f; u8 f10; };
extern struct S *gBtlNet;
extern void GFL_NET_HANDLE_SetUserInfo(char *p, int a, int b, int c);
void BTL_NET_BeginSync(int a)
{
    if (gBtlNet != 0) {
        gBtlNet->f0f = a;
        gBtlNet->f10 = 1;
        GFL_NET_HANDLE_SetUserInfo(gBtlNet->f00, a, 1, gBtlNet->f08);
    }
}
