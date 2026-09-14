# A parameter moved out of r0 at entry names the tail call's arity

summary: an opening `mov r1, r0` whose destination the body never reads is
argument setup for the call at the end of the function, so the callee takes a
second parameter; written as a one-argument call the function comes out four
bytes shorter with everything shifted by one instruction.

Found in: src/pending/sub_02030EAC.c (0x02030EAC)

`mov r1, r0` as the very first instruction of an ARM function, where
nothing in the body ever reads r1 and the body is then free to use r0 as
a scratch register, is not register-allocator noise. r1 is caller-saved,
so parking a value there buys nothing on its own; the only thing that
forces the copy is a call at the end of the function that wants that
value as its *second* argument while its first argument is computed into
r0 from the same pointer.

Seen at 0x02030EAC (list unlink, `src/pending/sub_02030EAC.c`):

```
02030EAC  mov r1, r0            <- the tell
02030EB0  ldr r2, [r1]
02030EB4  ldr ip, [pc, #0x28]
...       (body uses r0 freely as a scratch)
02030EDC  ldr r0, [r1]          <- first argument, recomputed from r1
02030EE0  bx ip                 <- r1 is still the incoming pointer
```

Written as the one-argument call the shape reads as:

```c
sub_02030C68(n->owner);
```

and mwcc keeps `n` in r0 throughout, emits no `mov`, and produces a
function exactly one instruction (four bytes) shorter with every concrete
byte shifted up by one slot. Every plausible rearrangement of the body
(binding the links to locals, casting the parameter through a `void *`,
re-reading the owner, hoisting the unlink into a static that gets
inlined, giving the function a return value) leaves that `mov` absent:
the body cannot produce it, because the body does not need it.

Adding the second argument is what produces it:

```c
extern void sub_02030C68(struct Owner *o, struct Node *n);
...
sub_02030C68(n->owner, n);
```

The general rule: when a function opens by copying a parameter into a
scratch register that the body never touches, look at the last call, not
at the body. The copy is the argument setup for that call, hoisted to
entry because the body is about to spend the register it came in.

This is the entry-side counterpart of
`a-loop-carried-value-in-a-callees-argument-register-names-the-arity.md`,
which reads the same evidence at a loop back-edge, and the inverse of
`a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md`:
there the extra registers are leftovers nobody set up, here one register
is set up deliberately and that is exactly the difference.

Cross-check before you believe it: disassemble the callee and confirm it
actually reads r1. 0x02030C68 opens `ldr r2, [r0, #4]` and then stores
through r1 at `str r3, [r1, #8]`, so the second argument is real.
