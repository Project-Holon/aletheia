# field_g3dobj (ov021)

Three parts remain, every one EXACT.

- p01 | p02: c99=DIFF (merging changes the code; real unit boundary candidate).
- p02 | p03: the element and manager objects have about fifteen local views
  (Elem_021C6400 .. Elem_021C69B4, Mgr_021C6470 etc., all views of one 0x68-byte
  element and a 0x2C-byte item). func_021C6470 and func_021C6590 reach the item
  through u8 * with 0x2C strides and pass it to prototypes that take S * and
  Elem_021C69B4 *. Casts at the calls change the bytes; it needs one canonical
  Elem / Item / Mgr struct and the callers rewritten against it.
