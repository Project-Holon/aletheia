# A colour swap that no source form fixes can be a per-function opt_lifetimes off

summary: when two long-lived values sit in each other's callee-saved registers and every
source spelling leaves the swap, try `#pragma opt_lifetimes off` before the function (with
`#pragma opt_lifetimes reset` after it) before more source variants.

Found in: src/matched/ov/ov055_func_021F3DD4.c (0x021F3DD4)

The draft was instruction-identical to the original except that the pointer parameter p and
the first call result a had swapped registers (original p r4, a r5). About fifteen lanes tried
local types, declaration orders, parameter copies, inline accessors and struct forms; all left
the same 26 bytes. A diagnostic pass over compiler versions, optimisation flags and the
pragmas already used in matched files found one setting that closes it:

```c
#pragma opt_lifetimes off
void func_021F3DD4(...) { ... }
#pragma opt_lifetimes reset
```

With lifetime splitting off, the parameter keeps one web from entry, and the allocator colours
it before the call result. Eight other matched files already carry this pragma.

How to use it: for a pure register-colour or spill-slot residue, run the per-function pragmas
(opt_lifetimes, opt_propagation, opt_common_subs, opt_dead_assignments, scheduling, peephole)
once, early, as a short diagnostic. It is one compile per pragma, not a source sweep. On the
other eight hard drafts of wave D9r none of them helped, so it is not a universal fix.
