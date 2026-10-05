/*
 * function: func_021D6B40
 * address:  0x021D6B40
 * packet:   pkt_ov125_021D6B40
 * region:   ov125
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * 2026-10-04 (D3-06): same size (1136 bytes); every block matches except the
 *   placement of the shared tail "str r0,[sp,#8]; b end" (ret = call; break).
 *   Original: all ret-setting cases branch to the tail inside case 0x55F1
 *   sub-case 2 (021D6F46), and sub-case 3 (021D87FC call) keeps its own copy.
 *   This draft: the compiler puts the shared tail in the first case (0x5208)
 *   and sub-case 3 also branches there, so everything after 021D6B9C is
 *   shifted by 2 bytes. Tried without effect: no break after sub-case 3, an
 *   explicit default, u32 return types for the 021D8xxx callees, swapping
 *   case order (layout follows source order; tail goes to the first block).
 *   Fixed already: separate n2/m2/base2 locals (frame 0x40), signed switch
 *   value, assert written as !(f() == 0 ? 1 : 0), per-case B(0x493) stores.
 *
 * symbols:
 *   func_021D7700  0x021D7700  thumb  ov125
 *   func_021D7154  0x021D7154  thumb  ov125
 *   func_021D75C0  0x021D75C0  thumb  ov125
 *   func_021D860C  0x021D860C  arm  ov125
 *   func_021D8654  0x021D8654  arm  ov125
 *   func_021D8694  0x021D8694  arm  ov125
 *   func_021D8754  0x021D8754  arm  ov125
 *   func_021D879C  0x021D879C  arm  ov125
 *   func_021D87FC  0x021D87FC  arm  ov125
 *   func_021D885C  0x021D885C  arm  ov125
 *   func_021D88BC  0x021D88BC  arm  ov125
 *   func_021D88F0  0x021D88F0  arm  ov125
 *   func_021B9748  0x021B9748  thumb  ov114
 *   func_021B9774  0x021B9774  thumb  ov114
 *   func_021B9790  0x021B9790  thumb  ov114
 *   func_021B97F4  0x021B97F4  thumb  ov114
 *   func_021B9800  0x021B9800  thumb  ov114
 *   func_021B9838  0x021B9838  thumb  ov114
 *   func_021B98A0  0x021B98A0  thumb  ov114
 *   func_021B98D8  0x021B98D8  thumb  ov114
 *   func_021B98F8  0x021B98F8  thumb  ov114
 *   func_021B99B8  0x021B99B8  thumb  ov114
 *   func_021B99DC  0x021B99DC  thumb  ov114
 *   func_021B99F0  0x021B99F0  thumb  ov114
 *   func_021B99F4  0x021B99F4  thumb  ov114
 *   func_021B9A14  0x021B9A14  thumb  ov114
 *   func_0200853C  0x0200853C  thumb
 *   func_02045F5C  0x02045F5C  arm
 *   func_0200B784  0x0200B784  thumb
 *   func_0200B91C  0x0200B91C  thumb
 *   func_0200BA44  0x0200BA44  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   d_021D8D28  0x021D8D28  data a4
 *   d_020A7370  0x020A7370  data
 */

/*
 * 2026-10-05 (wave D4 lane07): DIFF, unchanged. Tried inner 0x55F1 switch in source order 2,0,1,3: layout follows source order and the shared tail still goes to the first case (0x5208), so the order is not the lever. Original: every ret-setting case except 0x55F1 sub-case 3 branches to the store at the end of sub-case 2 (sub-case 2 falls into it). Untried idea: the ret-setting cases in another form (ret assigned through a common label/goto, or the 0x55F1 sub-switch in a static inline helper that returns the call result).
 */
/*
 * 2026-10-05 (wave D5 lane09): DIFF, 96 bytes (was 782 with this tool run). New form: the 0x55F1
 *   sub-cases 0 and 1 compute r and `goto set`, sub-case 2 falls into `set: ret = r; break;`. The shared
 *   tail "str r0,[sp,#8]; b end" now sits after sub-case 2 as in the original, and every other
 *   ret-setting case branches there. Residue: sub-case 3 is also merged into that tail (b 021D6F46);
 *   the original keeps its own `str r0,[sp,#8]; b end` copy, so everything after it is 4 bytes short.
 *   Tried for sub-case 3: no break, goto end, return types u32/short/u8 for func_021D87FC, all other
 *   cases through goto set; the 0x55F1 switch as an inline helper (void with int *ret, or int return).
 */
