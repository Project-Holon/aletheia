/*
 * function: sub_0200A358
 * address:  0x0200A358
 * packet:   pkt_0200A358
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  none available -- 0x021DFEAC (+0x4A) and 0x021DFE90 (+0x56) are
 *           overlay-window addresses that SEVEN overlays hold (ov093, ov119,
 *           ov137, ov170, ov175, ov183, ov228) and that NONE of them carries
 *           a func_ label at, so `attest_overlay_label` refuses at part 1 and
 *           no region hint helps; the `veneer` class admits ARM shapes only
 *           (ov228's thunk at 0x021DFE90 is the Thumb tail-call shape mwccarm
 *           itself emits); a word scan over all 242 regions finds neither
 *           address in any literal pool, so `literal` has no witness either;
 *           and the two calls sit inside the one 120-byte leaf, so no cut can
 *           make the compared range smaller than the function.  Permanent
 *           until disasm.py labels either address.  ALL 120 BYTES ARE RIGHT,
 *           8 of 10 sites resolved.
 * symbols:
 *   sub_020071CC   0x020071CC  thumb
 *   sub_020071EC   0x020071EC  thumb
 *   sub_0200A480   0x0200A480  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_021DFC20  0x021DFC20  thumb  ov228
 *   func_021DFE90  0x021DFE90  thumb
 *   func_021DFEAC  0x021DFEAC  thumb
 *   ov_id_E4       0x000000E4  data
 *
 * WHAT CHANGED THIS WAVE (docs/notes/pkt_0200A358.c.txt had this row at DIFF,
 * 112 bytes against 120, 91 concrete bytes out).  The note's C spelled the
 * dispatch on a2 as `if (a2 == 1) t = sub_020071EC(a1);` with `t` initialised
 * to 1.  The original is a SWITCH with an explicit empty-ish case 0:
 *
 *   0200A36A  cmp r4, #0 / beq  ->  0200A374: b 0200A37E  (t = 1)
 *   0200A36E  cmp r4, #1 / beq  ->  0200A376: bl 20071EC
 *   0200A372  b            ->  0200A37E: movs r0, #1      (default, t = 1)
 *
 * Two separate branch targets that both land on `movs r0, #1` is the tell of
 * docs/idioms/empty-switch-arms-are-what-make-the-table.md read the other way
 * round: case 0 and the default arm are written out separately in the source
 * even though they do the same thing.  Writing the switch with case 0,
 * case 1 and default each assigning `t` recovers the missing 8 bytes AND the
 * register allocation -- the `if` form spilled a3 to `[sp]` where the
 * original keeps it in r7 -- and takes the row from 91 concrete bytes out to
 * zero in one edit.  The 0xE4 pool word is the same absolute linker symbol
 * func_0200A3D0 next door uses
 * (docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/pending/func_0200A358.c \
 *       --func sub_0200A358 --addr 0x0200A358 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *sub_020071CC(int a, int b);
extern int   sub_020071EC(int a);
extern void  sub_0200A480(u8 *p);
extern void  func_02034AC4(void *id);
extern void  func_02082BCC(void *dst, int val, unsigned n);
extern void *func_021DFC20(int a);
extern int   func_021DFE90(void *p);
extern void *func_021DFEAC(void);
extern u8    ov_id_E4[];

void sub_0200A358(u8 *p, int a1, int a2, int a3)
{
    int t;

    func_02082BCC(p, 0, 0xc);
    switch (a2) {
    case 0:
        t = 1;
        break;
    case 1:
        t = sub_020071EC(a1);
        break;
    default:
        t = 1;
        break;
    }
    if (t != 0) {
        *(u32 *)p = (u32)sub_020071CC(a1, 0x22);
        *(u32 *)(p + 4) = 1;
        return;
    }
    func_02034AC4(ov_id_E4);
    *(u32 *)(p + 8) = (u32)func_021DFC20(a3);
    *(u32 *)p = (u32)func_021DFEAC();
    *(u32 *)(p + 4) = 0;
    if (func_021DFE90((void *)*(u32 *)(p + 8)) == 0) {
        func_02082BCC((void *)*(u32 *)p, 0, 0x368);
        sub_0200A480(p);
    }
}
