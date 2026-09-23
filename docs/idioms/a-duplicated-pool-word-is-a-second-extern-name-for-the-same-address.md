# A duplicated pool word is a second extern name for the same address

summary: mwccarm emits one literal-pool word per (symbol, addend), so a pool
that carries the same address twice in one function means the source named
it through two different externs; one name makes 1.1p1 CSE both uses into a
callee-saved register (and every 2.0 build share one word), two names give
two independent pool loads.

Found in: src/matched/func_0202271C.c (0x0202271C), and earlier
src/matched/func_02023F98.c (0x02023F98) in the same module

The image (Thumb, 1.1p1 -O4,p), wipe.c's slot-0 setup:

    ldr  r1, [pc, #0x24]   ; d_0209F570
    ldr  r0, [pc, #0x24]   ; 0x020A73D0, pool 0x02022750
    str  r1, [r0]
    ldrh r0, [r4, #0x24]
    bl   func_020222A8
    ldr  r1, [pc, #0x20]   ; 0x020A73D0 again, pool 0x02022754
    adds r0, r4, #0
    bl   func_020238B4

`g.f00 = (u32)tbl; ...; func_020238B4(p, &g.f00);` with one extern keeps
the address in r5 across the first call (push {r3, r4, r5, lr}, 9 bytes
out); ../2.0/sp2 reloads it but from one shared pool word (1 byte out).
Spellings that fold to the same relocation do not split the word: `&g`,
`*(u32 *)&g`, `&g.f10 - 4`, `(u8 *)&g + 0x10 - 0x10`. Declaring a second
extern at the same address (`g_wipe_slot0  0x020A73D0  data` in the
symbols block) for the argument is EXACT under 1.1p1.

The sibling slots (0x02022758 ff.) need only one name because their two
uses differ by the slot offset (`g` for the store base, `g + 0x10` for the
argument) and so are already two pool words. The bytes fix how many names
were in play, not whether the original had two objects or two declarations
of one; func_02023F98's header says the same. When a pool carries an
address twice, count the names before trying front ends or statement
orders.
