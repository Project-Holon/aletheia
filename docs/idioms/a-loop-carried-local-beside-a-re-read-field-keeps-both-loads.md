# A loop-carried local beside a re-read field keeps both loads

summary: two loads of the same struct field, one at the bottom of a loop feeding
the back-edge compare and one at the top of the body feeding the work, mean the
loop condition is on a named local refreshed at the bottom while the body reads
the field again; a bare `while (p->f != end)` with `n = p->f` inside CSEs the
pair and loses four bytes at the body top.

Found in: `src/matched/sub_020310C4.c` (0x020310C4)

At `-O4,p` this compiler does global common-subexpression elimination across a
loop back edge, so a field read at the top of a loop body is normally folded
into whatever register already holds the value from the bottom-of-loop compare.
When the original keeps *both* loads, that is evidence about the source, not
noise from the scheduler.

## The tell

Both of these appear, with no call between them:

```
+0064    ldr r0, [r6, #0x30]        ; bottom of loop, feeds the compare
+0068    cmp r0, r5
+006C    bne  body_top
...
body_top:
+0020    ldr r7, [r6, #0x30]        ; top of body, feeds the work
```

and the loop entry compares the value it just *stored*, rather than reloading:

```
+000C    ldr r0, [r5, #8]
+0010    str r0, [r6, #0x30]
+0014    cmp r0, r5
+0018    beq  after_loop
```

## The two shapes

The obvious C folds the two loads into one:

```c
p->cursor = s->next;
while (p->cursor != s) {
    struct TcblNode *n = p->cursor;   /* becomes `mov r0, r7` */
    ...
}
```

The compiler proves that on entry and on the back edge the field equals a value
it already has in a register, keeps it in `r7` across the loop, and emits one
load at the bottom instead of two. The result is byte-correct everywhere else
and exactly one instruction (four bytes) shorter.

The shape that reproduces the original gives the condition its own local:

```c
cur = s->next;
p->cursor = cur;
while (cur != s) {
    struct TcblNode *n = p->cursor;   /* a real load, every iteration */
    ...
    cur = p->cursor;                  /* the bottom-of-loop load */
}
```

`cur` is the loop-carried value the compare uses, so the entry test costs no
load at all, and `n` is a separate read that the compiler is not free to drop
because a function pointer is called through it in between.

## Rule

Count the loads of the loop's own field. One load plus a register copy at the
body top is the plain `while (p->f != end)`. Two loads, with the entry test
using the just-stored value, is a named loop variable refreshed at the bottom of
the body and a second, independent read at the top.
