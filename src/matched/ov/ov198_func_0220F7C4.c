/*
 * function: func_0220F7C4
 * address: 0x0220F7C4
 * packet: pkt_ov198_0220F7C4
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x02045CAC has no witness; owned by the integrator. No overlay leaves filed.
 * symbols:
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_0220E13C 0x0220E13C thumb ov198
 *   func_0220E1D4 0x0220E1D4 thumb ov198
 *   func_02211944 0x02211944 thumb ov198
 *   func_02020FE4 0x02020FE4 thumb
 *   func_02045CAC 0x02045CAC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 low:7; u8 high:1; } Flag;
extern int func_022110D4(u8 *,int);
extern void func_0220E13C(u8 *);
extern void func_0220E1D4(u8 *);
extern void func_02211944(u8 **);
extern u32 func_02020FE4(void *,u32,u32);
struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
int func_0220F7C4(u8 *p)
{
    u8 *q = *(u8 **)p;
    if (((Flag *)(p+func_022110D4(p,q[32])*76))[27].high != 0) {
        func_02045CAC(*(void **)(p+0x1ea0),91,*(void **)(p+0x1ea8));
        func_0220E13C(p);
        (*(u8 **)p)[32] = 6;
        *(u32 *)(p+0x217c) = 31;
        func_02211944((u8 **)p);
        return 23;
    }
    if ((q+func_022110D4(p,q[32]))[56] != 0) {
        func_0220E1D4(p);
        func_0220E13C(p);
        (*(u8 **)p)[32] = 6;
        *(u32 *)(p+0x217c) = 31;
        func_02211944((u8 **)p);
        return 23;
    }
    if (func_02020FE4((void *)*(u16 *)(q+36),39,*(u16 *)(q+16)) != 0 &&
        func_02020FE4((void *)*(u16 *)(q+36),40,*(u16 *)(q+16)) == 0) {
        *(u32 *)(p+0x217c) = 18;
        return 29;
    }
    q[72] = func_022110D4(p,q[32]);
    return 31;
}
