/*
 * function: sub_020419E4
 * address:  0x020419E4
 * packet:   pkt_020419E4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * note:     blocked on func_02041B94 (label class): its only image-wide
 *   witness is the +0014 call site inside this same function, so no outside
 *   attestation exists. --suggest-split confirms no partition frees it
 *   (best partition: 0 pieces, function left out). All concrete bytes
 *   match; only this one relocation site stays wildcarded.
 *
 * Guards on the singleton pointer at 0x02146A44: if it is NULL, returns
 * immediately. Otherwise runs the two teardown workers func_02041B94 and
 * func_02041A1C in order, then re-reads the pointer (it is re-loaded, not
 * cached across the calls, since either worker could plausibly rewrite it)
 * and clears the two u16 fields at +4 and +6.
 *
 * symbols:
 *   gUnk_02146A44  0x02146A44  data
 *   func_02041B94  0x02041B94  arm
 *   func_02041A1C  0x02041A1C  arm
 */

typedef unsigned short u16;
typedef unsigned char  u8;

struct Unk02146A44 {
    u8  pad_00[4];
    u16 field_4;
    u16 field_6;
};

extern struct Unk02146A44 *gUnk_02146A44;

extern void func_02041B94(void);
extern void func_02041A1C(void);

void sub_020419E4(void)
{
    if (gUnk_02146A44 == 0) {
        return;
    }

    func_02041B94();
    func_02041A1C();

    gUnk_02146A44->field_4 = 0;
    gUnk_02146A44->field_6 = 0;
}
