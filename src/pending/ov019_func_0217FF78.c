/*
 * function: func_0217FF78
 * address:  0x0217FF78
 * packet:   pkt_ov019_0217FF78
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_0217FF78   0x0217FF78  thumb
 *   func_020399A8   0x020399A8  arm
 *   func_0203D1A4   0x0203D1A4  arm
 *   func_02008550   0x02008550  thumb
 *   func_021751DC   0x021751DC  thumb  ov012
 *   func_021677E4   0x021677E4  thumb
 *   func_021675D0   0x021675D0  thumb
 *   func_02167848   0x02167848  thumb  ov010
 *
 * Up to four entries of the table based at p+0x18 (stride 0x2c), dispatching
 * each through one of two handlers.  Addresses are Black-image addresses.
 *
 * blocker: one of two call sites now resolved. 0x021751DC was matched in
 * ov012 (the only overlay with a function start there; see
 * src/matched/ov012_func_021751DC.c) and attests the +0024 site as `matched`.
 * 0x02167848 is still unresolved.  The region/ISA hint is now correct
 * (`thumb ov010`: Thumb code, ov010; ov009 holds ARM data at the address), so
 * ambiguity is gone, but no func_ label exists in any overlay
 * (target_extent is None): `label`/`sole-ref/code` cannot fire, and the only
 * reference image-wide is the call inside this range, so it needs an EXACT
 * ov010 entry.  The leaf itself caps at DIFF on register allocation because
 * mwcc copies a2 into r4 and uses r2 for the 0x1c stride constant, where the
 * original keeps a2 in r2 and the constant in r3 (see
 * docs/notes/ov019_func_0217FF78.c.txt); a region hint cannot resolve an
 * unlabelled leaf.
 */

typedef unsigned int u32;

extern void func_020399A8(void);
extern int func_0203D1A4(void);
extern int func_021751DC(u32 *p, int i, u32 *out);
extern int func_021677E4(u32 v, int i);
extern int func_02008550(u32 *q);
extern void func_021675D0(u32 v, int i, int mode, u32 *out);
extern void func_02167848(u32 v, int i, u32 *out);

void func_0217FF78(u32 *p)
{
    int count;
    int i;
    u32 tmp[5];

    func_020399A8();
    count = func_0203D1A4();

    for (i = 0; i < 4; i++) {
        if (count != i && func_021751DC(p, i, tmp) == 1) {
            if (func_021677E4(p[0], i) == 0) {
                int v = func_02008550((u32 *)((char *)p + 0x18 + 0x2c * i));
                int mode = 1;

                if (v)
                    mode = 4;
                func_021675D0(p[0], i, mode, tmp);
            } else {
                func_02167848(p[0], i, tmp);
            }
        }
    }
}
