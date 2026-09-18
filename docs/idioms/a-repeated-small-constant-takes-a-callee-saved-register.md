# A repeated small constant takes a callee-saved register, and everything below it moves up one

summary: under `-O4,p` this front end materialises a small literal that is used
more than once into the lowest callee-saved register at the top of the
prologue and copies it into every argument register, where the original
rematerialises the immediate at each use; the pooled register then steals the
first callee-saved slot and pushes every local, every pointer and the whole
`push {...}` list one register higher, so a single shared `0` can move twenty
instructions.

Found in: nothing filed - this is the wall; measured on
`src/pending/func_02072894.c` (the opposite case, which does not pool),
and on the near misses in `docs/notes/pkt_02073AB4.c.txt`,
`docs/notes/pkt_02073F3C.c.txt`, `docs/notes/pkt_020746E8.c.txt`,
`docs/notes/pkt_020733E8.c.txt`, `docs/notes/pkt_02072A44.c.txt` and
`docs/notes/pkt_02073598.c.txt`.

Minimal repro, compiled with the project's pinned line
(`--cc 1.1p1 -proc arm946e -O4,p`):

```c
void h2(u32, u32);
void b1(u32 *p) { h2(p[0], 0); h2(p[1], 0); h2(p[2], 0); }
```

```
push {r3, r4, r5, lr}      /* two callee-saved, not one */
mov  r5, r0
mov  r4, #0                /* the zero, pooled once       */
ldr  r0, [r5]
mov  r1, r4                /* and copied at every site    */
bl   h2
ldr  r0, [r5, #4]
mov  r1, r4
bl   h2
...
```

The original's shape, which no spelling reaches, is `mov r1, #0` at each call
and `push {r3, lr}`.

The tell is not the pooled register itself - it is that the *address* of a
local quietly moves: in func_020734AC (`arm9`, pack `pkt_020733E8`) the
object pointer goes from r5 to r6 and the second parameter from r6 to r7, and
`push {r4,r5,r6,lr}` becomes `push {r3,r4,r5,r6,r7,lr}`. If a function is
byte-correct except that every callee-saved register is one higher than the
image and the `push` list is two registers longer, look for a repeated `0` or
`1` before you touch anything else.

Spellings that were measured and all still pool:

* `0`, `0u`, `(u32)0`, `(void *)0`, `NULL`, `(u8)0`, `sizeof(...)`-derived 0;
* a `void *` parameter with a null pointer constant - the pointer/int
  distinction does not separate the constants;
* binding the constant to a named local (`u32 z = 0;`) or a `const` local;
* for the literal `1`: `1`, `1u`, a local `u32 one = 1`, a `#define`, and
  reading the constant out of a struct field;
* reordering the statements so the constant's uses are no longer adjacent.

This is the mirror image of
`a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md`,
which is the case where the original *does* want the shared register. There
the pooling is evidence for a variable; here it is a front-end difference and
the function is not reachable from C under `-O4,p`.
