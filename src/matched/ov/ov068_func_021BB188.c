/*
 * function: func_021BB188
 * address: 0x021BB188
 * packet: pkt_ov068_021BB188
 * region: ov068
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: final two bytes are alignment padding before next labelled function.
 * symbols:
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_021BB140 0x021BB140 thumb ov068
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0204E720(u32,int,int,int);
extern int func_0204E804(void);
extern void func_021BB140(void *p);
void func_021BB188(void *p,u32 *state) { switch(*state) { case 0: func_0204E720(3,0,16,0); *state=1; break; case 1: if(func_0204E804()==0) *state=2; break; case 2: func_021BB140(p); break; } }
