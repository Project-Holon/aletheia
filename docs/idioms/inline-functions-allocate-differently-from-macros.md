# Inline helper functions colour registers differently from the same code as macros

summary: when a hot expression (a rotate, the MD5 F/G/H/I functions, a MIN) comes out right instruction by instruction but with registers permuted and loops recoloured, write it as a `static inline` function instead of a macro. The inlined parameters become their own variables and change allocation order. When the argument is volatile, an inline function also reads it once where a macro reads it twice.

Found in: src/matched/ProcessBlock.c (0x02080D68), src/matched/NVRAMi_WriteCallback.c (0x020839E8)

ProcessBlock (MD5) as macros compiled to 956 B, one instruction long (an `ldm` of
two registers instead of three), with every register renamed. Permuting all
720 declaration orders did not fix it. A `static inline` ROTATE_LEFT brought
it to 952 B, 190 bytes out, with rounds 3 and 4 still recoloured; making
F/G/H/I inline too gave EXACT. In NVRAMi_WriteCallback (volatile arg[3]) the
page-remainder MIN as a ternary reloads arg[1] (`ldrlo`). As an inline
`u32 Min(u32, u32)` it loads once, which matches the image's `cmp; movhs`.
