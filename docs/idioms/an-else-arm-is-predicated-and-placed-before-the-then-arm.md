# An else arm short enough to predicate is emitted before the then arm

summary: when the else arm of an `if (x == 0) { call } else { stores }` is short
enough to predicate, the compiler emits it first (movne/strne/popne) and falls
through into the then arm; an image whose predicated block sits ahead of a call
is therefore the `== 0` test with the call first, not the `!= 0` test with the
stores first, and the `!= 0` spelling is branched and four bytes long.

Found in: src/matched/func_020314F4.c (0x020314F4), src/matched/func_02045F5C.c
(0x02045F5C)

func_020314F4 (ARM) in the image:

```
cmp   r0, #0
movne r0, #1 / strne x4 / popne {r4, pc}
mov   r0, r1 ... bl func_02031538 ...
```

`if (obj->buffer != 0) { four stores; return; } obj->buffer = f(...);` compiles
to `beq` over an unpredicated block (72 bytes against 68), and the note that
recorded it read it as a predication threshold.  `if (obj->buffer == 0) {
obj->buffer = f(...); } else { four stores }` is byte-identical to the image.
func_02045F5C is the same finding in a larger body: `if (mode != 0) { entry =
resident } else { seek; read }` is 11 bytes out in the scheduling of the file
arm, `if (mode == 0) { seek; read } else { entry = resident }` is EXACT.  This
refines docs/idioms/the-fall-through-arm-is-the-source-order.md: the source
order holds for branched arms, but a predicated else arm is hoisted above the
then arm.
