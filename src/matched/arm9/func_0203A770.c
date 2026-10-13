/*
 * function: GFL_NET_COMMAND_CallCommand
 * address:  0x0203A770
 * packet:   pkt_0203A748
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   GFL_NET_COMMAND_GetHeaderSize 0x0203A634  arm
 *   GFL_NET_HANDLE_IsNegotiationDone 0x020399B8  arm
 *   GFL_NET_COMMAND_GetRecvFunc 0x0203A70C  arm
 *   GFL_NET_COMMAND_GetCommandWork 0x0203A730  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 GFL_NET_COMMAND_GetHeaderSize(u32 a);
extern u32 GFL_NET_HANDLE_IsNegotiationDone(u8 *p);
extern int GFL_NET_COMMAND_GetRecvFunc(u32 idx);
extern u32 GFL_NET_COMMAND_GetCommandWork(u32 a);

void GFL_NET_COMMAND_CallCommand(u32 a, u32 b, int c, u32 d, u32 e, u32 f)
{
    u32 ok;
    u32 fn;

    if (GFL_NET_COMMAND_GetHeaderSize(b) == 0) {
        return;
    }
    ok = 1;
    if (GFL_NET_HANDLE_IsNegotiationDone((u8 *)f) == 0) {
        if (c >= 0x11) {
            ok = 0;
        }
    }
    if (ok == 0) {
        return;
    }
    fn = GFL_NET_COMMAND_GetRecvFunc(c);
    if (fn == 0) {
        return;
    }
    ((void (*)(u32, u32, u32, u32, u32))fn)(a, d, e, GFL_NET_COMMAND_GetCommandWork(c), f);
}
