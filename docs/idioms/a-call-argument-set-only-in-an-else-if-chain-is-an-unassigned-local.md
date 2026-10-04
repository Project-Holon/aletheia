# A call argument set only in an if/else-if chain with no else is an unassigned local

summary: when two `mov rN, #k` pairs set a call's arguments under `x == 0` and
`x == 1` and the fall-through path reaches the `bl` with those registers
untouched (a callee-saved register never written, or an entry argument
register still live), the locals have no initialiser and no `else`;
initialising them to the first arm's constants adds moves the original lacks.

Found in: `src/matched/ov/ov186_func_021FE90C.c` (EXACT),
`src/matched/ov/ov186_func_021FE970.c` (EXACT*, twin with other mask bits).

The original:

```
ldr r0, [r3, #8]
cmp r0, #0
bne .L1
movs r5, #0x10      @ start
movs r2, #0         @ end
b .Lcall
.L1: cmp r0, #1
bne .Lcall          @ any other value: r5 is the caller's, r2 is entry r2
movs r5, #0
movs r2, #0x10
.Lcall: ... adds r1, r5, #0 ; blx func_0204E720
```

The C that gives it, first compile:

```c
s32 start, end;
...
if (p[2] == 0) {
    start = 16;
    end = 0;
} else if (p[2] == 1) {
    start = 0;
    end = 16;
}
func_0204E720(mask, start, end, p[6]);
```

The earlier lane's `int start = 16, end = 0;` with a single
`if (p[2] == 1)` was parked as DIFF after a full budget plus checks: the default values are materialised before the test and the
register assignment shifts. The unassigned spelling is the original
behaviour, not a permuter-style read-before-assignment: the binary itself
passes the unset registers on that path. See also
`switch-arms-tail-merge.md` for the switch form of the same thing.
