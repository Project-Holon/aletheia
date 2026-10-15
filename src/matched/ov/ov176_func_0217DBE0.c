/*
 * function: DIGITALCARDCHECK_Phase6,DIGITALCARDCHECK_EndPhase
 * unit: yes
 * address: 0x0217DBE0
 * packet: pkt_ov176_0217DBE0
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_ClearCallback 0x021E8AA8 thumb ov177
 *   LIVEBATTLEMATCH_IRC_SetMenuValue 0x0217DFD0 thumb ov176
 *   LIVEBATTLEMATCH_IRC_GetMenuValue 0x0217DFE4 thumb ov176
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 *   DIGITALCARDCHECK_EndPhase 0x0217DC20 thumb ov176
 */
extern void LIVEBATTLEMATCH_IRC_SetMenuValue(int *, int, int);
extern int LIVEBATTLEMATCH_IRC_GetMenuValue(int *);
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *p, int v);
extern void DIGITALCARDCHECK_EndPhase(int);
extern void WIFIBATTLEMATCH_UTIL_ClearCallback(int);
void DIGITALCARDCHECK_Phase6(int a, int *state, int *p)
{
    switch (*state) {
    case 0:
        LIVEBATTLEMATCH_IRC_SetMenuValue(p, 0x6F, 1);
        *state = 1;
        break;
    case 1:
        if (LIVEBATTLEMATCH_IRC_GetMenuValue(p))
            *state = 2;
        break;
    case 2:
        WIFIBATTLEMATCH_UTIL_SetCallback((int *)a, (int)DIGITALCARDCHECK_EndPhase);
        break;
    }
}
void DIGITALCARDCHECK_EndPhase(int a) { WIFIBATTLEMATCH_UTIL_ClearCallback(a); }
