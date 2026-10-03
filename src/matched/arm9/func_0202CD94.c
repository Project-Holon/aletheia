/*
 * function: func_0202CD94
 * address:  0x0202CD94
 * packet:   pkt_0202CC70
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0202CDD4  0x0202CDD4  thumb
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct WinMgr {
    void *wins;
    u16 unk04;
    u16      : 15;
    u16 flag : 1;
};

extern u32 func_0202CDD4(struct WinMgr *mgr, u32 idx);

void func_0202CD94(struct WinMgr *mgr)
{
    u32 i;

    if (!mgr->flag) return;
    mgr->flag = 0;
    for (i = 0; i < mgr->unk04; i++) {
        if (func_0202CDD4(mgr, i) == 1) mgr->flag = 1;
    }
}
