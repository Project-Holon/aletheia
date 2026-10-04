/*
 * function: func_021F4FA4
 * address:  0x021F4FA4
 * packet:   pkt_021F4FA4
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocker resolved: 0x020056BC was matched in arm9 (src/matched/
 * func_020056BC.c, shard pkt_020056BC); the call now attests as `matched`.
 * All 32 bytes are right.
 *
 * symbols:
 *   func_020056BC  0x020056BC  thumb
 *
 *
 * Start a frame with the 0x48-byte object held at +0xd40 and keep the result at +0xdf8.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_021F4FA4.c --func func_021F4FA4  *       --addr 0x021F4FA4 --region ov135 --thumb --cc dsi/1.1p1 --diff
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_020056BC(void);
extern u8 *func_0202EE30(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);

void func_021F4FA4(u8 *p)
{
    *(u32 *)(p + 0xdf8) = (u32)func_0202EE30((void *)func_020056BC(), (void *)(*(u32 *)(p + 0xd40)),
                                        0xf, 0x10, 0x48);
}
