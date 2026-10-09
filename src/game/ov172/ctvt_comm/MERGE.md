# ctvt_comm (ov172)

Translation unit 021B77E8..021BA174. Five parts, each byte-exact. Part boundaries left:

- p01 | p02 | p03: p02 is one ARM function (021B7B5C); p01 and p03 are Thumb. Real file boundaries.
- p03 | p04: p04 is one ARM function (021BA014) between Thumb parts. Real boundary.

Hidden functions added to p03: func_021B8118, func_021B811C, func_021B8120, func_021B8B20
(gap code between neighbouring functions).
