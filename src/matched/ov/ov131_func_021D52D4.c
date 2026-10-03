/*
 * function: func_021D52D4
 * address: 0x021D52D4
 * packet: pkt_ov131_021D52D4
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Default max=2 followed by conditional max=1 preserves the register select.
 * interfaces: 0203633C/020362DC owner units spell their full-word payload as
 *   void *. This caller consumes r0 as an input bitmask; u32 return retains
 *   all 32 bits without dereferencing or narrowing. Guards stay signed while
 *   updates use unsigned wrapping through the same int lvalue.
 * arithmetic: signed p+58 guard accepts negatives; scaled address uses
 *   unsigned 32-bit multiply/add for the original wrapping lsl/add sequence.
 * symbols:
 *   func_0203633C 0x0203633C arm
 *   func_020362DC 0x020362DC arm
 *   func_021D5C98 0x021D5C98 thumb ov131
 *   func_021D5B58 0x021D5B58 thumb ov131
 *   func_021D62E4 0x021D62E4 thumb ov131
 *   func_020061E4 0x020061E4 thumb
 *   func_0204B878 0x0204B878 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern unsigned int func_0203633C(void);
extern u32 func_020362DC(void);
extern void func_021D5C98(void *);
extern int func_021D5B58(u8 *,int);
extern int func_021D62E4(char *);
extern void func_020061E4(u32);
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
int func_021D52D4(char *p)
{
    int max;
    if (func_0203633C() & 0x80) {
        if (func_021D5B58((u8 *)p,1)==1) {
            func_021D5C98(p);
            func_0204B878(*(void **)(p+0x188),3);
            func_0204B878(*(void **)(p+0x18c),10);
            *(int *)(p+0x48)=0;
            *(int *)(p+0x4c)=1;
            func_020061E4(1636);
            *(u8 *)(p+0x1c)=0;
            return 1;
        }
    } else if (func_0203633C() & 0x40) {
        if (func_021D5B58((u8 *)p,0)==1) {
            func_021D5C98(p);
            func_0204B878(*(void **)(p+0x188),11);
            func_0204B878(*(void **)(p+0x18c),2);
            *(int *)(p+0x48)=1;
            *(int *)(p+0x4c)=0;
            func_020061E4(1636);
            *(u8 *)(p+0x1c)=0;
            return 1;
        }
    } else if (func_0203633C() & 0x10) {
        max=2;
        if (*(int *)(p+0x40)==0) max=1;
        if (*(int *)(p+0x58)<max && *(int *)(p+0x38)==0) {
            *(int *)(p+0x58)=(int)((u32)*(int *)(p+0x58)+1);
            func_021D5C98(p);
            func_020061E4(1637);
            *(u8 *)(p+0x1c)=0;
            return 1;
        }
    } else if (func_0203633C() & 0x20) {
        if (*(int *)(p+0x58)>0 && *(int *)(p+0x38)==0) {
            *(int *)(p+0x58)=(int)((u32)*(int *)(p+0x58)-1);
            func_021D5C98(p);
            func_020061E4(1637);
            *(u8 *)(p+0x1c)=0;
            return 1;
        }
    } else if (func_020362DC() & 2) {
        *(int *)(p+0x54)=1;
        (*(u8 **)(p+8))[0x12]=1;
        *(int *)(p+0x50)=2;
        func_0204B878(*(void **)(p+0x194),9);
        *(void **)(p+0x1a0)=*(void **)(p+0x194);
        func_020061E4(1361);
        *(u8 *)(p+0x1c)=0;
        return 1;
    } else if ((func_020362DC() & 0x400) && func_021D62E4(p)==1) {
        *(int *)(p+0x54)=2;
        (*(u8 **)(p+8))[0x12]=2;
        *(int *)(p+0x50)=2;
        func_0204B878(*(void **)(p+0x190),8);
        *(void **)(p+0x1a0)=*(void **)(p+0x190);
        func_020061E4(1366);
        *(u8 *)(p+0x1c)=0;
        return 1;
    } else if ((func_020362DC() & 0x800) && func_021D62E4(p)==1) {
        if (*(int *)(p+0x58)<3) {
            if (*(int *)((u32)p+0x60+(u32)*(int *)(p+0x58)*4)==1) {
                *(int *)((u32)p+0x60+(u32)*(int *)(p+0x58)*4)=0;
                func_0204B878(*(void **)(p+0x184),6);
            } else {
                *(int *)((u32)p+0x60+(u32)*(int *)(p+0x58)*4)=1;
                func_0204B878(*(void **)(p+0x184),7);
            }
            func_020061E4(1606);
            *(u8 *)(p+0x1c)=0;
        }
        return 1;
    }
    return 0;
}
