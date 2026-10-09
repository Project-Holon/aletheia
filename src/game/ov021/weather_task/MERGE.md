# weather_task: merge status

30 parts remain (was 32). Round 8 lane w8b ran uniq (typedef variants), unifyvec, uniqs
(plain struct tag variants) and the greedy harmonizer pass: it joined p04+p05 and p06+p07
(old numbering). Every other boundary still fails. Reasons seen in the last greedy run:

- Stand-in prototypes (u8 */u32 parameters, K&R externs such as func_021A1BDC, func_021A1C34,
  func_0216D5F8, func_021A6D9C, func_021A6DA4) against typed definitions in other parts:
  give each function its definition's prototype and fix the callers (same method as
  pdw_postman: a call that passes fewer arguments than the definition takes usually just
  leaves the register alone; add the argument the register already holds).
- void/int return mismatches (`return f(...)` of a void callee): make the caller void.
- Pure DIFF merges (p07, p11, p21 to p24, p26, p27, p31, p32 old numbering): usually a
  parameter narrowed by a prototype that is only visible in the merged file. In pdw_postman
  the fix was the callee's parameter type (u16 i became u32 i) and a plain-C rewrite of a
  goto lookup into two switch cases that load the value into a local.
- Generic struct tags (Obj, Sub, Elem, Cam, Holder) used for different objects: handled by
  uniq.py/uniqs.py renames; canonical structs by offset are still to do.

Tools used (scratchpad r8/w8b): uniq.py, uniqs.py, unifyvec.py, addv3.py, go31.py, pair2.py, auto2.sh.
