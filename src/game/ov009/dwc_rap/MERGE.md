# dwc_rap (ov009): 9 parts left (was 30)

Round 5 (r5s03): one canonical struct DwcRapWork (0x7AC bytes, the block d_021A8264 points to)
replaced the ~40 views in old parts 04..17, 21, 23, 25, 27. Old parts 01..18 (with the
hidden functions) merged into dwc_rap_p01.c (MATCH: the stub func_02155330 jumps to
func_02156DB0, which has no independent witness inside p01). Old p18 keeps its own local
struct view (merge tool renamed it): convert it too.
Hidden functions added (all in p01): func_02155234 (4-arg forwarder to func_0215568C, so
func_0215568C now takes an unused 4th parameter a3), func_0215523C (tail call to
func_02156888), func_0215528C (tail call to func_02155388), func_02155330 (tail call to
func_02156DB0). The old p14|p15 gap (0x02155D3A..3C) is two bytes of Thumb padding only.

Left (new numbering; old numbers in brackets):
- p02 [19,20,21]: p19 part still has its own struct views (cb, aid, cnt, b79f); convert with
  scratchpad r5s03/conv.py (fields cb28C/cb294 exist in the struct).
- p03 [22]: raw offset code with pointer arithmetic (g + 0x34c + i * 32, (g + i)[0x32c]):
  use d->ent[i] and d->bytes[i].
- p04 [23]: (int)((char *)(int *)g + 0x34C + (i << 5)).
- p05 [24]: G_02156888 and G_02156A3C views (retry -> cnt[0], f750 -> w750); naive conversion
  gives DIFF, needs a careful field-by-field rewrite (cb29C is void(*)(int,int)).
- p06 [25,26,27]: verifies; old p26 and p27 also still have local views.
- p07 [28]: the volatile off2 trick around arr/arr2 (0x17c/0x1fc) in func_02156CF4.
- p08 [29]: int *g_021A8264 view and struct Obj at d_021A8268.
- p09 [30]: d_021A8268 struct Obj (separate global; merges with p08 only).
Canonical struct text: scratchpad r5s03/conv.py (STRUCT), driver go.py, installer inst.py.
d_021A8264_obj stays a separate extern alias of the same address: merging it into
&d_021A8264 changes the literal pool order (DIFF).