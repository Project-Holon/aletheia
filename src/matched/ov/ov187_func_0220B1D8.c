/*
 * function: func_0220B1D8
 * address: 0x0220B1D8
 * packet: pkt_ov187_0220B1D8
 * region: ov187
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012A30 0x02012A30 thumb
 *   func_02005E9C 0x02005E9C thumb
 *   func_02005DE4 0x02005DE4 thumb
 *   func_02005DF8 0x02005DF8 thumb
 *   func_02028A58 0x02028A58 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_02013930 0x02013930 thumb
 *   func_0220B0F8 0x0220B0F8 thumb ov187
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { unsigned char low:1, flag:1, rest:6; } Flag;
struct BigObj;
extern unsigned int func_02012A30(const struct BigObj *);
extern void func_02005E9C(void);
struct SoundSys;
extern void func_02005DE4(void *p);
extern void func_02005DF8(u32);
extern void func_02028A58(struct SoundSys *sys, u8 level, u16 frames);
extern void func_020307B0(void *);
extern void func_02013930(void *);
extern void func_0220B0F8(u8 *p, u32 v);
void func_0220B1D8(u8 *a, u8 *b)
{
    void *p = (void *)func_02012A30(*(void **)(*(u8 **)(b+0x17F0)+4));
    func_02005E9C();
    func_02005DE4(0);
    func_02005DF8(30);
    if (*(u32 *)*(u8 **)(b+0x17F0) == 0) func_02028A58(p,64,0);
    *(u32 *)(b+0x17E4) = ((Flag *)(a+0xC1))->flag;
    func_020307B0(*(void **)(a+0x34));
    func_02013930(a);
    func_020307B0(a);
    func_0220B0F8((u8 *)((u32)b),0);
}
