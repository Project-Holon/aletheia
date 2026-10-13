/*
 * function: func_021BCFAC
 * address: 0x021BCFAC
 * packet: pkt_ov093_021BCFAC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note 2026-10-05 (wD9r lane04): EXACT* (the trailing 021BD07E halfword is alignment padding). Closed
 *   with `r -= x - y; if (r < x - y) return 3;` in place of the one-expression
 *   `(u16)(r - (u16)(x - y)) < x - y`. The redefinition of r splits its live range, so the first use
 *   reloads the spilled r (`str r0,[sp]; ldr r0,[sp]`). No cast stand-in.
 * note 2026-10-05 (wD9 lane18): still DIFF 55 B (no stand-in). Reading: the first use of r must be an
 *   operation on the spilled r (the u16 to u32 widening node), not the call temp; any plain form forwards r0.
 *   Tried: a static inline u16 rnd(u32) for both random calls; operands reversed (x - y > r) in one and both
 *   compares; an int d = x - y block; r as u32 with (u16) at the def and (int)r at the compare (a real
 *   signedness cast, still forwards r0). All 55 B.
 * note 2026-10-05 (integrator): the source no longer has the (int)(u32)r stand-in cast, so it is DIFF (the plain compare drops the reload of r). With the cast it verifies EXACT*: rejected as a stand-in.
 * note 2026-10-05: witness src/matched/arm9/func_02018480.c filed (EXACT); the wildcard at +0x38 resolves after regeneration. The reload still needs the (int)(u32)r spelling, which is a no-op steering cast (stand-in, not accepted). Tried without it: u16 callee return type for func_021D78AC with plain compares, and an int local fed from the u16 return: both forward r0 and drop the ldr (200 bytes). Parked MATCH* because of the cast; reading: r is spilled for real (p,a,x,y fill r4..r7), so the original defines r with the store at the def and the reload at first use; no stand-in free source found.
 * evidence (older): every concrete byte matched (MATCH*, the trailing 021BD07E
 *   halfword is alignment padding). The one wildcard is +0x38, the bl to the
 *   ARM9 Thumb thunk func_02018480 (ldr r3,[pc]; bx r3; .word 0x02018489),
 *   which has no witness outside this range: label/sole-ref need an arm9
 *   label or a matched entry there. It is an arm9 leaf, the integrator's; its verified
 *   C is below. Once it is filed this caller re-runs to EXACT*.
 * blocker:
 *   func_02018480 0x02018480 thumb, arm9; `one --thumb` (no --region): EXACT
 *     extern int func_02018488(void *p, int q);
 *     int func_02018480(void *p, int q)
 *     {
 *         return func_02018488(p, q);
 *     }
 *   (func_02018488 0x02018488 thumb resolves by label; it reads r0 and r1 and
 *   returns the 0/1 in r6.)
 * note: the reload `str r0,[sp]; ldr r0,[sp]` at 021BD046/021BD048 comes only
 *   from spelling the first use of r through a widening cast, `(int)(u32)r`;
 *   plain `r`, `(int)r` and u16/u32/int locals forward r0 into the compare
 *   and drop the ldr (55 bytes out), and `(u32)r` alone reloads but turns
 *   the bge into bhs.
 * symbols:
 *   func_02018480 0x02018480 thumb
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021B8DDC 0x021B8DDC thumb ov093
 *   func_021B8FF4 0x021B8FF4 thumb ov093
 *   func_021D5844 0x021D5844 thumb ov093
 *   func_021B871C 0x021B871C thumb ov093
 *   func_021B85A0 0x021B85A0 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021D78AC 0x021D78AC thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021BD080 0x021BD080 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_021B86B8(void ***);
extern u8 func_021D5440(u8 *);
extern u8 func_021B8DDC(u32);
extern u8 func_021B8FF4(u8 *);
extern void *func_021D5844(void *);
extern int func_021B871C(char *);
extern int func_02018480(void *, int);
struct Unk021D62A8;
extern u8 func_021B85A0(u8 **p);
extern int func_021D59B4(u8 *, int);
extern u32 func_021D78AC(u32);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern int func_021BD080(u8 *, u8 *);

int func_021BCFAC(u8 *p, u8 *a)
{
    int k;
    u32 n;
    u16 x, y;
    if ((u32)func_021B86B8(*(void ****)(p + 4)) <= 1) {
        k = func_021B8DDC(func_021D5440(a));
        if (k == func_021B8FF4(*(u8 **)(p + 4))) {
            void *v = func_021D5844(a);
            if (func_02018480(v, func_021B871C(*(char **)(p + 4))) == 0) {
                n = func_021B85A0((u8 **)(*(u8 **)(p + 4)));
                if (n < 8) {
                    u16 r;
                    x = (u16)func_021D59B4(a, 15);
                    y = (u16)(10 * (n + 1));
                    if (x <= y) return 0;
                    if ((u16)func_021D78AC(x + y + 1) < y) return 0;
                    if (func_021D62C4((struct Unk021D62A8 *)a, 2) != 0) return 4;
                    r = func_021D78AC(256);
                    if (r < x - y && func_021BD080(p, a) == 0) return 2;
                    r -= x - y;
                    if (r < x - y) return 3;
                    return 4;
                }
            }
        }
    }
    return 0;
}
