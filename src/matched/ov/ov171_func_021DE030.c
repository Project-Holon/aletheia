/*
 * function: func_021DE030
 * address: 0x021DE030
 * packet: pkt_ov171_021DE030
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B944 0x0204B944 arm
 *   func_0204B8D4 0x0204B8D4 arm
 *   func_0204A600 0x0204A600 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
extern u32 func_0204B944(struct Obj *);
extern void func_0204B8D4(struct Obj *,u32);
extern void func_0204A600(void);
void func_021DE030(u8 *p)
{
    unsigned i;
    u8 *element;
    for(i=0;i<16;i++) {
        element=p+i*4;
        if(*(void **)(element+0xb74)!=0 && func_0204B944(*(struct Obj **)(element+0xb74))!=1)
            func_0204B8D4(*(struct Obj **)(element+0xb74),4096);
    }
    func_0204A600();
}
