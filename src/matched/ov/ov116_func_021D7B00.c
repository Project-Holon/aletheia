/*
 * function: func_021D7B00, func_021D7B64
 * address: 0x021D7B00
 * packet: pkt_ov116_021D7B00
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * unit: yes
 * status: EXACT
 * symbols:
 *   func_02157170 0x02157170 thumb ov009
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0203CA98 0x0203CA98 arm
 *   func_021D7158 0x021D7158 thumb ov116
 *   func_021D7200 0x021D7200 thumb ov116
 *   func_021D7184 0x021D7184 thumb ov116
 *   func_021D81B4 0x021D81B4 thumb ov116
 *   func_021D8010 0x021D8010 thumb ov116
 *   func_021D80CC 0x021D80CC thumb ov116
 */
typedef unsigned char u8;
extern int func_02157170(int,int);
extern int func_0200FB24(void);
extern void func_0203CA98(void);
extern int func_021D7158(void *);
extern int func_021D7200(void *);
extern int func_021D7184(void *);
extern void func_021D81B4(void *);
extern void func_021D8010(void *,int);
extern int func_021D80CC(void *);
int func_021D7B00(u8 *p) {
    int yes=1;
    int no=0;
    if(func_02157170(1,0)!=0) return no;
    if(func_0200FB24()!=0) {
        func_0203CA98();
        return no;
    }
    if(func_021D7158(p+0x182c)!=0) {
        int v;
        if(func_021D7200(p+0x182c)!=0) return no;
        v=func_021D7184(p+0x182c);
        func_021D81B4(p+4);
        func_021D8010(p+4,v);
        return yes;
    }
    return no;
}
int func_021D7B64(u8 *p) { return func_021D80CC(p+4); }
