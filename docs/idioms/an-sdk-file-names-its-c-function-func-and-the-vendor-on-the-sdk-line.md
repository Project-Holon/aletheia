# An SDK file names its C function `func_XXXXXXXX` and puts the vendor name on the `sdk:` line

summary: a pending/overlay SDK source whose C function is named with the
vendor's own identifier still compiles, but `match.py one --func
func_XXXXXXXX` fails with "function 'func_XXXXXXXX' not found in tu.o; object
defines: ... MBi_ChildCallback"; the C identifier must be `func_XXXXXXXX` and
the vendor name belongs only on the `sdk:` header line, which is the spelling
`manifest` keys off.

Found in: src/pending/ov_sdk/ov107_func_021F4EFC.c (0x021F4EFC)

An SDK row can carry the vendor's real symbol name in its header:

```
 * function: func_021F4EFC
 * sdk: MBi_ChildCallback (libmb.TWL.HYB.a mb_wm_base.o).
```

`function:` names the C function the harness extracts; the extractor looks for
that exact identifier in the object. If the source instead declares

```c
static void MBi_ChildCallback(void *arg) { ... }
```

then `match.py one --func func_021F4EFC` reports

    function 'func_021F4EFC' not found in tu.o; object defines:
        $a, $d, MBi_ChildCallback

because the object exports the vendor name, not the packet name. The fix is
mechanical: rename the definition to `func_021F4EFC`, replace any self-reference
(the `WM_StartConnectEx(func_021F4EFC, ...)` callback argument here), keep the
vendor spelling only on the `sdk:` line. This is the same convention the
address-bearing-name rule in
`only-func-and-sub-names-carry-an-address-by-convention.md` rests on: only
`func_`/`sub_` names are special, and here it also decides what the compiler
emits for the self-reference - a vendor-named static is the wrong symbol.
