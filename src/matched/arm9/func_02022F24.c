/*
 * function: func_02022F24
 * address:  0x02022F24
 * packet:   pkt_02022F0C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern void func_02022568(u32 a0, u32 a1, u32 a2);

void func_02022F24(u32 a0, u8 *a1, u32 a2)
{
    func_02022568(a0, a1[0x309], a2);
}
