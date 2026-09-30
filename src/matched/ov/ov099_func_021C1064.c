/*
 * function: func_021C1064, func_021C10A0, func_021C10A4
 * address: 0x021C1064
 * packet: pkt_ov099_021C1064
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * unit: yes
 * symbols:
 *   func_021C19A8 0x021C19A8 thumb ov099
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_0203C554 0x0203C554 arm
 *   func_021C2408 0x021C2408 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 */
extern void func_021C19A8(char *);
extern void func_021C18C8(char *,int,unsigned);
extern void func_0203C554(int);
extern void func_021C2408(char *);
extern void func_021BA8EC(char *);
int func_021C1064(char *p,int ret) {
    func_021C19A8(p);
    func_021C18C8(p,1,2);
    func_0203C554(1);
    *(int *)(p+0x1f0)=-1;
    *(int *)(p+0x1cc)=11;
    func_021C2408(p);
    func_021BA8EC(p);
    return ret;
}
int func_021C10A0(char *p,int ret){return ret;}
int func_021C10A4(char *p,int ret){return ret;}
