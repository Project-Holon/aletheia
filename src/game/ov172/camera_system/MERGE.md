# camera_system (ov172)

Translation unit 021B6100..021B6A00. Not mergeable further: the parts alternate
between ARM and Thumb code, and p03, p07, p15 use no lang flag while the others use
c99. Each part is a separate compile unit by instruction set, so every boundary is a
real file boundary (the unit boundary guess is weak, tools/tuboundary.py).
Parts p01..p31 are in address order.

Round 5 (lane s11) re-checked the headers: p01..p31 alternate thumb/arm strictly (p03, p07, p15 have no lang), so no two
neighbours share an ISA. Nothing to merge.
