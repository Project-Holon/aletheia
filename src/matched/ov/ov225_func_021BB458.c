/*
 * function: func_021BB458
 * address: 0x021BB458
 * packet: pkt_ov225_021BB458
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * width: 021BB4B0/021BB4B8 truncate r3 to u8 before 02027FEC; retain u8 fourth extern argument.
 * symbols:
 *   func_02027F60 0x02027F60 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_02027FEC 0x02027FEC thumb
 *   func_02045808 0x02045808 arm
 *   func_020355C4 0x020355C4 arm
 *   func_02028218 0x02028218 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
struct R;
struct Obj;
struct MsgBank;struct U16Vec;
struct Entry { void *resource; u16 tag; u16 pad; unsigned flags; };
extern struct R *func_02027F60(u16, u16, unsigned, unsigned, u16);
extern void *func_02045EC0(struct MsgBank *, unsigned);
extern unsigned func_02027FEC(unsigned, unsigned, unsigned, u8, u8, u16);
extern void func_02045808(struct U16Vec *);
extern u8 func_020355C4(void);
extern void func_02028218(struct Obj *, unsigned);
void func_021BB458(char *p)
{
    struct Entry entries[2];
    u8 i;
    *(struct R **)(p + 8) = func_02027F60(5, 4, *(unsigned *)(*(char **)(p + 4) + 0xc), *(unsigned *)(*(char **)(p + 4) + 0x14), *(u16 *)(*(char **)(p + 4) + 4));
    entries[0].resource = func_02045EC0(*(struct MsgBank **)(*(char **)(p + 4) + 0x1c), 0);
    entries[0].tag = 0x39e3;
    entries[0].flags = 0;
    entries[1].resource = func_02045EC0(*(struct MsgBank **)(*(char **)(p + 4) + 0x1c), 1);
    entries[1].tag = 0x39e3;
    entries[1].flags = 0;
    for (i = 0; i < 2; i++) {
        *(unsigned *)(p + i * 4 + 0xc) = func_02027FEC(*(unsigned *)(p + 8), (unsigned)&entries[i], 1, (i + 1) * 3, 30, *(u16 *)(*(char **)(p + 4) + 4));
        func_02045808(entries[i].resource);
    }
    if (func_020355C4() == 0) func_02028218(*(struct Obj **)(p + *(u8 *)*(char **)p * 4 + 0xc), 1);
}
