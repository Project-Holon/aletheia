# ov009 libssl/libcps: `index = 0` belongs before the second block call

Class: the CPS MD5/SHA-1/RSA block-fold helpers in ov009 (`md5.o`, `sha1.o`,
`ssl.o`, `arc4.o`, all `TwlWiFi_base/libssl`, `s+0xf0`-style network code in
`TwlWiFi/libcps`). Two rows closed by this one lever, one more half-closed.

## Filed (EXACT)

| address | function | bytes |
|---|---|---|
| 0x02163438 | `CPSi_md5_calc` (md5.o) | 184 |
| 0x02163CF0 | `CPSi_sha1_calc` (sha1.o) | 184 |

Both parked rows said "register allocation shift: the image keeps
ctx/data0/datalen/index/room in r8/r7/r6/r4/r5, this compiler form uses
r7/r6/r5/r3/r4, all differing bytes are register numbers" and listed every
declaration-order and named-temp lever as tried. None of those move it,
because the trigger is not a declaration at all: it is **where the
`index = 0;` statement sits**.

The fold is

```c
MI_CpuCopy8(data, ctx->buffer + index, room);   /* flush the partial block */
CPSi_md5_block(ctx, ctx->buffer);               /* then block  */
for (i = room; i + 63 < datalen; i += 64)
    CPSi_md5_block(ctx, data + i);
index = 0;                                      /* parked form: at the end */
```

Writing

```c
MI_CpuCopy8(data, ctx->buffer + index, room);
index = 0;                       /* <- one statement earlier, before the call */
CPSi_md5_block(ctx, ctx->buffer);
for (i = room; i + 63 < datalen; i += 64)
    CPSi_md5_block(ctx, data + i);
```

takes `CPSi_md5_calc` from 76 bytes out to EXACT and `CPSi_sha1_calc` from 90
to EXACT. Two effects, one statement: it shortens the if-branch so `room` dies
into the loop counter (image `mov r4, #0` sits between the argument setup and
`bl` at +0068), and it lifts the whole callee-saved pool one register — the
prologue becomes the image's `push {r4, r5, r6, r7, r8, lr}` with
ctx/data/datalen/room/index = r8/r7/r6/r5/r4 instead of r3-r7. With the
statement after the loop the same five locals sit exactly one register lower.

Probe that proved it (lane S7, `scratch/s7/`): a stub with a sixth declared
local that the optimiser coalesces away still flips the pool to r4-r8, i.e. the
pool choice follows the *web count at the allocation stage*, not the emitted
instruction count. So when a whole SDK function is one register low and no
declaration order moves it, look for a statement that can be moved so a web
dies earlier rather than for a different way to spell the same web.

## SHA-1 twin

`CPSi_sha1_calc` needs the same two things. Its index is taken from count[1]
*before* the count pair is updated, in the md5 statement shape:

```c
index = (ctx->count[1] >> 3) & 0x3f;                    /* first */
if ((ctx->count[1] += datalen << 3) < (u32)(datalen << 3))
    ctx->count[0]++;
ctx->count[0] += (u32)datalen >> 29;
room = 64 - index;                                      /* then room */
```

that is what schedules the image's `lsr r2, r3, #3` above the predicated
`count[0]++`; the parked form kept a `saved` copy and computed the index after
the count updates, which is 19 bytes out on its own. `(u32)saved >> 3` and the
explicit `saved` local are both unnecessary: the compiler already keeps the old
count[1] in r3 while the compound add overwrites the field.

## Still open in this family (residues named)

- `0x021612C8 create_key_block` (ssl.o): 318 out, 436 vs 440. Not attempted
  this lane; the parked note's "same register shift" claim is about a
  two-register swap (len=sb/p=fp), so expect the same *web-count* trigger.
- `0x021602B8 cert_item` 714 out (1192 vs 1196), `0x02161C80
  parse_record_in_buf` 260 out, `0x02163628 CPSi_sha1_block` 142 out
  (1652 == 1652).
