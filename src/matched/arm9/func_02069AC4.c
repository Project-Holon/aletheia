/*
 * function: NNSi_G2dFontFixupSections
 * address:  0x02069AC4
 * packet:   pkt_020694D8
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Relocate the section table of an NFTR-style font resource loaded at `base`:
 * the u16 at +0x0C is the byte offset of the first section header and the u16
 * at +0x0E the section count; each header carries its own FourCC at +0 and its
 * own size at +4, which is the stride to the next one.
 *
 * Per-signature fixups, all "add `base` to a stored file offset":
 *   'FINF'  +0x10 unconditionally, then +0x14 and +0x18 if non-zero
 *   'CWDH'  +0x0C if non-zero
 *   'CMAP'  +0x10 if non-zero
 *   'CGLP'  nothing -- an EMPTY arm whose target is the default exit.
 *
 * Per-file compiler pin, "kept branches" tell (docs/FRONTEND-PINS.md). The
 * original keeps the dead `cmp r5, lr` at 0x02069B00 (e155000e), the left
 * leaf of the four-way search tree, immediately before the unconditional
 * `b 0x02069B74` to the default exit. dsi/1.1p1 -O4,p folds that compare
 * away because the CGLP arm and the default share a target, giving 216
 * bytes against the original's 220, with every other byte identical and
 * shifted by exactly those four. Empty-arm, `default:`-fallthrough,
 * `continue` and `goto` spellings all fold the same way under 1.1p1.
 * ../2.0/sp2 keeps the compare: 220 bytes, 0 mismatches.
 */

typedef signed int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u32 sig;
    u32 size;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
} Section;

typedef struct {
    u8  unk00[0xc];
    u16 off0C;
    u16 cnt0E;
} Font;

void NNSi_G2dFontFixupSections(Font *base)
{
    Section *s;
    s32 i;
    s32 n;
    u32 v;

    s = (Section *)((u8 *)base + base->off0C);
    i = 0;
    n = base->cnt0E;
    if (n <= 0) return;
    do {
        switch (s->sig) {
        case 0x46494e46:
            s->unk10 = s->unk10 + (u32)base;
            v = s->unk14;
            if (v != 0) s->unk14 = v + (u32)base;
            v = s->unk18;
            if (v != 0) s->unk18 = v + (u32)base;
            break;
        case 0x43574448:
            v = s->unk0C;
            if (v != 0) s->unk0C = v + (u32)base;
            break;
        case 0x434d4150:
            v = s->unk10;
            if (v != 0) s->unk10 = v + (u32)base;
            break;
        case 0x43474c50:
            break;
        }
        i++;
        s = (Section *)((u8 *)s + s->size);
    } while (i < (s32)base->cnt0E);
}
