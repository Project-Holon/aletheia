# An 8-byte Thumb or 12-byte ARM stub that jumps through a pool word is a compiled tail call, not a linker veneer

summary: `ldr r3,[pc]; bx r3; .word target` (Thumb, 8 bytes) and `ldr ip,[pc]; bx ip; .word target` (ARM, 12 bytes) are what mwcc writes for a function whose only job is to call another one. They are ordinary functions to write as `void f(void) { g(); }`, not veneers to skip.

Found in: src/game/ov010/event_field_proclink.c (0x0216171C), src/game/ov107/unit_021F4560_p03.c (0x021F5ED8)

Two forms, both with a literal pool word holding the target address (the low bit
set when the target is Thumb):

```
Thumb, 8 bytes            ARM, 12 bytes
ldr r3, [pc]              ldr ip, [pc]
bx  r3                    bx  ip
.word target              .word target
```

mwcc emits them for a tail call: the call is the last thing the function does,
so it jumps (`bx`) instead of calling (`bl`) and does not save `lr`. The
register is r3 in Thumb and ip in ARM. The target may be Thumb or ARM; the `bx`
switches state from the low bit of the pool word.

How to write them:

```c
void func_0216171C(void)
{
    func_020307B0();            /* Thumb stub, ARM target: ldr r3,[pc]; bx r3 */
}

int func_021F5ED8(void)
{
    return MBi_CallReset();     /* ARM stub: ldr ip,[pc]; bx ip */
}
```

A stub that forwards its parameters unchanged is the same code with the
parameters named: `int f(char *url) { return g(url); }`. Because r0 to r3 are not
touched, the bytes are identical whether the forwarded arguments are written or
left out, so take the signature from the target and its callers. A stub that
first moves arguments (`adds r0, r1, #0` before the load) is a forwarder that
drops or reorders parameters, e.g. `void f(int a, u8 *b, int c) { g(b, c); }`.

These are not the linker veneers. The real ones stay unwritten:

- `bx pc; nop; ldr ip, [pc]; bx ip; .word target` (Thumb to ARM, 16 bytes), and
- `ldr pc, [pc, #-4]; .word target` (ARM, 8 bytes).

The sign of a real veneer is the interworking prefix or the direct `ldr pc`; the
two stub forms above have neither and sit where a function would start.

Why it matters: a gap tool that calls the stubs veneers makes every translation
unit around one look like it has an unfilled linker gap, so the parts on both
sides are never merged. After the stub is written as a function the two parts
compile as one file (ov010 event_field_proclink, ov114 ghttpEncryption and
unit_021C2284, ov125 unit_021D7CEC, ov093 unit_021DA624, ov107 unit_021F4560 p03
with p04 all merged this way). tools/gamegaps.py lists them as class `leaf`,
note `tailstub target=...`.
