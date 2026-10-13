/*
 * function: GFL_NET_SYSTEM_SendEndCallback
 * address:  0x02038A90
 * packet:   pkt_02038A90
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   str_020A7A24   0x020A7A24  data
 *   str_020A7A50   0x020A7A50  data
 *   func_02034714  0x02034714  arm
 *   GFL_NET_GetChildSendSize  0x0203D6BC  arm
 *   GFL_NET_GetMaxConnectNum  0x0203D680  arm
 *   func_0203D798  0x0203D798  arm
 *   GFL_NET_SYSTEM_SetDebugByte  0x02037224  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern const u8 str_020A7A24[];
extern const u8 str_020A7A50[];
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 GFL_NET_GetChildSendSize(void);
extern u32 GFL_NET_GetMaxConnectNum(void);
extern void *func_0203D798(void);
extern void GFL_NET_SYSTEM_SetDebugByte(u8 v, int b);

int GFL_NET_SYSTEM_SendEndCallback(u32 a)
{
    GFL_NET_GetChildSendSize();
    GFL_NET_GetMaxConnectNum();
    func_0203D798();
    if (a != 0) {
        GFL_NET_SYSTEM_SetDebugByte(4, 0x5d4);
    } else {
        func_02034714((const char *)str_020A7A24, 0x5d8, (const char *)str_020A7A50);
    }
    return 1;
}
