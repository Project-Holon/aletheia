/*
 * function: func_021BF60C
 * address: 0x021BF60C
 * packet: pkt_ov217_021BF60C
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202173C 0x0202173C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
struct PalAnmObj;
extern int func_0202173C(struct PalAnmObj *,u16,u16,s16,u8,u8,u16,void *);
void func_021BF60C(char *p)
{
    func_0202173C(*(struct PalAnmObj **)(p+0x3b8),1,0xffff,3,0,7,0xffff,*(void **)(p+0x3bc));
    func_0202173C(*(struct PalAnmObj **)(p+0x3b8),4,0xffff,3,0,7,0xffff,*(void **)(p+0x3bc));
}
