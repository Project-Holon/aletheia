/*
 * function: func_02091E44
 * address:  0x02091E44
 * packet:   pkt_02091AE8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * isa:      arm
 * status:   EXACT
 *
 * The seek (fseek shape) of the buffered-stdio object documented in
 * docs/families/cluster_02091588.h and cluster_02091AE8.h.  The real entry is
 * the push {r0-r3} home area at 0x02091E44 (the +0x38 handler takes &pos); the
 * listing's label at 0x02091E48 is the body, hence EXACT* against a 4-byte
 * listing extent until the seed at 0x02091E44 replaces it.
 *
 * Closed wave 12 after four lanes stalled at 448/28.  The two coupled residues
 * were both in the declarations, not the allocator:
 *   - the f08 state is a BITFIELD MEMBER OF THE STRUCT and is ASSIGNED as one
 *     (`p->f08.mode = 2;` / `= 0;`).  That is the `bic ip, #7 / orr #2` read-
 *     modify-write off the word the mode test already loaded, and the plain
 *     re-read after the store; no volatile view is involved.
 *   - the in-window test is `if (pos >= f18 || pos < f34) mode = 0; else
 *     {...}`: the disjunction's THEN arm is the `b` the image keeps between
 *     the two compares.  The positive `&&` form cross-jumps it away.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02091E44.c \
 *       --func func_02091E44 --addr 0x02091E44 --arm --cc 1.1p1
 *   EXACT*, 448 bytes, 3 of 3 relocation sites resolved.
 *   ../2.0/sp2 and ../2.0/sp2p2: 488 bytes, DIFF.
 *
 * symbols:
 *   g_02153FAC     0x02153FAC  data
 *   func_02091650  0x02091650  arm
 *   func_02091CBC  0x02091CBC  arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

struct F04 { u32 lo : 2; u32 mode : 3; u32 m2 : 2; u32 omode : 3; u32 hi : 22; };
struct F08 { u32 mode : 3; u32 hi : 29; };

struct File {
    u32 f00;
    struct F04 f04;
    struct F08 f08;
    u8  f0c;
    u8  f0d;
    u8  f0e[2];
    u8  pad10[0x08];
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
    u32 f34;
    u32 (*f38)(u32 a, u32 *pos, u32 whence, u32 d);
    u32 f3c;
    u32 f40;
    u32 pad44;
    u32 f48;
};

extern u32 g_02153FAC;
extern s32 func_02091650(struct File *p, u32 *out);
extern u32 func_02091CBC(struct File *p);

s32 func_02091E44(struct File *p, u32 pos, u32 whence)
{
    u8 mode;

    mode = p->f04.omode;
    if (mode != 1 || p->f0d != 0) {
        g_02153FAC = 0x28;
        return -1;
    }
    if (p->f08.mode == 1 && func_02091650(p, 0) != 0) {
        p->f0d = 1;
        p->f28 = 0;
        g_02153FAC = 0x28;
        return -1;
    }
    if (whence == 1) {
        whence = 0;
        pos += func_02091CBC(p);
    }
    if (whence != 2 && p->f04.mode != 3 && p->f08.mode - 2 <= 1) {
        if (pos >= p->f18 || pos < p->f34) {
            p->f08.mode = 0;
        } else {
            p->f24 = p->f1c + (pos - p->f34);
            p->f28 = p->f18 - pos;
            p->f08.mode = 2;
        }
    } else {
        p->f08.mode = 0;
    }
    if (p->f08.mode == 0) {
        if (p->f38 != 0 && p->f38(p->f00, &pos, whence, p->f48) != 0) {
            p->f0d = 1;
            p->f28 = 0;
            g_02153FAC = 0x28;
            return -1;
        }
        p->f0c = 0;
        p->f18 = pos;
        p->f28 = 0;
    }
    return 0;
}
