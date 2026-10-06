# unit_0207C9D0.c (arm9)

Three parts remain (`_p01`, `_p02`, `_p03`).
`_p02` (func_0207CCA4, func_0207CDB8) defines reg_CP_SQRT_PARAM and the CP_DIV/CP_SQRT registers without `volatile`
(`*(u64 *)`), the other parts with `volatile u64`. Making `_p02` volatile changes its bytes (DIFF), so the
register macros and the static inline helpers (CP_SetSqrt64 etc.) cannot share one definition. Needs a struct/reg
pass that finds the one spelling every function accepts.
