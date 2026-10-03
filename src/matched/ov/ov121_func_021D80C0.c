/*
 * function: func_021D80C0
 * address: 0x021D80C0
 * packet: pkt_ov121_021D80C0
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8198 0x021D8198 thumb ov121
 *   func_021D8380 0x021D8380 thumb ov121
 *   func_021D849C 0x021D849C thumb ov121
 *   func_021DD980 0x021DD980 thumb ov121
 *   func_021DD1FC 0x021DD1FC thumb ov121
 *   func_021DA8B8 0x021DA8B8 thumb ov121
 */
extern void func_021D8198(char *),func_021D8380(char *),func_021D849C(char *),func_021DD980(char *);
extern void func_021DD1FC(void **);
extern void func_021DA8B8(void *);
void func_021D80C0(void *p,int n,char *q) {
 func_021D8198(q);func_021D8380(q);func_021D849C(q);
 if(*(char **)q) {func_021DD980(*(char **)q);func_021DD1FC(*(void ***)(q+4));}
 func_021DA8B8(p);
}
