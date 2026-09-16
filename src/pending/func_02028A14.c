/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * unit:     yes
 * function: func_02028A14
 * address:  0x02028A14
 * packet:   pkt_0202878C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH, every concrete byte right (0 differing bytes, 60 of 60)
 *
 * field_sound_system.c's per-frame step: it advances the queue, runs the two
 * handlers the current mode selects out of a pair of private dispatch tables,
 * then ticks the ringtone handle at +0xA8 and the volume fader at +0xA4 that
 * src/matched/unit_0202878C.c drives.
 *
 * The two tables are two pool words, 0x020A7554 and 0x020A7518, indexed by the
 * same mode word; the mode is re-read between the two calls rather than kept,
 * which is four bytes shorter than a named local here
 * (docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md).
 *
 * Why it is capped: four of the five relocations have no witness outside this
 * one function.  func_02028D54 (pkt_02028B50) and func_02029F4C (the packet at
 * 0x02029D44) are branched to from nowhere else in the image, and the two
 * table pool words 0x020A7554 and 0x020A7518 appear in no other literal pool,
 * which is the weak `literal` class's only route for plain data.  No cut
 * helps; it closes when those two functions acquire manifest entries or when a
 * second reader of either table turns up.
 *
 * symbols:
 *   func_02028D54  0x02028D54  thumb
 *   func_02029F4C  0x02029F4C  thumb
 *   func_0202878C  0x0202878C  thumb
 *   gHandlersA     0x020A7554  data
 *   gHandlersB     0x020A7518  data
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/func_02028A14.c \
 *       --addr 0x02028A14 --thumb
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Sys {
    u32   unk00;
    u32   unk04;
    u8    unk08[0x9C];
    void *fader;
    void *ringtone;
};

typedef void (*Handler)(struct Sys *s);

extern void func_02028D54(struct Sys *s);
extern void func_02029F4C(void *p);
extern void func_0202878C(void *p);
extern Handler gHandlersA[];
extern Handler gHandlersB[];

void func_02028A14(struct Sys *s)
{
    func_02028D54(s);
    gHandlersA[s->unk04](s);
    gHandlersB[s->unk04](s);
    func_02029F4C(s->ringtone);
    func_0202878C(s->fader);
}
