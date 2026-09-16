# Declaration order picks the register, initialisation order picks the load

summary: for a block of locals that are all loaded from the same struct up
front, the order they are declared in decides which register each one gets and
the order they are assigned in decides the order of the loads; when the
original's register assignment and load order disagree, the two orders in the
source have to disagree too.

Found in: `src/matched/unit_0202878C.c`, `func_0202880C` (0x0202880C)

`docs/idioms/declaration-order-decides-which-register-a-local-gets.md` says the
register follows the declaration and not the initialisation. This is the other
half of the same observation: the *loads* follow the initialisation. As long as
a function reads its fields in the same order it declares them, the two are the
same order and nobody notices. A function whose original does not is a five
byte diff that no single ordering closes.

## The tell

Every instruction is right, the sizes agree, and two or three registers are
swapped between a pair of locals, or two loads are in the wrong order, and
permuting the declarations trades one for the other:

```
    +0082    ldrh r2, [r0, #6]       | ldrh r3, [r0, #6]
    +0084    ldrb r4, [r0, #1]       | ldrb r4, [r0, #1]
    +0086    ldrb r3, [r0, #2]       | ldrb r2, [r0, #2]
    +008A    cmp  r2, #0             | cmp  r3, #0
    +008E    subs r0, r3, r4         | subs r0, r2, r4
```

Reordering the declarations to fix the registers then swaps the two `ldrb`
instead:

```
    +0084    ldrb r4, [r0, #1]       | ldrb r3, [r0, #2]
    +0086    ldrb r3, [r0, #2]       | ldrb r4, [r0, #1]
```

## Worked case

`func_0202880C` interpolates a volume level: it reads the elapsed count, the
start and target levels and the duration out of a nine byte record, and if the
elapsed count is non zero it returns `from + (to - from) * elapsed / frames`.

The original loads `elapsed`, `from`, `to`, `frames` in that order, and holds
them in r2, r4, r3, r1. Written the obvious way, with the declarations in the
load order, `elapsed` gets r3 and `to` gets r2. Every permutation of a combined
declare-and-initialise block is either five bytes wrong (registers) or two
bytes wrong (load order). Splitting the block closes it:

```c
u16 elapsed;
u8  from;
u8  to;
u16 frames;
u32 level;

from = s->unk01;
to = s->unk02;
elapsed = s->unk06;
frames = s->unk04;
```

Declared elapsed, from, to, frames for the registers; assigned from, to,
elapsed, frames for the loads.

## Rule

When a run of struct loads is right in every byte except that a pair of
registers or a pair of loads is transposed, stop permuting one list. Write the
declarations and the assignments as two separate blocks and permute them
independently: the declarations against the register numbers, the assignments
against the load order.
