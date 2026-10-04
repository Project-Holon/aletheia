/*
 * function: func_021DE5C4
 * address: 0x021DE5C4
 * packet: pkt_ov119_021DE5C4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_021E12F8 0x021E12F8 thumb ov119
 *   func_021E1098 0x021E1098 thumb ov119
 *   func_0202208C 0x0202208C thumb
 *   func_021B6548 0x021B6548 thumb ov067
 *   func_021DEBD4 0x021DEBD4 thumb ov119
 *   func_021D8980 0x021D8980 thumb ov119
 *   func_021DD09C 0x021DD09C thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DE12C 0x021DE12C thumb ov119
 *   func_021DE518 0x021DE518 thumb ov119
 *   func_021DEA24 0x021DEA24 thumb ov119
 */
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct TaskMenu;
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_021E12F8(char *p);
extern void func_021E1098(char *p);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern int func_021B6548(unsigned char *p, unsigned int id, int v);
extern void func_021DEBD4(void *);
extern void func_021D8980(char *p);
extern void func_021DD09C(char *p);
extern void func_021D8E84(void *,int);
extern void func_021DE12C(char *p);
extern void func_021DE518(void *);
extern void func_021DEA24(char *p);
void func_021DE5C4(char *p)
{
    int v;
    if(func_020279E8((struct TaskMenu *)(*(int *)(p+0x64c)))) {
        v=func_02027A04((const u8 *)(*(int *)(p+0x64c)));
        func_021E12F8(p); func_021E1098(p);
        *(int *)(p+0x64c)=0;
        switch(v) {
        case 0: func_021D8E84(p,(int)func_021DE12C); return;
        case 1:
            func_0202208C((void *)3,0,0,0,6,1,*(u16 *)(p+0x5f4));
            func_021B6548((unsigned char *)(*(int *)(p+0x9c0)),1,0);
            func_021D8E84(p,(int)func_021DE518); return;
        case 2:
            func_021DEBD4(p); func_021D8980(p); func_021DD09C(p);
            func_021D8E84(p,(int)func_021DEA24); return;
        }
    }
}
