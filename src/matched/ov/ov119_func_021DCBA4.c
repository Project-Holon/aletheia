/*
 * function: func_021DCBA4
 * address: 0x021DCBA4
 * packet: pkt_ov119_021DCBA4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020173EC 0x020173EC thumb
 *   func_02082D44 0x02082D44 arm
 *   func_021E36C8 0x021E36C8 thumb ov119
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_02015EA0 0x02015EA0 thumb
 *   func_0203D34C 0x0203D34C arm
 *   func_0204E720 0x0204E720 arm
 */
extern int func_020173EC(void);
extern void func_02082D44(void *,const void *,int);
extern void func_021E36C8(void *,int,int,int,int);
extern int func_021D8AA8(void *);
extern void func_02015EA0(unsigned);
extern void func_0203D34C(int,int);
extern void func_0204E720(int,int,int,int);
void func_021DCBA4(char *a, char *p)
{
    func_02082D44(*(void **)(a+0x34),*(void **)(p+0x5dc),func_020173EC());
    func_02082D44(*(void **)(a+0x38),*(void **)(p+0x5e0),func_020173EC());
    func_021E36C8(p,0,1,*(int *)(a+0x34),1);
    func_021E36C8(p,1,1,*(int *)(a+0x38),1);
    func_02015EA0(*(unsigned *)(p+(func_021D8AA8(p) == 0 ? 0x848 : 0x844)));
    *(int *)(p+0x830)=*(int *)(a+0x3c);
    *(int *)(p+0x834)=*(int *)(a+0x40);
    func_0203D34C(0,*(unsigned short *)(p+0x5f4));
    func_0204E720(3,16,0,2);
}
