/*
 * function: func_02155F58
 * address:  0x02155F58
 * packet:   pkt_ov009_02155F58
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * 2026-10-05 (wave D6 lane 19): still 4 bytes (bne/b instead of beq onto case 4's `b end`).
 *   Tried: `if (r == 0) { } else { ... }` (empty then-arm, same bne/b). The r == 0 target is
 *   threaded to the tail before range fixing in every form so far.
 *
 * note (2026-10-04, wave D3 lane 13): complete draft, only residue is the first
 *   branch after func_02059E38: original is `beq 0x2156022` (a short branch to the
 *   `b end` that closes case 4), ours is `bne body; b end` (+4 bytes, 440 vs 436).
 *   Everything after matches instruction for instruction modulo that shift.
 *   Tried: `if (r == 0) goto tail;` plus a tail label (same output).
 *   Idea left: find what makes mwcc retarget a far beq to an existing b-trampoline.
 * note (2026-10-05, D4-11): still 4 bytes (beq onto case 4's `b end`). Tried: `goto skip`
 *   with the label inside case 4 before its break (threaded to end, same output); the
 *   post-switch tail written out in the r == 0 arm (504 bytes, no cross-jump); an
 *   `else { ret = 0; }` / `else { ret = r; }` arm (still bne/b, worse).
 * note (2026-10-05, D5-15): still 4 bytes. mwcc threads the branch to `end` without
 *   checking range, so the original beq target must have held code at threading time
 *   that a later pass removed (or a cross-jump merged a separate `b end` block into
 *   case 4's tail). Tried: `do { if (r == 0) break; ... } while (0)` and again
 *   `goto skip` with `skip: break;` after case 4's if (both bne/b, 440 bytes).
 *
 * symbols:
 *   g_021A8264  0x021A8264  data  ov009  a4
 *   func_02155374  0x02155374  thumb  ov009
 *   func_02059E38  0x02059E38  arm
 *   func_02059F18  0x02059F18  arm
 *   func_0203C9AC  0x0203C9AC  arm
 *   func_0205CC20  0x0205CC20  arm
 *   func_020111E8  0x020111E8  thumb
 *   func_0216AD50  0x0216AD50  arm  ov009
 *   func_021C5B80  0x021C5B80  arm  ov114
 *   DWC_GdbShutdown  0x021E1340  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef int (*Cb)(u32, u32, u32, int);

extern u8 *g_021A8264;
extern void func_02155374(int v);
extern int func_02059E38(int *a, int *b);
extern void func_02059F18(void);
extern void func_0203C9AC(int a, u32 b, u32 c, u32 d);
extern void func_0205CC20(void);
extern void func_020111E8(void);
extern void func_0216AD50(void);
extern void func_021C5B80(void);
extern void DWC_GdbShutdown(void);

u32 func_02155F58(void)
{
    int a, b;
    int r;
    u32 ret = 0;
    Cb cb;

    r = func_02059E38(&a, &b);
    if (r != 0) {
        cb = *(Cb *)(g_021A8264 + 0x294);
        if (cb != 0) {
            if (cb(*(u32 *)(g_021A8264 + 0x298), a, b, r) == 1)
                return ret;
        }
        cb = *(Cb *)(g_021A8264 + 0x28C);
        if (cb != 0)
            cb(*(u32 *)(g_021A8264 + 0x290), a, b, r);
        ret = a;
        if (a == 0 || b == 1)
            ret = r;
        switch (b) {
        case 1:
            func_02059F18();
            if (g_021A8264 != 0 && *(u32 *)(g_021A8264 + 0x754) == 0xE)
                func_02155374(6);
            break;
        case 2:
            if (a <= -40000 && a >= -41999)
                DWC_GdbShutdown();
            if (g_021A8264 != 0 && *(u32 *)(g_021A8264 + 0x754) == 0xE)
                func_02155374(6);
            break;
        case 4:
            if (a <= -40000 && a >= -41999)
                DWC_GdbShutdown();
            break;
        case 5:
            func_021C5B80();
            break;
        case 3:
        case 6:
            if (g_021A8264 != 0) {
                switch (*(u32 *)(g_021A8264 + 0x754)) {
                case 3: case 6: case 7: case 8: case 9: case 10: case 11:
                case 14: case 18: case 19: case 20:
                    if (g_021A8264[0x7A9] == 1) {
                        func_0216AD50();
                        g_021A8264[0x7A9] = 0;
                    }
                    func_0205CC20();
                    break;
                case 0: case 1: case 2:
                    func_0205CC20();
                    break;
                default:
                    break;
                }
            }
            if (g_021A8264 != 0)
                func_02155374(0x10);
            break;
        case 7:
            if (g_021A8264 != 0) {
                Cb f;
                func_02155374(0x11);
                f = *(Cb *)(g_021A8264 + 0x2A8);
                if (f != 0)
                    ((void (*)(int))f)(-a);
            }
            break;
        default:
            break;
        }
    }
    if (g_021A8264[0x79E] != 0) {
        ret = 0x3EE;
        func_0203C9AC(a, b, r, ret);
    } else if (*(u32 *)(g_021A8264 + 0x754) == 0x14) {
        ret = 0x3F0;
        func_0203C9AC(a, b, r, ret);
    } else if (r != 0) {
        func_0203C9AC(a, b, r, 0);
        func_020111E8();
    }
    return ret;
}
