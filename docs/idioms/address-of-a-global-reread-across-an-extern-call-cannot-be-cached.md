# Address-of-a-global reread across an extern call cannot be forced into a cache

summary: when the original takes the address of the same global twice, once
before and once after an unrelated call to an ordinary (non-`static`) extern,
`-O4,p` reloads it from the literal pool both times; every C spelling tried
instead has the compiler cache the address in the register the reload would
have used and reuse it, costing 4-8 bytes and a different schedule, with no
spelling found that reproduces the second reload.

Found in: docs/notes/waza_tool_0201c7a4_diff.c.txt (0x0201C7A4), and the
0x0201C7D0 sibling (three reloads instead of two, same shape).

Both functions in waza_tool.c share this skeleton: forward a `StrObj *`
argument through an ARM veneer call, discarding the return, then call two or
three more externs, each taking the address of the same file-scope scratch
object `g_0214655C`:

```c
void sub_0201C7A4(u32 a, u32 b, u32 c, struct StrObj *owner, u32 e)
{
    sub_02045A90(owner);
    sub_0201C808(&g_0214655C, e, a, b, c);
    sub_0201C8BC(&g_0214655C, owner);
}
```

The original reloads `&g_0214655C` from the pool separately before each call
(two distinct `ldr r0, [pc, #n]` instructions, both resolving to the same
pool word). `-O4,p` instead loads it once into a scratch register (`r4`,
whichever register the pool load would have needed at the *first* site) and
reuses that register at every later site, which is smaller in instruction
count but different in byte count and scheduling since the reload is folded
into the register-move sequence that follows the veneer call.

Tried and equally CSE'd, all producing the identical wrong 48/56-byte
schedule:

- binding `&g_0214655C` to a local pointer once and passing the local to
  both calls (makes the caching explicit instead of implicit, same bytes);
- `volatile` on the global and on both pointer parameters (address-of a
  volatile object is still a compile-time constant to this front end, so it
  has no effect at all, unlike a *value* reread through a pointer, which
  `docs/idioms/a-global-reread-across-a-call-to-a-visible-static-needs-volatile.md`
  does fix);
- re-casting the second reference, `(struct Scratch *)&g_0214655C`;
- declaring the global as `struct Scratch g_0214655C[1]` and using the
  array-decay form instead of `&` at both call sites;
- giving the first callee a discarded non-`void` return, on the theory that
  consuming a return value might perturb the scheduler enough to force a
  fresh load afterward.

Unlike the sibling-field-reload idiom
(`a-field-reload-after-a-sibling-store-cannot-be-forced.md`), the callees
here are genuine unresolved externs of unknown effect, which is exactly the
condition the `volatile`-fixes-a-reread idiom describes for *value* rereads;
here the address computation itself is the value, and it never depends on
what an extern call might have written, so no qualifier changes it. This
looks like a case the pinned `-O4,p` / `dsi/1.1p1` compiler genuinely does
not reproduce for this call shape, not a wrong C guess: every relocation
resolves and the byte differences are pure scheduling, not evidence gaps.
