# field_flash (ov021)

Two parts, both EXACT (was 9). p01 holds the old p01..p08, p02 starts at func_021C7FB4.
- p01|p02: the local struct Q is Q_021C6E5C in p01 and Q_021C7FB4 (f0, f4) in p02; Obj_021C6E5C has no
  fA/fC/f18 members in one view while func_021C7C10 writes them; Vec and VecFx32 are two views of one
  12-byte vector (func_0207CA00, func_0207CCA4, func_0207C9D0 take both). Needs one canonical Obj, Q and Vec.