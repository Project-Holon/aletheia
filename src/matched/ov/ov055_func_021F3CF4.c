/*
 * function: CROWD_UpdatePerson
 * address: 0x021F3CF4
 * packet: pkt_ov055_021F3CF4
 * region: ov055
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gCrowdPersonUpdateFuncs 0x021F45C0 data a4
 */
extern void (*gCrowdPersonUpdateFuncs[])(unsigned char *,unsigned int,unsigned int);
void CROWD_UpdatePerson(unsigned char *p, int a, int b) { if (p[0]) gCrowdPersonUpdateFuncs[p[2]](p,a,b); }
