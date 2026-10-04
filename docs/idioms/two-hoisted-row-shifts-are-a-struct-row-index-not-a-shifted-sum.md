# Two separate row shifts are a struct-row index, not a shifted sum

summary: when the original computes `base << 4` once above a loop and adds
`(i >> 1) << 4` inside it, the C is a 16-byte struct (or `u8 (*)[16]`) array
indexed by `base + (i >> 1)`. Plain byte arithmetic, written as
`(a << 4) + ((i >> 1) << 4)`, `a * 16 + (i >> 1) * 16` or
`(a + (i >> 1)) << 4`, is folded by 1.1p1 into one `(a + (i >> 1)) << 4` with
no hoisted shift.

Found in: src/matched/ov/ov199_func_02213894.c (0x02213894)

The original stores `a << 4` and `b << 4` to stack slots after the loop guard
and, per element, adds `j` last: `adds r3, row, f8; adds r3, j, r3;
strb [r3, #0xa]`. `((u8 (*)[16])(p->f8 + 0xa))[a + (i >> 1)][j]` gets the
hoisted shifts but adds `j` in the wrong operand order.
`((struct Row *)p->f8)[a + (i >> 1)].name[j]`, where `struct Row { u8
pad[10]; u8 name[6]; }`, is EXACT.

The same function had two more fixes:
- A switch whose arms differ only in the value stored to one field is written
  with the store in each arm. The single store after the switch (`v = 0;
  break;` and so on) gives one wrong branch target, because the original
  case-0/3 arm branches to the case-1/4 arm's `b`.
- A dense switch on 0..4 where cases 1..3 share the default arm keeps its jump
  table only when `case 1: case 2: case 3:` are written next to `default:`.
  Without them, 1.1p1 emits a compare chain.
