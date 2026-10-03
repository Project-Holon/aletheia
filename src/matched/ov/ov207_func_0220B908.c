/*
 * function: func_0220B908
 * address: 0x0220B908
 * packet: pkt_ov207_0220B908
 * region: ov207
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
struct Descriptor;struct Cfg;extern void func_0201F73C(void *,int,unsigned short,int);extern void func_02045334(struct Descriptor *);extern void func_02045374(struct Cfg *);extern unsigned char func_02045730(struct Descriptor *);extern void func_02041B6C(unsigned);
void func_0220B908(char *p){if(!*(unsigned *)(p+60)){struct Descriptor *d;unsigned flag=1;func_0201F73C(*(void **)(p+36),1,*(unsigned *)(p+48),8);d=*(struct Descriptor **)(p+36);func_02045334(d);func_02045374((struct Cfg *)d);func_02041B6C(func_02045730(d));*(unsigned *)(p+60)=flag;}}
