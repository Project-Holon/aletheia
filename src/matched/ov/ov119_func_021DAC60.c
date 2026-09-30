/*
 * function: func_021DAC60
 * address: 0x021DAC60
 * packet: pkt_ov119_021DAC60
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203D34C 0x0203D34C arm
 *   func_0215642C 0x0215642C thumb ov009
 *   func_02045CAC 0x02045CAC arm
 *   func_021E0FF4 0x021E0FF4 thumb ov119
 *   func_021E1030 0x021E1030 thumb ov119
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_02022230 0x02022230 thumb
 *   func_0202208C 0x0202208C thumb
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DAC20 0x021DAC20 thumb ov119
 */
typedef unsigned short u16;
extern void func_0203D34C(int,int),func_0215642C(int),func_02045CAC(int,int,int),func_021E0FF4(void *,int,int),func_021E1030(void *);
extern void func_02043534(int),func_020435F4(int),func_02022230(int),func_0202208C(int,int,int,int,int,int,int);
extern void func_021D8E84(void *,int),func_021DAC20(void *);
void func_021DAC60(char *p) {
 func_0203D34C(1,*(u16 *)(p+0x5f4));if(*(int *)(p+0x118c)==2)func_0215642C(1);
 func_02045CAC(*(int *)(p+0x720),6,*(int *)(p+0x738));func_021E0FF4(p,1,0);func_021E1030(p);
 func_02043534(16);func_020435F4(4);func_02022230(0);
 func_0202208C(4,1,1,0,6,1,*(u16 *)(p+0x5f4));func_021D8E84(p,(int)func_021DAC20);
}
