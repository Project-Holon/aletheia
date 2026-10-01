/*
 * function: func_021DE3E8
 * address: 0x021DE3E8
 * packet: pkt_ov119_021DE3E8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 02035C08 return is consumed in r0; full 02035BBC forwarding body returns int, as in matched 021D98AC.
 * symbols:
 *   func_02040588 0x02040588 arm
 *   func_020221A4 0x020221A4 thumb
 *   func_021B63D0 0x021B63D0 thumb ov067
 *   func_021B6448 0x021B6448 thumb ov067
 *   func_021B6470 0x021B6470 thumb ov067
 *   func_0202208C 0x0202208C thumb
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DE2C4 0x021DE2C4 thumb ov119
 *   func_02035C08 0x02035C08 arm
 *   d_021E80C4 0x021E80C4 data a4
 *   func_020355D8 0x020355D8 arm
 *   func_021E68F4 0x021E68F4 thumb ov119
 *   func_021DE1B4 0x021DE1B4 thumb ov119
 *   func_020061E4 0x020061E4 thumb
 *   func_021DE3BC 0x021DE3BC thumb ov119
 *   func_020355C4 0x020355C4 arm
 *   func_020362DC 0x020362DC arm
 *   func_021DE208 0x021DE208 thumb ov119
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct S S;
typedef struct { char pad[0xfd8]; int obj[2][3]; } State;
extern void func_02040588(int,int);
extern unsigned func_020221A4(void);
extern void func_021B63D0(S *);
extern int func_021B6448(u8 *),func_021B6470(u8 *);
extern void func_0202208C(void *,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
extern void func_021D8E84(void *,int),func_021DE2C4(char *),func_021DE3BC(void *);
extern int func_02035C08(const void *);
extern const char d_021E80C4[];
extern void func_020355D8(u8),func_021E68F4(int,int),func_021DE1B4(State *,int),func_020061E4(int);
extern u8 func_020355C4(void);
extern void *func_020362DC(void);
extern int func_021DE208(char *);
static inline int poll(void) { int v=(int)func_020362DC(); if(v)func_020355D8(0); return v; }
void func_021DE3E8(char *p)
{
    int idx;
    func_02040588(3,1);
    if(func_020221A4()) {
        func_021B63D0(*(S **)(p+0x9c0));
        if(func_021B6448(*(u8 **)(p+0x9c0))==1) {
            func_0202208C((void *)3,0,0,0,6,1,*(u16 *)(p+0x5f4));
            func_021D8E84(p,(int)func_021DE2C4);
            return;
        }
        if(func_021B6470(*(u8 **)(p+0x9c0))==-1) {
            idx=func_02035C08(d_021E80C4);
            if(idx!=-1) {
                func_020355D8(1);
                *(int *)(p+0x10a0)=idx;
                func_021E68F4((int)p,-1);
                func_021DE1B4((State *)p,*(int *)(p+0x10a0));
                func_020061E4(0x548);
                *(int *)(p+0xf2c)=0;
                func_021D8E84(p,(int)func_021DE3BC);
                return;
            }
            if(func_020355C4() && poll()) {
                func_020355D8(0);
                func_021E68F4((int)p,*(int *)(p+0x10a0));
                func_020061E4(0x548);
                *(int *)(p+0xf2c)=0;
                func_021D8E84(p,(int)func_021DE3BC);
                return;
            }
            if(func_021DE208(p)) {
                func_020061E4(0x548);
                func_021E68F4((int)p,*(int *)(p+0x10a0));
                func_021DE1B4((State *)p,*(int *)(p+0x10a0));
                *(int *)(p+0xf2c)=0;
                func_021D8E84(p,(int)func_021DE3BC);
            }
        }
    }
}
