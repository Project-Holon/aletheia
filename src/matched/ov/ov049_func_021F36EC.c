/*
 * function: func_021F36EC
 * address: 0x021F36EC
 * packet: pkt_ov049_021F36EC
 * region: ov049
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021897BC 0x021897BC thumb ov021
 *   func_021F3868 0x021F3868 thumb ov049
 *   func_021897A0 0x021897A0 thumb ov021
 */
extern int *func_021897BC(char *p,int idx);
extern void func_021F3868(int *q,char *p);
extern void func_021897A0(unsigned char *p,int id);
void func_021F36EC(char *p) { func_021F3868(func_021897BC(p,0),p); func_021897A0((unsigned char *)p,0); }
