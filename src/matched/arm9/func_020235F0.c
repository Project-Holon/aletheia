/*
 * function: WIPE_SUB_CircleStart
 * address:  0x020235F0
 * packet:   pkt_02022F60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * cap: the call at +0036 to WIPE_SUB_CircleInit (0x0202368C) is the only reference
 *      to that address outside its own body, and it is inside this range, so
 *      the `label` class refuses it.  All 76 bytes and the other relocation
 *      site (func_02030734) reproduce exactly.  Promotes to EXACT the moment
 *      WIPE_SUB_CircleInit has its own manifest entry.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   WIPE_SUB_CircleInit  0x0202368C  thumb
 *   g_dat          0x020A7450  data
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
typedef signed char    s8;
struct Ctx;
struct Par;
extern void WIPE_SUB_CircleInit(struct Ctx *ctx, const struct Par *par, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7, u32 s8);

struct S {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0C;
    u32 f10;
    void *f14;
    u32 f18;
    u32 f1C;
    u32 f20;
};

void WIPE_SUB_CircleStart(struct S *p, u32 a1)
{
    p->f14 = func_02030734((u16)p->f20, 0x38, 0, (const char *)0x020A7450, 0x0D63);
    WIPE_SUB_CircleInit(p->f14, (const struct Par *)a1, p->f04, p->f08, p->f10, p->f18, p->f1C, p->f20);
    p->f0C = p->f0C + 1;
}
