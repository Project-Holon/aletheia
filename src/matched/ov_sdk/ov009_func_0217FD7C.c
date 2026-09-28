/*
 * function: func_0217FD7C
 * address:  0x0217FD7C
 * packet:   pkt_ov009_0217FD7C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiExecuteSoap (gssoap.o)
 *
 * symbols:
 *   func_0217FDA0                  0x0217FDA0  arm ov009
 */

typedef void (*GSSoapCallback)(int, void *, void *, void *);

extern void *func_0217FDA0(char *theURL, char *theService, void *theRequestSoap, GSSoapCallback theCallbackFunc, unsigned int theTimeoutMs, void *theUserData);

void *func_0217FD7C(char *theURL, char *theService, void *theRequestSoap, GSSoapCallback theCallbackFunc, void *theUserData)
{
    return func_0217FDA0(theURL, theService, theRequestSoap, theCallbackFunc, 0, theUserData);
}
