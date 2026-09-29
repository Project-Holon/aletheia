# A call in a switch arm that sets up no arguments takes the already-loaded locals where they sit

summary: when locals loaded before a switch sit in r1/r2 (or the switch index sits in r1/r2/r3) and one arm calls with no argument moves at all, that call's parameters are those locals and the incoming r0; a callee declared without them keeps the locals in r0/r1 and misses.

Found in: `src/matched/ov/ov020_func_02184C78.c` (0x02184C78),
`src/matched/ov/ov020_func_02184A14.c` (0x02184A14)

Two symptoms, one cause. In 0x02184C78 the original loads `a = p[0]`, `b = p[2]`
into r1, r2 and the switch index into r3, then case 0 does `adds r0,r1; adds r1,r2`
before `bl` (two extra moves), while a C version with `a`, `b` passed as
`f(a, b)` allocates them r0, r1 and the index r2. In 0x02184A14 the index lands in
r1 instead of r0.

The reason is a different arm that reaches its `bl` with no setup at all:

- 0x02184C78 case 3 is a bare `bl 0x021BF66C`. It is `func_021BF66C(ctx, a, b)`:
  r0 is still the incoming `ctx`, r1 and r2 are the two loaded locals. Declaring it
  `int f(void)` drops the arguments, frees r0 for `a`, and every register shifts.
- 0x02184A14 case 1 is `bl 0x021C6E48; cmp r0,#0` straight after the call to
  0x02188D38. r0 still holds that call's result, so it is `func_021C6E48(t)` with
  `int t = func_02188D38(z);`, and r0 being live is what pushes the switch index to r1.

Tell: an arm whose `bl` is preceded by nothing, in a function whose other arms build
their arguments. Read the registers at that point as the arguments and give the callee
the matching parameter list.
