/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x02005B04
 * packet:   pkt_02005924
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: GFL_USE_ReleaseWaveArcSet
 *
 * symbols:
 *   _SndStack  0x020AA1AC  data
 *   GFL_USE_BeginSndSlot      0x02005834  thumb
 *   GFL_USE_EndSndSlot      0x02005858  thumb
 *   func_020748E0     0x020748E0  arm
 *
 * Close the current connection slot with a status word taken from the
 * second word of the argument block.  Its own byte range because the
 * function immediately before it, 0x02005A98, cannot be attested: the only
 * `blx` to func_02074A6C anywhere in the image is the one inside it.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub02005B04Cur {
    u16   unk00;
    u16   unk02;
    int   index;
    u32 **unk08;
};

extern struct Sub02005B04Cur _SndStack;

extern void GFL_USE_BeginSndSlot(u32 v);
extern void GFL_USE_EndSndSlot(void);
extern void func_020748E0(u32 *a, u32 b);

void GFL_USE_ReleaseWaveArcSet(const u32 *arg)
{
    u32 v = arg[1];

    GFL_USE_EndSndSlot();
    func_020748E0(*_SndStack.unk08, v);
    GFL_USE_BeginSndSlot(v);
}
