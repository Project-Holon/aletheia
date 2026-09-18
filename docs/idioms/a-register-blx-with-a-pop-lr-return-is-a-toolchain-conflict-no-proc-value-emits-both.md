# A register blx with a pop-lr return is a toolchain conflict: no -proc value emits both

summary: a function that contains register `blx rN` (ARMv5T) *and* the ARMv4T epilogue
`pop {..., lr}; bx lr` cannot be reproduced by mwccarm 1.1p1 under any `-proc` value it accepts. Every
v5+ value emits `blx rN` but returns through `pop {..., pc}`; every ARMv4T value returns through
`pop {..., lr}; bx lr` but reaches an indirect call with `mov lr, pc; bx rN`, which is two instructions
where the original has one. The pop-lr epilogue is therefore necessary but not sufficient as an
ARMv4T tell, so read
`an-arm-epilogue-of-pop-lr-then-bx-names-a-proc-arm7tdmi-unit.md` together with this one.

Found in: `0x02053E1C` (packet `pkt_02053218`), `0x0205429C` and `0x02054718` (packet `pkt_0205429C`),
all DIFF under both `-proc arm946e` and `-proc arm7tdmi`, with the full C recovered in
`docs/notes/pkt_02053218.c.txt` and `docs/notes/pkt_0205429C.c.txt`

The measured proof, 32 `-proc` values and nine `-si`/`dsi` builds:

| family | indirect call | non-leaf return |
| --- | --- | --- |
| v5+ (`v5t`, `v5te`, `v6*`, `v7`, `arm9ej`, `arm926ej`, `arm946e`, `arm966e`, `arm1020e`, `arm1022e`, `arm1026ej`, `XScale`, `pxa25x/26x`) | `blx rN` | `pop {..., pc}` |
| ARMv4T (`v4`, `v4t`, `arm7tdmi`, `arm710t/720t/740t`, `arm9tdmi`, `arm920t/922t/940t`, `dbmx1`, `dbmxl`) | `mov lr, pc; bx rN` | `pop {..., lr}; bx lr` |

No value is in both lists, all nine compiler builds 1.1 through 1.6sp2 give the same epilogue for the
same probe, and neither `#pragma peephole off` nor toggling `-interworking` closes it. On the three
functions above, `-proc arm946e` (the pinned default) gives 1128 compiled against 1116 original with
763 concrete bytes differing; `-proc arm7tdmi` gives 1144 against 1116 with 696 differing, which buys
the epilogue and loses both `blx`. The original unit was therefore built by a compiler this tree does
not have.

Detection is cheap, byte-level, and validated against those three functions:

```python
blx_rN  = word & 0x0FFFFFF0 == 0x012FFF30 and (word & 0xF) != 15
pop_lr  = (word >> 16) & 0xF == 13 and (word >> 20) & 1 and (word >> 23) & 3 == 1 \
          and word & 0x0C000 == 0x4000          # lr set, pc clear
bx_lr   = word & 0x0FFFFFF0 == 0x012FFF10 and (word & 0xF) == 14
```

A function with all three present is in the conflict class. Applied over the whole open pool it flags
14 functions and 9572 bytes, 2.39 coverage points, all in the 0x02052xxx to 0x02054xxx region
(`0x020525A0`, `0x020528D0`, `0x02052984`, `0x02052A50`, `0x02052DC8`, `0x02052F58`, `0x02052F90`,
`0x02053218`, `0x02053E1C`, `0x0205429C`, `0x02054718`, `0x02054A68`, and two more), and every sibling
in that region that *does* match was matched under `-proc arm7tdmi` and contains no register `blx`.

Consequence for planning: do not dispatch a lane at those functions. Their bytes are unreachable for
coverage unless the region is reclassified as library code the way `layout/runtime_arm9.txt` does for
`runtime.a`, or a second toolchain is admitted into the project. Screen the pool for the pattern first,
because the epilogue alone looks exactly like the region that *does* match.
