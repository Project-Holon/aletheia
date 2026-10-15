/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0200E684
 * packet:   pkt_0200E684
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: BATTLE_EXAMINATION_RefreshMarker, BATTLE_EXAMINATION_GetGreetingSize
 *
 * GF_STANDARD_SetupCalc: not otherwise called in arm9_main
 * symbols:
 *   GF_STANDARD_SetupCalc 0x0203F1FC  arm
 *
 * alias: BATTLE_EXAMINATION_RefreshMarker toggles one flag half of a caller object's field pair
 * addressed by the constant id 0x5c6: it looks the field up through
 * GF_STANDARD_SetupCalc, and if the stored halfword at +0x5c6 already equals the
 * looked-up value, rewrites the paired halfword at +0x5c2 with the constant
 * 0x7da and refreshes +0x5c6 with a second lookup.  BATTLE_EXAMINATION_GetGreetingSize is an
 * unlabelled getter returning the constant 0x28, sitting in what disasm.py
 * printed as trailing data after BATTLE_EXAMINATION_RefreshMarker because it carries no
 * register-saving prologue; see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200E684.c \
 *       --addr 0x0200E684 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 GF_STANDARD_SetupCalc(const u8 *src, u32 len);

void BATTLE_EXAMINATION_RefreshMarker(void *obj)
{
    u32 id = 0x5c6;
    if (*(u16 *)((u8 *)obj + id) == GF_STANDARD_SetupCalc(obj, id)) {
        *(u16 *)((u8 *)obj + (id - 4)) = 0x7da;
        *(u16 *)((u8 *)obj + id) = GF_STANDARD_SetupCalc(obj, id);
    }
}

u32 BATTLE_EXAMINATION_GetGreetingSize(void)
{
    return 0x28;
}
