# app_taskmenu (arm9)

Translation unit 020263B0..02028844. Three files, address order:

- `app_taskmenu_p01.c`: 020263B0..0202822D and 02028230..0202859F (the old p01 to p07 and the
  members func_020275DC, func_020275E0, func_02027A20, func_0202815C, merged in round 3).
  One `struct Cfg` now has the template pointer at +0x04 (`struct CfgTmpl *f04`), one `struct Src`,
  and `struct Obj` has `flags` at +0x14. func_02027FEC, func_0202800C and func_0202804C take
  `struct Cfg *`, `struct Src *`, u16, u16 like the definition of func_02028084.
- `app_taskmenu_p02.c`: func_0202822E, a lone `bx lr`. It is the second half of
  func_0202822C (`str r1, [r0, #8]` at +0, `bx lr` at +2), listed as its own function in the
  function map. It cannot be code of its own inside a merged file, and gamecheck needs the
  definition, so it stays a one-function file placed between p01's two ranges.
- `app_taskmenu_p03.c`: 020285A4..02028844.

Blocker p01|p03: the merged file loses the outside witness for `g_0209FD10`
(`unresolved: 0209FD10 (data, from header) has no witness outside 020263B0..02028846`).
The only references to that address are inside the range, so the verifier cannot attest the
pool word. The code itself is the same; this is the verifier's data-witness rule only.
