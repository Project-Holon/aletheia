/*
 * function: func_021BC82C
 * address: 0x021BC82C
 * packet: pkt_ov210_021BC82C
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020056BC 0x020056BC thumb
 *   func_0202173C 0x0202173C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
struct PalAnmObj;
extern void *func_020056BC(void);
extern int func_0202173C(struct PalAnmObj *,u16,u16,s16,u8,u8,u16,void *);
void func_021BC82C(char *p,u8 b,u8 c)
{
    func_0202173C(*(struct PalAnmObj **)(p+12),1,0xbfff,-14,b,c,0,func_020056BC());
    func_0202173C(*(struct PalAnmObj **)(p+12),2,0x7fef,-14,b,c,0,func_020056BC());
    func_0202173C(*(struct PalAnmObj **)(p+12),4,0xfe1f,-14,b,c,0,func_020056BC());
    func_0202173C(*(struct PalAnmObj **)(p+12),8,0xbfff,-14,b,c,0,func_020056BC());
}
