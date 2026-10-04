/*
 * function: func_021D73D8
 * address: 0x021D73D8
 * packet: pkt_ov123_021D73D8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203CD98 0x0203CD98 arm
 *   func_021B95D4 0x021B95D4 thumb ov114
 *   func_021B973C 0x021B973C thumb ov114
 *   func_021B9748 0x021B9748 thumb ov114
 *   func_021BE79C 0x021BE79C arm ov114
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D7390 0x021D7390 thumb ov123
 */
extern int func_0203CD98(void);
typedef unsigned char  u8;
extern int func_021B95D4(int index, u8 *p);
extern int func_021B973C(char *p);
extern int func_021B9748(u8 *p);
extern int func_021BE79C(void *handle, void *value_p, unsigned long length);
extern void func_021D6EE0(char *,int,int);
extern void func_021D7390(char *);
void func_021D73D8(char *p)
{
    if (*(int *)(p+0x78)) {
        --*(int *)(p+0x78);
        return;
    }
    if (func_0203CD98()) {
        if (func_021B95D4(8,*(void **)(p+0x10))) {
            p[2]=1;
            p[3]=0;
            func_021BE79C((void *)func_021B973C(*(void **)(p+0x10)),(void *)((unsigned int)(p+2)),4);
            if (func_021B9748(*(void **)(p+0x10))==0)
                func_021D6EE0(p,(int)func_021D7390,0x2cd);
        }
    }
}
