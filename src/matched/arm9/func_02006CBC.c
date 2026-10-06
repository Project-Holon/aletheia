/*
 * function: func_02006CBC
 * address:  0x02006CBC
 * packet:   pkt_02006CBC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  02006D3C - the 8-byte ARM `ldr pc, [pc, #-4]` stub whose pointer
 *           word 0x027047C0 lies outside every region of layout/layout.json,
 *           so the `veneer` class refuses the call.  All 112 concrete bytes
 *           and every other site are right.
 *
 * symbols:
 *   g_020A703C   0x020A703C  data
 *   g_020A7030   0x020A7030  data
 *   g_02146164   0x02146164  data
 *   func_02030734  0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0208BEF0  0x0208BEF0  arm
 *   func_0208BF38  0x0208BF38  arm
 *   func_0208B24C  0x0208B24C  arm
 *   func_02085D3C  0x02085D3C  arm
 *   func_02006D3C  0x02006D3C  arm
 *
 * Allocate and publish the two sound blocks: a 0x28-byte driver object and
 * a 0x2014-byte sample pool, both with the same string at 0x020A703C as
 * their `__FILE__`-style argument (0x59 and 0x5f are the two line numbers,
 * and only the first is a pool word - see
 * docs/idioms/consecutive-line-numbers-are-one-pool-word-and-adds.md).  The
 * sample pool is linked into the object at +0x24 before the hardware is
 * poked, the bitfield at +0x20 has its low bit cleared and set again
 * (`bics` for the clear), and the finished object is stored at 0x02146164.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02006CBC.c \
 *       --func func_02006CBC --addr 0x02006CBC --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

struct Sub02006CBCObj {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
};

extern char g_020A703C[];
extern char g_020A7030[];
extern void *g_02146164;

typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  func_02082BCC(void *p, u32 v, u32 n);
extern unsigned int func_0208BEF0(unsigned int status);
extern unsigned int func_0208BF38(unsigned int gain);
extern void  func_0208B24C(void);
extern int   func_02085D3C(void);
extern void  func_02006D3C(u32 a, char *b);

void func_02006CBC(u16 heap)
{
    struct Sub02006CBCObj *p;
    void *pool;

    p = func_02030734(heap, 0x28, 0, g_020A703C, 0x59);
    func_02082BCC(p, 0, 0x28);
    pool = func_02030734(heap, 0x2014, 0, g_020A703C, 0x5f);
    func_02082BCC(pool, 0, 0x2014);
    p->unk24 = (u32)pool;
    func_0208BEF0(1);
    func_0208BF38(2);
    p->unk20 = (p->unk20 & ~1u) | 1u;
    func_0208B24C();
    if (func_02085D3C() == 1) {
        func_02006D3C(0, g_020A7030);
    }
    g_02146164 = p;
}
