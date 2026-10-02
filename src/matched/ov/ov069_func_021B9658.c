/*
 * function: func_021B9658
 * address: 0x021B9658
 * packet: pkt_ov069_021B9658
 * region: ov069
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: final two bytes are alignment padding before next labelled function.
 * symbols:
 *   func_021B9E44 0x021B9E44 thumb ov069
 *   func_021B9DFC 0x021B9DFC thumb ov069
 *   func_0202CD94 0x0202CD94 thumb
 *   func_0204A600 0x0204A600 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021B9E44(u8 *p);
extern void func_021B9DFC(u8 *p);
extern void func_0202CD94(void *p);
extern void func_0204A600(void);
int func_021B9658(u32 a,u32 b,u32 c,u8 *p) { if(func_021B9E44(p)==0) return 1; func_021B9DFC(p); func_0202CD94(*(void **)(p+4)); func_0204A600(); return 0; }
