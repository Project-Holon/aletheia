/*
 * function: GFL_NET_SYSTEM_RecvParentCallback
 * address:  0x020381D8
 * packet:   pkt_02037F48
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   GFL_NET_GetSession  0x0203D788  arm
 *   GFL_NET_SYSTEM_RecvData  0x020380E4  arm
 *   func_02034714  0x02034714  arm
 *   GFL_NET_SYSTEM_SetDebugByte  0x02037224  arm
 *   d_020A7A20     0x020A7A20  data
 *   d_020A7A24     0x020A7A24  data
 *   d_020A7A50     0x020A7A50  data
 *
 * Second half of this packet's chain: it calls GFL_NET_SYSTEM_RecvData, whose own entry
 * is in this shard, so the call site is attested by `matched` rather than by
 * the single in-range witness the lane table saw.
 *
 * The flow: two global locks are set up, then the interface object reached
 * through *(p + 0x340) is asked twice (its +0xA4 and +0xAC entries); only if
 * both answer non-zero does the transfer run - otherwise the two literals at
 * 0x020A7A24/0x020A7A50 go to 0x02034714 with 0x400.  The transfer calls the
 * object's +0x64 entry with the two arguments and zeroed r2/r3, reads the
 * +0x80 entry for the record number, and hands (u16)record-number, first
 * argument and (u16)second argument to GFL_NET_SYSTEM_RecvData before the fixed 4 /
 * 0x40C delay through 0x02037224.
 *
 * The guards' polarity is the `bne` / `beq` pair at +0x2C and +0x38: the two
 * object calls are one conjunction whose false arm is the failure block
 * written first, which is the if/else spelling and not a guard chain.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_RecvParentCallback.c \
 *       --func GFL_NET_SYSTEM_RecvParentCallback --addr 0x020381D8 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *GFL_NET_GetInitParam(void);
extern void *GFL_NET_GetSession(void);
extern u32 GFL_NET_SYSTEM_RecvData(u32 a0, u8 *rec, u32 len);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void GFL_NET_SYSTEM_SetDebugByte(u8 v, int b);
extern u8 d_020A7A20[];
extern u8 d_020A7A24[];
extern u8 d_020A7A50[];

void GFL_NET_SYSTEM_RecvParentCallback(u32 a0, u32 a1)
{
    u8 *p;
    u32 v;

    GFL_NET_GetInitParam();
    p = GFL_NET_GetSession();

    if (((u32 (*)(void)) * (u32 *)(*(u32 *)(p + 0x340) + 0xA4))() == 0 ||
        ((u32 (*)(void)) * (u32 *)(*(u32 *)(p + 0x340) + 0xAC))() == 0) {
        func_02034714((const char *)d_020A7A24, 0x400, (const char *)d_020A7A50);
        return;
    }

    if (*(u8 *)(d_020A7A20 + 1) != 0)
        return;
    ((void (*)(u32, u32, u32, u32))
         * (u32 *)(*(u32 *)(p + 0x340) + 0x64))(a0, a1, 0, 0);
    v = ((u32 (*)(void)) * (u32 *)(*(u32 *)(p + 0x340) + 0x80))();
    GFL_NET_SYSTEM_RecvData((u16)v, (u8 *)a0, (u16)a1);
    GFL_NET_SYSTEM_SetDebugByte(4, 0x40C);
}
