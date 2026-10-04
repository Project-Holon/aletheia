/*
 * function: func_021BCFAC
 * address: 0x021BCFAC
 * packet: pkt_ov093_021BCFAC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH*
 * evidence: every concrete byte matches (MATCH*, the trailing 021BD07E
 *   halfword is alignment padding). The one wildcard is +0x38, the bl to the
 *   ARM9 Thumb thunk func_02018480 (ldr r3,[pc]; bx r3; .word 0x02018489),
 *   which has no witness outside this range: label/sole-ref need an arm9
 *   label or a matched entry there. It is an arm9 leaf, Ilias's; its verified
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
extern u8 func_021B85A0(u8 *);
extern int func_021D59B4(u8 *, int);
extern u32 func_021D78AC(u32);
extern int func_021D62C4(void *, int);
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
                n = func_021B85A0(*(u8 **)(p + 4));
                if (n < 8) {
                    u16 r;
                    x = (u16)func_021D59B4(a, 15);
                    y = (u16)(10 * (n + 1));
                    if (x <= y) return 0;
                    if ((u16)func_021D78AC(x + y + 1) < y) return 0;
                    if (func_021D62C4(a, 2) != 0) return 4;
                    r = func_021D78AC(256);
                    if ((int)(u32)r < x - y && func_021BD080(p, a) == 0) return 2;
                    if ((u16)(r - (u16)(x - y)) < x - y) return 3;
                    return 4;
                }
            }
        }
    }
    return 0;
}
