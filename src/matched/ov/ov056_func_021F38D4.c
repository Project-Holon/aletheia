/*
 * function: func_021F38D4
 * address: 0x021F38D4
 * packet: pkt_ov056_021F38D4
 * region: ov056
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0218C860 0x0218C860 thumb ov021
 *   func_0218C69C 0x0218C69C thumb ov021
 */
extern void func_0218C860(void *);
extern void func_0218C69C(unsigned char *,int,int,int);
void func_021F38D4(unsigned char *p) { if (*(void **)p) { func_0218C860(*(void **)p); func_0218C69C(*(unsigned char **)(p+8),*(int *)(p+4),0,1); func_0218C69C(*(unsigned char **)(p+8),*(int *)(p+4),0,3); *(int *)p=0; *(int *)(p+4)=0; *(int *)(p+8)=0; } }
