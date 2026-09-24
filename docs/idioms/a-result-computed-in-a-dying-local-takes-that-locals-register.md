# A result computed in a dying local takes that local's register

summary: when two fresh temporaries come out in each other's registers and
no declaration order, type (int, u32, long) or statement order flips them,
compute one of them IN a local that dies at that point (a loop-carried value
about to be reassigned). The value then lives in that local's register, and
values coalesced with it follow it.

Found in: src/matched/func_020681E4.c (0x020681E4)

NitroSystem g2d_CharCanvas.c GetCharIndex1D, ../2.0/sp2 -O4,p, ARM. Each
round ends by computing two saturated logs, log_w then log_h, each with an
in-place clz (`movge rX, #3; movlt rX, w; clzlt rX, rX; rsblt rX, rX, #31`).
It then reads the new shift pair from g_020A18F4[log_h][log_w] into the
loop-carried shift locals sw and sh. The image has log_w in r6 (sh's
register) and log_h in r7 (sw's register). The row pointer
`table + log_h * 8` coalesces into r7, which then takes the new sw.

With two fresh block locals lw and lh (`if (w >= 8) lw = 3; else { lw = w;
asm { clz lw, lw } lw = 31 - lw; }`, and the same for lh), the instruction
stream is exact, but lw and lh swap registers (18 bytes out). Results that
did not move it: int, u32 and long logs in all nine combinations; all 1440
declaration orders with long logs; the logs at function scope in all 84
positions; self-assignments (wave 19 ties_c).

Computing log_w in `sh` itself closes it. sh is dead from that point until
`sh = (s.h = p[1])`:

    int lh;
    const u8 *p;
    if (w >= 8) sh = 3; else { sh = w; asm { clz sh, sh } sh = 31 - sh; }
    if (h >= 8) lh = 3; else { lh = h; asm { clz lh, lh } lh = 31 - lh; }
    p = g_020A18F4[lh][sh];

Every placement with log_w in sh matches, whether log_h is in a fresh lh,
in sw, in tmp or in tmp1. log_w in tmp or tmp1 with log_h in sw gives 15, and
log_h in sw with a fresh lw also gives 15. So only the local whose register
the value must occupy matters. The other log can be fresh.
