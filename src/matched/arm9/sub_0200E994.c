/*
 * function: LIVEBATTLEMATCH_SAVE_HasOpponentMac
 * address:  0x0200E994
 * packet:   pkt_0200E994
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0200E918  0x0200E918  thumb
 *   func_0200E938  0x0200E938  thumb
 *   GF_STANDARD_CompareBytes  0x0203EFC8  arm
 *
 * Linear search over up to 10 stored 6-byte keys: func_0200E918(base, 0)
 * gives the stored count (capped at 10), func_0200E938 copies the i'th key
 * into a stack buffer, and GF_STANDARD_CompareBytes (DWC's own key comparator)
 * compares it against the caller's key. Returns 1 on the first match, 0
 * if none of the stored keys match.
 *
 * EXACT* because the 70 compiled bytes fall six short of the disasm.py
 * extent: MISC_SAVEDATA_GetMacStructSize, a four-byte constant getter with no
 * register-saving prologue, hides in the two trailing pad bytes plus this
 * function's own alignment filler (see "the two missing labels" in
 * docs/MATCHING.md); it is matched separately.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/LIVEBATTLEMATCH_SAVE_HasOpponentMac.c \
 *       --func LIVEBATTLEMATCH_SAVE_HasOpponentMac --addr 0x0200E994 --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef signed int     s32;
extern u8 func_0200E918(const u8 *base, u32 idx);
extern void func_0200E938(u8 *obj, u32 id, void *dest);
extern s32 GF_STANDARD_CompareBytes(const u8 *a, const u8 *b, u32 n);

u32 LIVEBATTLEMATCH_SAVE_HasOpponentMac(void *base, void *key)
{
    int i;
    int count = func_0200E918(base, 0);
    u8 buf[6];

    if (count > 10) {
        count = 10;
    }

    for (i = 0; i < count; i++) {
        func_0200E938(base, i, buf);
        if (GF_STANDARD_CompareBytes(key, buf, 6) == 0) {
            return 1;
        }
    }
    return 0;
}
