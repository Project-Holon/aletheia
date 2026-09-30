/*
 * function: func_021DBA80
 * address: 0x021DBA80
 * packet: pkt_ov119_021DBA80
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021D8C84 0x021D8C84 thumb ov119
 *   func_021DF7AC 0x021DF7AC thumb ov119
 *   func_02027858 0x02027858 thumb
 *   func_021D94A0 0x021D94A0 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DBA38 0x021DBA38 thumb ov119
 */
extern void func_02082BCC(void *,int,int);
extern void func_021D8C84(void *);
extern void func_021DF7AC(void *,int);
extern void func_02027858(int);
extern void func_021D94A0(void *,int);
extern void func_021D8E84(void *,int);
extern void func_021DBA38(void *);
void func_021DBA80(char *p)
{
    *(int *)(p+0x1088)=0;
    *(short *)(p+0x1078)=0;
    *(short *)(p+0x107a)=0;
    func_02082BCC(p+0xca0,0,0x78);
    func_02082BCC(p+0xd18,0,0x3c);
    func_02082BCC(p+0xd54,0,0x3c);
    func_021D8C84(p);
    func_021DF7AC(p,1);
    if(*(int *)(p+0x64c)) {
        func_02027858(*(int *)(p+0x64c));
        *(int *)(p+0x64c)=0;
    }
    func_021D94A0(p,0);
    func_021D8E84(p,(int)func_021DBA38);
}
