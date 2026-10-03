/*
 * unit: yes
 * function: func_021F38C0, func_021F38E4
 * address: 0x021F38C0
 * packet: pkt_ov052_021F38C0
 * region: ov052
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021F3AC0 0x021F3AC0 data ov052 a4
 *   func_020307B0 0x020307B0 arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern char d_021F3AC0[];
extern void func_020307B0(void *);

void func_021F38C0(char *a)
{
    *(void **)(a + 0x24) = func_02030734(*(unsigned short *)(a + 0xc), 12, 1, d_021F3AC0, 0x164);
}

void func_021F38E4(char *a)
{
    func_020307B0(*(void **)(a + 0x24));
}
