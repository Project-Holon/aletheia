/*
 * function: GFL_NET_SetAutoExit
 * address:  0x0203D7B0
 * packet:   pkt_0203D7B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * blocker:  none available -- the ABS32 at +0008 names 0x0203C8E8, whose
 *           prologue is `ldr r1, [pc, #0xc]` and saves no lr, so disasm.py
 *           emitted no func_ label there (the unlabelled-leaf idiom) and
 *           evidence().labels has no entry.  sole-ref/code therefore refuses
 *           it, veneer_at() does not recognise it, and the pool word under
 *           test is the only reference to it in the image, so `literal` and
 *           `label` both discard their only witness.  All 12 bytes are
 *           correct.  It becomes EXACT the moment 0x0203C8E8 is seeded into
 *           layout/function_starts.txt (the integrator's file) or a second
 *           referrer is decompiled.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/pending/GFL_NET_SetAutoExit.c \
 *       --func GFL_NET_SetAutoExit --addr 0x0203D7B0 --cc 1.1p1 --arm
 *
 * symbols:
 *   GFL_NET_STATE_SetAutoExit  0x0203C8E8  arm
 */

typedef unsigned char  u8;
extern void GFL_NET_STATE_SetAutoExit(u8 v);

void GFL_NET_SetAutoExit(u8 a0)
{
    GFL_NET_STATE_SetAutoExit(a0);
}
