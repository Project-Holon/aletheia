# A global struct member is re-read, not cached in a local

summary: A module-global reached through a helper or a fixed base compiles
differently if the source re-reads the member at every use instead of caching
the pointer in a local; the image reloads the base after every call, and only
the re-reading spelling reproduces the vendor allocation.

When a function reaches a module-global through a helper such as
`DWCi_GetMatchCnt()` or through a fixed global base like
`s_bNeedCloseStatsConnection`, spelling the access as a **fresh member
expression at every use** can compile quite differently from binding the
pointer once to a local and then using the local.

The two spellings are semantically identical, but the register allocator
treats them differently, and only one of them reproduces the vendor object.

## Worked example: `DWCi_UpdateFriendReq` (ov009, 0x021692C4)

A reconstruction that cached the list pointer

```c
FriendState *state = (FriendState *)s_bNeedCloseStatsConnection;
FriendList  *fl    = state->fl;
... fl->reason ... fl->connection ... fl->list ...
```

compiled to **604 bytes** against the original **676**.  Re-reading the
global member at every use

```c
extern FriendState s_bNeedCloseStatsConnection;
#define FL (s_bNeedCloseStatsConnection.fl)
... FL->reason ... FL->connection ... FL->list ...
```

compiled to exactly **676** and reached `EXACT`.  The image re-loads
`[base, #0xc]` after every call (the `bl` could have written the global),
so caching it in a callee-saved register drops every reload and shifts the
whole allocation.

## Same lever on `DWCi_GPProfileSearchCallback` (ov009, 0x02169934)

Caching `state` gave 624 bytes with the base in r5; replacing every
`state->fl` with `s_bNeedCloseStatsConnection.fl` gave the exact **636**
bytes and matched every instruction except a three-register rotation.

## The tell

The original disassembly re-loads the same struct pointer
(`ldr rX, [base, #off]`) immediately after each `bl` even though the value
is loop-invariant.  That is the compiler proving the callee may have
written the global, which only happens when the source re-reads the
member rather than caching it.

Contrast the existing
[Global re-read across a call to a same-file static needs `volatile`](a-global-reread-across-a-call-to-a-visible-static-needs-volatile.md):
that entry is about a *field* load being kept live; this one is about the
*base pointer* being de-cached by re-spelling the member expression.
