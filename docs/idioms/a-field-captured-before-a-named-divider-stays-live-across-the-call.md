# A field captured before a named divider stays live across the call

summary: when a signed interpolation keeps its start value in a saved register across the division helper, copy the field into the result local before calling the named helper; an inline field expression reloads it after an ordinary extern call.

Found in: src/matched/ov/ov186_func_021FB0E8.c (0x021FB0E8), src/matched/ov/ov186_func_021FB1EC.c (0x021FB1EC)

Both transitions load the signed halfword at object+0x20 into r5, form
`(to - start) * tick` in r0, call the signed divider, then add the quotient
to r5. The original keeps the start value live across the call.

For a direct `_s32_div_f` extern, this spelling reloads the start field after
the call because an ordinary extern may change the pointed object:

```c
value = p->from + _s32_div_f((p->to - p->from) * p->tick, p->duration);
```

Capture the start in the signed halfword result local first:

```c
value = p->from;
value = value + _s32_div_f((p->to - value) * p->tick, p->duration);
```

The captured value takes r5, remains there across the helper, and the final
halfword conversion still happens after adding the quotient. In B0E8 the
first spelling, together with reversed x/y stack-local order, gave a 262-byte
DIFF with 111 concrete bytes wrong; capturing the start and restoring the
two local slots gave EXACT at 260 bytes. The same spelling produced B1EC's
258-byte EXACT* result with two trailing alignment bytes. The adjacent
scratch TU also verified EXACT at 518 bytes.

Use a named runtime helper when preserving its behavior on a potentially
zero denominator; do not replace that call with C division merely to obtain
the compiler's pure-operation alias assumptions.
