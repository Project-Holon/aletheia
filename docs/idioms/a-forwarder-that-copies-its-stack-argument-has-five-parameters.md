# A forwarder that copies its stack argument has five parameters, not four

summary: a small forwarder shaped `push {r3,r4,lr}; sub sp,#4; ldr r4,[sp,#0x10]; str r4,[sp]; bl` forwards five arguments; declaring only four makes the compiler drop the copy and emit a bare tail `bl`.

Found in: src/matched/func_021C5478.c (0x021C5478) and src/matched/func_021C54B4.c (0x021C54B4)

The original:

```
push {r3, r4, lr}
sub  sp, #4
ldr  r4, [sp, #0x10]     ; the caller's stack word
str  r4, [sp]            ; becomes the callee's outgoing stack word
bl   func_021C5404
add  sp, #4
pop  {r3, r4, pc}
```

With `void f(int a,int b,int c,int d){ g(a,b,c,d); }` the compiler emits a
four-byte bare tail call: the fourth int already travels in r3, so nothing needs
the stack, and the whole push/sub/copy dance vanishes.  The copy exists only
because the incoming stack word is the function's *fifth* parameter, which has to
be re-placed for the callee so the wrapper's own saved registers do not shift it:

```c
void f(int a, int b, int c, int d, int e) { g(a, b, c, d, e); }
```

Deciding the arity from the stack copy, not from the visible r0-r3 moves, is the
tell.
