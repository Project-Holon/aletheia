# A scene-callback parameter takes a bare function name, and the vendor's DWARF prototype does not parse

summary: `DWCi_ChangeScene`'s DWARF prototype is `void (*)(...)`, but mwccarm
1.1p1 under `-lang c99` rejects that declarator outright (`')' expected`), and
the house spelling `extern void DWCi_ChangeScene(void (*scene)());` is the one
that compiles.  The scene target must be an `extern void <name>(void)`
*function* passed by bare name; declaring it as data and passing `&name` is the
shape the unverified drafts of the `endScene2` pair shipped.

Found in: src/matched/ov_sdk/ov016_func_021CB5D8.c (0x021CB5D8), and the
sibling static copy at 0x021CAA9C.

`scenesetrakubutt.o` ends its two `endScene2` copies with a tail that is a
`DWCi_SetParam_` call and a `DWCi_ChangeScene` call whose single argument is a
pooled ABS32:

```
021CB668  mov  r0, #2
021CB66C  mov  r1, #1
021CB670  bl   DWCi_SetParam_
021CB674  ldr  r0, [pc, #0x20]        ; 0x021CC998  DWCi_SceneSetSelectWay
021CB678  bl   DWCi_ChangeScene
```

Three things have to line up and none of them is visible in the instruction
stream, which is why the drafts got them wrong:

* **The pooled word is a function address, not a pointer variable.** Both
  `DWCi_SceneSetSelectWay` (0x021CC998) and `DWCi_SceneSetRakuButton`
  (0x021CA838) are arm text - the matched `ov016_func_021CC998.c` and
  `ov016_func_021CA838.c` are their own bodies.  Declaring them
  `extern int DWCi_SceneSetSelectWay;` and writing
  `DWCi_ChangeScene((void (*)())&DWCi_SceneSetSelectWay)` is the read of a data
  word, and it happens to produce the same pool value, so the failure is silent
  until the declarations are corrected.  Declare the function and pass its name.
* **The symbol name is not the relocation label.** The reloc records
  `DWCi_SceneSetRakuButton1`; the symbol it resolves to is spelled
  `DWCi_SceneSetRakuButton`.  Use the symbol spelling or the ABS32 goes
  unresolved and the run drops to MATCH.
* **`void (*)(...)` is a DWARF-only spelling.** Written into the source it is
  a hard CCERR, and the two follow-on errors
  (`illegal implicit conversion from 'void ()' to 'void (*)(...)'`, one per call
  site) name a type the front end never built.  `void (*scene)()` is the same
  parameter to this compiler and byte-identical in the output.

What the drafts also got wrong, and the `show` listing settles immediately: the
guarded `DWCi_GXlInvisible(1, 1)` sits **inside** the `Choose == 0` arm, not
after it.  At 0x021CB5D8 the `bne` at +0x0058 skips both the
`DWCi_COMMENTlDelete` call and the `DWCi_GXlInvisible(1, 1)` pair, so the tail
of the guarded block is two calls wide:

```
021CB624  ldr  r0, [pc, #0x6c]        ; Choose
021CB62C  cmp  r0, #0
021CB630  bne  #0x21cb644
021CB634  bl   DWCi_COMMENTlDelete
021CB638  mov  r0, #1
021CB63C  mov  r1, r0
021CB640  bl   DWCi_GXlInvisible      ; (1, 1) - inside the guard
021CB644  mov  r4, #0                 ; the pooled zero, not hoisted
```

That `mov r4, #0` reads like the pooled-constant wall in
`a-repeated-small-constant-takes-a-callee-saved-register.md`, and it is not:
the zero is not live at entry, and the two literal `0` arguments
(`DWCi_GXlInvisible(0, 0x15)` and `DWCi_SetParam_(0, 0)`) pool into `r4` on
their own.  No named local, no `int z = 0;` - the plain literal spelling is
EXACT at 204 bytes with all 16 relocations resolved.
