/*
 * function: func_021F080C
 * address: 0x021F080C
 * packet: pkt_ov107_021F080C
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F0D1C 0x021F0D1C thumb ov107
 *   func_021F5E7C 0x021F5E7C arm ov107
 *   func_021F0850 0x021F0850 thumb ov107
 *   func_02034714 0x02034714 arm
 *   d_021F6EAC 0x021F6EAC data a4
 *   d_021F6E24 0x021F6E24 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021F0D1C(u16);
extern int func_021F5E7C(int);
extern int func_021F0850(const char **p);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u8 d_021F6EAC[],d_021F6E24[];
void func_021F080C(void *p,int channel){
 func_021F0D1C(2);
 if(func_021F5E7C(channel)){func_021F0D1C(7);return;}
 *(int *)(d_021F6EAC+24)=1;
 if(!func_021F0850(p))func_02034714((const char *)d_021F6E24,0,(const char *)d_021F6E24);
}
