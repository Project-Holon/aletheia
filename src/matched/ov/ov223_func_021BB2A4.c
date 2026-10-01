/*
 * function: func_021BB2A4
 * address: 0x021BB2A4
 * packet: pkt_ov223_021BB2A4
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Declare width before the zero x initializer: its store shares the
 * upcoming call's zero r2; const p left the six-byte scheduling diff.
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201D42C 0x0201D42C thumb
 *   func_02045770 0x02045770 arm
 *   func_020437DC 0x020437DC arm
 *   func_020437E4 0x020437E4 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_021BAF48 0x021BAF48 thumb ov223
 * The bitmap accessors' own sources return u16. This caller uses each
 * result at full width without truncation, so its declarations widen them.
 */
typedef unsigned short u16;
typedef signed short s16;
struct MsgBank;
struct StrObj;
struct Descriptor;
struct U16Vec;
struct Bmp;
extern void *func_02045EC0(struct MsgBank *, unsigned);
extern unsigned func_0201D304(struct StrObj *, unsigned, unsigned);
extern unsigned func_0201D42C(struct StrObj *, void *);
extern void *func_02045770(struct Descriptor *);
extern unsigned func_020437DC(const struct Bmp *);
extern unsigned func_020437E4(const struct Bmp *);
extern void func_0201C724(void *, unsigned, unsigned, unsigned, unsigned, unsigned, u16);
extern void func_02045808(struct U16Vec *);
extern int func_021BAF48(char *);
void func_021BB2A4(char *p)
{
    struct StrObj *text = func_02045EC0(*(struct MsgBank **)(p + 0x234), 12);
    u16 width = func_0201D304(text, *(unsigned *)(p + 0x18), 0);
    u16 x = 0;
    u16 height = func_0201D42C(text, *(void **)(p + 0x18));
    unsigned w = func_020437DC(func_02045770(*(struct Descriptor **)(p + 0x238)));
    unsigned h = func_020437E4(func_02045770(*(struct Descriptor **)(p + 0x238)));
    u16 y = 0;
    if (w > width)
        x = ((int)w - width) / 2;
    if (h > height)
        y = ((int)h - height) / 2;
    func_0201C724(*(void **)(p + 0x1C), (unsigned)func_02045770(*(struct Descriptor **)(p + 0x238)),
                 (s16)x, (s16)y, (unsigned)text, *(unsigned *)(p + 0x18), 0x3C40);
    func_02045808((struct U16Vec *)text);
    *(int *)(p + 0x244) = 0;
    func_021BAF48(p);
}
