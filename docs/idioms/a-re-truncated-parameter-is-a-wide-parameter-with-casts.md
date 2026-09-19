# A small integer parameter that is re-truncated at every use is a 32-bit parameter with casts, not a narrow parameter

summary: when a parameter is spilled and then zero-extended again at each
call that takes it, declare the parameter as the wide type and cast at each
use; declaring it narrow makes mwcc skip the truncation entirely and drop
two instructions per site.

Found in: `src/matched/sub_02024368.c` (packet pkt_02024368)

The original's prologue, with `r1` the second argument:

```
02024368  push {r3, r4, r5, r6, r7, lr}
0202436A  adds r6, r0, #0            ; the first parameter
0202436C  adds r0, r1, #0
0202436E  lsls r0, r0, #0x10
02024370  lsrs r0, r0, #0x10         ; r0 = (u16)r1, for the call
02024372  str r1, [sp]               ; ... and the RAW register, spilled
```

and then, twice more:

```
020243CA  ldr r3, [sp]
020243CC  lsls r3, r3, #0x10
020243CE  lsrs r3, r3, #0x10
020243D4  ldr r1, [sp]
020243D6  lsls r1, r1, #0x10
020243DA  lsrs r1, r1, #0x10
```

Three separate `lsls`/`lsrs` pairs, one per use, always applied to a value
just reloaded from the spill slot.  Written as a `u16` parameter this
disappears: mwcc treats the narrow parameter as already clean, spills the
raw register, and reloads it straight into the argument (`ldr r0, [sp]`
with no pair), which is 12 bytes short over the whole function and shifts
every later offset.

Measured on sub_02024368 (original 180 bytes):

```
void f(u16 *slots, u16   heap, int n)   -> 168 bytes, no truncation pairs
void f(u16 *slots, u32   heap, int n)
        with (u16)heap at each use      -> 180 bytes, EXACT
```

The tell is not the type name, it is that the spill slot holds the value
*before* truncation: if the raw register is what gets stored, the source
expression is a cast, not a narrow variable.  A genuinely narrow parameter
is truncated once on entry and the spilled word is the truncated one.
