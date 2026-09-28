/*
 * function: func_020124F4
 * address:  0x020124F4
 * packet:   pkt_020124F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  label - 0x0216237C, 0x0216CC58, 0x0215E31C and 0x021647A0 each
 *           have exactly ONE branch anywhere in the image and it is the `bl`
 *           inside this function (0x020125AA, 0x020125E0, 0x02012698,
 *           0x020126DC), so the `label` class has no outside witness.  Two
 *           overlays (ov009, ov010) hold each address, so even with the
 *           `ov010` region hint on the symbols: line the witness condition
 *           still fails.  `sole-ref/code` cannot carry them either: it reads
 *           `evidence().labels`, which is the ARM9 listing only, so an
 *           overlay-resident function start is outside its index.
 *           `tu --suggest-split` confirms no cut helps ("best partition:
 *           0 piece(s), 1 function(s) left out") -- the only witnesses are
 *           the calls that need them.  Same wall as src/pending/func_02012704.c
 *           (the matching destructor), which is blocked on five siblings of
 *           these same overlay addresses.
 *           Every one of the 528 concrete bytes is correct; only the four
 *           relocation FIELDS stay wildcarded.
 * symbols:
 *   g_020A728C     0x020A728C  data
 *   func_02030734  0x02030734  arm
 *   func_020070A4  0x020070A4  thumb
 *   func_0202E888  0x0202E888  thumb
 *   func_02008854  0x02008854  thumb
 *   func_02008844  0x02008844  thumb
 *   func_02008848  0x02008848  thumb
 *   func_0200884C  0x0200884C  thumb
 *   func_02006E40  0x02006E40  thumb
 *   func_02012A60  0x02012A60  thumb
 *   func_02008468  0x02008468  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008730  0x02008730  thumb
 *   memcpy         0x02082D44  arm
 *   func_0216237C  0x0216237C  thumb  ov010
 *   func_021623DC  0x021623DC  thumb  ov010
 *   func_02012FE4  0x02012FE4  thumb
 *   func_02159B48  0x02159B48  thumb  ov010
 *   func_020071CC  0x020071CC  thumb
 *   func_0216CC58  0x0216CC58  thumb  ov010
 *   func_02028844  0x02028844  thumb
 *   func_02014428  0x02014428  thumb
 *   func_02008254  0x02008254  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_02007AA4  0x02007AA4  thumb
 *   func_020097C4  0x020097C4  thumb
 *   func_0200BDE4  0x0200BDE4  thumb
 *   func_02161D98  0x02161D98  thumb  ov010
 *   func_0200857C  0x0200857C  thumb
 *   func_020071E4  0x020071E4  thumb
 *   func_0215E31C  0x0215E31C  thumb  ov010
 *   func_0202E43C  0x0202E43C  thumb
 *   func_02012C18  0x02012C18  thumb
 *   func_0202E770  0x0202E770  thumb
 *   func_0202751C  0x0202751C  thumb
 *   func_021647A0  0x021647A0  thumb  ov010
 *
 * The constructor of the big game_data object destroyed by func_02012704.
 * 0x6B0 bytes from func_02030734(heap, 0x6B0, 1, "game_data.c", 0xAD); the
 * field offsets are the destructor's, read through a u8 * so the compiler
 * derives them all from the two pooled/scaled bases 0x1C4 (= 0x71 << 2),
 * 0x158 (= 0x56 << 2) and 0x6AC.
 *
 * THE TWO LEVERS (both found this wave; 528 bytes size-exact on the first
 * write, then 176 concrete-byte mismatches down to 0 in two changes):
 *
 * 1. THE HEAP PARAMETER IS `u16`, NOT `int`.  With `int` the seven prologue
 *    instructions are the right seven in the wrong order: mwcc emits the
 *    `str r0, [sp, #4]` spill LAST, after `movs r1,#0xad / str r1,[sp] /
 *    movs r1,#0x6b / ldr r3,pool / lsls r1,r1,#4 / movs r2,#1`, while the
 *    original emits it FIRST.  A `u16` parameter has a narrowed stack home
 *    the marshaller must establish before it builds the other arguments,
 *    which is exactly the original's order.  No spelling of the body moves
 *    it: `int heap = a0;` as the first local, as the last local, hoisting
 *    0x6B0 into a named `size`, and 300 single mutations of the permuter in
 *    --mode hill ("no single mutation improves") all leave the same seven.
 *    The permuter's --mode anneal found it as `type:p(a0:int->u16)` in 286
 *    compiles; the sibling caller src/matched/func_020082EC.c independently
 *    corroborates it, passing `(unsigned short)a0` to the same allocator.
 *
 * 2. THE memcpy ARGUMENTS ARE EVALUATED THROUGH TWO NAMED LOCALS, in the
 *    original's order: `n = func_02008468(); src = func_02012944(p);` and
 *    only then `memcpy(func_02008730(*(u32 *)p), src, n)`.  Written as one
 *    nested expression mwcc schedules func_02008730 first and the whole
 *    tail of the function reallocates: that alone was 169 of the 176
 *    mismatches.  (docs/idioms/an-inline-call-argument-is-scheduled-per-site-
 *    a-local-is-not.md)
 *
 * Verified with:
 *   python3 tools/match.py one --src src/pending/func_020124F4.c \
 *       --func func_020124F4 --addr 0x020124F4 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern char  g_020A728C[];
extern void *func_02030734(int heap, int size, int flag, void *file, int line);
extern u32   func_020070A4(void);
extern u8    func_0202E888(void);
extern u32   func_02008854(u32 h);
extern u32   func_02008844(u32 a);
extern u32   func_02008848(u32 a);
extern u32   func_0200884C(u32 a);
extern u32   func_02006E40(int heap);
extern void  func_02012A60(void *p);
extern u32   func_02008468(void);
extern void *func_02012944(void *p);
extern void *func_02008730(u32 h);
extern void *memcpy(void *dst, const void *src, u32 n);
extern u32   func_0216237C(int heap);
extern void  func_021623DC(void);
extern u32   func_02012FE4(u32 h);
extern u32   func_02159B48(int heap);
extern u32   func_020071CC(u32 h, u32 id);
extern u32   func_0216CC58(int heap, u32 n, u32 c);
extern u32   func_02028844(void *p, int heap);
extern u32   func_02014428(int heap);
extern u32   func_02008254(int heap);
extern u32   func_0200873C(u32 h);
extern u32   func_02007AA4(int heap, u32 h);
extern u32   func_020097C4(int heap);
extern void  func_0200BDE4(void *p);
extern void  func_02161D98(void *p);
extern u32   func_0200857C(int heap);
extern u32   func_020071E4(u32 h);
extern u32   func_0215E31C(int heap);
extern void  func_0202E43C(void *p);
extern void  func_02012C18(void *p);
extern u32   func_0202E770(int heap);
extern u32   func_0202751C(int heap, u32 n);
extern u32   func_021647A0(void *p, int heap);

void *func_020124F4(u16 heap)
{
    u8 *p;
    int i;
    u32 n;
    void *src;

    p = func_02030734(heap, 0x6B0, 1, g_020A728C, 0xAD);
    *(u32 *)p = func_020070A4();
    *(u8 *)(p + 0x1C4) = func_0202E888();
    *(u8 *)(p + 0x1C6) = 0;

    *(u32 *)(p + 0x15C) = func_02008854(*(u32 *)p);
    *(u32 *)(p + 0x160) = func_02008844(*(u32 *)(p + 0x15C));
    *(u32 *)(p + 0x164) = func_02008844(*(u32 *)(p + 0x15C));
    *(u32 *)(p + 0x168) = func_02008848(*(u32 *)(p + 0x15C));
    *(u32 *)(p + 0x16C) = func_0200884C(*(u32 *)(p + 0x15C));

    *(u32 *)(p + 0x1A4) = func_02006E40(heap);

    for (i = 0; i < 5; i++) {
        func_02012A60(p + 4 + i * 0x44);
    }

    n = func_02008468();
    src = func_02012944(p);
    memcpy(func_02008730(*(u32 *)p), src, n);

    *(u32 *)(p + 0x158) = func_0216237C(heap);
    func_021623DC();
    *(u32 *)(p + 0x1AC) = func_02012FE4(*(u32 *)p);
    *(u32 *)(p + 0x1B0) = func_02159B48(heap);
    *(u32 *)(p + 0x1A8) = func_0216CC58(heap, 0x40, func_020071CC(*(u32 *)p, 0x33));
    *(u32 *)(p + 0x1B4) = func_02028844(p, heap);
    *(u32 *)(p + 0x1B8) = func_02014428(heap);
    *(u32 *)(p + 0x18C) = func_02008254(heap);
    *(u32 *)(p + 0x190) = func_020071CC(*(u32 *)p, 0x19);
    *(u32 *)(p + 0x194) = func_020071CC(*(u32 *)p, 0x1A);
    *(u32 *)(p + 0x198) = func_0200873C(*(u32 *)p);
    *(u32 *)(p + 0x19C) = func_02007AA4(heap, *(u32 *)p);
    *(u32 *)(p + 0x1A0) = func_020097C4(heap);

    for (i = 0; i < 4; i++) {
        func_0200BDE4(p + 0x1D4 + i * 0x10);
    }

    for (i = 0; i < 2; i++) {
        func_02161D98(p + 0x214 + i * 0x1E8);
    }

    *(u32 *)(p + 0x6AC) = func_0200857C(heap);
    *(u32 *)(p + 0x1C0) = 0;
    func_020071E4(*(u32 *)p);

    *(u32 *)(p + 0x5E4) = func_0215E31C(heap);
    func_0202E43C(p + 0x5E8);
    func_02012C18(p);
    *(u32 *)(p + 0x680) = 0;
    *(u32 *)(p + 0x688) = 0;
    *(u32 *)(p + 0x684) = func_0202E770(heap);
    *(u32 *)(p + 0x68C) = func_0202751C(heap, 0x8001);
    *(u32 *)(p + 0x690) = func_021647A0(p, heap);
    *(u32 *)(p + 0x6A4) = 0;
    *(u32 *)(p + 0x6A8) = 0;

    return p;
}
