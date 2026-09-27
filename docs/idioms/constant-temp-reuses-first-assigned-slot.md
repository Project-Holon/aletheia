# A spilled constant temporary takes the slot of the local initialised first

summary: with `int sC = -1; int s8 = -1;` this compiler sinks the initialisers
and parks the reused `0x70` stride constant in `sC`'s slot; dropping the
initialisers and assigning `s8 = -1; sC = -1;` puts the constant in `s8`'s
slot and orders the two `-1` stores the way the original does.

Found in: `src/matched/func_021B9280.c` (0x021B9280)

A 184-byte lerp scans two rows, then lerps `sC` into `s8`. The two locals live
in `[sp+8]` and `[sp+0xc]`, and the address `0x70` is materialised once and
reloaded for the second row:

```
movs r1, #0x70
str  r1, [sp, #8]      /* which slot the constant borrows */
...
ldr  r1, [sp, #8]
...
ldr  r0, [sp, #8]
subs r0, #0x71         /* -1, rematerialised from 0x70 */
str  r0, [sp, #8]      /* s8 initialised first */
str  r0, [sp, #0xc]    /* then sC */
```

Neither the code nor the frame changes, but the constant wants a scratch slot
and picks the one belonging to whichever local the allocator scheduled first.
The obvious spelling

```c
int sC = -1;
int s8 = -1;
```

initialises `sC` first, so the constant lands in `[sp+0xc]` and the two `-1`
stores come out `[sp+0xc]`, `[sp+8]` — five concrete bytes wrong. Swapping the
*declarations* (`int s8 = -1; int sC = -1;`) is worse, not better: the slot
assignment flips with the declaration order (see
`local-declaration-order-is-stack-order.md`) and seventeen bytes move.

What reproduces the original is separating declaration from initialisation:

```c
int sC, s8, num, i;

s8 = -1;
sC = -1;
```

Now the constant borrows `s8`'s slot and `s8` is assigned first, which is the
observed layout. The same function also needs the final sum written `num + sC`,
not `sC + num`, for the last `adds` to land in the right register; that half is
`commutative-operand-order-names-the-temporary.md` applied to a non-call
operand. Both levers are needed together and neither is visible in the diff as
anything but moved stack offsets.
