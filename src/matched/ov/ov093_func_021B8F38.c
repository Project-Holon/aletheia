/*
 * function: func_021B8F38
 * address: 0x021B8F38
 * packet: pkt_ov093_021B8F38
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B86C8 0x021B86C8 thumb ov093
 *   func_021B86B8 0x021B86B8 thumb ov093
 */
extern int func_021B86C8(unsigned char *);
extern void *func_021B86B8(void ***p);
int func_021B8F38(unsigned char *p) { unsigned int v; if(func_021B86C8(p)) { v=(unsigned int)func_021B86B8((void ***)p); if(v!=1 && v!=0) return 1; } return 0; }
