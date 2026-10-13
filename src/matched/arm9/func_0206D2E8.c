/*
 * function: NNSi_G3dFuncSbc_CALLDL
 * address:  0x0206D2E8
 * packet:   pkt_0206CB8C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * A script-opcode step: run the 0x34 hook in mode 1, decode the nine-byte
 * instruction word at [s] into a byte offset (p[1..4]) and a payload
 * (p[5..8]), both assembled byte-by-byte because the stream is unaligned,
 * hand them to NNS_G3dGeSendDL unless flag 0x100 or the hook's own 0x40 bit
 * is set, run the hook again in mode 3, and advance the cursor by 9.
 *
 * PIN ../2.0/sp2: the re-read/forward tell (the NNSi_G3dAnmObjInitNsBva /
 * func_02068EA0 family of docs/FRONTEND-PINS.md).  The hook dispatch appears
 * twice, at 0x0206D308..0x0206D31C and 0x0206D39C..0x0206D3B0, and both times
 * the image loads the hook pointer AFTER the flag store has retired:
 *   ldr r1, [r5, #8]  / mov r0, r5 / bic r1, r1, #0x40 /
 *   str r1, [r5, #8]  / ldr r1, [r5, #0x34] / blx r1
 * 1.1p1 -O4,p proves the store cannot alias the 0x34 field and hoists that
 * load above the read-modify-write, giving
 *   ldr r0, [r5, #8] / ldr r1, [r5, #0x34] / bic r2, r0, #0x40 /
 *   mov r0, r5 / str r2, [r5, #8]
 * -- the same 220 bytes with those five instructions permuted at both sites,
 * 28 concrete bytes out.  A `volatile` hook field, a `volatile` flags field,
 * the compound `&= ~0x40u` spelling, and binding the flag word and the hook
 * to named locals with the hook read written last all schedule identically
 * under 1.1p1.  Under the pin the same C is 220 bytes, 0 mismatches.
 *
 * symbols:
 *   NNS_G3dGeSendDL  0x0206DC00  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void NNS_G3dGeSendDL(const u32 *src, u32 sz);

struct S0206D2E8 {
    u8 *cur;        /* 0x00 */
    u32 pad4;
    u32 flags;      /* 0x08 */
    u8 pad0c[0x34 - 0x0c];
    void (*cb)(struct S0206D2E8 *);  /* 0x34 */
    u8 pad38[0x96 - 0x38];
    u8 mode;        /* 0x96 */
};

void NNSi_G3dFuncSbc_CALLDL(struct S0206D2E8 *s)
{
    u32 m;
    u32 g;
    u8 *p;
    if (s->cb != 0) m = s->mode; else m = 0;
    if (m == 1) {
        s->flags = s->flags & ~0x40;
        s->cb(s);
        if (s->cb != 0) m = s->mode; else m = 0;
        g = s->flags & 0x40;
    } else {
        g = 0;
    }
    if ((s->flags & 0x100) == 0 && g == 0) {
        p = s->cur;
        NNS_G3dGeSendDL((const u32 *)(p + (p[1] | (p[2] << 8) | (p[3] << 16) | (p[4] << 24))),
                      p[5] | (p[6] << 8) | (p[7] << 16) | (p[8] << 24));
    }
    if (m == 3) {
        s->flags = s->flags & ~0x40;
        s->cb(s);
    }
    s->cur = s->cur + 9;
}
