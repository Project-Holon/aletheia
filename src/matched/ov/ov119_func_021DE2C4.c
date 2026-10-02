/*
 * function: func_021DE2C4
 * address: 0x021DE2C4
 * packet: pkt_ov119_021DE2C4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020221A4 0x020221A4 thumb
 *   func_02040588 0x02040588 arm
 *   func_021E6440 0x021E6440 thumb ov119
 *   func_021E1CE8 0x021E1CE8 thumb ov119
 *   func_020490F4 0x020490F4 arm
 *   func_02049990 0x02049990 arm
 *   func_02049238 0x02049238 arm
 *   func_021E3208 0x021E3208 thumb ov119
 *   func_02041B6C 0x02041B6C arm
 *   func_021D8FA4 0x021D8FA4 thumb ov119
 *   func_021D89EC 0x021D89EC thumb ov119
 *   func_021D9468 0x021D9468 thumb ov119
 *   func_021DEBD4 0x021DEBD4 thumb ov119
 *   func_021DD09C 0x021DD09C thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DEA24 0x021DEA24 thumb ov119
 *   func_021D8980 0x021D8980 thumb ov119
 *   func_0202208C 0x0202208C thumb
 */
typedef unsigned short u16;
extern unsigned func_020221A4(void);
extern void func_02040588(int,int);
extern void func_021E6440(int,int,int);
extern void func_021E1CE8(void *,int);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_02049990(void *,unsigned,int,int,u16,int,int,unsigned);
extern void func_02049238(void *);
extern void func_021E3208(void *,int);
extern void func_02041B6C(int);
extern int func_021D8FA4(void *,int);
extern int func_021D89EC(void *);
extern void func_021D9468(void *,int,int);
extern void func_021DEBD4(void *),func_021DD09C(void *),func_021D8980(void *);
extern void func_021D8E84(void *,int),func_021DEA24(void *);
extern void func_0202208C(void *,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
void func_021DE2C4(char *p)
{
    void *resource;
    int zero,slot,mon;
    if(func_020221A4()) {
        zero=0;
        func_02040588(3,zero);
        func_021E6440((int)p,-1,-1);
        func_021E1CE8(p,0);
        resource=func_020490F4(102,*(u16 *)(p+0x5f4));
        func_02049990(resource,11,2,0,(u16)*(int *)(p+0x86c),zero,zero,*(u16 *)(p+0x5f4));
        func_02049238(resource);
        func_021E3208(p,0);
        func_02041B6C(3);
        p[0x11f3]=zero;
        slot=1;
        if(func_021D89EC((void *)func_021D8FA4(p,slot))) {
            mon=func_021D8FA4(p,slot);
            func_021D9468(p,slot,mon);
        }
        slot=0;
        if(func_021D89EC((void *)func_021D8FA4(p,slot))) {
            mon=func_021D8FA4(p,slot);
            func_021D9468(p,slot,mon);
        }
        func_021DEBD4(p);
        func_021DD09C(p);
        func_021D8E84(p,(int)func_021DEA24);
        func_021D8980(p);
        func_0202208C((void *)3,1,1,0,6,1,*(u16 *)(p+0x5f4));
    }
}
