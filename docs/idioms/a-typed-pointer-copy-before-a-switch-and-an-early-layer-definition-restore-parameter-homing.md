# A typed pointer copy before a switch and an early layer definition restore parameter homing

summary: In these Thumb constructors, bind a byte-pointer parameter to a typed local before the switch and define the true-arm layer before the field stores; together these spellings recover the parameter's stack home, heap/layer registers and four-byte frame difference.

Found in: `src/matched/ov/ov177_func_021E6118.c` and `src/matched/ov/ov177_func_021E5D68.c`.

Both constructors allocate 0x244 bytes, initialise fields, select one of two display layers, dispatch on a halfword in the incoming descriptor, and pass the descriptor to a setup callee. Later they advance the original byte-pointer parameter by 0x9c and load through it.

The matching form retains distinct byte and typed views:

```c
char *w;
Layer layer;
Pt pos;
Info *tmp;
/* allocation and common stores */
if (mode) {
    layer = 2;
    *(u8 *)(w + 0x230) = 1;
    /* remaining true-arm stores and display-register call */
} else {
    /* false-arm stores */
    layer = 6;
    /* display-register call */
}
tmp = (Info *)info;
switch (*(u16 *)(info + kind_offset)) {
    /* display calls */
}
setup((Work *)w, tmp, /* other arguments */);
info += 0x9c;
use(*(u32 *)info);
```

For 021E6118, putting `layer = 2` after the stores and casting `info` directly in `setup` compiled to 388 bytes against 392, with 104 concrete bytes different. The image homes `info` at sp+0x10 and uses r7 for the heap and r6 for the layer; that spelling kept `info` in r7, heap in r6 and layer in r4. Const, parameter integer spelling and enum layer alone did not repair it. The once-only permuter found the two changes together; fixed-flag `one` verified EXACT, 392 bytes and 13 resolved relocations.

Applying that combined spelling to 021E5D68 also gave EXACT, 400 bytes and 13 resolved relocations. Its inline-cast form gave 396 bytes and 372 differing bytes; a signed heap variant reached 400 bytes but still differed at 312 bytes. These measurements establish the combined lever; neither isolated mutation was separately tested. The functions keep their observed u16 heap and byte-pointer parameter types.
