/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * function: func_0201D83C
 * address:  0x0201D83C, 22 bytes, one function
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH, every concrete byte right (0 differing bytes, 22 of 22)
 *
 * gf_font.c's destructor: runs the per-kind teardown hook, releases the
 * buffers and frees the object.
 *
 * Why it is capped: the `bl` at 0x0201D840 is the only branch to func_0201DADC
 * anywhere in the image, and func_0201DADC cannot itself be matched, because
 * the only thing that names the dispatch table it loads, 0x0209E744, is
 * func_0201DADC's own pool word.  So the `label` class has no witness, no cut
 * helps (the range cannot be smaller than this one function) and the `matched`
 * class cannot reach a function whose blocker is a private table.
 *
 * func_0201D9C8, the other call, is carried by the `matched` class through
 * src/matched/unit_0201D9C8.c.
 *
 * It closes the day 0x0209E744 is named by a second pool word, or
 * func_0201DADC acquires a second caller.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/unit_0201D83C.c  *       --addr 0x0201D83C --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Font {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    void *unk0C;
    u8  pad10[0x40];
    void *unk50;
    void *unk54;
    u8  unk58[8];
    void *unk60;
    void *unk64;
    void *unk68;
    u32 unk6C;
    u16 unk70;
    u8  unk72;
    u8  pad73;
    u8  unk74;
    u8  unk75;
    u16 unk76;
    u8  pad78[4];
    u16 unk7C;
    u8  unk7E;
    u8  unk7F;
    void *unk80;
    void *unk84;
    void *unk88;
    void *unk8C;
    void *unk90;
};

extern void func_020307B0(void *p);
extern void func_0201DADC(struct Font *p);
extern void func_0201D9C8(struct Font *p);

void func_0201D83C(struct Font *p)
{
    func_0201DADC(p);
    func_0201D9C8(p);
    func_020307B0(p);
}
