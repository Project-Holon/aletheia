# A sentinel test and a null test on the same word are two members of a union

summary: when a loop tests one word twice with no store or call between the
two tests and the original keeps both loads, the two tests are not the same
access path; spelling the word as a union whose members are read by different
types is what stops mwccarm forwarding the first load into the second, and no
loop shape does it.

Found in: `src/matched/func_0201F8F4.c` (0x0201F8F4)

## The tell

A table walk terminated by a sentinel that also stops early on a null entry:

```
0201F8FA  ldr r0, [r5]      <- guard: is this the terminator?
0201F8FE  cmp r0, r6        (r6 = 0xFFFFFFFF, movs/mvns)
0201F900  beq end
0201F902  movs r4, #0
0201F904  ldr r0, [r5]      <- body: is this slot empty?     LOOP HEAD
0201F906  cmp r0, #0
0201F908  beq end
0201F90A  blx func_02045808
0201F90E  str r4, [r5]
0201F910  adds r5, #8
0201F912  ldr r0, [r5]      <- rotated bottom test
0201F914  cmp r0, r6
0201F916  bne 0x201F904
```

Three loads of `[r5]` with nothing between the first two but a `movs`, and the
bottom one feeding straight back into a block that loads the same address
again. Any of them looks redundant, and mwccarm agrees: written with one
`u32` member it emits only two loads and reuses the guard's value for the
body test, 36 bytes instead of 38.

## What does not work

None of these changes anything; all three compile to the identical 36 bytes:

```c
while (s->handle != 0xFFFFFFFF) { if (s->handle == 0) break; ... s++; }
for (; s->handle != 0xFFFFFFFF; s++)  { if (s->handle == 0) return; ... }
if (s->handle == 0xFFFFFFFF) return;
do { if (s->handle == 0) return; ... s++; } while (s->handle != 0xFFFFFFFF);
```

Loop rotation is not the variable. `volatile` is not the answer either: it
would also force a fresh load for the call argument, which the original does
not have, and it would be a claim about hardware that is not true here.

## What works

Give the word two types:

```c
struct Slot {
    union {
        u32   raw;
        void *ptr;
    } u;
    u32 tag;
};

if (s->u.raw == 0xFFFFFFFF)
    return;
do {
    if (s->u.ptr == 0)
        return;
    func_02045808(s->u.ptr);
    s->u.raw = 0;
    s++;
} while (s->u.raw != 0xFFFFFFFF);
```

mwccarm's redundant-load elimination keys on the access path including the
member, so `s->u.raw` and `s->u.ptr` are two different loads of one address
and both survive. That is the whole 2-byte-to-EXACT step, and it recovers a
real fact about the original: the slot is a tagged word whose sentinel value
is compared as an integer and whose live value is used as a pointer.

## The second half of the rule

Once the union is in, the null test must be on the *same member the call
consumes*. Testing `s->u.ptr` and then calling `func_02045808(s->u.raw)`
leaves the test in r1 and passes the stale guard load in r0:

```
* +0010  ldr r0, [r5]   | ldr r1, [r5]
* +0012  cmp r0, #0     | cmp r1, #0
```

Declaring the callee to take the pointer and passing `s->u.ptr` closes it.
The register the tested value lands in is therefore evidence for which member
the call argument is, the same way
`docs/idioms/cmp-operand-order-names-the-temporary.md` reads a register out of
a compare.
