/*
 * function: func_021FC694
 * address: 0x021FC694
 * packet: pkt_ov132_021FC694
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203CBAC 0x0203CBAC arm
 *   func_02087C6C 0x02087C6C arm
 *   d_021FDE4C 0x021FDE4C data a4
 *   d_021FDDEC 0x021FDDEC data a4
 *   func_021FCAA0 0x021FCAA0 thumb ov132
 */
typedef unsigned short u16;
typedef unsigned char  u8;
extern u8 *func_02012944(void *p);
typedef unsigned int   u32;
struct Req;
extern void func_0203CBAC(struct Req *req, u32 a2, u32 a3);
extern void func_02008494(void *, void *);
extern void func_02087C6C(void *);
extern void func_021FCAA0(char *p);
extern char d_021FDE4C[];
extern char d_021FDDEC[];
void *func_021FC694(int a,char *p)
{
    *(void **)(p+0x5c)=func_02012944(*(void **)(p+0x58));
    if(*(int *)(p+0xc)==1) d_021FDE4C[5]=4;
    else {
        d_021FDE4C[5]=0;
        func_0203CBAC((struct Req *)d_021FDDEC,(u32)func_021FCAA0,(u32)p);
    }
    func_02008494(*(void **)(p+0x5c),p+0x20);
    func_02087C6C(p+0x40);
    *(u16 *)(p+0x46)=0x3a0b;
    return p;
}
