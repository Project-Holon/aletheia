/*
 * function: func_021D6064
 * address: 0x021D6064
 * packet: pkt_ov131_021D6064
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020173E8 0x020173E8 thumb

 */
extern void *func_020185F0(void *);
extern void *func_0201AB28(void *, int);
extern int func_020173E8(void);
void *func_021D6064(unsigned char *p) {
 switch((*(unsigned char **)(p+8))[12]) {
 case 0: return func_020185F0(**(void ***)(p+8));
 case 1: return func_020185F0(func_0201AB28(**(void ***)(p+8),*(unsigned short *)(p+24)));
 case 2: return (unsigned char *)**(void ***)(p+8)+func_020173E8()* *(unsigned short *)(p+24);
 default: return 0;
 }
}
