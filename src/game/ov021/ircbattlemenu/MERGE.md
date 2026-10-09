# ircbattlemenu: merge status

Parts are in address order; the greedy pass (tools/restructure.py merge, verified EXACT)
joined every neighbour that compiles. 15 parts remain. Every remaining boundary fails
for one of these reasons:

- A function declared with different prototypes in different parts (extern with
  different pointer or u32 parameter types, or a part's extern against the definition
  in another part). Fix: one prototype per function (the definition's) and casts at calls.
- A local type name (Obj, Sub, Elem, Cam, Rec, Mgr, Inner, Outer, Rect4) used for
  different objects in different parts. restructure.py renames them Name_ADDR, which
  then breaks calls across the boundary. Fix: one canonical struct per object, built
  from all views (offsets checked), applied to every part.

Work list: run scratchpad ol022/protos.py <tu> to list the conflicting prototypes,
then ol022/go.py (REG=ov021 python go.py <tu> apply) after each canonicalisation.

Round 3 check (r3_ov06): no boundary of this TU has uncovered code before it (no bx lr or tail-call stub words), so every remaining boundary is a struct or prototype conflict, not a hidden function.
