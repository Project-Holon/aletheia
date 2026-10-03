/*
 * function: func_021C4A98
 * address: 0x021C4A98
 * packet: pkt_ov127_021C4A98
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
char *func_021C4A98(unsigned *p)
{
 unsigned i=0;
 if (i<p[1]) { char *base=(char *)p[0];
 do { if (*(unsigned *)(base+i*24)==0) return base+i*24; i++; } while(i<p[1]); }
 return 0;
}
