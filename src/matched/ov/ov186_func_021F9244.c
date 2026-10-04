/*
 * function: func_021F9244
 * address: 0x021F9244
 * packet: pkt_ov186_021F9244
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012A30 0x02012A30 thumb
 *   func_02028A58 0x02028A58 thumb
 *   func_021FF8D4 0x021FF8D4 thumb ov186
 *   func_021FF4E4 0x021FF4E4 thumb ov186
 *   ov125_id 0x0000007d data
 *   func_02034A5C 0x02034A5C arm
 *   func_021FEDC4 0x021FEDC4 thumb ov186
 *   func_021FE734 0x021FE734 thumb ov186
 *   func_021F9A6C 0x021F9A6C thumb ov186
 *   func_02012F08 0x02012F08 thumb
 *   func_021FC238 0x021FC238 thumb ov186
 *   func_0200C3EC 0x0200C3EC thumb
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_021FB92C 0x021FB92C thumb ov186
 *   func_021FC474 0x021FC474 thumb ov186
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
struct BigObj;
extern unsigned int func_02012A30(const struct BigObj *p);
extern void func_02028A58(int,int,int);
extern int func_021FF8D4(char *);
extern void func_021FF4E4(int);
extern char ov125_id[];
extern void func_02034A5C(int);
extern void func_021FEDC4(int,int);
extern void func_021FE734(int);
extern void func_021F9A6C(int *);
extern int func_02012F08(int);
extern int func_021FC238(int);
extern void func_0200C3EC(int,unsigned char);
extern void func_021FBDA4(int,unsigned);
extern void func_021FB92C(int);
extern void func_021FC474(char *);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
int func_021F9244(int sys,int unused,int unused2,int *p)
{
    int *nested=(int *)((int *)p[6])[3];
    if(nested[0]==0) func_02028A58(func_02012A30((const struct BigObj *)nested[1]),0x7f,0);
    if(p[5]) {
        if(func_021FF8D4((char *)p[5])) ((int *)((int *)p[6])[3])[3]=2;
        func_021FF4E4(p[5]); p[5]=0;
    } else func_02034A5C((int)ov125_id);
    func_021FEDC4(p[4],p[1]);
    func_021FE734(p[3]);
    func_021F9A6C((int *)p[2]);
    nested=(int *)((int *)p[6])[3];
    if(nested[0]==0) {
        int a=func_02012F08(nested[1]);
        int b=func_021FC238(p[1]);
        func_0200C3EC(a,b);
    }
    func_021FBDA4(p[1],0);
    func_021FBDA4(p[1],1);
    func_021FB92C(p[1]);
    func_021FC474((char *)p[0]);
    func_020315D4((struct S020315D4 *)sys);
    func_020306F0(0x5a);
    return 1;
}
