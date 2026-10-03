/*
 * function: func_021D4DA4
 * address: 0x021D4DA4
 * packet: pkt_ov123_021D4DA4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02027778 0x02027778 thumb
 *   func_02027CD8 0x02027CD8 thumb
 *   func_02045808 0x02045808 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 heap; u8 mode; void *data; int flag; u8 a,b,c,d; } Descriptor;
struct MsgBank;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void *func_02027778(Descriptor *, void *);
extern void func_02027CD8(void *, int);
extern void func_02045808(struct U16Vec *vec);
void func_021D4DA4(char *p)
{
    Descriptor desc;
    desc.heap = *(u16 *)(p + 12);
    desc.mode = 2;
    desc.data = p + 0x23c;
    desc.flag = 1;
    desc.a = 32;
    desc.b = 14;
    desc.c = 13;
    desc.d = 3;
    *(void **)(p + 0x23c) = func_020457B0(100, *(u16 *)(p + 12));
    func_02045CAC(*(void **)(p + 0x24), 4, *(void **)(p + 0x23c));
    *(u16 *)(p + 0x240) = 0x39e0;
    *(void **)(p + 0x248) = func_020457B0(100, *(u16 *)(p + 12));
    func_02045CAC(*(void **)(p + 0x24), 5, *(void **)(p + 0x248));
    *(u16 *)(p + 0x24c) = 0x39e0;
    *(void **)(p + 0x238) = func_02027778(&desc, *(void **)(p + 0x254));
    func_02027CD8(*(void **)(p + 0x238), 1);
    func_02045808(*(void **)(p + 0x23c));
    func_02045808(*(void **)(p + 0x248));
}
