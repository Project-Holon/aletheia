/*
 * function: func_021BB18C
 * address: 0x021BB18C
 * packet: pkt_ov223_021BB18C
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note 2026-10-04: DIFF, 8 bytes short. Original computes the offset 0x24C early as an integer (r4=0x240; r0=r4+0xc spilled to
 *   [sp,#0x18], reloaded for the final `str r6,[r5,r0]`) and keeps r4 as shared 0x240 (0x234 = r4-0xc). Constant-folded here whatever
 *   `off`/`k` locals were tried, so the hoisted spill slot and the pushed r3 are missing. Body logic is believed correct.
 * symbols:
 *   func_0201EC64 0x0201EC64 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201EE60 0x0201EE60 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201D42C 0x0201D42C thumb
 *   func_020437DC 0x020437DC arm
 *   func_020437E4 0x020437E4 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_021BAF48 0x021BAF48 thumb ov223
 *   d_021BC730 0x021BC730 data a4
 *   d_021BC710 0x021BC710 data a2
  *
 * note 2026-10-04 (lane 20, D2): tried `unsigned off = k; off += 0xC;` (declared first, or after the
 * calls), desc declared before off, and an enum-typed k (228 B, but then p+k pointer adds). The plain
 * forms constant-fold; the enum form keeps the spill but changes the address math. The original first
 * stores r4 (0x240) to [sp,#0x18] then +0xc to the same slot: off is a non-foldable variable.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern const u32 d_021BC730[];
extern const u16 d_021BC710[];
struct MsgBank;
struct StrObj;
struct Descriptor;
struct U16Vec;
struct Bmp;
struct CharBuf;
extern void *func_0201EC64(u32 heap);
extern void *func_02045EC0(struct MsgBank *, unsigned);
extern void *func_020457B0(unsigned size, u16 heap);
extern void func_0201EE60(void *, unsigned, unsigned);
extern void func_0201F250(void *, void *, void *);
extern void func_02045808(struct U16Vec *);
extern void func_0201ED04(void *);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *, u8);
extern unsigned func_0201D304(struct StrObj *, unsigned, unsigned);
extern unsigned func_0201D42C(struct StrObj *, void *);
extern u16 func_020437DC(const struct Bmp *bmp);
extern u16 func_020437E4(const struct Bmp *bmp);
extern void func_0201C724(void *, unsigned, unsigned, unsigned, unsigned, unsigned, u16);
extern int func_021BAF48(char *);
void func_021BB18C(char *p, int idx)
{
    unsigned k = 0x240;
    unsigned off = k + 0xC;
    struct Descriptor *desc = *(struct Descriptor **)(p + k);
    u16 x = 0;
    void *words = func_0201EC64(*(u16 *)p);
    void *text = func_02045EC0(*(struct MsgBank **)(p + k - 0xC), d_021BC730[idx]);
    struct StrObj *buf = func_020457B0(0x40, *(u16 *)p);
    u16 height;
    unsigned h;
    func_0201EE60(words, 1, d_021BC710[idx]);
    func_0201F250(words, buf, text);
    func_02045808((struct U16Vec *)text);
    func_0201ED04(words);
    func_02043B5C((struct CharBuf *)func_02045770(desc), 0);
    func_0201D304(buf, *(unsigned *)(p + 0x18), 0);
    height = func_0201D42C(buf, *(void **)(p + 0x18));
    func_020437DC(func_02045770(desc));
    h = func_020437E4(func_02045770(desc));
    if (h > height)
        x = ((int)h - height) / 2;
    func_0201C724(*(void **)(p + 0x1C), (unsigned)func_02045770(desc), 0, (s16)x, (unsigned)buf, *(unsigned *)(p + 0x18), 0x3C40);
    func_02045808((struct U16Vec *)buf);
    *(u32 *)(p + off) = 0;
    func_021BAF48(p);
}
