/*
 * function: func_021C2050
 * address:  0x021C2050
 * packet:   pkt_ov172_021C2050
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  measures DIFF (96/96, 11 concrete bytes), not MATCH.  Wave8
 *           improved 35 -> 11 with two levers: (1) reverse the third colour
 *           expression's OR operands to `(yuyv >> 24) | ((yuyv & 0xff000000)
 *           >> 16)` (35 -> 15; this is what makes the image's `lsr r5,#0x10`
 *           and `orr r1,r5,r1,lsr #24` fall out), and (2) declare `x` last
 *           among the scalars (y before x: `yuyv,y,x` order, 15 -> 11; the
 *           DWARF forward order is yuyv,y,x,pYuyv,ybuf,crbuf).  The whole
 *           body arithmetic now matches opcode for opcode; the remaining 11
 *           bytes are a single 3-cycle of {x, anonymous `ybuf + y` base,
 *           crbuf}: image colours x=r2, base=r4, crbuf=lr, ours x=lr, base=r2,
 *           crbuf=r4 (so +000C `add r4,r3,ip,lsl#1` vs `add r2,...`, +000C
 *           middle store `strh r6,[r4,r7]` vs `strh r6,[r7,r2]`, +0050 crbuf
 *           store, +0054 `cmp r2,ip` vs `cmp lr,ip`).  `y` is already ip in
 *           both.  Tried this lane, all inert at 11: all 6 scalar declaration
 *           permutations (x last required; x first = 15), pointer declaration
 *           position/permutation, `x`/`y`/`yuyv` as `unsigned int`, in-loop and
 *           preheader no-code self-assignments (`x=x;`,`y=y;`,`crbuf=crbuf;`,
 *           `ybuf=ybuf;`), the null-pointer counter-increment idiom
 *           (`x=(unsigned long)((char*)0+x+1)`, `(int)`, `(unsigned char*)`),
 *           `crbuf = ybuf + (y+y)` (68), `crbuf = ybuf + y*2` (28), named
 *           middle base, `*(ybuf+y+x)`, `ybuf[x+y]`.  The cycle is an
 *           allocator tie on the anonymous loop-invariant base, reached only
 *           from the six DWARF locals; see
 *           docs/idioms/declaration-order-decides-which-register-a-local-gets.md.
 *
 * opus (2026-10-01): also inert at 11: `&ybuf[y] + y`, `crbuf = ybuf + y; crbuf += y;`,
 *           x/y and init-statement reorders; `&ybuf[y + y]` 100 B; crbuf as the
 *           middle plane with `crbuf[y + x]` for the third is worse.
 * w9_nm / prior waves: 35 B residue (whole-body rotation), see history below.
 *           The first divergence was +000C `add r4,r3,ip,lsl#1` (image) vs
 *           `add r1,...` (ours); the third-expression operand reversal was the
 *           unlocking lever.
 *
 * sdk:      SSP_YUV422ToYUV888 (jpegenc.o)
 *
 * symbols:
 *   (none)
 */

void func_021C2050(void *src, unsigned long width, unsigned long height, void *dst)
{
    unsigned long yuyv;
    unsigned long y;
    unsigned long x;
    unsigned long *pYuyv;
    unsigned short *ybuf;
    unsigned short *crbuf;

    pYuyv = (unsigned long *)src;
    ybuf = (unsigned short *)dst;
    y = (width * height) >> 1;
    crbuf = ybuf + y + y;
    for (x = 0; x < y; x++) {
        yuyv = *pYuyv++;
        ybuf[x] = (yuyv & 0xff) | ((yuyv & 0xff0000) >> 8);
        ybuf[y + x] = (yuyv & 0xff00) | ((yuyv & 0xff00) >> 8);
        crbuf[x] = (yuyv >> 24) | ((yuyv & 0xff000000) >> 16);
    }
}
