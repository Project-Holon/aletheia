/*
 * function: func_021D4AF4
 * address: 0x021D4AF4
 * packet: pkt_ov093_021D4AF4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F3B88 0x021F3B88 data ov093 a4
 *   GFL_NET_HANDLE_SetUserInfo 0x0203A424 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct S { void *f00; u32 f04; u16 f08; u8 pad[5]; u8 f0f; u8 f10; };
extern struct S *d_021F3B88;
extern void GFL_NET_HANDLE_SetUserInfo(char *p, int a, int b, int c);
void func_021D4AF4(int a)
{
    if (d_021F3B88 != 0) {
        d_021F3B88->f0f = a;
        d_021F3B88->f10 = 1;
        GFL_NET_HANDLE_SetUserInfo(d_021F3B88->f00, a, 1, d_021F3B88->f08);
    }
}
