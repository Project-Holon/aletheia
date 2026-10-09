# unit_021903B0 (ov009)

All parts verify byte-exact on their own. Greedy merging of adjacent parts (type policies rename/first/last, both function orders) stops at:

- unit_021903B0_p02.c with the part before it: CCERR: line 134: illegal implicit conversion from 'int *' to | line 134: 'int' | line 139: 'nick' is not a member of class 'struct 
- unit_021903B0_p03.c with the part before it: CCERR: line 506: 'searchStartTime' is not a member of class 'struct ' | line 508: 'remove' is not a member of class 'struct ' | line 583: 'numNamespace
- unit_021903B0_p04.c with the part before it: CCERR: line 183: undefined identifier 'GPIBuffer' | line 200: undefined identifier 'u32' | line 210: undefined identifier 'GPIBool

Parts: unit_021903B0_p01.c, unit_021903B0_p02.c, unit_021903B0_p03.c, unit_021903B0_p04.c

Causes are conflicting local struct views of one object (different field names or offsets per member), prototypes that differ between members, or c99=DIFF. A later struct pass has to unify them.
