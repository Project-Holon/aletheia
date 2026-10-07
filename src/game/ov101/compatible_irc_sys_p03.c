/*
 * file:     compatible_irc_sys_p03.c
 * unit:     yes
 * function: func_021B66A4, func_021B66B8
 * address:  0x021B66A4
 * region:   ov101
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039338 0x02039338 arm
 *   func_02082D44 0x02082D44 arm
 */
struct Entry;
extern struct Entry *func_020399A8(void);
extern unsigned short func_02039338(void);
extern void func_02082D44(void *,const void *,unsigned);
void func_021B66A4(int a,int b,int c,int *d,unsigned e);
void func_021B66B8(unsigned a,int b,void *c,unsigned char *d,unsigned e);

void func_021B66A4(int a,int b,int c,int *d,unsigned e) { if(e==(unsigned)func_020399A8()) d[28]=1; }

void func_021B66B8(unsigned a,int b,void *c,unsigned char *d,unsigned e) { if(e==(unsigned)func_020399A8()) { if(a!=func_02039338()) func_02082D44(c,d+0x3c,4); } }
