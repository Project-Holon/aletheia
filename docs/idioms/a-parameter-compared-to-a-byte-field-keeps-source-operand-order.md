# A parameter compared with a byte field keeps source operand order

summary: A one-byte cmp operand swap in a parameter-versus-byte-field equality can follow the expression operand order directly. Put the parameter first when the image compares its entry register against the field's scratch register.

Found in: src/matched/ov/ov093_func_021B9090.c (0x021B9090), src/matched/ov/ov093_func_021B90BC.c (0x021B90BC)

Both wrappers first test the byte at offset 0x23 of their pointed-to object, then compare the second parameter in r1 with the byte at offset 0x46c of the wrapper object. `p[0x46c] == k` gave DIFF with exactly one concrete byte wrong: `cmp r5,r1` instead of `cmp r1,r5`. `k == p[0x46c]` gave EXACT in both wrappers, with the same extent, register allocation and resolved call relocations under dsi/1.1p1 -O4,p c99.

This differs from the named call-result idiom: neither comparison operand here is a call result, and no temporary is needed. The change preserves the byte read, equality condition and call behavior.
