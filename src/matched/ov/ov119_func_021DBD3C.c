/*
 * function: func_021DBD3C
 * address: 0x021DBD3C
 * packet: pkt_ov119_021DBD3C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_2D_UpdateIconFlight 0x021E665C thumb ov119
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   func_021DBC98 0x021DBC98 thumb ov119
 *   func_021DBC3C 0x021DBC3C thumb ov119
 */
extern int POKETRADE_2D_UpdateIconFlight(char *p);
extern int POKETRADE_PROC_IsNetSession(void *);
extern void POKETRADE_PROC_SetStep(void *, int);
extern void func_021DBC98(char *p);
extern void func_021DBC3C(char *p);
void func_021DBD3C(char *p)
{
    if (POKETRADE_2D_UpdateIconFlight(p)) {
        if (POKETRADE_PROC_IsNetSession(p)) {
            POKETRADE_PROC_SetStep(p, (int)func_021DBC98);
            return;
        }
        POKETRADE_PROC_SetStep(p, (int)func_021DBC3C);
    }
}
