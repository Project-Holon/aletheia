/*
 * file:     unit_020746C4_p08.c
 * unit:     yes
 * function: func_020751F4, func_0207524C, func_02075274, func_020752A4
 * address:  0x020751F4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020751F4    0x020751F4  arm
 *   func_020896AC    0x020896AC  arm
 *   func_020896CC    0x020896CC  arm
 *   func_0208A38C    0x0208A38C  arm
 */
struct SNDBankData;
struct SNDWaveArc;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;


extern u32 func_02087988(void);
extern void func_0208799C(u32);
struct Global;
extern struct Global *func_020742E4(struct Global *val);
extern u32 func_0207466C(u32);
extern void func_02074694(u32, u32);
void func_020751F4(u32 a, u32 b, u32 c) {
    u32 t, s;
    if (b == 0) return;
    s = func_02087988();
    t = (u32)func_020742E4((struct Global *)b);
    if (func_0207466C(c) == a) func_02074694(c, 0);
    func_020742E4((struct Global *)t);
    func_0208799C(s);
}

typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

extern void func_020751F4(u32 a, u32 b, u32 c);
extern void func_020896AC(const void *start, const void *end);
extern void func_020896CC(const void *start, const void *end);
extern void func_0208A38C(struct SNDBankData *bank);
extern void func_020896EC(const void *start, const void *end);
extern void func_0208A424(struct SNDWaveArc *waveArc);
void func_0207524C(u8 *p, u32 len, u32 b, u32 c);
void func_02075274(u8 *p, u32 len, u32 b, u32 c);
void func_020752A4(int a, int b, int c, int d);


/*
 *           r2 sweep: still capped -- no EXACT manifest entry covers the site; the matched class has no witness to offer.
 *
 * Reads a bank header, then invalidates the range [p, p + len) of sequence
 * data; the length survives in r4 across the first call.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0207524C.c \
 *       --func func_0207524C --addr 0x0207524C --cc 1.1p1 --arm
 */
void func_0207524C(u8 *p, u32 len, u32 b, u32 c)
{
    func_020751F4((u32)p, b, c);
    func_020896AC(p, p + len);
}


/*
 *           r2 sweep: still capped -- no EXACT manifest entry covers the site; the matched class has no witness to offer.
 *
 * The bank flavour: same range invalidate plus the bank teardown.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02075274.c \
 *       --func func_02075274 --addr 0x02075274 --cc 1.1p1 --arm
 */
void func_02075274(u8 *p, u32 len, u32 b, u32 c)
{
    func_020751F4((u32)p, b, c);
    func_020896CC(p, p + len);
    func_0208A38C((struct SNDBankData *)p);
}


/*
 * Kept as its own file rather than folded with func_020752D4, its immediate
 *  * neighbour: the two are the only callers of 0x0208A424 anywhere in the image,
 *  * so any range holding both has no witness left for that site and caps at
 *  * MATCH. Split, each file is the other's witness.
 */
void func_020752A4(int a, int b, int c, int d)
{
    func_020751F4(a, c, d);
    func_020896EC((const void *)a, (const void *)(a + b));
    func_0208A424((struct SNDWaveArc *)a);
}
