/*
 * function: func_02162478
 * address: 0x02162478
 * packet: pkt_ov010_02162478
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02162F0C 0x02162F0C thumb ov010
 */
typedef unsigned short u16;
extern int func_02162F0C(char *, int *);
int func_02162478(char *p, int *v) { char *r=*(char **)(p+0x28); u16 n,i; if(r) { n=*(u16 *)(p+0x18); for(i=0;i<n;i++,r+=22) { if(func_02162F0C(r,v) && *(u16 *)(r+6)==6) return 1; } } return 0; }
