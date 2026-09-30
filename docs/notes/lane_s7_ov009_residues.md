# Lane S7 residues: ov009 libcps `dhcp_analyze_response` and libssl `CPSi_rc4_init`

Both rows are parked with a named residue. Neither was closed inside the lane
budget; both headers now carry the measurements below.

## 0x0215BF88 `func_0215BF88` = `dhcp_analyze_response` (libcps network.o)

880-byte row, extent now **exact** (was -4). Parked at **65 bytes out** (was
240 out / -4 on the extent).

Fixed this lane: the DHCP option 0x35 arm is a **switch on `s[1]` with case 2
and case 5**, not `if / else if`. With the if/else-if spelling the compiler
predicates the `== 2` arm inline and branches over it, so the image's
out-of-line arm block is missing and the whole function is one instruction
short — every branch-to-tail and pool offset shifts by 4, which is the 240
"differing" bytes. The switch spelling restores the image's layout:
`cmp r5,#2; beq ARM2; cmp r5,#5; moveq...; streq...; b END; ARM2: mov r4,sl;
str r2,[lr,#0x38]; b END`, and the extent becomes 880.

Remaining residue (65 bytes), first differing instruction:

```
  * +0108    addeq r3, r5, #0xf0     | cmpeq r0, #0x63
```

It is one tie and its scheduling shadow: the image keeps the option pointer
(`s += 0xf0`) in **r3** and the `g_021A826C.dhcp_mode & 2` mask in **ip**, and
having the pointer in a scratch register it can predicate the address add into
the `&&` chain (`addeq ...` before the last `cmpeq r0, #0x63`); this compile
swaps the two (pointer in ip, mask in r3) and therefore emits an unconditional
`add ip, r5, #0xf0` after the `bne`. Every other differing byte is one of the
two register names inside the option loop.

What is *not* the trigger (measured): the `mode` local must stay a named local
— writing `g_021A826C.dhcp_mode & 2` inline in case 6 collapses the whole
allocation (868 bytes, 678 out). Inert: `mode` at function scope, `mode` as a
declaration initialiser, `mode` before vs after `s += 0xf0`, `s = s + 0xf0`,
`int` vs `u32` mode, a named `opt` pointer local (888 bytes), case order
swapped, else-if nesting, store-before-result.

## 0x02163E40 `CPSi_rc4_init` (libssl arc4.o)

120-byte row, size exact, **21 bytes out**, first differing instruction:

```
  * +0010    add r4, r0, #2          | add lr, r0, #2
```

Pure mirrored pair swap over four registers: image `m` = r4, `m_i` = lr,
k-zero temp = r0, accumulation chain = r3; this compile `m` = lr, `m_i` = r4,
k-zero temp = r3, chain = r0. Instruction stream, order and operands are
otherwise identical. Twelve spellings tried in this lane (declaration order
both ways, `m` last, declaration initialiser, `&ctx->m[0]`, no `m` local at all
= 93 out, chained `ctx->x = ctx->y = 0` = 23 out, `j +=`, `k++`, separate
`j`/`k` assignment, `unsigned int i` = 34 out, `m = m;` and `m_i = m_i;`
self-assignments at the loop head and after the load): no move from 21.
