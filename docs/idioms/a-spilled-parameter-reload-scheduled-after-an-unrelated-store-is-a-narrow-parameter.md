# A spilled parameter reload scheduled after an unrelated store is a narrow parameter

## Shape

A parameter is spilled at entry and reloaded after a loop to fill a u32 field. The original issues an
unrelated constant store first and the reload after it:

```
movs  r3, #1
str   r3, [sp, #0x2c]     ; e[2].term = 1
ldr   r0, [sp, #8]        ; reload of the size parameter
movs  r2, #3
str   r0, [sp, #0x30]     ; c.size = size
```

With a `u32` parameter, mwcc hoists the reload to the top of the block and sinks the constant store
to the end, whatever the source order of the statements.

## Source

The parameter is narrower than the field it fills:

```c
int func_021C0AC8(void *parent, void *bank, u16 size)
{
    ...
    e[2].term = 1;
    c.size = size;      /* u32 field */
```

The listing shows no extension (mwcc trusts the caller's zero extension), so only the schedule tells
the type. Store orders, pointer locals, blocks and labels around the store do not change it.

## Seen in

ov110 func_021C0AC8 (wave D9r, 27 bytes to EXACT after ten lanes of store-order tries).
