# An enum-typed zero keeps its own web where a u32 zero is folded

summary: when the image materialises `movs rN, #0` early, among loads, and keeps it in a register that the C's other values contend for, every integer spelling of the zero (named local, `x - x`, `x & 0`, `static const`, forwarding from a cleared field) is folded before allocation. A zero held in an enum-typed local (`typedef enum { Z0 } E; E z; z = Z0;`) is not folded and gets its own web.

Found in: src/matched/func_0202627C.c (0x0202627C)

The finish arm of the game_comm request machine clears four fields and a flag
bit, then calls a saved callback:

```
ldrb r3, [r4, #4]      <- flag byte
movs r2, #0            <- the zero, early, in r2
ldr  r5, [r4, #0x20]   <- the callback, in r5
ldr  r0, [r4, #0x1c]
lsls r1, r3, #0x1e
str  r2, [r4, #0x18]
strb r2, [r4, #5]
str  r2, [r4, #0x20]
str  r2, [r4, #0x1c]
movs r2, #2            <- the bics mask reuses the zero's register
...
blx  r5
```

Measured under dsi/1.1p1 -O4,p. Four waves wrote the zero as a named `u32`
local, `a - a`, `a & 0`, `(u32)(p != p)`, `&= 0` and forwarding from the first
cleared field. All of them came out byte-identical to a plain `0` (10 bytes
out: the callback in r2 and the zero in r5). An `extern const` or a real
compare changes the instruction. The finding in the notes was that a zero
cannot be given its own web by how it is spelled.

An enum can do it. With `-enum int` an enum-typed value is kept out of early
folding (see an-enum-type-keeps-values-out-of-constant-folding.md), so

```c
typedef enum { Z0 } E;
...
E z;
z = Z0;            /* assigned FIRST, before the reads */
cb = p->f20;
a = p->f1c;
b = p->b1;
p->f18 = z;
p->kind = z;
p->f20 = 0;
p->f1c = z;
p->b1 = 0;
if (cb != 0)
    cb(a, b);
```

is EXACT. Two things carry the weight. First, the zero is the enum and is
assigned before the reads. In the flag-word form of the arm, with reads w,
cb, a, b, z first is 7 and z at any later position is 10. Second, the read
order. With a u32 zero, all 24 read orders sweep to 10 at best. With the
enum zero first, cb, a, b is 0, a, cb, b is 4, and a, b, cb is 10.

It is not a general cure for zero ties. On wipe_sub 0x0202350C the same
enum zero moves the residue from 4 to 2 bytes, but it does not close it
(docs/notes/func_0202350C.c.txt). Where the enum zero is assigned also matters
there. Assigned between the kb and k8 reads, it is materialised in place.
Assigned before both reads, it is materialised late, just before its store.
