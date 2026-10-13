/*
 * function: GFL_NET_SYSTEM_ResetBuffers
 * address:  0x02037478
 * packet:   pkt_02037478
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _pNetSys     0x021469D0  data
 *   str_020A7A20   0x020A7A20  data
 *   GFL_NET_GetMaxConnectNum  0x0203D680  arm
 *   GFL_NET_SYSTEM_GetSendSize  0x02037258  arm
 *   GFL_NET_GetChildSendSize  0x0203D6BC  arm
 *   func_02082BCC  0x02082BCC  arm
 *   GFL_NET_RING_BUFF_Init  0x0203640C  arm
 *   GFL_NET_SYSTEM_InitRecvState  0x02037234  arm
 *   GFL_NET_SYSTEM_SetDebugByte  0x02037224  arm
 *   GFL_NET_QUEUE_Reset  0x02036B4C  arm
 *
 * Second half of net_system init: wipe and re-seed every buffer
 * GFL_NET_SYSTEM_InitWork allocated (docs/families/net_system.h).  Closed from the
 * 520-byte / 135-out source of docs/notes/pkt_02037288_wave25.c.txt with two
 * changes:
 *   1. GFL_NET_RING_BUFF_Init is a THREE-argument call at every site.  The first
 *      loop's "leftover" r2 is the slot stride f1E0 passed as the header's
 *      length (same finding as GFL_NET_SYSTEM_ResetRecvBuffer); with it the file is 12 out.
 *   2. the loop index is declared FIRST, before the three counts.  With
 *      the counts first, n1 and i swap r7/r8 (the last 12 bytes).
 * The three product pairs stay spelled differently per site (n2 + n2 vs
 * n2 << 1, etc.) so the compiler rematerialises instead of CSEing them.
 */
typedef unsigned char  u8;
typedef unsigned int   u32;
typedef signed int     s32;

struct Net {
    u32  f00;
    u32 *f04;
    u8  *f08;
    u8  *f0C;
    u8  *f10;
    u8  *f14;
    u8   pad18[0x1b0 - 0x18];
    u32  f1B0;
    u32  f1B4[8];
    u8   pad1D4[0x1e0 - 0x1d4];
    u32  f1E0;
};

extern struct Net *_pNetSys;
extern u8 str_020A7A20[];
extern u32 GFL_NET_GetMaxConnectNum(void);
extern u32 GFL_NET_SYSTEM_GetSendSize(void);
extern u32 GFL_NET_GetChildSendSize(void);
extern void func_02082BCC(u8 *p, u32 v, u32 n);
struct Rec;
extern void GFL_NET_RING_BUFF_Init(struct Rec *p, u32 a, int b);
extern void GFL_NET_SYSTEM_InitRecvState(u8 *p);
extern void GFL_NET_SYSTEM_SetDebugByte(u8 v, int b);
extern int GFL_NET_QUEUE_Reset(int a0);

void GFL_NET_SYSTEM_ResetBuffers(void)
{
    s32 i;
    s32 n1;
    s32 n2;
    s32 n3;

    n1 = GFL_NET_GetMaxConnectNum();
    n2 = GFL_NET_SYSTEM_GetSendSize();
    n3 = GFL_NET_GetChildSendSize();

    func_02082BCC(_pNetSys->f10, 0, _pNetSys->f1E0 * n1);
    for (i = 0; i < n1; i++) {
        GFL_NET_RING_BUFF_Init((struct Rec *)((u8 *)_pNetSys + 0x4c + i * 16),
              (u32)(_pNetSys->f10 + i * _pNetSys->f1E0), _pNetSys->f1E0);
        ((u8 *)_pNetSys)[0x1d7 + i] = 0;
    }

    func_02082BCC(_pNetSys->f0C, 0, n2 + n2);
    GFL_NET_RING_BUFF_Init((struct Rec *)((u8 *)_pNetSys + 0x3c), (u32)_pNetSys->f0C, (u32)n2 << 1);
    for (i = 0; i < n2; i++)
        _pNetSys->f08[i] = 0;

    func_02082BCC((u8 *)_pNetSys->f04, 0, n3 * 16 - n3);
    GFL_NET_RING_BUFF_Init((struct Rec *)((u8 *)_pNetSys + 0x1c), (u32)((u8 *)_pNetSys->f04), ((u32)n3 << 4) - n3);
    *(u8 *)_pNetSys->f00 = 0xff;
    for (i = 1; i < n3; i++)
        ((u8 *)_pNetSys->f00)[i] = 0;

    func_02082BCC(_pNetSys->f14, 0, _pNetSys->f1E0 + _pNetSys->f1E0 * 2);
    GFL_NET_RING_BUFF_Init((struct Rec *)((u8 *)_pNetSys + 0x2c), (u32)_pNetSys->f14,
                  _pNetSys->f1E0 * 3);
    for (i = 0; i < 8; i++) {
        GFL_NET_SYSTEM_InitRecvState((u8 *)_pNetSys + 0x11c + i * 16);
        _pNetSys->f1B4[i] = 0;
    }
    _pNetSys->f1B0 = 0;
    GFL_NET_SYSTEM_InitRecvState((u8 *)_pNetSys + 0x19c);
    GFL_NET_SYSTEM_SetDebugByte(4, 0x13a);
    str_020A7A20[1] = 4;
    GFL_NET_QUEUE_Reset((int)((u8 *)_pNetSys + 0xcc));
    GFL_NET_QUEUE_Reset((int)((u8 *)_pNetSys + 0xf4));
    ((u8 *)_pNetSys)[0x1e8] = 0;
    ((u8 *)_pNetSys)[0x1eb] = 1;
    ((u8 *)_pNetSys)[0x1ea] = 0;
    ((u8 *)_pNetSys)[0x1ed] = 0;
}

