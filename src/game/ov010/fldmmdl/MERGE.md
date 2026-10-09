# fldmmdl (ov010)

Round 7 (lane s10): 9 parts to 8. Old p08+p09 merged EXACT: func_0216E39C was a goto stand-in with int arguments, now typed C `void func_0216E39C(const char *ctx, u32 id, u8 *w)`; its two callers (p04, p08) pass typed arguments.

Boundaries left (current pair errors, new numbering):
- p01|p02: struct Work_0216C2FC against Work_0216BF38 / Work_0216C270 (one object, different field sets): one struct with the union of the fields.
- p02|p03: int passed where unsigned int * is expected (line in merged file ~1417).
- p03|p04: unsigned char * against int; two anonymous struct views.
- p04|p05, p05|p06: int where void * is expected; `void` result used as char *.
- p06|p07: void * against int; int * against a const anonymous struct pointer.
- p07|p08: p08's func_0216E114 is a goto stand-in that calls func_0216DA88 and func_0216D744 with one argument while p07/p06 define them with 4 and 2 parameters (stale registers; needs a K&R view); func_0216DD1C is passed Rec_0216E0E8 ** against Rec_0216D9A0 ** (same record, two struct names).
