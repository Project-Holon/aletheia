/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * function: ISS_CITY_UNIT_CalcVolume
 * address:  0x0202AF34
 * packet:   pkt_0202AF34
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A bare tail-call thunk to ISS_CITY_UNIT_CalcVolumeFromAxes (ldr r3, pool; bx r3; .word
 * 0x0202AF75).  Blocked at MATCH on `literal`: the pointer word 0x0202AF75
 * appears in exactly one literal pool image-wide, this thunk's own at
 * 0x0202AF38, so the ABS32 site has no outside witness.  There is no branch
 * to 0x0202AF74 anywhere else in the image either, so the `label` class is
 * empty too.  Closes when ISS_CITY_UNIT_CalcVolumeFromAxes acquires a manifest entry that is
 * not this file's own (a second reader of the thunk, or a matched
 * ISS_CITY_UNIT_CalcVolumeFromAxes elsewhere).
 *
 * THE BODY BELOW IS NEW (third band pass).  The file carried the note alone
 * because the shape had been reported as a linker veneer with no C spelling:
 * it is not.  A plain tail call reproduces all 8 bytes - 4 of code plus the
 * pool word - byte for byte, and the IRQ-window `ldr r3, [pc, #0]` + `bx r3`
 * is exactly what this front end emits for it.  The one relocation therefore
 * stays a wildcard (its own pool word is inside the compared range), which is
 * the MATCH cap and the only thing that keeps this entry out of the manifest.
 *
 * It is the last link of this lane's 0x0202AE68 chain: src/pending/
 * ISS_CITY_SYS_CalcUnitVolume.c is capped on this address's `label`, which is empty while
 * this file cannot be an EXACT entry.  The whole chain needs ISS_CITY_UNIT_CalcVolumeFromAxes
 * (50 bytes, in another packet) filed.
 *
 * symbols:
 *   ISS_CITY_UNIT_CalcVolumeFromAxes  0x0202AF74  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/ISS_CITY_UNIT_CalcVolume.c \
 *       --func ISS_CITY_UNIT_CalcVolume --addr 0x0202AF34 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef signed int     s32;
extern u8 ISS_CITY_UNIT_CalcVolumeFromAxes(u8 *obj, s32 *pos);

void ISS_CITY_UNIT_CalcVolume(int a, u32 b)
{
    ISS_CITY_UNIT_CalcVolumeFromAxes((u8 *)a, (s32 *)b);
}
