# Volatile on a just-stored field forces the object's reload

summary: when a ternary assigns a struct field and the else-arm passes that same
field to a call, mwccarm forwards the value it just stored and needs a `mov` to
move the call result into the select's result register; making the field
`volatile` re-reads it at the call, which is what the original does, and the
whole downstream register rotation follows.

Found in: `src/pending/ov_sdk/ov009_func_0215CB24.c` (0x0215CB24, 162 -> 148
concrete bytes)

`SOCLi_StartupCPS` computes

```c
cps_config->lan_buflen = cond ? socl_config->lan_buffer_size
                              : g_021A1CD8.defaultLanBufferSize;
cps_config->lan_buf = other ? socl_config->lan_buffer
                            : g_021A1CD8.config->alloc(cps_config->lan_buflen);
```

In the original the `lan_buf` select loads `lan_buffer` over the register that
still holds `lan_buflen`, so the alloc path has to reload the field:

```
ldr r0, [r6, #0x28]   /* lan_buffer: clobbers the lan_buflen in r0 */
cmp r0, #0
bne store
ldr r1, [pc, #0xd8]
ldr r0, [r5, #0x20]   /* reload cps_config->lan_buflen */
ldr r1, [r1]
ldr r1, [r1, #0x18]
blx r1
```

The obvious C lets the compiler keep `r0 = lan_buflen` live across the select
(it is the alloc argument register after all), pick `r1` for the `lan_buffer`
test, and then move the result back (`mov r1, r0`), recolouring everything
downstream. Declaring the field `volatile u32 lan_buflen;` refuses the
forwarding, reproduces the reload, and removes the symptom.

This is the structural sibling of
`a-re-read-of-a-field-just-stored-is-one-volatile-read-not-a-volatile-field.md`
and `a-global-reread-across-a-call-to-a-visible-static-needs-volatile.md`: the
lever is `volatile` on the storage, used purely to stop the front end forwarding
a store into a later call, not because the object is really volatile.
