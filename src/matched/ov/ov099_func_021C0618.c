/*
 * function: func_021C0618
 * address: 0x021C0618
 * packet: pkt_ov099_021C0618
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_020362DC 0x020362DC arm
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_0203C554 0x0203C554 arm
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_021C2408 0x021C2408 thumb ov099
 */

typedef unsigned int u32;
extern int func_021BA928(char *,int);
extern u32 func_020362DC(void);
extern void func_021BA8EC(char *);
extern void func_0203C554(u32 a);
extern void func_021C18C8(char *p, int kind, int value);
extern void func_021C2408(char *);
int func_021C0618(char *p,int ret) {
    if (!func_021BA928(p,ret)) return ret;
    if(func_020362DC()) {
        func_021BA8EC(p);
        func_0203C554(1);
        func_021C18C8(p,1,2);
        *(int *)(p+0x1f0)=-1;
        func_021C2408(p);
        *(int *)(p+0x1cc)=11;
    }
    return ret;
}
