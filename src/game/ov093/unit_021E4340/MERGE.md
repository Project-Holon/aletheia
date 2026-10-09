# unit_021E4340 (ov093)

Translation unit 021E4340..021E4754, split into 2 parts.

- `unit_021E4340_p01.c`: 021E4340..021E4738 (all matched functions and hidden setters).
- `unit_021E4340_p02.c`: the hidden setter at 0x021E4748.

Unmatched code: an ARM interworking veneer at 0x021E4738 (12 bytes: thumb
`bx pc`, `mov r8, r8`, then ARM `ldr ip, [pc]`, `bx ip`, literal word) sits
between the parts. No function covers it, so it is a file boundary. If the
veneer is ever matched, merge the two parts.
