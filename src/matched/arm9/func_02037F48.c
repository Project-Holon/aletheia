/*
 * function: GFL_NET_SYSTEM_SendWireless
 * address:  0x02037F48
 * packet:   pkt_02037F48
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Declaration order is what closes this one: p must be declared LAST of the
 * four locals so it takes r6 and the loop index takes r4 (see
 * docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 * The failure arm of the +0x5C poll is an out-of-line `goto`, not an
 * if-converted tail; the (u16) truncation of v happens after the n>0 test
 * and the index is zeroed before it.
 *
 * symbols:
 *   lbl_021469D0   0x021469D0  data
 *   d_020A7A20     0x020A7A20  data
 *   GFL_NET_GetSession  0x0203D788  arm
 *   GFL_NET_GetChildSendSize  0x0203D6BC  arm
 *   GFL_NET_GetMaxConnectNum  0x0203D680  arm
 *   GFL_NET_SYSTEM_PackSendData  0x02037D98  arm
 *   GFL_NET_SYSTEM_RecvChildData  0x020387A0  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *lbl_021469D0;
extern u8 d_020A7A20[];
extern void *GFL_NET_GetSession(void);
extern u32 GFL_NET_GetChildSendSize(void);
extern u32 GFL_NET_GetMaxConnectNum(void);
extern int GFL_NET_SYSTEM_PackSendData(int a);
extern int GFL_NET_SYSTEM_RecvChildData(u32 i, u8 *p, s32 n);

void GFL_NET_SYSTEM_SendWireless(void)
{
    s32 i;
    s32 n;
    u32 v;
    u8 *p;

    p = GFL_NET_GetSession();

    if (((u32 (*)(void)) * (u32 *)(*(u32 *)(p + 0x340) + 0x58))() == 0)
        return;

    if (*(u8 *)(lbl_021469D0 + 0x1EB) != 0)
        GFL_NET_SYSTEM_PackSendData(1);

    if (((u32 (*)(u32)) * (u32 *)(*(u32 *)(p + 0x340) + 0x5C))(*(u32 *)lbl_021469D0) != 1)
        goto fail;

    *(u8 *)(d_020A7A20 + 1) = 4;
    *(u8 *)(lbl_021469D0 + 0x1EB) = 1;

    v = GFL_NET_GetChildSendSize();
    n = GFL_NET_GetMaxConnectNum();
    i = 0;
    if (n > 0) {
        v = (unsigned short)v;
        do {
        GFL_NET_SYSTEM_RecvChildData((unsigned short)i,
                      (u8 *)(((u32 (*)(u32))
                           * (u32 *)(*(u32 *)(p + 0x340) + 0x60))(i)), v);
            i++;
        } while (i < n);
    }
    return;

fail:
    *(u8 *)(lbl_021469D0 + 0x1EB) = 0;
}
