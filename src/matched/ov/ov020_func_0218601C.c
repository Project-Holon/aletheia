/*
 * function: func_0218601C
 * address: 0x0218601C
 * packet: pkt_ov020_0218601C
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02012EBC 0x02012EBC thumb
 *   func_0201AD0C 0x0201AD0C thumb
 *   func_02012984 0x02012984 thumb
 *   func_02008B14 0x02008B14 thumb
 *   func_0216A358 0x0216A358 thumb ov010
 */
extern int func_02012EBC(int);
extern int func_0201AD0C(int);
extern int func_02012984(int);
extern char *func_02008B14(int);
extern int func_0216A358(int,int,void *,int);
void func_0218601C(int p) { int a; int b; int c; a=func_02012EBC(p); b=func_0201AD0C(a); c=func_02012984(p); func_0216A358(p,b,func_02008B14(a)+0x14,c); }
