/*
 * function: func_0220B880
 * address: 0x0220B880
 * packet: pkt_ov197_0220B880
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: the scaled index is its own int local added after each field
 *   offset (`*(short *)(*(char **)p + 0x30 + off)`), which puts the ldrb and
 *   lsls ahead of the `ldr r0,[r4]` base load (0220B8A4..0220B8AA). A row
 *   pointer `q = *(char **)p + idx*2` (either operand order, or as a short
 *   element address) loads the base first: 9 bytes.
 * prototype: func_0220B78C has no matched definition; (char *, unsigned) and
 *   void taken from its listing (r1 scaled by 4 as an index, no r0 use after).
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_0220B78C 0x0220B78C thumb ov197
 *   func_0220B3EC 0x0220B3EC thumb ov197
 *   func_0220B814 0x0220B814 thumb ov197
 *   func_0220B1D4 0x0220B1D4 thumb ov197
 *   d_0220DA08 0x0220DA08 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
struct CharBuf;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void func_0220B78C(u8 *p, u32 idx);
extern void func_0220B3EC(char *p, u32 i, int id, int w, int unused, int y, int unused2);
extern void func_0220B814(char *p, int n);
extern void func_0220B1D4(char *p, int i, int id, int y, u16 colour);
extern const u8 d_0220DA08[];
void func_0220B880(char *p)
{
    unsigned i;
    int x, y;
    int off;
    for (i = 31; i <= 34; i++)
        BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor **)(p + 0x28 + i * 8)), 0);
    off = *(u8 *)(p + 0x533) * 2;
    x = *(short *)(*(char **)p + 0x30 + off);
    y = *(short *)(*(char **)p + 0x38 + off) * 6;
    func_0220B78C((u8 *)p, x + y);
    func_0220B3EC(p, x + y, 0, 32, 0, 0, 0);
    func_0220B814(p, x + y);
    func_0220B1D4(p, 34, 31, 0, 0x3c40);
    *(const u8 **)(p + 0x59c) = d_0220DA08;
}
