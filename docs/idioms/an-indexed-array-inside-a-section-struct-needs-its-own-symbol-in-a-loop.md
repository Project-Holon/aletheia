# An indexed array inside a section struct needs its own symbol when a loop indexes it

summary: with an object's statics modelled as one struct per section, a loop over a member
array at a non-zero offset hoists the section base and emits `add rX, base, i` /
`ldrb rY, [rX, #off]`; when the original loads `ldrb rY, [rT, i]` from a pool word that
names the member's own symbol, declare that member as its own extern at its vendor address.

Found in: src/matched/ov016_func_021C5388.c (0x021C5388, getCharName in scenesetaplist.o)

getCharName walks CELL_WEP (section offset 0) and CELL_LV (offset 3). The pool holds
`CELL_WEP` and `CELL_LV` as two words, and the second loop is `ldrb r1, [r4, r6]` with r4 =
CELL_LV. `scenesetaplist_rodata.CELL_LV[i]` (or `*(p->CELL_LV + i)`, or
`(&p->CELL_LV[0])[i]`) keeps one pool word for the section and adds `#3` in the load. The
vendor symbol is real (`CELL_LV` is its own entry in the object's symtab), so

```c
extern const unsigned char CELL_LV[4];   /* 0x021DA51F, scenesetaplist_rodata + 3 */
```

is honest and closes it. Non-loop accesses to members at an offset (`R_FOCUS[Focus].l`)
still fold into per-field pool words through the struct and need nothing. keyboard.o's
DWCi_KBlInit loads CN_SKEY and CN_BTN the same way.
