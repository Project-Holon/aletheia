/*
 * function: func_021D43BC
 * address: 0x021D43BC
 * packet: pkt_ov120_021D43BC
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D439C 0x021D439C thumb ov120
 *   func_021D435C 0x021D435C thumb ov120
 *   func_021D437C 0x021D437C thumb ov120
 *   func_021D7E88 0x021D7E88 thumb ov120
 *   func_021D7E9C 0x021D7E9C thumb ov120
 *   func_021D7EB0 0x021D7EB0 thumb ov120
 *   func_021D6B84 0x021D6B84 thumb ov120
 *   func_020061E4 0x020061E4 thumb
 */
extern void func_021D439C(int,void *);
extern void func_021D435C(int,void *);
extern void func_021D437C(int,void *);
extern void func_021D7E88(int,int);
extern void func_021D7E9C(int,int);
extern void func_021D7EB0(int,int);
extern void func_021D6B84(int,int);
extern void func_020061E4(int);
int func_021D43BC(int n, char *p) {
    int result=0;
    switch(n) {
    case 0:func_021D439C(-1,p);result=2;func_021D7E88(*(int *)(p+0x40),*(int *)(p+0x144));break;
    case 1:func_021D439C(1,p);result=2;func_021D7E88(*(int *)(p+0x40),*(int *)(p+0x144));break;
    case 2:func_021D435C(-1,p);result=3;func_021D7E9C(*(int *)(p+0x40),*(int *)(p+0x13c));break;
    case 3:func_021D435C(1,p);result=3;func_021D7E9C(*(int *)(p+0x40),*(int *)(p+0x13c));break;
    case 4:func_021D437C(-1,p);result=4;func_021D7EB0(*(int *)(p+0x40),*(int *)(p+0x140));break;
    case 5:func_021D437C(1,p);result=4;func_021D7EB0(*(int *)(p+0x40),*(int *)(p+0x140));break;
    }
    if(n>=0 && n<=5) {func_020061E4(0x548);func_021D6B84(*(int *)(p+0x3c),n);}
    return result;
}
