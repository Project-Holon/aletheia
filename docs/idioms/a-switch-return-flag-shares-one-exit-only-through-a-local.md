# A dense switch returning a flag shares one exit only as a local set by the default, not as per-arm returns

summary: a nine-case switch that returns 0 for some values and 1 for the rest
compiles to one shared exit block (a single `movs r1, #1` / `adds r0, r1, #0`
/ `bx lr`) only when the source declares a result local initialised to the
fall-through value and lets the empty cases and `default` set it; spelling each
arm as its own `return 0` / `return 1` makes the compiler emit one return block
per arm and miss by 32 bytes.

Found in: `src/matched/ov119_func_021D8AA8.c` (0x021D8AA8), reached from
`src/pending/func_021D7130.c` (ov118).

The original is a nine-entry PC-relative halfword table on
`*(u32 *)(p + 0x118C)`: the cases whose table displacement is `0x12` fall into
`adds r0, r1, #0; bx lr` with `r1` still zero, the cases (and the `bhi`
default, values above 8) whose displacement is `0x10` fall into the block that
first does `movs r1, #1`.

Written as a switch of direct returns,

```c
switch (x) {
case 0: return 0;
case 1: return 1;
...
default: return 1;
}
```

the compiler emits a distinct `movs r0, #1; bx lr` per true arm (84 bytes,
then 52 once the arms are grouped, but still separate blocks), and the first
divergence is the missing `movs r1, #0` at the top.

Written with the result in a local, the fall-through arms empty, and only the
default setting it,

```c
unsigned int x = *(unsigned int *)((char *)p + 0x118C);
int r = 0;

switch (x) {
case 0:
case 4:
case 6:
case 7:
case 8:
    break;
default:
    r = 1;
}
return r;
```

the header is exactly `ldr r2, [pc, #0x2c]; movs r1, #0; ldr r0, [r0, r2]`,
the table entries for the unlisted cases 1, 2, 3 and 5 point at the single
`r1 = 1` block, and the whole function is byte-exact.

The tell is the trailing `adds r0, r1, #0` rather than a `movs r0, #imm`: the
return value is live in a register the whole function, so every arm has to
write that register and the compiler cross-jumps them only when the source
gave it one variable to write.
