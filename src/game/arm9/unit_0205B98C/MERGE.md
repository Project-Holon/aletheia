# unit_0205B98C (arm9)

Parts _p01.._p06 each verify EXACT. Greedy merge (lane 20) joined only some neighbours; blockers left:
- p01 + next: 'phase' undefined / opaque struct view vs the full ACHOLD/ACWORK definitions.
- p03/p05: struct tag 'tagACWORK' redefined, partial views (userInfo, fieldC) of the same work struct; unify to the full ACWORK (see unit_0205B33C.c for the offset-checked full layout).
- p06/p07 (last): ACHOLD undefined in the earlier part's scope.
Next step: one ACHOLD/ACWORK pair of structs for the whole TU (offsets agree with unit_0205B33C.c and unit_0205D0E4.c), then append the parts in address order.
