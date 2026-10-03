/*
 * unit: yes
 * function: func_021F80B0, func_021F80C8
 * address: 0x021F80B0
 * packet: pkt_ov112_021F80B0
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Struct parameter fixes the zero/load/store scheduling. The extent's
 * 021F80C8 tail stub is included; 021F53CC has its own verified shard.
 * symbols:
 *   func_021F53B4 0x021F53B4 thumb ov112
 *   func_021F5424 0x021F5424 thumb ov112
 *   func_021F53CC 0x021F53CC thumb ov112
 */
typedef unsigned char u8;
typedef struct { u8 pad0[0x4c]; int zero; u8 pad50[8]; int target; } Obj;
extern void func_021F53B4(int);
extern void func_021F5424(int, int);
extern void func_021F53CC(int, unsigned int);
void func_021F80B0(int a, Obj *b)
{
    func_021F53B4(b->target);
    b->zero = 0;
    func_021F5424(b->target, 0);
}
void func_021F80C8(int a, Obj *b, unsigned int c)
{
    func_021F53CC(b->target, c);
}
