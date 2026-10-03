/*
 * function: func_021D9D60
 * address: 0x021D9D60
 * packet: pkt_ov119_021D9D60
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_021E12F8 0x021E12F8 thumb ov119
 *   func_02045CAC 0x02045CAC arm
 *   func_021E1024 0x021E1024 thumb ov119
 *   func_021E1030 0x021E1030 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021D9CFC 0x021D9CFC thumb ov119
 *   func_021DBA80 0x021DBA80 thumb ov119
 */

extern int func_020279E8(int);
extern int func_02027A04(int);
typedef unsigned char  u8;
extern void func_021E12F8(char *p);
extern void func_02045CAC(int,int,int);
extern void func_021E1024(void *);
extern void func_021E1030(char *p);
extern void func_021D8E84(void *,int);
extern void func_021D9CFC(u8 *p);
extern void func_021DBA80(char *p);
void func_021D9D60(char *p) {
    int v;
    if (func_020279E8(*(int *)(p+0x64C))) {
        v=func_02027A04(*(int *)(p+0x64C));
        func_021E12F8(p);
        *(int *)(p+0x64C)=0;
        if (v==0) {
            func_02045CAC(*(int *)(p+0x720),6,*(int *)(p+0x738));
            func_021E1024(p);
            func_021E1030(p);
            func_021D8E84(p,(int)func_021D9CFC);
            return;
        }
        func_021D8E84(p,(int)func_021DBA80);
    }
}
