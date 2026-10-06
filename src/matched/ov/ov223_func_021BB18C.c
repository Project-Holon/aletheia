/*
 * function: func_021BB18C
 * address: 0x021BB18C
 * packet: pkt_ov223_021BB18C
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * note: 2026-10-05 (wD8 lane03): EXACT. The 0x24C slot is a pointer local `flag = (u32 *)(p + 0x24C)`
 *   set right after the desc load and written at the end (`*flag = 0`). mwcc keeps the 0x240 base from
 *   the desc load in r4, derives 0x24C from it at the top, spills only the offset and uses [r5,r0] at the
 *   store. The k/off locals and the enum type of earlier drafts are gone.
 *
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
struct WordSet;
extern struct WordSet *func_0201EC64(u32 heap);
extern void *func_02045EC0(struct MsgBank *, unsigned);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201EE60(struct WordSet *p, u32 i, u16 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *);
extern void func_0201ED04(struct WordSet *p);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *, u8);
extern unsigned func_0201D304(struct StrObj *, unsigned, unsigned);
extern unsigned func_0201D42C(struct StrObj *, void *);
extern u16 func_020437DC(const struct Bmp *bmp);
extern u32 func_020437E4(const struct Bmp *bmp);
extern void func_0201C724(void *, unsigned, unsigned, unsigned, unsigned, unsigned, u16);
extern int func_021BAF48(char *);
void func_021BB18C(char *p, int idx)
{
    struct Descriptor *desc;
    u16 x;
    void *words;
    void *text;
    u32 *flag;
    struct StrObj *buf;
    u16 height;
    unsigned h;
    desc = *(struct Descriptor **)(p + 0x240);
    flag = (u32 *)(p + 0x24C);
    x = 0;
    words = func_0201EC64(*(u16 *)p);
    text = func_02045EC0(*(struct MsgBank **)(p + 0x234), d_021BC730[idx]);
    buf = (struct StrObj *)func_020457B0(0x40, *(u16 *)p);
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
    *flag = 0;
    func_021BAF48(p);
}
