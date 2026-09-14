/*
 * unit:     yes
 * address:  0x02017100
 * packet:   pkt_02016FC8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_02017100, func_02017114, func_02017168
 *
 * The first of two parallel fillers of the same nine word record.
 * func_02017168 builds it from the five values func_02017114 reads out of the
 * save block and writes 0 into the last word; its twin at 0x02017214 builds
 * the same record from a pair of pointers and writes 1, so that word is the
 * tag saying which of the two produced it.  The twin is parked in
 * src/pending/unit_02017214.c: it is the only caller of six of its eight
 * callees.
 *
 * func_02017100 passes its first argument through func_020185F4 rather than
 * holding it in a callee-saved register, which is only possible because that
 * function returns its argument: it is the two byte `bx lr` at 0x020185F4 that
 * src/matched/unit_020185F0.c matches as an empty hook.  Written as a void
 * call followed by func_02017114(p, ...) the first argument would have to be
 * saved across it and the function grows a register.
 *
 * symbols:
 *   func_02017E88  0x02017E88  thumb
 *   func_02017EB4  0x02017EB4  thumb
 *   func_020185F4  0x020185F4  thumb
 *   func_0202D060  0x0202D060  thumb
 *   func_0202D09C  0x0202D09C  thumb
 *   func_0202D0D4  0x0202D0D4  thumb
 *   func_0202D110  0x0202D110  thumb
 *   func_0202D144  0x0202D144  thumb
 *   func_0202D178  0x0202D178  thumb
 *   func_0202D1AC  0x0202D1AC  thumb
 *   func_0202D1E0  0x0202D1E0  thumb
 */

typedef unsigned int u32;

extern u32   func_02017E88(void *p, u32 id, u32 v);
extern u32   func_02017EB4(void *p);
extern void *func_020185F4(void *p);

extern u32 func_0202D060(u32 a, u32 b, u32 c, u32 d);
extern u32 func_0202D09C(u32 h, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern u32 func_0202D0D4(u32 h, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern u32 func_0202D110(u32 h, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern u32 func_0202D144(u32 h, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern u32 func_0202D178(u32 h, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern u32 func_0202D1AC(u32 h, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern u32 func_0202D1E0(u32 h, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);


struct Stats {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
};

void func_02017114(void *p, struct Stats *out, u32 lvl);
void func_02017168(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, struct Stats *out,
                   u32 a6);

void func_02017100(void *p, struct Stats *out, u32 lvl)
{
    func_02017114(func_020185F4(p), out, lvl);
}

void func_02017114(void *p, struct Stats *out, u32 lvl)
{
    u32 a0 = func_02017E88(p, 5, 0);
    u32 a1 = func_02017E88(p, 0x6F, 0);
    u32 a2 = func_02017E88(p, 0x6E, 0);
    u32 a3 = func_02017EB4(p);
    u32 a4 = func_02017E88(p, 0x4C, 0);

    func_02017168(a0, a1, a2, a3, a4, out, lvl);
}

void func_02017168(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, struct Stats *out,
                   u32 a6)
{
    out->unk00 = func_0202D060(a0, a1, a2, a3);
    out->unk04 = func_0202D09C(out->unk00, a0, a1, a2, a3, a6, a4);
    out->unk08 = func_0202D0D4(out->unk00, a0, a1, a2, a3, a6, a4);
    out->unk0C = func_0202D110(out->unk00, a0, a1, a2, a3, a6, a4);
    out->unk10 = func_0202D144(out->unk00, a0, a1, a2, a3, a6, a4);
    out->unk14 = func_0202D178(out->unk00, a0, a1, a2, a3, a6, a4);
    out->unk18 = func_0202D1AC(out->unk00, a0, a1, a2, a3, a6, a4);
    out->unk1C = func_0202D1E0(out->unk00, a0, a1, a2, a3, a6, a4);
    out->unk20 = 0;
}
