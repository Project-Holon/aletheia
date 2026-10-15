/*
 * function: STARTMENU_SetNewPlayerNameAndGender
 * address:  0x021BC4A4
 * packet:   pkt_ov088_021BC4A4
 * region:   ov088
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020084E4  0x020084E4  thumb
 *   func_0200854C  0x0200854C  thumb
 *   func_02005728  0x02005728  thumb
 *   func_0200852C  0x0200852C  thumb
 *   GF_STANDARD_Rand  0x0203F0A8  arm
 *   func_02008550  0x02008550  thumb
 *   func_02008558  0x02008558  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

struct U16Vec;
extern void func_020084E4(u16 *out, struct U16Vec *vec);
extern void func_0200854C(int, int);
extern u32 func_02005728(u32 range);
struct Sub0200852CObj;
extern void func_0200852C(struct Sub0200852CObj *obj, u32 value);
extern u32 GF_STANDARD_Rand(void);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_02008558(struct Sub0200852CObj *obj, u8 value);

void STARTMENU_SetNewPlayerNameAndGender(int a, int b, int c)
{
    u64 x;
    u32 y;
    func_020084E4((u16 *)a, (struct U16Vec *)b);
    func_0200854C(a, c);
    func_0200852C((struct Sub0200852CObj *)a, func_02005728(-1));
    x = GF_STANDARD_Rand();
    y = func_02008550((const struct Sub0200852CObj *)a);
    func_02008558((struct Sub0200852CObj *)a, (u8)((u32)((x * 8) >> 32) + y * 8));
}
