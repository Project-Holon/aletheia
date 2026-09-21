/*
 * function: func_0203174C
 * address:  0x0203174C
 * packet:   pkt_0203174C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02033908  0x02033908  arm
 *   func_02033BF8  0x02033BF8  arm
 *   func_02033410  0x02033410  arm
 *   func_020319C0  0x020319C0  arm
 *   func_02034714  0x02034714  arm
 *   str_020A7848   0x020A7848  data
 *   str_020A7858   0x020A7858  data
 *   str_020A7868   0x020A7868  data
 *   g_02146994     0x02146994  data
 *
 * backup_system.c.  The save-block constructor; its already-matched caller
 * src/matched/func_0203192C.c fixes the five-argument signature.  The
 * allocator func_02030734 takes (heap, size, align, __FILE__, __LINE__)
 * with the line on the stack: 0x10e, 0x125 and 0x131.  0x154 is the block
 * size, kept live in sb, and the second assert's line 0x116 is derived from
 * it as `sub r1, sb, #0x3e` and the last allocation's 0x131 as
 * `add r0, sb, #0x130`
 * (docs/idioms/consecutive-line-numbers-are-one-pool-word-and-adds.md).
 * The `in` parameter must be `const`: without it an unrelated store may
 * alias the fields and the compiler reloads them, 151 concrete bytes out at
 * the same 480
 * (docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md).
 * The heap id is narrowed per call site because the callee prototypes take
 * `u16`; a `(u16)heap` cast in the body is CSEd into one register instead.
 * The two size roundings are the `((n + k) >> s) << t` shape written out,
 * with the `tst`/`addne` correction being the low-bit remainder test the
 * front end derives from `+ 2` / `& 0xf`.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct In {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
};

struct Blk {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u8  pad10[0x1c - 0x10];
    u8  f1c;
    u8  f1d;
    u8  pad1e[0x24 - 0x1e];
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
    u32 f34;
    u8  pad38[0x138 - 0x38];
    u32 f138;
    u32 f13c;
    u32 f140;
};

extern void *func_02030734(u16 heap, u32 size, u32 align, const u8 *file,
                           u32 line);
extern u32   func_02033908(u16 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern u32   func_02033BF8(void);
extern void  func_02033410(struct Blk *b, u32 f);
extern void  func_020319C0(struct Blk *b);
extern void  func_02034714(const u8 *file, u32 line, const u8 *expr);
extern const u8 str_020A7848[];
extern const u8 str_020A7858[];
extern const u8 str_020A7868[];
extern u32 g_02146994;

struct Blk *func_0203174C(const struct In *in, u32 heap, u32 c, u32 d, u32 e)
{
    struct Blk *b;
    u32 n;

    if (g_02146994 == 0)
        func_02034714(str_020A7848, 0x10c, str_020A7858);

    b = (struct Blk *)func_02030734(heap, 0x154, 1, str_020A7848, 0x10e);
    b->f00 = in->f08;
    b->f04 = in->f0c;
    b->f08 = in->f10;
    b->f0c = in->f14;

    if (c != 0 && d < b->f08)
        func_02034714(str_020A7848, 0x154 - 0x3e, str_020A7868);

    b->f140 = in->f04 << 1;
    if ((in->f04 & 1) != 0)
        b->f140 = b->f140 + 2;

    n = in->f04 + 2;
    b->f13c = (n >> 4) << 2;
    if ((n & 0xf) != 0)
        b->f13c = b->f13c + 4;

    b->f138 = (u32)func_02030734(heap, b->f13c, 1, str_020A7848,
                                 0x125);
    b->f2c = func_02033908(heap, in->f00, in->f04, b->f08, 0x10, 4,
                           b->f140);
    b->f30 = func_02033BF8();
    if (c != 0) {
        b->f34 = c;
        b->f1d = 0;
    } else {
        b->f34 = (u32)func_02030734(heap, b->f08, 1, str_020A7848,
                                    0x131);
        b->f1d = 1;
    }
    b->f1c = 0;
    b->f28 = 0;
    b->f24 = 0;
    if (e == 1)
        func_020319C0(b);
    else
        func_02033410(b, 1);
    return b;
}
