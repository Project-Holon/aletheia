# union_comm (ov012)

Round 4 (r4_ov04): 9 parts -> 7. Hidden functions added: func_021733C4, func_021733C8, func_02173400, func_02173404 (p06) and func_02173D7C (p07). Old p06+p07 and p08+p09 merged.

Left: p01..p05 are separated by struct views of one object (pair merges tried, each stops on pointer type conflicts):
- p01|p02: Work_0 vs the unnamed struct returned by func_02172BC0
- p02|p03: func_0217303C argument struct
- p03|p04: Entry_02172EDC vs Entry_021730F8 (func_021730C8)
- p04|p05: Entry_021730F8 vs Entry_021731E0 (func_021731E0)
- p05|p06: Rec_02173248 vs Rec (func_0217325C)
- p06|p07: Work_021734E0 vs unnamed struct (func_021734E0); func_02082BCC has two prototypes
A single canonical struct per object, by offset, is the next step.
