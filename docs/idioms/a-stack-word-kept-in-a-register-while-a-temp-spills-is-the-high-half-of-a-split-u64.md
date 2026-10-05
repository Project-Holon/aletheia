# A stack word kept in a register while a temp spills is the high half of a split u64

summary: the original loads the first stack argument word into a callee-saved
register at entry (`ldr r7, [sp, #0x30]`) and spills a value derived from it;
a `u32` fifth parameter compiles the other way (mwcc treats the parameter's
incoming slot as its spill home, so spilling it is free, and it keeps the temp
in the register instead). Declaring the fourth and fifth parameters as one
`unsigned long long` (old ATPCS splits it between r3 and the first stack
word, no alignment) makes the stack word a fresh value
(`d = (u32)(x >> 32)`), and the allocation matches.

Found in: `src/matched/ov/ov218_func_021B9AE4.c` (0x021B9AE4).

Signs:
- the caller stores two separate words (r3 and `[sp]`) for the two arguments;
- a `u8` fifth parameter gives the right allocation but the wrong load
  (`ldrb`), so the value is word-sized and not a parameter in its home slot;
- int, u32, const, a one-field struct by value, a local copy and a static
  inline parameter copy all leave the stack word reloaded from its home.

Source shape:

```
void f(u8 *p, u8 *a, u32 b, unsigned long long cd)
{
    u32 c = (u32)cd; u32 d = (u32)(cd >> 32);
    ...
}
```

A two-field struct by value `{u32 c; u32 d;}` does not work: mwcc spills
r0-r3 to a home area (`push {r0-r3}`) for it.
