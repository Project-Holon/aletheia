/*
 * function: func_021BB53C
 * address: 0x021BB53C
 * packet: pkt_ov225_021BB53C
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Lever: unhinted BF9C data uses this function's own overlay region.
 * symbols:
 *   func_02035C08 0x02035C08 arm
 *   func_020355C4 0x020355C4 arm
 *   func_020355D8 0x020355D8 arm
 *   func_020362DC 0x020362DC arm
 *   func_0203633C 0x0203633C arm
 *   func_02028218 0x02028218 thumb
 *   func_0202822C 0x0202822C thumb
 *   func_020061E4 0x020061E4 thumb
 *   d_021BBF9C 0x021BBF9C data a4
 */
typedef unsigned char u8;
extern const u8 d_021BBF9C[];
extern int func_02035C08(const void *);
extern u8 func_020355C4(void);
extern void func_020355D8(u8);
extern unsigned func_020362DC(void),func_0203633C(void);
extern void func_02028218(void *,unsigned);
extern void func_0202822C(void *,unsigned);
extern void func_020061E4(unsigned);
int func_021BB53C(char *p)
{
    int hit=func_02035C08(d_021BBF9C);
    if(func_020355C4()==0) {
        if(hit>=0 && hit<=1) {
            func_020355D8(1);
            func_02028218(*(void **)(p+**(u8 **)p*4+0xc),0);
        }
    } else {
        if(func_020362DC()!=0 && !(func_020362DC()&0x402)) {
            func_020355D8(0);
            func_02028218(*(void **)(p+**(u8 **)p*4+0xc),1);
            func_020061E4(0x548);
            return 0;
        }
    }
    if(func_020355C4()==0) {
        if(func_020362DC()&1) {
            func_0202822C(*(void **)(p+**(u8 **)p*4+0xc),1);
            func_020061E4(0x54c);
            return 1;
        } else if(func_0203633C()&0x40) {
            func_02028218(*(void **)(p+**(u8 **)p*4+0xc),0);
            if(**(u8 **)p==0) **(u8 **)p=1; else **(u8 **)p=0;
            func_02028218(*(void **)(p+**(u8 **)p*4+0xc),1);
            func_020061E4(0x548);
        } else if(func_0203633C()&0x80) {
            func_02028218(*(void **)(p+**(u8 **)p*4+0xc),0);
            if(**(u8 **)p==1) **(u8 **)p=0; else **(u8 **)p=1;
            func_02028218(*(void **)(p+**(u8 **)p*4+0xc),1);
            func_020061E4(0x548);
        } else if(func_0203633C()&0x220) {
            if(**(u8 **)p==1) {
                func_02028218(*(void **)(p+**(u8 **)p*4+0xc),0);
                **(u8 **)p=0;
                func_02028218(*(void **)(p+**(u8 **)p*4+0xc),1);
                func_020061E4(0x548);
            }
        } else if(func_0203633C()&0x110) {
            if(**(u8 **)p==0) {
                func_02028218(*(void **)(p+**(u8 **)p*4+0xc),0);
                **(u8 **)p=1;
                func_02028218(*(void **)(p+**(u8 **)p*4+0xc),1);
                func_020061E4(0x548);
            }
        }
    } else if(hit>=0 && hit<=1) {
        **(u8 **)p=hit;
        func_02028218(*(void **)(p+**(u8 **)p*4+0xc),1);
        func_0202822C(*(void **)(p+**(u8 **)p*4+0xc),1);
        func_020061E4(0x54c);
        return 1;
    }
    return 0;
}
