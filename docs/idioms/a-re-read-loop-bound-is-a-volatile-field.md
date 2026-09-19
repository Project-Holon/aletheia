# A loop bound that is re-read on every iteration means the field is volatile

summary: when the original re-loads a length field through the same pointer on
every pass of a loop (`ldrb r1, [r0, #4]` sitting between the payload test and
the loop's compare) while a plain field lets mwcc hoist the load out of the
loop and come out one instruction short, declare the field `volatile`; the
volatile qualifier is what forces the per-iteration re-read, and the field's
width and signedness are unchanged.

Found in: `src/matched/func_02096D10.c` (0x02096D10) and
`src/matched/func_02096DF0.c` (0x02096DF0), `pkt_02096990`

Both functions walk the same length-prefixed string object: byte +5 is the
terminator flag, +2 an s16 key, +4 the byte length, +5.. the payload. The tail
loop of each walks the payload of the object that was *not* exhausted by the
prefix compare, and the original tests its bound by re-reading the object:

```
02096DC0  ldrb r1, [r0, #4]     ; bound, re-read every iteration
02096DC4  add  ip, ip, #1
02096DC8  cmp  ip, r1
02096DCC  blt  0x02096DB8
```

with a plain `u8 f04` member mwcc hoists that load (it proves no store in the
loop can alias it) and the function comes out 220 bytes against the original's
224, everything else identical. `volatile u8 f04` reproduces the original bytes
exactly. The other two members do not need it: the prefix loop uses `int`
copies of the two lengths, so nothing is re-read there.

The tell is the pair of loads, one before the loop and one on the back edge,
of the same byte from the same base register. If only the entry test re-reads,
that is the `&&`-guarded `do`/`while` shape in func_02096DF0, not a volatile
effect; if the back edge re-reads, reach for the qualifier.

A `volatile` on the object rather than the member works too
(`volatile Str *p` reproduced the same bytes) but drags every other read of
that object along with it, so prefer the single member.
