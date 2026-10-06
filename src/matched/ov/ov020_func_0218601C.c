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
typedef unsigned char  u8;
struct Big;
struct BigObj;
extern void *func_02012EBC(struct Big *p);
extern void *func_0201AD0C(void *sys);
extern u8 func_02012984(const struct BigObj *p);
extern char *func_02008B14(int);
typedef unsigned int   u32;
extern int func_0216A358(int a, int b, u32 *p, int c);
void func_0218601C(int p) { int a; int b; int c; a=(int)func_02012EBC((struct Big *)p); b=(int)func_0201AD0C((void *)a); c=func_02012984((const struct BigObj *)p); func_0216A358(p,b,(u32 *)(func_02008B14(a)+0x14),c); }
