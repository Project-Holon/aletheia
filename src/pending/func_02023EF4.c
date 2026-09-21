/*
 * unit:     no
 * function: func_02023EF4
 * address:  0x02023EF4
 * packet:   pkt_02023E0C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Front end for func_02023E9C: given a record pointer and a two-bit engine
 * mask, it arms the record once per selected engine. Each arm first sets
 * the hardware blend-brightness register for that engine to the starting
 * value through G2x_SetBlendBrightness_ (0x0207D658), then calls
 * func_02023E9C with the shared step/from/to triple and the two stack
 * arguments (the starting value, and the engine bit itself as the tag).
 *
 * The two pool words 0x04000050 and 0x04001050 are the main and sub
 * engine's BLDCNT/BLDY block; both arms are written out in full rather
 * than factored behind a helper, which is what keeps them as two separate
 * call sequences rather than one tail-merged site (the second arm's first
 * blx takes an extra r2 argument, so they are not identical anyway).
 *
 * Note the second engine's register word is the plain constant 0x04001050
 * in the pool, not 0x04000050 + 0x1000 computed at run time.
 *
 * BLOCKER: capped at MATCH. All 108 bytes are byte-correct and four of the
 * six relocation sites resolve (G2x_SetBlendBrightness_ twice by label,
 * func_02023E9C twice by matched, once src/matched/func_02023E9C.c entered
 * the shard in this same run). The two remaining sites are the ABS32 pool
 * words at +0x60 and +0x68, the per-engine descriptor tables at 0x0202691C
 * and 0x020268FC that are func_02023E9C's first argument. Blocking evidence
 * class: literal. Neither word appears in any literal pool at another
 * address, and being plain data they can never be label-, veneer- or
 * matched-attested; the only two references anywhere in the image are the
 * two pool words inside this function's own range. A cut is not available
 * either, since both sites live in the one function. What would unstick it
 * is any other function that loads either table address, or a data-region
 * decompilation that defines the tables.
 *
 * Both engines pass the same record pointer p to func_02023E9C; the first
 * argument is the engine's own descriptor table, and the last argument is
 * the engine bit (1 or 2), which func_02023E9C stores to f04.
 *
 * G2x_SetBlendBrightness_ is called with two arguments in the first arm
 * and three in the second, so the two arms cannot tail-merge; declaring
 * two externs at the same address (0x0207D658) is what reproduces that.
 *
 * symbols:
 *   G2x_SetBlendBrightness_   0x0207D658  arm
 *   G2x_SetBlendBrightness2_  0x0207D658  arm
 *   func_02023E9C             0x02023E9C  thumb
 *   data_0202691C             0x0202691C  data
 *   data_020268FC             0x020268FC  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void G2x_SetBlendBrightness_(void *reg, u32 a);
extern void G2x_SetBlendBrightness2_(void *reg, u32 a, u32 b);
extern void func_02023E9C(void *rec, void *p, u16 steps, s16 from,
                          u32 a4, u32 a5);

extern char data_0202691C[];
extern char data_020268FC[];

void func_02023EF4(void *p, u16 steps, s16 from, s16 to, u32 mask)
{
    if (p == 0) {
        return;
    }

    if (mask & 1) {
        G2x_SetBlendBrightness_((void *)0x04000050, (u32)to);
        func_02023E9C(data_0202691C, p, steps, from, (u32)to, 1);
    }

    if (mask & 2) {
        G2x_SetBlendBrightness2_((void *)0x04001050, (u32)to, (u32)from);
        func_02023E9C(data_020268FC, p, steps, from, (u32)to, 2);
    }
}
