# camera_system (ov172)

Translation unit 021B6100..021B6A00. Three parts, each byte-exact. ARM and Thumb share one file with
`#pragma thumb off` / `#pragma thumb on` around the ARM asm veneers (prototypes and bodies both).

Open boundaries:
- p01 | p02 at 021B6390: the Thumb function 021B6338 ends at 021B638E and the tool fills the 2-byte gap
  before the ARM function with 00 00, the original image has a Thumb nop (C0 46) there. Same at
  p02 | p03 (021B6950 to 021B6974). The code itself is exact; only these two alignment bytes differ.
