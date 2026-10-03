/*
 * function: func_021D8790
 * address: 0x021D8790
 * packet: pkt_ov123_021D8790
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203CD98 0x0203CD98 arm
 *   func_021B99DC 0x021B99DC thumb ov114
 *   func_021B9790 0x021B9790 thumb ov114
 *   func_021B97F4 0x021B97F4 thumb ov114
 *   func_02082D44 0x02082D44 arm
 *   func_021D6E08 0x021D6E08 thumb ov123
 *   func_021D8650 0x021D8650 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D83A4 0x021D83A4 thumb ov123
 */
extern int func_0203CD98(void);
typedef unsigned char  u8;
extern int func_021B99DC(u8 *p);
extern int func_021B9790(u8 *p);
extern char *func_021B97F4(void *);
extern void func_02082D44(const void *,void *,unsigned int);
extern int func_021D6E08(char *,int);
extern void func_021D8650(char *,int,char *);
extern void func_021D6EE0(char *,int,int);
extern void func_021D83A4(char *p);
void func_021D8790(char *p)
{
    char *q;
    if (func_0203CD98()) {
        if (func_021D6E08(p,func_021B99DC(*(void **)(p+0x10)))) return;
        if (func_021B9790(*(void **)(p+0x10))) return;
        q=func_021B97F4(*(void **)(p+0x10));
        func_02082D44(q+0x80,*(char **)(p+0x20)+0xc,0x44);
        *(int *)(*(char **)(p+0x20)+0x50)=1;
        func_021D8650(p,*(unsigned short *)(q+0x80),q);
    } else {
        func_021D6EE0(p,(int)func_021D83A4,0x7d4);
    }
}
