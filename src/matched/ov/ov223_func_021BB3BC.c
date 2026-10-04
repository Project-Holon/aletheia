/*
 * unit: yes
 * function: func_021BB3BC, func_021BB404, func_021BB414
 * address: 0x021BB3BC
 * packet: pkt_ov223_021BB3BC
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02027FEC 0x02027FEC thumb
 *   func_02045808 0x02045808 arm
 *   func_02028148 0x02028148 thumb
 *   func_02028178 0x02028178 thumb
 * The lead's EXACT* ends at BB404; two complete 16-byte load/tail-call
 * followers cover the remaining extent. Parent cleared both starts.
 */
#include "../include/Obj00084.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct MsgBank;
struct U16Vec;
struct Item { void *text; u16 color; unsigned value; };
extern void *func_02045EC0(struct MsgBank *, unsigned);
extern unsigned func_02027FEC(unsigned, unsigned, unsigned, unsigned, u8, u16);
extern void func_02045808(struct U16Vec *);
extern void func_02028148(u8 *);
extern void func_02028178(u8 *);
void func_021BB3BC(char *p)
{
    struct Item item;
    item.text = func_02045EC0(*(struct MsgBank * *)&((struct Obj00084 *)p)->f234, 21);
    item.color = 0x39E3;
    item.value = 0;
    *(unsigned *)&((struct Obj00084 *)p)->f260 = func_02027FEC(*(unsigned *)&((struct Obj00084 *)p)->f25C, (unsigned)&item, 9, 21, 14, ((struct Obj00084 *)p)->f0);
    func_02045808(item.text);
}
void func_021BB404(char *p)
{
    func_02028148(*(u8 * *)&((struct Obj00084 *)p)->f260);
}
void func_021BB414(char *p)
{
    func_02028178(*(u8 * *)&((struct Obj00084 *)p)->f260);
}
