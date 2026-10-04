/*
 * function: func_021BCC40
 * address:  0x021BCC40
 * packet:   pkt_ov172_021BCC40
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE00C  0x021BE00C  thumb  ov172
 *   func_021BE034  0x021BE034  thumb  ov172
 *   func_021BE03C  0x021BE03C  thumb  ov172
 *   func_021BE044  0x021BE044  thumb  ov172
 *   func_0201EC64  0x0201EC64  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_020457B0  0x020457B0  arm
 *   func_0202E930  0x0202E930  thumb
 *   func_02045994  0x02045994  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0202E938  0x0202E938  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_020456F8  0x020456F8  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *
 * Redraws one dirty list row (+0 set): an empty row (+0x18 == 0xff) just clears its window; otherwise prints the entry's name, its level (message 0xe) and, for kind 0x20 entries, the extra count (message 0x10), then records whether the entry is selectable (+0xc of the entry) and marks the row window for transfer (+4).
 *
 * Blocker: byte-correct (MATCH); the arm9 callees 0x0202E930 and 0x0202E938 are
 *     unlabelled Thumb functions with no witness outside this function.  Seed and
 *     match them and this file is EXACT.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct FlagsA {
    u8 pad[0x21];
    u8 on : 1;
    u8 rest : 7;
};

struct FlagsB {
    u8 pad[2];
    u8 low : 6;
    u8 b6 : 1;
    u8 b7 : 1;
};

extern u16 func_021BE00C(u16 *p);
extern u32 func_021BE034(void *p);
extern u32 func_021BE03C(void *p);
extern u32 func_021BE044(void *p);
extern u32 func_0201EC64(u32 heap);
extern u32 func_02045770(u32 win);
extern void func_02043B5C(u32 a, u32 b);
extern u32 func_020457B0(u32 len, u32 heap);
extern u16 *func_0202E930(void *p);
struct Strbuf;
extern void func_02045994(struct Strbuf *o, const u16 *src, unsigned int len);
extern void func_0201C724(u32 a, u32 bmp, u32 x, u32 y, u32 text, u32 f, u32 color);
extern void func_02045808(u32 v);
extern u32 func_02045EC0(u32 a, u32 b);
extern u16 func_0202E938(void *p);
extern void func_0201EFA4(u32 ws, u32 idx, u32 val, u32 digits, u32 mode, u32 f);
extern void func_0201F250(u32 ws, u32 dst, u32 fmt);
extern void func_0201ED04(u32 ws);
extern void func_020456F8(u32 win);
extern u8 func_02045730(u32 win);
extern void func_02041B6C(u32 bit);

static inline u8 func_021BCC40_show(u32 win)
{
    func_020456F8(win);
    return func_02045730(win);
}

void func_021BCC40(void *ctx, char *list, char *row, int idx)
{
    u32 buf2;
    u32 fmt2;
    u32 msgs;
    u32 sys;
    u32 str;
    u32 buf;
    u8 *p;
    u32 heap;
    u32 fmt;
    u32 font;
    char *e;
    u32 ws;

    if (*(u32 *)row != 1)
        return;
    if (*(u8 *)(row + 0x18) != 0xff) {
        heap = func_021BE00C(ctx);
        font = func_021BE034(ctx);
        msgs = func_021BE03C(ctx);
        sys = func_021BE044(ctx);
        e = list + 0x1e4 + *(u8 *)(row + 0x18) * 0x24;
        ws = func_0201EC64(heap);
        func_02043B5C(func_02045770(*(u32 *)(row + 0x14)), 0);
        str = func_020457B0(0x20, heap);
        if (*(u8 *)(e + 0x18) == 0x20)
            func_02045994((struct Strbuf *)str, func_0202E930(*(void **)(e + 0x14)), 8);
        else
            func_02045994((struct Strbuf *)str, (const u16 *)(*(char **)(e + 0x14) + 0x1a), 8);
        func_0201C724(sys, func_02045770(*(u32 *)(row + 0x14)), 6, 0, str, font, 0x3c40);
        func_02045808(str);
        fmt = func_02045EC0(msgs, 0xe);
        buf = func_020457B0(0x20, heap);
        if (*(u8 *)(e + 0x18) == 0x20)
            func_0201EFA4(ws, 0, func_0202E938(*(void **)(e + 0x14)), 5, 2, 1);
        else
            func_0201EFA4(ws, 0, *(u16 *)(*(char **)(e + 0x14) + 0x18), 5, 2, 1);
        func_0201F250(ws, buf, fmt);
        func_02045808(fmt);
        func_0201C724(sys, func_02045770(*(u32 *)(row + 0x14)), 0x50, 0, buf, font, 0x3c40);
        func_02045808(buf);
        if (*(u8 *)(e + 0x18) == 0x20) {
            p = *(u8 **)(e + 0x14);
            *(u8 *)(e + 0x1f) = p[0x20];
            fmt2 = func_02045EC0(msgs, 0x10);
            buf2 = func_020457B0(0x20, heap);
            p += 0x20;
            func_0201EFA4(ws, 0, *p, 1, 0, 1);
            func_0201F250(ws, buf2, fmt2);
            func_02045808(fmt2);
            func_0201C724(sys, func_02045770(*(u32 *)(row + 0x14)), 0x90, 0, buf2, font, 0x3c40);
            func_02045808(buf2);
        } else {
            *(u8 *)(e + 0x1f) = 0;
        }
        if (*(u8 *)(e + 0x18) == 0x20) {
            if ((*(struct FlagsA **)(e + 0x14))->on == 1)
                *(u32 *)(e + 0xc) = 1;
            else
                *(u32 *)(e + 0xc) = 0;
        } else if ((*(struct FlagsB **)(e + 0x14))->b7 == 1 && (*(struct FlagsB **)(e + 0x14))->b6 == 0) {
            *(u32 *)(e + 0xc) = 1;
        } else {
            *(u32 *)(e + 0xc) = 0;
        }
        func_0201ED04(ws);
        *(u32 *)(row + 4) = 1;
    } else {
        func_02041B6C(func_021BCC40_show(*(u32 *)(row + 0x14)));
    }
    *(u32 *)row = 0;
}
