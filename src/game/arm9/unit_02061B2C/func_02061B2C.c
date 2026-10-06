/*
 * function: func_02061B2C
 * address:  0x02061B2C
 * packet:   pkt_02061B2C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_020A1718     0x020A1718  data
 *   func_020862F0  0x020862F0  arm
 *
 * Table dispatch: the handler g_020A1718[s[0]] is fetched first, func_020862F0
 * gets (s[1], s[3]), then the handler gets (s[1], s[2], s[3]).  The re-read
 * tell (docs/FRONTEND-PINS.md): the image reloads all three fields after the
 * first call with one `ldmib r5, {r0, r1, r2}` at 0x02061B4C; 1.1p1 keeps s[3]
 * live from the first call's argument and emits `ldr r2, [r5, #0xc]` plus a
 * two-register ldmib (52 bytes, 20 out).  Under ../2.0/sp2 the same C is 44
 * bytes, 0 mismatches; EXACT* only because the follower 0x02061B5C
 * (src/matched/func_02061B5C.c) has no label.
 */

typedef unsigned int u32;
typedef void (*Fn)(u32, u32, u32);
extern Fn g_020A1718[];
extern void func_020862F0(u32, u32);

void func_02061B2C(u32 *s)
{
    Fn f = g_020A1718[s[0]];
    func_020862F0(s[1], s[3]);
    f(s[1], s[2], s[3]);
}
