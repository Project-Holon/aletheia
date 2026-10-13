/*
 * function: func_02174CE4
 * address: 0x02174CE4
 * packet: pkt_ov012_02174CE4
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   COLOSSEUM_GetMyChoice 0x021750C0 thumb ov012
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3F8 0x0203D3F8 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 COLOSSEUM_GetMyChoice(char *);
struct Entry;
extern struct Entry *func_020399A8(void);
extern u32 func_0203D3F8(u32,u32,u32,u32,u32,u32,u32,u32);
u32 func_02174CE4(char *p)
{
    u8 v = COLOSSEUM_GetMyChoice(p);
    return func_0203D3F8((u32)func_020399A8(),0,0x1504,1,(u32)&v,1,0,0);
}
