/*
 * function: func_021C4954
 * address: 0x021C4954
 * packet: pkt_ov127_021C4954
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
char *func_021C4954(unsigned *p, unsigned id)
{
 unsigned i=0;
 if (i<p[1]) { char *base=(char *)p[0]; char *e;
 do { e=base+i*24; if (*(unsigned *)e==1 && id==*(unsigned short *)(e+12)) return e; i++; } while(i<p[1]); }
 return 0;
}
