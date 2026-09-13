# A call through a linker veneer is an ordinary extern declared at the veneer, not at the function

summary: when the pool word a tail call loads holds the address of a twelve
byte `ldr ip, [pc, #0]; bx ip; .word target` stub instead of the callee, the C
declares the extern at the stub's address and marks it `arm`; declaring the
real callee reproduces a different word and the unit comes out DIFF.

Found in: `src/matched/unit_02005794.c` (0x02005794, 0x020057A0)

A Thumb tail call to a function in another section is a literal pool word and
a `bx`, and the word is an `R_ARM_ABS32` the linker fills in. Usually it fills
it in with the callee's address. Sometimes it fills it in with the address of
a stub it generated:

```
02005794  4B 01     ldr r3, [pc, #4]
02005796  20 00     movs r0, #0
02005798  47 18     bx  r3
0200579A  46 C0     mov r8, r8            ; alignment before the pool
0200579C  88 27 07 02   .word 0x02072788  ; -> veneer_02072788

02072788  E59FC000  ldr ip, [pc, #0]
0207278C  E12FFF1C  bx  ip
02072790  0208970C  .word SND_SetMasterVolume
```

The obvious C, `extern void SND_SetMasterVolume(u32); ... SND_SetMasterVolume(0);`
with the symbol declared at 0x0208970C, compiles to the same four
instructions and the same relocation, and then the resolver writes 0x0208970C
into the pool word where the original has 0x02072788. Four bytes differ and
the unit is DIFF. Nothing in the source can fix that, because the difference
is not in the code the compiler emitted: it is in the value the linker chose,
and this project's harness does the linker's job from a declared address.

So the declaration names the veneer:

```c
/* The linker veneer in front of SND_SetMasterVolume; ARM. */
extern void veneer_02072788(u32 volume);
```

with

```
 * symbols:
 *   veneer_02072788  0x02072788  arm
```

Two details matter and both are load-bearing.

**The kind is `arm`, not `thumb`.** A veneer body is ARM code, so the ABS32
resolves to `(S + A) | T` with `T` zero and the pool word comes out even. Write
`thumb` and the word is 0x02072789, the `bx` would enter Thumb state at an ARM
address, and the byte comparison fails on the low byte.

**The name is how the address is attested.** 0x02072788 has no `func_` label,
because the stub has no register-saving prologue and `disasm.py`'s sweep never
fires on it, and nothing in the image branches to it, because the whole point
of a veneer is that callers reach it through a pool word. The only two words in
the 3.9 MB image that hold its address are the two inside this very file, so
the `literal` class discards both under the honesty rule. What carries it is
the `veneer` attestation class: the twelve bytes are a fixed encoding that
loads a constant into `ip` and branches to it, and the constant names
`SND_SetMasterVolume` in `layout/symbols_sdk.txt`. That is read entirely from
outside the compared range. See "The veneer class" in `docs/MATCHING.md`.

`tools/disasm.py` labels these `veneer_02072788` in the generated listings, so
a pool word pointing at one now reads

```
	.word	0x02072788                  /* 0200579C  -> veneer_02072788 */
```

and the name in the C is the name in the listing.

The counterpart to know about is the Thumb shape, `ldr r3, [pc, #0]; bx r3;
.word target`. The linker emits that too (0x021DFDB8 in ov228 is one), but so
does mwccarm, for a Thumb tail call with no argument set-up:
`src/matched/unit_02005C3C.c` is two committed instances of exactly those eight
bytes compiled from ordinary C. So the Thumb shape is not a linker signature,
it is not labelled, and it does not attest anything. Only the ARM forms do.
