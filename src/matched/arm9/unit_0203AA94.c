/*
 * unit:     yes
 * function: GFL_NET_COMMAND_SetSendSlot
 * address:  0x0203AA94
 * packet:   pkt_0203A958
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _pCommandWork     0x021469D8  data
 *   g_020A7AF8     0x020A7AF8  data
 *   g_020A7B78     0x020A7B78  data
 *   func_0203D798  0x0203D798  arm
 *   func_02034714  0x02034714  arm
 *   GFL_NET_HANDLE_GetNetHandleID  0x020395EC  arm
 *   GFL_NET_SYSTEM_SetSendQueue  0x02038C18  arm
 *   _u32_div_f     0x0209C2B0  arm
 *
 * The net_command.c command-queue trio, 0x0203AA94..0x0203AD6C, folded into
 * one translation unit: the enqueue (GFL_NET_COMMAND_SetSendSlot), the header pump
 * (GFL_NET_COMMAND_SendNextSlot) and the chunk pump (GFL_NET_COMMAND_Main).  All three walk the
 * same five 0x18-byte slot table at _pCommandWork and share the 4-bit status
 * nibble pair at record +0x17 / table +0x57.  Filed as a unit because the
 * three are individually EXACT and reproduce the range with its pools.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0203AA94.c \
 *       --addr 0x0203AA94 --arm
 */
#include "../include/Obj01629.h"
#include "../include/Obj01823.h"
#include "../include/Obj04116.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8   *_pCommandWork;
extern char  g_020A7AF8[];
extern char  g_020A7B78[];
struct Entry;
extern void *func_0203D798(void);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern int GFL_NET_HANDLE_GetNetHandleID(struct Entry *a);
extern int GFL_NET_SYSTEM_SetSendQueue(u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);

typedef struct {
    u8 lo : 4;
    u8 hi : 4;
} Status;

u32 GFL_NET_COMMAND_SetSendSlot(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4)
{
    u8 *cfg;
    u8 *t;
    u8 *st57;
    u8 *s;
    int i;
    int mtu;
    Status *sc;
    Status *st;

    cfg = func_0203D798();
    t = _pCommandWork;
    st57 = t + 0x57;
    for (i = 0; i < 5; i++) {
        sc = (Status *)&st57[i * 0x18];
        if (sc->hi)
            continue;
        if (sc->lo == 0)
            break;
    }
    if (i == 5)
        return 0;

    s = t + 0x40 + i * 0x18;
    ((struct Obj01629 *)s)->f4 = a3;
    mtu = cfg[0x61] - 0xc;
    if (mtu <= 0)
        func_02034714(g_020A7AF8, 0x22b, g_020A7B78);
    ((struct Obj01629 *)s)->fE = cfg[0x61] - 0xc;
    ((struct Obj01629 *)s)->f14 = a3 / ((struct Obj01629 *)s)->fE;
    ((struct Obj01629 *)s)->f10 = a3 % ((struct Obj01629 *)s)->fE;
    if (((struct Obj01629 *)s)->f10 != 0)
        ((struct Obj01629 *)s)->f14 = ((struct Obj01629 *)s)->f14 + 1;
    ((struct Obj01629 *)s)->f12 = 0;
    ((struct Obj01629 *)s)->fC = a2;
    s[0x16] = a1;
    ((struct Obj01629 *)s)->f8 = a4;
    ((struct Obj01629 *)s)->f0 = GFL_NET_HANDLE_GetNetHandleID((void *)a0);
    st = (Status *)(s + 0x17);
    st->hi = 1;
    return st->hi;
}

u32 GFL_NET_COMMAND_SendNextSlot(void)
{
    u16 hdr[6];
    u8 *s;
    Status *st;
    u8 *t;
    int i;

    t = _pCommandWork + 0x40;
    for (i = 0; i < 5; i++) {
        s = t + i * 0x18;
        st = (Status *)(s + 0x17);
        if (st->hi) {
            hdr[2] = ((struct Obj04116 *)s)->f14;
            *(u32 *)&hdr[0] = ((struct Obj04116 *)s)->f4;
            hdr[3] = ((struct Obj04116 *)s)->fC;
            hdr[4] = ((struct Obj04116 *)s)->fE;
            hdr[5] = s[0x16];
            st->lo = GFL_NET_SYSTEM_SetSendQueue(0xd, (u32)hdr, 0xc, 1,
                                   ((struct Obj04116 *)s)->f0, s[0x16], 0);
            st->hi = 1 - st->lo;
            return st->lo;
        }
    }
    return 0;
}

void GFL_NET_COMMAND_Main(void)
{
    int i;
    u32 n;
    u32 c;
    u32 base;
    u8 *t;
    u8 *s;

    t = _pCommandWork;
    for (i = 0; i < 5; i++) {
        if ((u32)(t[i * 0x18 + 0x57] << 0x1c) >> 0x1c) {
            s = t + 0x40 + i * 0x18;
            c = ((struct Obj01823 *)s)->f12;
            n = ((struct Obj01823 *)s)->fE;
            base = ((struct Obj01823 *)s)->f8 + n * c;
            if (c + 1 == ((struct Obj01823 *)s)->f14)
                n = ((struct Obj01823 *)s)->f10;
            if (GFL_NET_SYSTEM_SetSendQueue(0xc, base, n, 1,
                              ((struct Obj01823 *)s)->f0, s[0x16], 1) != 0)
                ((struct Obj01823 *)s)->f12 = ((struct Obj01823 *)s)->f12 + 1;
            if (((struct Obj01823 *)s)->f12 == ((struct Obj01823 *)s)->f14)
                s[0x17] = s[0x17] & ~0xf;
            return;
        }
    }
    GFL_NET_COMMAND_SendNextSlot();
}
