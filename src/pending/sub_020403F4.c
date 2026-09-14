/*
 * function: sub_020403F4
 * address:  0x020403F4
 * packet:   pkt_0203FC6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   g_02146A44   0x02146A44  data
 *   sub_02043094 0x02043094  arm
 *   sub_020307B0 0x020307B0  arm
 *
 * Release the payload of one entry of the 0x2c-byte table hanging off the
 * singleton pointer at 0x02146A44: if the pointer at +8 is set,
 * unregister it through sub_02043094 (passing the slot index and the
 * cookie at +0xc), free it, and NULL the slot.
 *
 * The slot index arrives in r0 and is never moved, so it is still there
 * as sub_02043094's first argument after the multiply.  The zero used for
 * sub_02043094's second argument and for the final store is materialised
 * once in r6 and shared
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 * Everything after the first call re-reads the global and re-indexes,
 * because the calls may store to it.
 *
 * Byte-correct, capped at MATCH: sub_02043094 is called from this one
 * site and nowhere else in the image, so its PC24 has no outside witness
 * of any class.  --suggest-split cannot help, the site is inside the one
 * function.  It unsticks when 0x02043094 is itself decompiled to EXACT
 * or a second caller turns up in an overlay.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_020403F4.c \
 *       --func sub_020403F4 --addr 0x020403F4 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Entry {
    u8    pad_00[8];
    void *unk_08;
    u32   unk_0c;
    u8    pad_10[0x1c];
};

extern struct Entry *g_02146A44;

extern void sub_02043094(u32 index, u32 zero, u32 cookie);
extern void sub_020307B0(void *p);

void sub_020403F4(u32 i)
{
    if (g_02146A44[i].unk_08 == 0) {
        return;
    }
    sub_02043094(i, 0, g_02146A44[i].unk_0c);
    sub_020307B0(g_02146A44[i].unk_08);
    g_02146A44[i].unk_08 = 0;
}
