/*
 * function: func_021FB5C4
 * address: 0x021FB5C4
 * packet: pkt_ov186_021FB5C4
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_02025A54 0x02025A54 thumb
 */
extern void func_0204B6F4(void *,unsigned char,unsigned);
extern void func_02025A54(unsigned char *,unsigned char);
void func_021FB5C4(char *p,int n) { func_0204B6F4(*(void **)p,n,0);func_02025A54(*(unsigned char **)(p+4),n+1); }
