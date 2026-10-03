/*
 * function: func_021B6424
 * address: 0x021B6424
 * packet: pkt_ov101_021B6424
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_02039468 0x02039468 arm
 *   func_021B64B8 0x021B64B8 thumb ov101
 */
typedef unsigned char u8;
typedef unsigned int   u32;
struct Entry;
struct Link;
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *p);
extern int func_02039468(unsigned int,unsigned int);
extern u32 func_021B64B8(u32 p, u32 a, u32 b, u32 c, u8 d, u32 e, u32 f, u32 g);
int func_021B6424(int p)
{
    unsigned int id;
    u8 other;
    if(*(int *)(p+0x78)) return 1;
    id=func_0203D1A4((void *)func_020399A8());
    other=(id == 0);
    if(func_02039468(0xD02,id) == 0) {
        return func_021B64B8(p,0xD02,4,p+0x38,other,0,0,1);
    } else {
        return 0;
    }
}
