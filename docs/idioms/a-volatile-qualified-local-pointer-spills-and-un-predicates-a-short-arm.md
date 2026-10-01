# A `volatile`-qualified local pointer spills, and its reload un-predicates a short guard arm

summary: `volatile` on a pointer-typed *struct member* is ignored for both the
pointee and if-conversion, but putting `volatile` on a local pointer variable
(`struct P * volatile p = ...`) forces that variable into a stack slot, so every
use reloads it; when one reload lands inside an `if` arm, the arm crosses the
five-instruction predication budget and the compiler emits the original's real
`cmp` / `b<cond>` / body / `b` join instead of `ldr<cond>`/`add<cond>`/`str<cond>`.

Found in: `src/pending/ov_sdk/ov009_func_0215D92C.c` (0x0215D92C,
`SOCLi_CopyCPSBuffer`), measured against `dsi/1.1p1 -O4,p --arm --lang c99`.

The residue on that function is a three-instruction RMW guard that is always
predicated at this front end:

```c
struct SOCLRecvPipe *recv_pipe = socket->recv_pipe;      /* 260 bytes, 101 differ */
if (recv_pipe->flag_noconsume == 0)
    recv_pipe->consumed += result;                        /* ldreq / addeq / streq / b */
```

Qualifying the *local* pointer instead of the pointee makes the guard a branch,
because the volatile pointer is homed on the stack and the arm now reads it back
before the RMW:

```c
struct SOCLRecvPipe * volatile recv_pipe = socket->recv_pipe;   /* 292 bytes */
```

```asm
+0084  ldr  r0, [sb, #0xa0]     ; socket->recv_pipe
+0088  str  r0, [sp, #0xc]      ; homed: the local is volatile
+008C  ldr  r0, [sp, #0xc]
+0090  ldrsb r0, [r0, #0xfe]    ; flag read reloads the pointer
+0094  cmp  r0, #0
+0098  bne  +0x...              ; <-- real branch, image's shape
+009C  ldr  r0, [sp, #0xc]      ; RMW reloads it again: arm is now >5 instructions
+      ...
```

So this is a *diagnostic* lever, not a closing one: it proves the +0x90 branch
is reachable from C at 1.1p1, and it proves the mechanism is the predication
budget, but it costs two reload instructions the image does not have. The image's
arm is exactly `ldr`/`add`/`str`, so no source shape that reaches the branch can
also reproduce those three instructions. The two are mutually exclusive at this
front end.

Two adjacent idioms bracket this and should be read with it:
`volatile-on-a-pointer-typed-member-is-ignored.md` (a pointer *member* is dropped
and does not touch if-conversion) and
`a-volatile-field-load-is-a-shape-lever-it-cannot-be-cse-d-or-merged-into-ldm.md`
(a volatile *field* access changes instruction count, not selection). The lever
here is the volatile *local pointer* and its spill, which is a third, distinct
case.

The generalisation: when a codegen residue is "the arm is three instructions and
the image branches it", check whether any access in the arm is through a
volatile-qualified local; if so it will spill and un-predicate, and you can
measure the threshold from both sides without pretending the extra reload is a
source spelling of the original.
