# A singleton global re-read through a macro, not cached in a local, frees the low callee-saved register

summary: when one global's address is used throughout, writing `#define G
((T*)g)` and re-evaluating it at each use gives the compiler a pure value it
can keep in the *lowest* callee-saved register and lets a nearby repeated
constant take the next one; binding `T *p = (T*)g;` first instead hands `p`
the next register and pushes the constant down, shifting every `[rN,#off]` and
the cold-block layout.

Found in: `src/matched/ov_sdk/ov009_func_02169BB0.c` (0x02169BB0)

`DWCi_GPGetInfoCallback_RecvBuddyRequest` reads the singleton
`s_bNeedCloseStatsConnection` (0x021AA860) a dozen times, and the loop also
needs a materialised constant `1`. With the natural

```c
FriendState *state = (FriendState *)s_bNeedCloseStatsConnection;
```

the constant took `r4` and `state` took `r5`; the image has `state` in `r4`
(`ldr r4,[pc,...]`) and the constant in `r5` (`mov r5,#1`). Every `[r5,#0xc]`
then disagreed and the deny block was laid out inline instead of sunk after
the main path. Expanding the pointer at each use fixes both:

```c
#define STATE ((FriendState *)s_bNeedCloseStatsConnection)
...
alreadyBuddy = 1;                 /* the repeated constant keeps r5  */
DWCi_SetReverseBuddyFlag(&STATE->fl->list[index], 1);
```

It also forced the `if (confirm == 0) { gpDenyBuddyRequest(...); return; }`
block to be emitted after the main path (`beq deny` at the top) rather than
inline, which the tail then matched byte for byte. The local spelling was a
169-byte near miss, the macro spelling EXACT.

This is the register-allocation cousin of
`keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md` and
`declaration-order-decides-which-register-a-local-gets.md`: the difference is
not declaration order but whether the value is a named local at all. If a
byte-for-byte body differs only in which register holds a singleton's address
and a same-lived constant, try inlining the global through a macro before
touching anything else.
