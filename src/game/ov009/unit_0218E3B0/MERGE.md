# unit_0218E3B0 (ov009)

All parts verify byte-exact on their own. Greedy merging of adjacent parts (type policies rename/first/last, both function orders) stops at:

- unit_0218E3B0_p02.c with the part before it: CCERR: line 289: illegal implicit conversion from 'char *' to | line 289: 'const unsigned char *
- unit_0218E3B0_p03.c with the part before it: CCERR: line 206: illegal implicit conversion from 'struct GPIBuffer *' to | line 206: 'struct GPIMessage *
- unit_0218E3B0_p04.c with the part before it: CCERR: line 300: illegal implicit conversion from 'struct GPIMessage *' to | line 300: 'struct GPIBuffer *
- unit_0218E3B0_p05.c with the part before it: CCERR: line 148: struct/union/enum/class tag 'GPIConnection' redefined | line 162: undefined identifier 'GPICallback' | line 164: undefined identifier 
- unit_0218E3B0_p06.c with the part before it: CCERR: line 321: 'state' is not a member of class 'struct ' | line 322: 'ip' is not a member of class 'struct ' | line 323: 'port' is not a member of c
- unit_0218E3B0_p07.c with the part before it: CCERR: line 137: illegal implicit conversion from 'struct GPIPeer *' to | line 137: 'struct  *

Parts: unit_0218E3B0_p01.c, unit_0218E3B0_p02.c, unit_0218E3B0_p03.c, unit_0218E3B0_p04.c, unit_0218E3B0_p05.c, unit_0218E3B0_p06.c, unit_0218E3B0_p07.c

Causes are conflicting local struct views of one object (different field names or offsets per member), prototypes that differ between members, or c99=DIFF. A later struct pass has to unify them.
