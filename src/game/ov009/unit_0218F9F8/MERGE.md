# unit_0218F9F8 (ov009)

All parts verify byte-exact on their own. Greedy merging of adjacent parts (type policies rename/first/last, both function orders) stops at:

- unit_0218F9F8_p02.c with the part before it: CCERR: line 42: undefined identifier 'GPIBuddyStatus' | line 43: undefined identifier 'GPIBuddyStatusInfo' | line 61: identifier 'GPIBuddyStatus' redec
- unit_0218F9F8_p03.c with the part before it: CCERR: line 68: struct/union/enum/class tag 'GPIProfile' redefined | line 80: struct/union/enum/class tag 'GPIConnection' redefined | line 150: 'profil
- unit_0218F9F8_p04.c with the part before it: CCERR: line 57: struct/union/enum/class tag 'GPIProfile' redefined | line 188: 'profileid' is not a member of class 'struct GPIConnection' | line 206: 
- unit_0218F9F8_p05.c with the part before it: CCERR: line 105: 'b8' is not a member of class 'struct GPIProfile' | line 109: expression syntax error | line 110: expression syntax error
- unit_0218F9F8_p06.c with the part before it: CCERR: line 95: struct/union/enum/class tag 'GPIProfile' redefined | line 247: 'numBlocked' is not a member of class 'struct GPIConnection' | line 284:

Parts: unit_0218F9F8_p01.c, unit_0218F9F8_p02.c, unit_0218F9F8_p03.c, unit_0218F9F8_p04.c, unit_0218F9F8_p05.c, unit_0218F9F8_p06.c

Causes are conflicting local struct views of one object (different field names or offsets per member), prototypes that differ between members, or c99=DIFF. A later struct pass has to unify them.