/*
 * 2026-10-05 (wave D6 lane02): DIFF, 96 bytes unchanged. Tried: sub-case 3 of 0x55F1 as
 *   "r = func_021D87FC(...); ret = r; break;" (identical, still merged into the set tail). Listing
 *   re-read: the 0x55F0 sub-case 3 (021D8694) and the 0x5208/0x5209/0x55F2/0x55F3 cases all branch
 *   to 021D6F46; only 0x55F1 sub-case 3 keeps "str r0,[sp,#8]; b 021D6F90". So at tail-merge time
 *   its block must differ from the others (other jump target or other last statement); no source
 *   form found that gives this.
 */
/*
 * 2026-10-05 (wave D7 lane07): DIFF, 96 bytes unchanged. Listing re-read: 0x55F2 and 0x55F3 reach
 *   the shared store at 021D6F46 by BACKWARD branches, 0x5208/0x5209/0x55F0 sub-case 3 by forward
 *   ones; nothing else targets 021D6F54 (case 3's own copy). Tried (all 96 bytes): case 3 with a
 *   block-local u32 temp (`t = f(); ret = t;`); all plain `ret = f(); break;` with only case 3 via a
 *   temp (782, survivor moves to 0x5208); `default: break;` before case 3; case 3 `goto out` with
 *   `out:` after the inner switch; case 3 `goto out` with `out:` after the outer default's assert
 *   call. Reading: the cross-jumper merges case 3 post-RA in every form; the image's case 3 must
 *   differ at merge time in a way no tried form reproduces.
 */
