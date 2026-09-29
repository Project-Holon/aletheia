# A guard on the parameter with its decremented copy computed after the call is `while (i-- != 0)` over a copy made before the call

summary: when a downward u8 loop opens with a copy of the count parameter made
before an intervening `bl` (`adds r4, r7, #0`), the `subs; lsls #24; lsrs #24`
of that copy after the call, and an entry guard that tests the parameter (or
its spill slot) rather than the copy, the C is `u8 i = n; x = f(...);
while (i-- != 0) { ... p[i] ... }`; the explicit `i = n - 1; if (n != 0) do
{ ... } while (i-- != 0);` spelling folds the copy away or hoists the
decrement above the call.

Found in: `src/matched/ov/ov093_func_021B8E28.c` (0x021B8E28),
`src/matched/ov/ov093_func_021B98AC.c` (0x021B98AC)

The image (0x021B8E28):

```
adds r7, r1, #0        ; n
adds r4, r7, #0        ; i = n, before the call
...
bl   func_021B8CFC
subs r0, r4, #1        ; rotated first test: i-- ...
lsls r0, r0, #0x18
lsrs r4, r0, #0x18
cmp  r7, #0            ; ... against the old value, which is n
beq  done
```

The rotated first test of `while (i-- != 0)` is "old = i; i = i - 1; if
(old == 0) exit": copy propagation turns `old` into `n`, which is why the
guard reads the parameter while the decrement works on the copy. Two earlier
lanes wrote the loop as an explicit guard plus `do`/`while` with `i = n - 1`
and parked both functions: with `i` assigned after the call the copy folds
into `n` (one register fewer, no spill), and with it assigned before the call
the `subs/lsls/lsrs` lands above the `bl`.

In 0x021B98AC the parameter is spilled (five values live over the call) and
the spill store sat above the `ldr r6, [r7]` of `p = *q`; declaring the
parameter `char *const *q` let the load move above the spill store (see
`const-pointer-lets-a-field-load-survive-a-store.md`) and made it EXACT.
