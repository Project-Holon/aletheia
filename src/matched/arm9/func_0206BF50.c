/*
 * function: NNSi_G3dFuncSbc_SHP_InternalDefault
 * address:  0x0206BF50
 * packet:   pkt_0206BEA0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The four-stop hook walk of the 0x0206B94C family, one slot over: the state
 * byte at +0x91 is read through the +0x20 hook (zero when the hook is null),
 * and stops 1, 2 and 3 each clear bit 6 of the status word at +0x08 and call
 * the hook. Only the flag/0x100 gate between stops 1 and 2 does work, handing
 * NNS_G3dGeSendDL the second argument's own +0x08 offset and its +0x0c word.
 *
 * PINNED ../2.0/sp2 on the re-read/forward tell (docs/FRONTEND-PINS.md), the
 * same measurement as src/matched/NNSi_G3dFuncSbc_MTX.c one packet over. The hook
 * dispatch appears THREE times, at 0x0206BF74..0x0206BF88,
 * 0x0206BFD8..0x0206BFEC and 0x0206C008..0x0206C01C, and every time the image
 * loads the hook pointer AFTER the flag store has retired: `ldr r1, [r5, #8]`
 * (`08 10 95 e5`) / `mov r0, r5` / `bic r1, r1, #0x40` (`40 10 c1 e3`) /
 * `str r1, [r5, #8]` (`08 10 85 e5`) / `ldr r1, [r5, #0x20]` (`20 10 95 e5`) /
 * `blx r1` (`31 ff 2f e1`). dsi/1.1p1 -O4,p hoists that load above the
 * read-modify-write at all three sites: the same 212 bytes, 42 concrete bytes
 * out. Under the pin the same C is 212 bytes, 0 mismatches.
 *
 * NOT a 1.2 candidate despite the three `blx r1`: the returns are
 * `popne {r4, r5, r6, pc}` / `pop {r4, r5, r6, pc}`, not the ARMv4T pair.
 *
 * symbols:
 *   NNS_G3dGeSendDL  0x0206DC00  arm
 */

typedef unsigned int u32;
typedef unsigned char u8;

typedef struct Obj0206BF50 Obj0206BF50;
struct Obj0206BF50 {
    u32   f00;
    u32   f04;
    u32   f08;
    u8    pad0c[0x20 - 0x0c];
    void (*f20)(Obj0206BF50 *);
    u8    pad24[0x91 - 0x24];
    u8    f91;
};

typedef struct Arg0206BF50 {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
} Arg0206BF50;

extern void NNS_G3dGeSendDL(const u32 *src, u32 sz);

void NNSi_G3dFuncSbc_SHP_InternalDefault(Obj0206BF50 *p, u32 unused, Arg0206BF50 *a)
{
    u32 st;
    u32 flag;

    st = p->f20 ? p->f91 : 0;
    if (st == 1) {
        p->f08 &= ~0x40;
        p->f20(p);
        st = p->f20 ? p->f91 : 0;
        flag = p->f08 & 0x40;
    } else {
        flag = 0;
    }
    if (flag == 0) {
        if (!(p->f08 & 0x100)) {
            NNS_G3dGeSendDL((const u32 *)((u8 *)a + a->f08), a->f0c);
        }
    }
    if (st == 2) {
        p->f08 &= ~0x40;
        p->f20(p);
        st = p->f20 ? p->f91 : 0;
    }
    if (st == 3) {
        p->f08 &= ~0x40;
        p->f20(p);
    }
}
