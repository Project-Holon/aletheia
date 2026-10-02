# A field spelled two ways is copy-propagated, not CSE-hoisted

summary: Spelling a reused field once as a struct member and once as a raw offset prevents CSE from hoisting its load ahead of an independent index operand; copy propagation still supplies the later call argument.

Shape: two independent loads feeding one address add come out in the
opposite order to the obvious C, and every operand order, local and cast
leaves them unchanged.

    ldr r1, [r5]        ; c->w        (target: w first)
    ldr r0, [r5, #4]    ; c->key
    adds r1, r1, r0
    ldrb r1, [r1, r4]
    ...
    bl  callee          ; r0 = key reused as the argument

Cause: when the same field (`c->key`) is written in both the index and the
later call argument, CSE turns it into a temp placed ahead of the whole index
expression, so key loads first. When the second use is spelled differently
(`*(int *)((char *)c + 4)`, or the index uses the raw form and the call the
field), CSE does not pair them; the value still reaches the call through copy
propagation, but the index expression keeps its source order and `c->w`
loads first.

    if (c->tag == c->w->tag[c->key])
        c->w->mask &= func_021F935C(*(int *)((char *)c + 4)) ^ 0xFFFFFFFF;

Seen: ov094 func_022011FC (EXACT). The same two-byte residue sits on
ov094 func_02201098 (tag at +0x38).
