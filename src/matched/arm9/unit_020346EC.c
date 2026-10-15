/*
 * function: SAVEDATA_SetPanicHandlers
 * address:  0x020346EC
 * packet:   pkt_020345F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_Sink  0x0214699C  data
 *
 * Stores its three call arguments into fixed offsets of a fixed global.
 * g_Sink is the same address SAVEDATA_PanicFail (pkt_02034714, this packet's
 * neighbour) reads back at +0xc as a callback pointer: this is the
 * "register" half of an assert/panic hook the next packet's first
 * function fires. This function only ever touches offsets 0, 4 and 8, so
 * the callback slot at +0xc is left out of the struct here.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/unit_020346EC.c \
 *       --func SAVEDATA_SetPanicHandlers --addr 0x020346EC --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Sink {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern struct Sink g_Sink;

void SAVEDATA_SetPanicHandlers(u32 a, u32 b, u32 c)
{
    g_Sink.unk8 = a;
    g_Sink.unk4 = b;
    g_Sink.unk0 = c;
}
