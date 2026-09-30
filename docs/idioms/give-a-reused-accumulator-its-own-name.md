# Give a reused accumulator its own name so the coalescer can merge it

summary: Writing `x = x + a + b` and then using `x` again colours the callee-saved
registers differently from giving the second value a local of its own; the
separate name lets the register coalescer put the two back in one register, and
every other live value then lands where the original has it.

Found in: src/matched/ov_sdk/ov009_func_02160E1C.c (0x02160E1C)

The original is `client_hello_v2` from `libssl.TWL.HYB.a(ssl.o)`, 192 bytes of
code, and the DWARF of the defining object names four locals and two parameters:

```
  param  struct _CPSSslConnection *  con         r7
  param  unsigned char *             s           r6
  variable unsigned short            method      r0
  variable int                       random_len  r5
  variable int                       sessionID_len r0
  variable int                       pairlist_len  r4
```

So the four values that need a saved register are `pairlist_len` in r4,
`random_len` in r5, `s` in r6 and `con` in r7: the two locals take the bottom
of the range and the two parameters sit above them. The neighbouring
`rcv_server_hello` (0x02160C9C, also EXACT) has one local and two parameters and
colours them r4/r5/r6 the same way, which is what makes the shape legible: the
allocator fills r4 upward, locals first.

The obvious C accumulates the offset back into the variable that held the
pairlist length:

```c
pairlist_len = (s[2] << 8) + s[3];
...
pairlist_len = pairlist_len + 8 + sessionID_len;
if (random_len >= 0x20)
    func_02082D44(s + pairlist_len, con->random, 0x20);
```

That compiles to the right instruction sequence at the right offsets and then
miscolours 26 bytes: `pairlist_len`/r4, `s`/r5, `con`/r6, `random_len`/r7. One
long-lived local ends up *above* the parameters instead of below them, and a
second-order effect follows: the `s[4]` temporary, which the original keeps in
r5 and then reuses for `random_len` (its live range starts two instructions
later, at the `add r5, r0, r2, lsl #8`), is pushed out to `ip`. Both the wrong
homes and the `ip` are the same fault.

Writing the second value as its own local fixes all of it:

```c
offset = pairlist_len + 8 + sessionID_len;
if (random_len >= 0x20)
    func_02082D44(s + offset, con->random, 0x20);
```

Now the allocator has two names whose live ranges abut rather than one name with
a hole in it, the coalescer merges them back into a single register, and
`random_len` takes the r5 slot the original has it in, which in turn leaves r5
free early enough for the `s[4]` temporary. Every byte matches.

Two things this is *not*, both of which cost iterations here:

* **Declaration order is inert.** All 24 permutations of the four local
  declarations compile to the same 26-byte DIFF, so the order the vendor wrote
  the declarations in cannot be recovered by permuting them and cannot be the
  lever. Same for the DWARF listing order, which is not the declaration order
  anyway.
* **`const` is not the lever here either.** Marking the two length locals
  `const` moves 122 bytes, because it drops the `lsl`/`lsrs` pair that truncates
  `method` and reshuffles the block. `const` earns its keep in
  `ov009_func_0215D2A8.c`, where it lets a load hoist above an outgoing-argument
  store; here it destroys more than it fixes.

The general form of the rule: when a name in the DWARF is live across a region
where the original's register numbering implies a *different* name took over,
prefer giving the second role its own local over reusing the first, and let the
coalescer do the merging. The instruction stream is unchanged either way, so the
diff is register fields only and `sdkobj`'s DWARF register column is the only
place the answer is written down.
