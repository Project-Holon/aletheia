# field_effect (ov021): 2 parts (was 17)

Round 10 (w10a) merged everything from 0x021A87A8 to the end into p01 (EXACT). p02 stays on purpose.

p01|p02 is a real overlap, not a type conflict. func_021A8E10 (in p01) is the whole function
`p = s->pf8; if (p == 0) return 0; return p->f8;` and its bytes run through 0x021A8E1F. The symbol
func_021A8E14 (p02) is a second entry label in the middle of those bytes. A TU that holds both
doubles the bytes (DIFF); p02 alone is EXACT. gamecheck needs the function present, so p02 stays a
separate file that is not part of any other TU compile. If a way to record a mid-function label
appears, drop p02 and name p01 field_effect.c.

Hidden functions added to p01 (gap 0x021AB474 to 0x021AB4B8, three leaf predicates on an id):
- func_021AB474: `id == 0x54 || (unsigned short)(id + 0xFFA9) <= 1`
- func_021AB490: `id == 0x52 || id == 0x56 || id == 0x58`
- func_021AB4A4: `id == 0x51 || id == 0x55 || id == 0x57`
