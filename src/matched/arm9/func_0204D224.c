/*
 * function: func_0204D224
 * address:  0x0204D224
 * packet:   pkt_0204D18C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   s_clact_c      0x020A7F74  data
 *   func_020648B4  0x020648B4  arm
 *   func_02030734  0x02030734  arm
 *   func_02064754  0x02064754  arm
 *   func_020627D8  0x020627D8  arm
 *   func_0206469C  0x0206469C  arm
 *
 * Record constructor in clact.c.  Wave 15 (register-tie lane): EXACT* (the
 * listing extent runs over the unlabelled fill leaf 0x0204D2C8, filed as
 * src/matched/func_0204D2C8.c).  Two facts closed it:
 *  - the older 2-byte "best source" in
 *    docs/notes/pkt_0204D18C.func_0204D224.c.txt stored a1->f14 into +0x04
 *    and a1->f0c into +0x70, which is NOT what the image does (image: +0x04
 *    gets f0c, +0x70 gets f14).  The honest residue with the image's
 *    pairing was 9 bytes.
 *  - `const struct A *a1` with the four stores written straight from a1 and
 *    func_020648B4 fed a fresh a1->f14: the const source lets mwcc keep all
 *    four loads above the stores in field order and CSE the f14 re-read.
 *    The `volatile` device on +0x04 is no longer needed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204D224.c \
 *       --func func_0204D224 --addr 0x0204D224 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct P {
    u32 f00;
    u32 f04;
    u32 f08;
    u8  pad_0c[0x70 - 0x0c];
    u32 f70;
    u32 f74;
    u32 f78;
};

struct A {
    u8  pad_00[0x0c];
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
};

extern char s_clact_c[];
extern u32  func_020648B4(u32 a, u32 b);
extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
extern void func_02064754(void *a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern u32  func_020627D8(u32 a, u32 b);
extern void func_0206469C(void *a, u32 b);

void func_0204D224(struct P *p, const struct A *a1, u32 heap)
{
    p->f04 = a1->f0c;
    p->f08 = a1->f10;
    p->f70 = a1->f14;
    p->f74 = a1->f18;

    p->f78 = (u32)func_02030734(heap, func_020648B4(a1->f14, 1), 0, s_clact_c, 0x171d);
    func_02064754((u8 *)p + 0xc, p->f78, p->f08, p->f04, p->f70, 1);
    func_0206469C((u8 *)p + 0xc, func_020627D8(p->f74, 0));
}

