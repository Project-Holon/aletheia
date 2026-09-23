# An ARM `ldr r1, [pc]; bx r1` stub to an even address is a hand-written SDK asm function

summary: a compiled ARM tail call through a pool word spends ip, and a linker
island would not be emitted for an ARM target in `b` range; an eight-byte
`ldr r1, =f; bx r1` is an `asm void` body and matches written that way.

Found in: src/matched/func_02084D98.c (0x02084D98)

The image at 0x02084D98 is `ldr r1, [pc]; bx r1; .word 0x02084D78`. The pool
word is even, so the target is ARM code 0x20 bytes back, well inside the
range of a plain `b`: no linker emits a veneer for that. The obvious C,
`void f(int a) { g(a); }`, compiles under dsi/1.1p1 to `ldr ip, [pc]; bx ip`
(2 bytes out: the register nibbles). Calling through a cast constant is not a
tail call at all (push, blx, pop). Written as

```c
asm void func_02084D98(int a)
{
    ldr r1, =func_02084D78
    bx r1
}
```

it is EXACT with the pool word resolved. Earlier notes filed this shape as
"not code, a linker veneer"; check the target parity and distance before
accepting that: an odd word or an out-of-range target is a veneer, an even
in-range one with r1 is SDK assembly.
