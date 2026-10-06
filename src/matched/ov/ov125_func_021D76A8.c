/*
 * function: func_021D76A8
 * address: 0x021D76A8
 * packet: pkt_ov125_021D76A8
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200725C 0x0200725C thumb
 *   func_020073D8 0x020073D8 thumb
 *   func_0200B448 0x0200B448 thumb
 *   func_02012E4C 0x02012E4C thumb
 */
struct Ctrl;
struct Big;
extern void *func_02012EBC(struct Big *p); extern unsigned int func_0200725C(struct Ctrl *,unsigned int,unsigned char); extern void *func_020073D8(void *,unsigned int,unsigned int); extern void func_0200B448(void *); extern void func_02012E4C(unsigned char *,unsigned int);
void func_021D76A8(unsigned char *p,unsigned char heap,unsigned int id) {void *s=func_02012EBC((struct Big *)p); func_0200725C(s,id,heap); func_0200B448(func_020073D8(s,id,0)); func_02012E4C(p,id);}
