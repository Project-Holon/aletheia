/*
 * function: func_021B9C90
 * address: 0x021B9C90
 * packet: pkt_ov133_021B9C90
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_021B9C08 0x021B9C08 thumb ov133
 *   func_0201ED04 0x0201ED04 thumb
 */
extern void *func_0201EC64(unsigned int); extern void func_0201EEF4(void *,unsigned int,void *); extern void func_021B9C08(unsigned char *,unsigned int,void *); extern void func_0201ED04(void *);
void func_021B9C90(unsigned char *p) {void *r=func_0201EC64(*(unsigned short *)p);func_0201EEF4(r,0,*(void **)(*(unsigned char **)(*(unsigned char **)(p+4)+4)+4));func_021B9C08(p,0,r);func_0201ED04(r);}
