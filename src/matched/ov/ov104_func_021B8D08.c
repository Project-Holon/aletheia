/*
 * function: IRC_RHYTHM_InitParticle
 * address: 0x021B8D08
 * packet: pkt_ov104_021B8D08
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 */
extern void MI_CpuFill8(void *,unsigned char,unsigned int);
void IRC_RHYTHM_InitParticle(unsigned int *p, unsigned int a, int b) { MI_CpuFill8(p,0,44); p[0]=a; p[1]=b; }
