# A bitmask complement built from `eors` against -1 instead of `mvns` says the mask is 64 bit

summary: mwccarm compiles `~x` on a 32 bit value to `mvns`, so a live
`movs rN, #3` / `subs rN, rN, #4` / `eors` triple is the low half of a **64
bit** NOT whose high half was dead-code eliminated; the mask is a `long long`
even where the field it is applied to is a `u32`, and spelling it `~mask`
instead of `mask ^ -1` costs the whole function.

Found in: `src/matched/sub_02019388.c` (0x020196F6, 0x020197C6, 0x020198F0)

`func_02019388` sets and clears flag bits in three different fields: a `u32` at
substruct A +0x1C, a `u32` at substruct B +0x14, and a `u64` at substruct C
+0x18. All three arms have the same shape,

```c
mask = 1 << n;
if (v != 0) {
    field |= mask;
} else {
    field &= complement;
}
```

and the only thing that is not obvious is `complement`. The two 32 bit arms
compile to

```
movs r1, #3
subs r1, r1, #4        /* r1 = -1 */
ldr  r2, [r6, #0x1c]
eors r0, r1            /* ~mask, one word of it */
ands r0, r2
```

while the 64 bit arm materialises **two** minus ones and does two `eors`.
mwccarm has `mvns` and uses it for a 32 bit `~x`, so the `eors` form is not a
32 bit complement at all: it is the generic 64 bit NOT, `lo ^ -1` and
`hi ^ -1`, with the high half dropped afterwards because the destination is
only 32 bits wide.

That fixes `mask` as one function-scope `long long` shared by all three arms.
The shift stays a plain `movs r0, #1` / `lsls r0, r1` in the 32 bit arms,
because only the low half of `(long long)(1 << n)` is ever read there, so the
64 bit type leaves no other trace and is easy to miss.

Three wrong spellings, all of them plausible:

* `~mask` with `mask` a `u64`: mwccarm folds the complement of the low half to
  `mvns` and the function is 904 concrete bytes wrong at the right size minus
  twelve.
* `mask ^ 0xFFFFFFFF`: the constant fits one word, so the 64 bit arm loses its
  second `eors` and 346 bytes are wrong.
* one `u32` mask per arm: the shift then sinks into both sides of the `if`
  instead of being computed once in front of it, each arm grows four bytes, and
  the extra register pressure moves the record pointer out of `r7`, so the four
  substruct calls at the top of the function reload it from the frame and
  another eighteen bytes change. A codegen difference three hundred bytes away
  from the code that caused it is the expensive part of this one.
