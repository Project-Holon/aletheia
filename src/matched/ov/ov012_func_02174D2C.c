/*
 * function: COLOSSEUM_SendChoiceReply
 * address: 0x02174D2C
 * packet: pkt_ov012_02174D2C
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: The address-taken payload is the third parameter: sp+0x20
 *        after the 16-byte home area, 8-byte save and 16-byte call frame.
 *        Taking the first parameter's address added a reload and gave DIFF.
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
int COLOSSEUM_SendChoiceReply(char *a, u32 b, u32 c)
{
    COLOSSEUM_GetMyChoice(a);
    return func_0203D3F8((u32)func_020399A8(),(u8)b,0x1505,4,(u32)&c,1,0,0);
}
