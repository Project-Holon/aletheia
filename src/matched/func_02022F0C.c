/*
 * function: func_02022F0C
 * address:  0x02022F0C
 * packet:   pkt_02022F0C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  02022F60 label
 *
 * symbols:
 *   func_02022518  0x02022518  thumb
 *   func_02022F60  0x02022F60  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern void func_02022518(u32 a0, u8 *a1, u32 a2, u32 a3, u32 a4);
extern void func_02022F60(void);

void func_02022F0C(u32 a0, u8 *a1, u32 a2, u32 a3)
{
    func_02022518(a0, a1, (u32)func_02022F60, a1[0x309], a2);
}
