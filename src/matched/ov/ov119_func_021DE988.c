/*
 * function: func_021DE988
 * address: 0x021DE988
 * packet: pkt_ov119_021DE988
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
 *   func_021D8980 0x021D8980 thumb ov119
 *   func_021DD09C 0x021DD09C thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DE950 0x021DE950 thumb ov119
 *   func_021DEA24 0x021DEA24 thumb ov119
 */
extern int func_020279E8(int);
extern int func_02027A04(int);
extern void func_021E12F8(void *);
extern void func_021E1098(void *);
extern void func_021D8980(void *);
extern void func_021DD09C(void *);
extern void func_021D8E84(void *,int);
extern void func_021DE950(void *);
extern void func_021DEA24(void *);
void func_021DE988(char *p)
{
    int v;
    if(func_020279E8(*(int *)(p+0x64c))) {
        v=func_02027A04(*(int *)(p+0x64c));
        func_021E12F8(p);
        func_021E1098(p);
        *(int *)(p+0x64c)=0;
        if(v==0) {
            func_021D8E84(p,(int)func_021DE950);
            return;
        }
        func_021E1098(p);
        func_021D8980(p);
        func_021DD09C(p);
        func_021D8E84(p,(int)func_021DEA24);
    }
}
