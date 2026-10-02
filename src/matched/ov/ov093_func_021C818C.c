/*
 * function: func_021C818C
 * address: 0x021C818C
 * packet: pkt_ov093_021C818C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D5444 0x021D5444 thumb ov093
 *   func_0201B718 0x0201B718 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021B9934(char *, int);
extern u16 func_021D5444(void *);
extern unsigned int func_0201B718(void *, unsigned int, unsigned int, unsigned int);
int func_021C818C(u8 *p, int v) { unsigned int species; u16 i; species=func_021D5444((void *)func_021B9934(*(char **)(p+8),v)); for(i=0;i<7;i++) { if(func_0201B718(*(void **)(p+0x4a4),species,0,i)) return 1; } return 0; }
