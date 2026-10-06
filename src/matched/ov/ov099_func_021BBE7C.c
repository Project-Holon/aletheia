/*
 * function: func_021BBE7C
 * address: 0x021BBE7C
 * packet: pkt_ov099_021BBE7C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   data_021C3B30 0x021C3B30 data a4
 *   data_021C39F0 0x021C39F0 data a4
 *   func_021BAC24 0x021BAC24 thumb ov099
 *   func_02020D10 0x02020D10 thumb
 */
#include "../include/Obj00976.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Desc;
struct Pair { u32 a, b; };
extern char data_021C3B30[];
extern struct Pair data_021C39F0[];
extern void func_021BAC24(char *, struct Desc *, struct Pair *, int, int, u32);
extern void func_02020D10(u8 *p, u32 v);
void func_021BBE7C(char *p)
{
    *(u16 *)(data_021C3B30 + 0x14) = 2;
    *(u16 *)(data_021C3B30 + 0x16) = 2;
    func_021BAC24(p, (struct Desc *)(data_021C3B30 + 4), data_021C39F0, 2, 5, 18);
    func_02020D10(*(u8 * *)&((struct Obj00976 *)p)->fBC, 1);
}
