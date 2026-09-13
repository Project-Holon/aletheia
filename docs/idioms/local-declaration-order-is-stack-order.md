# Locals are laid out with the later declaration at the lower stack address

summary: the last local declared sits at `sp+0`, so a wrong declaration order
shows up only as wrong stack offsets and nothing else.

Found in: `src/matched/unit_0200857C.c` (0x02008658)

`sub_02008658` puts a 0x10-byte `RTCDate` at `sp+0xC` and a 0xC-byte `RTCTime`
at `sp+0`. Declaring the date first and the time second produces exactly that.

```c
struct RTCDate date;    /* ends up at sp+0xC */
struct RTCTime time;    /* ends up at sp+0   */
```

The other order puts the date at `sp+0`, and the function is then seven bytes
wrong in the stack offsets and identical everywhere else.

This is a one-line fix that is invisible unless the diff is read as offsets
rather than as code: the instruction sequence, the register allocation and the
size are all unchanged, so it looks like a near miss in the body when it is
really a declaration order in the header of the function.
