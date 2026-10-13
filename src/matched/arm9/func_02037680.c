/*
 * function: GFL_NET_SYSTEM_ResetRecvBuffer
 * address:  0x02037680
 * packet:   pkt_02037478
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   str_020A7A24   0x020A7A24  data
 *   str_020A7A34   0x020A7A34  data
 *   _pNetSys     0x021469D0  data
 *   func_02034714  0x02034714  arm
 *   GFL_NET_RING_BUFF_Init  0x0203640C  arm
 *   GFL_NET_SYSTEM_InitRecvState  0x02037234  arm
 *
 * Reset one net_system slot (docs/families/net_system.h).  The 8-byte
 * "colouring" residue of docs/notes/pkt_02037288_wave25.c.txt was a wrong
 * reading of the callee's argument list: GFL_NET_RING_BUFF_Init here takes THREE
 * arguments, (header, buffer, length), and r2 at the call is the slot
 * stride f1E0 passed on purpose as the buffer length, not a leftover of
 * the mla.  The slot header is initialised to { f10 + i * f1E0, f1E0 }.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Net {
    u8 pad00[0x10];
    u8 *f10;
    u8 pad14[0x4c - 0x14];
    u8 f4C[0x11c - 0x4c];
    u8 f11C[0x1b4 - 0x11c];
    u32 f1B4[8];
    u8 pad1D4[0x1d7 - 0x1d4];
    u8 f1D7[8];
    u8 pad1DF[0x1e0 - 0x1df];
    u32 f1E0;
};

extern const u8 str_020A7A24[];
extern const u8 str_020A7A34[];
extern struct Net *_pNetSys;
extern void func_02034714(const char *expr, u32 line, const char *file);
struct Rec;
extern void GFL_NET_RING_BUFF_Init(struct Rec *p, u32 a, int b);
extern void GFL_NET_SYSTEM_InitRecvState(u8 *p);

void GFL_NET_SYSTEM_ResetRecvBuffer(int i)
{
    if (i >= 8) {
        func_02034714((const char *)str_020A7A24, 0x155, (const char *)str_020A7A34);
    }
    _pNetSys->f1B4[i] = 0;
    GFL_NET_RING_BUFF_Init((struct Rec *)(_pNetSys->f4C + i * 16), (u32)(_pNetSys->f10 + i * _pNetSys->f1E0), _pNetSys->f1E0);
    _pNetSys->f1D7[i] = 0;
    GFL_NET_SYSTEM_InitRecvState(_pNetSys->f11C + i * 16);
}
