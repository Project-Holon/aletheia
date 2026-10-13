/*
 * function: GFL_NET_SYSTEM_DispatchRecv
 * address:  0x02038D68
 * packet:   pkt_02038D68
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203D798   0x0203D798  arm
 *   func_02039338   0x02039338  arm
 *   func_0203996C   0x0203996C  arm
 *   GFL_NET_COMMAND_CallCommand   0x0203A770  arm
 *   GFL_NET_SYSTEM_InitRecvState   0x02037234  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_DispatchRecv.c \
 *       --func GFL_NET_SYSTEM_DispatchRecv --addr 0x02038D68 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef unsigned short u16;
extern void *func_0203D798(void);
extern u16 func_02039338(void);
typedef signed int     s32;
struct Entry;
extern struct Entry *func_0203996C(s32 idx);
extern void GFL_NET_COMMAND_CallCommand(u32 a, u32 b, int c, u32 d, u32 e, u32 f);
extern void GFL_NET_SYSTEM_InitRecvState(u8 *p);

void GFL_NET_SYSTEM_DispatchRecv(int a0, u32 a1, u32 a2, u8 *a3)
{
    u32 v;

    func_0203D798();
    v = (u32)func_0203996C(func_02039338());
    GFL_NET_COMMAND_CallCommand(a3[0x0E], a3[0x0F], a0, a1, a2, v);

    if (func_02039338() == 0) {
        v = (u32)func_0203996C(0xFF);
        if (a0 < 0x11)
            GFL_NET_COMMAND_CallCommand(a3[0x0E], a3[0x0F], a0, a1, a2, v);
    }

    GFL_NET_SYSTEM_InitRecvState(a3);
}
