/*
 * function: func_021F4ED8
 * address: 0x021F4ED8
 * packet: pkt_ov194_021F4ED8
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F4DD8 0x021F4DD8 thumb ov194
 *   func_021F4F10 0x021F4F10 thumb ov194
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 func_021F4DD8(const u16 *);
extern int func_021F4F10(const u16 *,const u16 *);
u16 func_021F4ED8(const char *p,const u16 *b) {int n=func_021F4DD8((const u16 *)p);int i;for(i=0;i<n;i++){if(func_021F4F10((const u16 *)(p+2+i*24),b))return i;}return 65535;}
