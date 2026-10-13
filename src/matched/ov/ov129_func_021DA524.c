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
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_0201F73C 0x0201F73C thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_021DA578 0x021DA578 thumb ov129
 */
typedef unsigned char u8;
extern unsigned int BMP_WIN_Create(unsigned int layer, unsigned int a, unsigned int b, unsigned int tiles, u8 c, u8 d, u8 slot);
extern void func_0201F73C(void *,int,int,int);
struct Cfg;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
typedef unsigned int   u32;
extern void func_021DA578(void *p, int a, void *b, u32 c);
void func_021DA524(void **p,int a,int b,int c,int d,int e,int f,int g,int h)
{
    *p=(void *)BMP_WIN_Create((u8)b,(u8)c,(u8)d,(u8)e,f,12,1);
    func_0201F73C(*p,2,1,11);
    BMP_WIN_MakeScreen(*p);
    func_021DA578(*p,a,(void *)g,h);
}
