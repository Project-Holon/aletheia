/*
 * function: func_021DA524
 * address: 0x021DA524
 * packet: pkt_ov129_021DA524
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two zero alignment bytes at 0x021DA576; next labelled function is 0x021DA578.
 * symbols:
 *   func_020450F0 0x020450F0 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045374 0x02045374 arm
 *   func_021DA578 0x021DA578 thumb ov129
 */
typedef unsigned char u8;
extern void *func_020450F0(u8,u8,u8,u8,u8,u8,u8);
extern void func_0201F73C(void *,int,int,int);
struct Cfg;
extern void func_02045374(struct Cfg *cfg);
typedef unsigned int   u32;
extern void func_021DA578(void *p, int a, void *b, u32 c);
void func_021DA524(void **p,int a,int b,int c,int d,int e,int f,int g,int h)
{
    *p=func_020450F0(b,c,d,e,f,12,1);
    func_0201F73C(*p,2,1,11);
    func_02045374(*p);
    func_021DA578(*p,a,(void *)g,h);
}
