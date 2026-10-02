/*
 * function: func_021BEBD8
 * address: 0x021BEBD8
 * packet: pkt_ov093_021BEBD8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021B8D8C 0x021B8D8C thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 func_021D5440(u8 *);
extern int func_021B8D8C(void *,void *,u32);
extern void func_021CD4B0(void *,u32,...);
void func_021BEBD8(u8 *p,u8 *a,int c,int d)
{
    int n;
    n=func_021B8D8C(*(void **)(p+4),*(void **)(p+8),func_021D5440(a));
    func_021CD4B0(*(void **)(p+12),0x30,n,d,c,0);
}
