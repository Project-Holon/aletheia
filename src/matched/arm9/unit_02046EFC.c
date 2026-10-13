/*
 * unit:     yes
 * function: G3D_SYSTEM_DeleteResource
 * address:  0x02046EFC
 * packet:   pkt_02046EFC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *
 * The guarded destructor of the 0x48BF-tagged object, 0x02046EFC-0x02046F48
 * including its one pool word.  A NULL handle is a no-op, and so is a handle
 * whose tag halfword is not 0x48BF; otherwise the tag is stamped down to
 * 0x48BE ("freed"), the owned buffer at +4 is released and nulled, and the
 * object itself is released.
 *
 * The two tags are one pool word and a `sub r1, r1, #1`: 0x48BF is not an
 * ARM rotated immediate so it costs a pool word, and 0x48BE is then derived
 * from it rather than pooled a second time, the same accounting as
 * docs/idioms/consecutive-line-numbers-are-one-pool-word-and-adds.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02046EFC.c \
 *       --addr 0x02046EFC --cc 1.1p1 --arm
 */

typedef unsigned short u16;

struct Tagged {
    u16   tag;
    u16   pad02;
    void *buf;
};

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void G3D_SYSTEM_DeleteResource(struct Tagged *p)
{
    if (p == 0) {
        return;
    }
    if (p->tag != 0x48BF) {
        return;
    }
    p->tag = 0x48BE;
    if (p->buf != 0) {
        func_020307B0(p->buf);
        p->buf = 0;
    }
    func_020307B0(p);
}
