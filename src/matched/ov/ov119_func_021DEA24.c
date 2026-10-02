/*
 * function: func_021DEA24
 * address: 0x021DEA24
 * packet: pkt_ov119_021DEA24
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 02035C08 returns the r0 consumed by original after its forwarding call; matched 021D98AC documents full ARM9 forwarding proof.
 * symbols:
 *   func_021B63D0 0x021B63D0 thumb ov067
 *   func_021B6448 0x021B6448 thumb ov067
 *   func_021B6470 0x021B6470 thumb ov067
 *   func_021B6548 0x021B6548 thumb ov067
 *   func_02045CAC 0x02045CAC arm
 *   func_021E1024 0x021E1024 thumb ov119
 *   func_021DD09C 0x021DD09C thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DE9E8 0x021DE9E8 thumb ov119
 *   func_02035C08 0x02035C08 arm
 *   d_021E80C4 0x021E80C4 data a4
 *   func_020355D8 0x020355D8 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021E68F4 0x021E68F4 thumb ov119
 *   func_021DE754 0x021DE754 thumb ov119
 *   func_020355C4 0x020355C4 arm
 *   func_020362DC 0x020362DC arm
 *   func_021DE208 0x021DE208 thumb ov119
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct S S;
struct MsgBank;
extern void func_021B63D0(S *),func_021B6548(int,int,int);
extern int func_021B6448(u8 *),func_021B6470(u8 *);
extern void func_02045CAC(struct MsgBank *,unsigned,void *),func_021E1024(void *),func_021DD09C(void *),func_021D8E84(void *,int),func_021DE9E8(void *);
extern int func_02035C08(const void *);
extern u32 func_020362DC(void);
extern u8 func_020355C4(void);
extern const char d_021E80C4[];
extern void func_020355D8(u8),func_020061E4(int),func_021E68F4(int,int);
extern int func_021DE754(char *,int),func_021DE208(char *);
static inline int poll(void) { int v=func_020362DC(); if(v)func_020355D8(0); return v; }
void func_021DEA24(char *p)
{
    int idx,sentinel;
    func_021B63D0(*(S **)(p+0x9c0));
    if(func_021B6448(*(u8 **)(p+0x9c0))==1) {
        func_02045CAC(*(struct MsgBank **)(p+0x720),148,*(void **)(p+0x738));
        func_021E1024(p);
        func_021B6548(*(int *)(p+0x9c0),1,0);
        func_021DD09C(p);
        func_021D8E84(p,(int)func_021DE9E8);
        return;
    }
    sentinel=-1;
    if(func_021B6470(*(u8 **)(p+0x9c0))==sentinel) {
        idx=func_02035C08(d_021E80C4);
        if(idx!=sentinel) {
            func_020355D8(1);
            func_020061E4(0x548);
            func_021E68F4((int)p,sentinel);
            if(func_021DE754(p,idx)) return;
        }
        if(func_020355C4() && poll()) {
            *(int *)(p+0x10a0)%=6;
            if(*(int *)(p+0x10a0)<0) *(int *)(p+0x10a0)=0;
            func_021E68F4((int)p,*(int *)(p+0x10a0));
            func_020061E4(0x548);
            return;
        }
        if(poll()==1) {
            if(func_021DE754(p,*(int *)(p+0x10a0))) return;
        }
        if(func_021DE208(p)) {
            func_021E68F4((int)p,*(int *)(p+0x10a0));
            func_020061E4(0x548);
        }
    }
}
