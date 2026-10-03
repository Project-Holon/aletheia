/*
 * function: func_021E92A8
 * address: 0x021E92A8
 * packet: pkt_ov170_021E92A8
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * trailing extent: two-byte zero alignment at 021E93F2.
 * symbols:
 *   func_021EBA5C 0x021EBA5C thumb
 *   func_021DD14C 0x021DD14C thumb
 *   func_020355C4 0x020355C4 arm
 *   func_020260F4 0x020260F4 thumb
 *   func_021ED508 0x021ED508 thumb
 *   func_021ECB20 0x021ECB20 thumb
 *   func_021ED888 0x021ED888 thumb
 *   func_021EF480 0x021EF480 thumb
 *   func_021EF670 0x021EF670 thumb
 *   func_021EF68C 0x021EF68C thumb
 */
struct WinMgr;
extern void func_021EBA5C(char *,int);
extern void func_021DD14C(unsigned char *);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Struct_02025CD0;
extern u8 func_020355C4(void);
extern void func_020260F4(struct Struct_02025CD0 *obj, u32 state);
extern void func_021ED508(unsigned char *,int,int);
extern void func_021ECB20(unsigned char *,int,int);
extern void func_021ED888(char *,int);
extern int func_021EF480(struct WinMgr *mgr);
extern void func_021EF670(char *);
extern void func_021EF68C(char *);
#define WORK (*(char **)(p+0x2c))
int func_021E92A8(unsigned char *p)
{
    func_021EBA5C(WORK,0x18);
    func_021DD14C(p);
    if(func_020355C4()==1) func_020260F4(*(void **)(WORK+0x70),0);
    else func_020260F4(*(void **)(WORK+0x70),1);
    func_021ED508(p,0xe,1);
    switch(*(unsigned *)(*(char **)p+0x24)) {
    case 0: func_021ECB20(p,2,0); return 0x31;
    case 1: func_021ED888(WORK,1); func_021ECB20(p,1,0); return 0x2c;
    case 2:
        if(func_021EF480(*(struct WinMgr **)(WORK+0x74))==1) {
            func_021ECB20(p,2,0); func_021EF68C(WORK); return 0x1b;
        }
        func_021ED888(WORK,1); func_021ECB20(p,1,0); func_021EF670(WORK); return 0x11;
    case 3:
        if(func_021EF480(*(struct WinMgr **)(WORK+0x74))==1) {
            func_021ECB20(p,0x82,0); func_021EF68C(WORK); return 0x46;
        }
        func_021ED888(WORK,1); func_021ECB20(p,0x81,0); func_021EF670(WORK); return 0x39;
    case 4:
        if(func_021EF480(*(struct WinMgr **)(WORK+0x74))==1) {
            func_021ECB20(p,2,0); func_021EF68C(WORK); return 0x27;
        }
        func_021ED888(WORK,1); func_021ECB20(p,1,0); func_021EF670(WORK); return 0x23;
    case 5: func_021ED888(WORK,1); func_021ECB20(p,0x81,1); return 0x4b;
    }
    return 0x11;
}
