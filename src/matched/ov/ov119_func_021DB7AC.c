/*
 * function: func_021DB7AC
 * address: 0x021DB7AC
 * packet: pkt_ov119_021DB7AC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E4E64 0x021E4E64 thumb ov119
 *   func_021E42B4 0x021E42B4 thumb ov119
 *   func_021E4598 0x021E4598 thumb ov119
 *   func_02006238 0x02006238 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_0203D29C 0x0203D29C arm
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3F8 0x0203D3F8 arm
 */
typedef short s16;
typedef unsigned u32;
extern void func_021E4E64(int,char *,int);
extern void func_021E42B4(char *),func_021E4598(char *),func_020061E4(int);
extern int func_02006238(void),func_021D8A24(void *),func_0203D29C(void);
extern u32 func_020399A8(void);
extern u32 func_0203D3F8(u32,u32,u32,u32,u32,u32,u32,u32);
#define H(o) (*(s16 *)(p+(o)))
#define I(o) (*(int *)(p+(o)))
void func_021DB7AC(char *p,int a,int b)
{
    if(H(0x107c)<0) H(0x107c)+=(s16)I(0x63c);
    if(I(0x63c)<=H(0x107c)) H(0x107c)-=(s16)I(0x63c);
    func_021E4E64(I(0x828),p,1);
    func_021E42B4(p);
    func_021E4598(p);
    if(func_02006238()==0 && a) func_020061E4(0x72b);
    if(func_021D8A24(p) && b) {
        if(func_0203D29C()) {
            if(H(0x107c)%16==0) {
                func_0203D3F8(func_020399A8(),255,0xc0c,2,(u32)(p+0x107c),0,1,1);
                return;
            }
        } else {
            func_0203D3F8(func_020399A8(),255,0xc0c,2,(u32)(p+0x107c),0,1,1);
            return;
        }
    } else {
        if(func_021D8A24(p)==0) H(0x107e)=H(0x107c);
    }
}
