# A two-case switch whose arms both `return` puts the default epilogue before the arms

summary: For a two-case `switch` where every case ends in `return`, mwccarm emits the compare chain, then the default (fall-through) epilogue, and only then the case bodies each followed by its own epilogue.

Found in: src/matched/func_021DDA50.c (0x021DDA50)

The image was:
```
cmp r6, #0
beq case0
cmp r6, #1
beq case1
add sp, #0xc          ; default: fall-through epilogue
pop {r3, r4, r5, r6, pc}
case0:
...
add sp, #0xc
pop {..., pc}         ; case0's own return
case1:
...
add sp, #0xc
pop {..., pc}         ; case1's own return
```

The equivalent if/else chain
```
if (v == 0) { ...; return; }
if (v == 1) { ...; return; }
```
compiles 4 bytes shorter: it inverts the first test, places the `v == 0` body inline, and leaves the "neither" return after the second test rather than before both bodies. Writing the two arms as `switch (v) { case 0: ... return; case 1: ... return; }` reproduces the image exactly — the default exit is outlined to the compare chain, and each `return` keeps its own epilogue instead of being folded to a shared one.
