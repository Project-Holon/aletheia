/*
 * function: func_021DE024
 * address: 0x021DE024
 * packet: pkt_ov121_021DE024
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding after the return.
 * symbols:
 *   func_021DDC58 0x021DDC58 thumb ov121
 *   func_021DDCF8 0x021DDCF8 thumb ov121
 *   func_021DDD64 0x021DDD64 thumb ov121
 *   func_021DA4A8 0x021DA4A8 thumb ov121
 *   func_021DA318 0x021DA318 thumb ov121
 *   func_02040588 0x02040588 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021DDC58(const unsigned *,void *,u16);
extern void func_021DDCF8(unsigned *,void *,u16);
extern void func_021DDD64(void *,void *,u16);
extern void func_021DA4A8(u8 *p);
extern void func_021DA318(u8 *p);
extern void func_02040588(u8,int);
void func_021DE024(void *unused,char *p)
{
    if (*(int *)(p+0x12c)) return;
    *(int *)(p+0x12c)=1;
    switch (*(int *)(p+0x130)) {
    case 0: func_021DDC58((unsigned *)(*(char **)(p+0x11c)+0xa0),p,*(u16 *)(p+0x118)); break;
    case 1: func_021DDCF8((unsigned *)(*(char **)(p+0x11c)+0xa0),p,*(u16 *)(p+0x118)); break;
    }
    func_021DDD64(p,*(void **)(p+0x11c),*(u16 *)(p+0x118));
    func_021DA4A8(*(void **)(p+0x144));
    func_021DA318(**(void ***)(p+0x11c));
    func_02040588(*(u16 *)(*(char **)(p+0x11c)+0x96),1);
    func_02040588(*(u16 *)(*(char **)(p+0x11c)+0x94),1);
}
