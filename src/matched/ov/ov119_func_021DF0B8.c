/*
 * function: func_021DF0B8
 * address: 0x021DF0B8
 * packet: pkt_ov119_021DF0B8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Second loop accesses use p+i*4+0xfe4, keeping the offset in r7 rather than hoisting p+0xfe4.
 * symbols:
 *   func_02156E24 0x02156E24 thumb ov009
 *   func_02156DC4 0x02156DC4 thumb ov009
 *   func_0200853C 0x0200853C thumb
 *   func_021B9800 0x021B9800 thumb ov114
 *   func_021B98A0 0x021B98A0 thumb ov114
 *   func_021B98D8 0x021B98D8 thumb ov114
 *   func_021B98F8 0x021B98F8 thumb ov114
 *   func_021B9748 0x021B9748 thumb ov114
 *   func_021D89EC 0x021D89EC thumb ov119
 *   func_020173EC 0x020173EC thumb
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DEEFC 0x021DEEFC thumb ov119
 *   func_021DEF1C 0x021DEF1C thumb ov119
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_02156E24(int,int,int);
extern void func_02156DC4(int,void *);
extern int func_0200853C(void *);
extern u8 *func_021B9800(int,int,int);
extern void func_021B98A0(u8 *,int,int,int);
extern void func_021B98D8(u8 *,int,int);
extern int func_021B98F8(u8 *);
extern int func_021B9748(u8 *);
extern int func_021D89EC(void *);
extern int func_020173EC(void);
extern void func_021D8E84(void *,int);
extern void func_021DEEFC(void *);
extern void func_021DEF1C(void *);
void func_021DF0B8(char *p) {
 int n=0;
 int i;
 func_02156E24(13,0x10000,*(u16 *)(p+0x5f4));
 *(u8 **)p=func_021B9800(*(u16 *)(p+0x5f4),func_0200853C(*(void **)(p+0x830)),*(int *)(*(char **)(p+8)+0x24));
 func_02156DC4((int)func_021DEEFC,p);
 for(i=0;i<3;i++) if(func_021D89EC(*(void **)(p+0xfe4+i*4))) n++;
 func_021B98A0(*(u8 **)p,*(u16 *)(p+0x5f4),func_020173EC()*n,2);
 for(i=0;i<3;i++) if(func_021D89EC(*(void **)(p+i*4+0xfe4))) func_021B98D8(*(u8 **)p,*(int *)(p+i*4+0xfe4),func_020173EC());
 func_021B98F8(*(u8 **)p);func_021B9748(*(u8 **)p);func_021D8E84(p,(int)func_021DEF1C);
}
