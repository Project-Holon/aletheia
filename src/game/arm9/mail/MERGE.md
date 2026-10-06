# mail (arm9)

Parts _p01.._p04 verify EXACT. Blockers (lane 20):
- macro BLOCK_ID defined differently in neighbouring parts (rename or unify to one definition);
- struct Sub02008F80Entry incomplete in one part and complete in the next (one definition needed);
- signed char * vs unsigned char * argument type differences at later parts.

- `sub_02008AEC.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `unit_02009110.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.
