# A named local for the loaded global base settles a field-store run

summary: when a struct-field run stores a self/pointer field first and a
field computed off a loaded global second, putting the assignment in
source order fixes the store order but recolours the block (the loaded
global lands in the pointer register and a constant in the scratch); binding
the loaded global to a named local and adding the offset to that local keeps
the store order and the original colouring.

Found in: src/matched/ov_sdk/ov016_func_021D5A58.c (0x021D5A58, DWCi_FNTlFormBgEx, dsi/1.1p1, ARM)

The tail of the function is

```
cv->self = cv;
cv->font = g_021DE680 + font * 8;
cv->f20  = 1;
cv->f24  = 1;
```

The image issues the self store before the font computation:

```
ldr  r0, [pc, #0xa4]     ; &g_021DE680
mov  r1, #1
ldr  r0, [r0]            ; g_021DE680
str  r5, [r5, #0x18]     ; cv->self
add  r0, r0, r4, lsl #3  ; font
str  r0, [r5, #0x1c]     ; cv->font
str  r1, [r5, #0x20]
str  r1, [r5, #0x24]
```

Writing `cv->font = ...;` first (source order font-then-self) leaves only
the two stores transposed, 10 bytes.  Writing `cv->self = cv;` first gives
the right order but recolours: the loaded global takes r1 and the constant
1 takes r0, 21 bytes.

Naming the loaded base fixes both:

```c
char *base = g_021DE680;
cv->self = cv;
cv->font = base + font * 8;
```

The named local pins the load to r0 and the `add r0, r0, r4, lsl #3` reads
it there, so the self store keeps its place and the constant stays in r1.
The relocation and pool word are unchanged; this is a colouring lever for a
run of field stores whose base value is one pooled global load.