/*
 * 2026-10-05 (wave D8 lane08): DIFF, 96 bytes unchanged. Tried: all four 0x55F1 sub-cases set r and break, one
 *  `ret = r;` after the inner switch, out-of-range `default: goto skip;` (115 bytes, worse: case 2 loses its own
 *  store). Reading: in the image the 0x55F1 case 3 copy is the one that is not cross-jumped, which would fit a block
 *  that falls through to the join at merge time; no source order found that gives this with the image layout.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02034714(const char *expr, u32 line, const char *file);
extern const char d_021D8D28[];
extern void *d_020A7370;
extern char *func_021D7700(void);
extern int func_021D7154(int, int, int *, int *);
extern void func_021D75C0(void);
extern int func_021D860C(void *, u32);
extern int func_021D8654(u16, u32);
extern int func_021D8694(u32, void *, u32, u32);
extern int func_021D8754(void *, u32);
extern int func_021D879C(u32, u32);
extern int func_021D87FC(u32, u32);
extern int func_021D885C(u32, u32);
extern int func_021D88BC(u32, u32, u32, u32);
extern int func_021D88F0(u32, u32, u32);
extern int func_021B9748(u8 *);
extern void func_021B9774(u8 *);
extern int func_021B9790(u8 *);
extern u8 *func_021B97F4(u8 *);
extern u8 *func_021B9800(u16, u32, u32);
extern void func_021B9838(u8 *);
extern void func_021B98A0(u8 *, u16, u32, u32);
extern void func_021B98D8(u8 *, void *, u32);
extern int func_021B98F8(u8 *);
extern void func_021B99B8(u8 *);
extern int func_021B99DC(u8 *);
extern int func_021B99F0(u8 *);
extern u32 func_021B99F4(u8 *, int);
extern void *func_021B9A14(u8 *, u8);
extern void func_02082D44(const void *, void *, u32);
extern u32 func_0200853C(void);
extern void func_0200B784(u16, int *, int *);
extern u8 *func_0200B91C(void);
extern void func_0200BA44(void *);
extern void func_02012944(u32);
extern void func_02012EBC(u32);
extern void func_02045F5C(void *, u32, void *, u32);

#define W(o) (*(u32 *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))
#define B(o) (*(u8 *)(p + (o)))
#define OBJ (*(u8 **)(p + 0x404))

int func_021D6B40(u8 *p, int *done)
{
    int n, m;
    int idx, sub;
    int n2, m2;
    int ret;
    int r;
    char *base;
    char *base2;
    int i;
    u8 *h;
    int a, b;
    u8 x;

    *done = 0;
    ret = 0;
    switch (*(int *)(p + 0x3d8)) {
    case 0x5208:
        ret = func_021D860C(p + 0x174, W(0x3ac));
        break;
    case 0x5209:
        ret = func_021D8654(H(0x3a4), W(0x3ac));
        break;
    case 0x55f0:
        switch (B(0x402)) {
        case 0:
            base = func_021D7700();
            if (OBJ != 0)
                func_02034714(d_021D8D28, ret, d_021D8D28);
            func_02012944(W(0));
            OBJ = func_021B9800((u16)W(0x13c), func_0200853C(), W(0x494));
            func_021B98A0(OBJ, (u16)W(0x13c), 0x540, 3);
            func_0200B784(*(u16 *)(base + 0xa6), &n, &m);
            B(0x490) = 0;
            for (i = 0; i < n; i++) {
                func_021B98D8(OBJ, base + 0xd00 + i * 0x2a4, *(u16 *)(base + i * 0x2a4 + 0xcfe) * 0x70);
                B(0x490) += (u8)*(u16 *)(base + i * 0x2a4 + 0xcfe);
            }
            if (!func_021B98F8(OBJ))
                func_02034714(d_021D8D28, 0, d_021D8D28);
            if (!(func_021B9748(OBJ) == 0 ? 1 : 0))
                func_02034714(d_021D8D28, 0, d_021D8D28);
            B(0x402)++;
            break;
        case 1:
            a = func_021B99DC(OBJ);
            b = func_021B9790(OBJ);
            if (a != 200 && b != 15) {
                switch (func_021B99DC(OBJ)) {
                case 0x190: B(0x493) = 0x96; break;
                case 0x191: B(0x493) = 0x97; break;
                case 0x198: B(0x493) = 0x98; break;
                default: B(0x493) = 0x99; break;
                }
                func_021B99B8(OBJ);
                func_021B9774(OBJ);
                func_021B9838(OBJ);
                OBJ = 0;
                *done = 1;
                return 1;
            }
            if (b == 0) {
                h = func_021B97F4(OBJ);
                if (func_021B99F0(h) == 0) {
                    B(0x492) = 0;
                    func_02082D44(func_021B9A14(h, B(0x490)), p + 0x40a, 0x80);
                    for (i = 0; i < B(0x490); i++)
                        W(0x48c) = func_021B99F4(h, i);
                    B(0x402)++;
                } else {
                    base2 = func_021D7700();
                    if (B(0x403) == 1)
                        B(0x492) = 1;
                    func_0200B784(*(u16 *)(base2 + 0xa6), &n2, &m2);
                    for (i = 0; i < B(0x490); i++) {
                        W(0x48c) = func_021B99F4(h, i);
                        if (W(0x48c) != 0 && B(0x403) == 0) {
                            if (!func_021D7154((int)p, i, &idx, &sub))
                                break;
                            {
                                char *e = base2 + 0xd00 + idx * 0x2a4 + sub * 0x70;
                                func_02045F5C(d_020A7370, *(u16 *)(e + 6), e + 0x32, 11);
                            }
                            W(0x5a0) = 1;
                        }
                    }
                    if (B(0x403) == 0) {
                        func_0200BA44(func_0200B91C());
                        B(0x402) = 0;
                        B(0x403)++;
                    } else {
                        B(0x402)++;
                    }
                }
                func_021B99B8(OBJ);
                func_021B9838(OBJ);
                OBJ = 0;
                break;
            }
            if (b != 15 && OBJ != 0) {
                func_021B99B8(OBJ);
                func_021B9774(OBJ);
                func_021B9838(OBJ);
                OBJ = 0;
                return 1;
            }
            return 0;
        case 2:
            func_02012EBC(W(0));
            func_021D75C0();
            B(0x402)++;
            break;
        case 3:
            ret = func_021D8694(W(0x174), p + 0x40a, 0x80, W(0x3ac));
            break;
        }
        break;
    case 0x55f1:
        switch (W(0x3e0)) {
        case 0:
            r = func_021D8754(p + 0x174, W(0x3ac));
            goto set;
        case 1:
            r = func_021D879C(0x64, W(0x3ac));
            goto set;
        case 2:
            r = func_021D885C(0x64, W(0x3ac));
        set:
            ret = r;
            break;
        case 3:
            ret = func_021D87FC(0x64, W(0x3ac));
            break;
        }
        break;
    case 0x55f2:
        ret = func_021D88BC(W(0x3a4), W(0x3a8), 0x64, W(0x3ac));
        break;
    case 0x55f3:
        ret = func_021D88F0(W(0x3a4), W(0x3a8), W(0x3ac));
        break;
    default:
        func_02034714(d_021D8D28, 0, d_021D8D28);
        break;
    }
    if (ret == 1)
        W(0x3dc) = W(0x3d8);
    return ret;
}
