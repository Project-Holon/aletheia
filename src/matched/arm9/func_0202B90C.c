/*
 * function: ISS_3DS_SYS_OnZoneChange
 * address:  0x0202B90C
 * packet:   pkt_0202B90C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0202BB40  0x0202BB40  thumb
 *
 * A bare tail-call thunk, same shape as ISS_3DS_SYS_Update (ldr r3, [pc, #0];
 * bx r3; .word 0x0202BB41).  0x0202BB40 is itself another thunk (to
 * ISS_3DS_SYS_ResetSources), filed as src/matched/func_0202BB40.c in the same shard;
 * that entry is the matched witness for this pool word.
 */

typedef unsigned char  u8;
extern void func_0202BB40(u8 *p);

void ISS_3DS_SYS_OnZoneChange(u8 *a0)
{
    func_0202BB40(a0);
}
