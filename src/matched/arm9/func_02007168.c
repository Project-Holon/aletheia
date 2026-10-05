/*
 * function: func_02007168
 * address:  0x02007168
 * packet:   pkt_02007168
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocker:  02031BB4 (arm) reached only by the `blx` inside this function; also EXACT* -> the follower at 0x020071A8 carries no label
 *
 * symbols:
 *   func_02007428  0x02007428  thumb
 *   func_02031BB4  0x02031BB4  arm
 *   func_02008754  0x02008754  thumb
 *
 * Two byte flags at +4 and +5 are one `||` (the first arms the early return,
 * the second skips it), while the pair at the end is a genuine `&&` - so
 * only the first guard shares its exit.  The early arm returns the zero it
 * just stored into both flags, which is why the `movs r0, #0` is not
 * duplicated into a third register.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02007168.c \
 *       --func func_02007168 --addr 0x02007168 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub02007168 {
    u8  unk00;
    u8  unk01;
    u8  unk02;
    u8  unk03;
    u8  unk04;
    u8  unk05;
    u8  unk06;
    u8  unk07;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
};

extern void func_02007428(void);
extern int func_02031BB4(u32 a0);
extern u8 func_02008754(void *sys);

u32 func_02007168(struct Sub02007168 *p)
{
    u32 r;

    if (p->unk04 == 1 || p->unk05 == 1) {
        func_02007428();
        p->unk04 = 0;
        p->unk05 = 0;
        return 0;
    }
    r = func_02031BB4(p->unk10);
    if (r == 2 && func_02008754(p) == 0) {
        p->unk00 = 0;
        p->unk01 = 1;
    }
    return r;
}
