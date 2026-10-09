# field_g3dobj (ov021)

Two parts remain, both EXACT (was 3). Round 5 (r5s08): the 16-byte stub at 021C6068
(`adds r2,r0; adds r0,r1; adds r1,r2; ldr r3; movs r2,#0xff; bx r3`) is the hidden function
func_021C6068 (`return func_021C6078(b, a, 0xff);`); it closed the old p01|p02 gap and the old p01 and p02 are now one file.

Remaining boundary p01|p02 (at func_021C6658):
- The element and manager objects have about fifteen local views (Elem_021C6400 .. Elem_021C69B4,
  Mgr_021C6470 etc., all views of one 0x68-byte element and a 0x2C-byte item). func_021C6470 and
  func_021C6590 reach the item through u8 * with 0x2C strides and pass it to prototypes that take
  S * and Elem_021C69B4 *. Casts at the calls change the bytes; it needs one canonical
  Elem / Item / Mgr struct and the callers rewritten against it.
