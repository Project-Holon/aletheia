/*
 * function: func_021BE5B8
 * address:  0x021BE5B8
 * packet:   pkt_ov099_021BE5B8
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * note: 2026-10-05 (wD6 lane13): EXACT. func_0204B258 takes two arguments (bank, p); the second is the
 * value stored at p + 0x114. The 0x110/0x114 offsets are plain literals: mwcc derives them from the 0x64
 * count constant by itself.
 *
 * symbols:
 *   func_0204A48C  0x0204A48C  arm
 *   func_0204B100  0x0204B100  arm
 *   func_0204B034  0x0204B034  arm
 *   func_0204B258  0x0204B258  arm
 *   d_021C3740  0x021C3740  data  a4
 *   d_021C375C  0x021C375C  data  a4
 *   d_021C3AA0  0x021C3AA0  data  a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 d_021C3740[];
extern u8 d_021C375C[];
extern u8 d_021C3AA0[];
extern void func_0204A48C(const void *a, const void *b, u32 heap);
extern void *func_0204B100(int count, u32 flag, u32 heap);
extern void *func_0204B034(const void *a, u32 b, u32 heap);
extern void func_0204B258(void *bank, void *p);

void func_021BE5B8(char *p)
{
    func_0204A48C(d_021C3740, d_021C3AA0, 0x21);
    *(void **)(p + 0x110) = func_0204B100(0x64, 0, 0x21);
    *(void **)(p + 0x114) = func_0204B034(d_021C375C, 2, 0x21);
    func_0204B258(*(void **)(p + 0x110), *(void **)(p + 0x114));
}
