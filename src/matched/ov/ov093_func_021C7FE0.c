/*
 * function: func_021C7FE0
 * address: 0x021C7FE0
 * packet: pkt_ov093_021C7FE0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two bytes alignment padding follow.
 * ABI: original forwards full-word B8DDC/B9010 results without narrowing;
 * widen B9010 and B8B9C input declarations relative to narrow legacy sources.
 * symbols:
 *   func_021B8DDC 0x021B8DDC thumb ov093
 *   func_021B9010 0x021B9010 thumb ov093
 *   func_021B8B9C 0x021B8B9C thumb ov093
 *   func_021B9AF8 0x021B9AF8 thumb ov093
 */
typedef unsigned char u8;
extern int func_021B8DDC(u8);
extern unsigned int func_021B9010(u8 *, int);
extern int func_021B8B9C(u8 *, unsigned int);
extern char *func_021B9AF8(char *, int);
char *func_021C7FE0(u8 *p, u8 v) { unsigned int k; k=func_021B9010(*(u8 **)(p+4), func_021B8DDC(v)); if(func_021B8B9C(*(u8 **)(p+4),k)) return func_021B9AF8(*(char **)(p+8),k); return 0; }
