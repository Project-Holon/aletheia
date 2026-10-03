/*
 * function: func_021D99F4
 * address: 0x021D99F4
 * packet: pkt_ov119_021D99F4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020221A4 0x020221A4 thumb
 *   func_021D8FA4 0x021D8FA4 thumb ov119
 *   func_021E1D68 0x021E1D68 thumb ov119
 *   func_021D8B38 0x021D8B38 thumb ov119
 *   func_0202208C 0x0202208C thumb
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021D98AC 0x021D98AC thumb ov119
 */
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 func_020221A4(void);
extern void *func_021D8FA4(void *,int);
extern void func_021E1D68(char *p, void *a);
extern void func_021D8B38(char *p);
extern void func_0202208C(int,int,int,int,int,int,int);
extern void func_021D8E84(void *,int);
extern void func_021D98AC(char *p);
void func_021D99F4(char *p) { if(func_020221A4()) { *(int *)(p+0x10a0)=0; func_021E1D68(p,func_021D8FA4(p,0));func_021D8B38(p);func_0202208C(3,1,1,0,6,1,*(u16 *)(p+0x5f4));func_021D8E84(p,(int)func_021D98AC); } }
