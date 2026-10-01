/*
 * function: func_021D8BE4
 * address: 0x021D8BE4
 * packet: pkt_ov129_021D8BE4
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DA610 0x021DA610 thumb ov129
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_021DA578 0x021DA578 thumb ov129
 *   func_021D8AF4 0x021D8AF4 thumb ov129
 */

extern void func_021DA610(int,int,int,int);
extern int func_020362DC(void);
extern int func_02035C60(void);
extern void func_021DA578(int,int,int,int);
extern void func_021D8AF4(char *,int);
int func_021D8BE4(char *p)  {
    switch(*(int *)(p+0x234))  {
        case 0: func_021DA610(*(int *)(p+0x310),*(int *)(p+0x328),*(int *)(p+0x314),*(int *)(p+0x344));
        *(int *)(p+0x234)+=1;
        break;
        case 1: if((func_020362DC() & 2) || (func_020362DC() & 1) || func_02035C60())  {
            func_021DA578(*(int *)(p+0x310),*(int *)(p+0x328),*(int *)(p+0x314),*(int *)(p+0x344));
            func_021D8AF4(p,1);
        }
        break;
    }
    return 0;
}
