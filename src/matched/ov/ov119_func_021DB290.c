/*
 * function: func_021DB290
 * address: 0x021DB290
 * packet: pkt_ov119_021DB290
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware read/write at 021DB2AA/021DB2AE
 * symbols:
 *   func_020435F4 0x020435F4 arm
 *   func_021E5D84 0x021E5D84 thumb ov119
 *   func_021E1098 0x021E1098 thumb ov119
 *   func_021DF7AC 0x021DF7AC thumb ov119
 *   func_021E71E0 0x021E71E0 thumb ov119
 *   func_021DBB6C 0x021DBB6C thumb ov119
 *   func_021E6700 0x021E6700 thumb ov119
 *   func_021E7058 0x021E7058 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DB278 0x021DB278 thumb ov119
 */
typedef unsigned int   u32;
extern void func_020435F4(u32 planes);
extern void func_021E5D84(char *p);
extern void func_021E1098(char *p);
extern void func_021DF7AC(void *,int);
extern void func_021E71E0(void *,int);
extern void func_021DBB6C(char *p);
extern void func_021E6700(void *);
extern void func_021E7058(void *);
extern void func_021D8E84(void *,int);
extern void func_021DB278(void *);
void func_021DB290(void *p)
{
    func_020435F4(0x1a);
    func_021E5D84(p);
    func_021E1098(p);
    *(volatile unsigned *)0x04001000 &= 0xffff1fff;
    func_021DF7AC(p,1);
    func_021E71E0(p,0);
    func_021DBB6C(p);
    func_021E6700(p);
    func_021E7058(p);
    func_021D8E84(p,(int)func_021DB278);
}
