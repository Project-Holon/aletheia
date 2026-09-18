/*
 * function: func_02012088
 * address:  0x02012088
 * packet:   pkt_02012088
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_0203133C  0x0203133C  arm
 *   func_02011F90  0x02011F90  thumb
 *
 * ica_anime.c's teardown entry: release the object's +0x08 resource through
 * the ARM helper, then run the shared destructor on the object itself.
 *
 * blocker:  label: the call to 0x02011F90 at +0x0c is its only caller, and 0x02011F90 is itself capped on 0x0202B4F0 (0x0201E000..0x0202E000 lane, not writable from pkt_02012088).  Every concrete byte is right.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02012088.c \
 *       --func func_02012088 --addr 0x02012088 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct IcaAnime {
    u8  pad00[0x08];
    u32 f08;            /* +0x08 */
};

extern void func_0203133C(u32 v);
extern void func_02011F90(struct IcaAnime *p);

void func_02012088(struct IcaAnime *p)
{
    func_0203133C(p->f08);
    func_02011F90(p);
}
