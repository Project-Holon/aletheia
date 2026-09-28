/*
 * function: func_0204EE64
 * address:  0x0204EE64
 * packet:   pkt_0204EE0C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02046FF8   0x02046FF8  arm
 *   func_02047388   0x02047388  arm
 *   func_020473B8   0x020473B8  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204EE64.c \
 *       --func func_0204EE64 --addr 0x0204EE64 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02046FF8(u32 heapId);
extern u32 func_02047388(u32 heapId);
extern u32 func_020473B8(u32 heapId);

struct Struct_0204EE64 {
    u32 heapId;
    u8 pad[0xc - 4];
    u32 offC;
    u32 off10;
    u8 pad2[0x20 - 0x14];
    u32 off20;
    u32 off24;
};

void func_0204EE64(struct Struct_0204EE64 *p, u32 heapId)
{
    u32 res;

    p->heapId = heapId;
    if (func_02046FF8(heapId) == 0) {
        p->offC = 0;
        p->off10 = 0;
        return;
    }

    p->off20 = func_02047388(heapId);
    res = func_020473B8(heapId);

    p->off24 = res;
    p->offC = (u32)(p->off20 << 16) >> 13;
    p->off10 = (u32)(res << 16) >> 13;
}
