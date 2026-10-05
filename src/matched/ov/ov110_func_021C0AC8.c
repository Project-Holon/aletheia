/*
 * function: func_021C0AC8
 * address: 0x021C0AC8
 * packet: pkt_ov110_021C0AC8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * lang: c99
 * status: EXACT
 * note: 2026-10-05 (wD9r lane27): closed by the u16 type of the size parameter (stored to the u32
 *   Config.size). The u32 parameter let the scheduler hoist the size reload above the e[2].term store.
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02027778 0x02027778 thumb
 *   func_02045808 0x02045808 arm
 *   d_021C3C94 0x021C3C94 data ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Entry { void *str; u16 flag; u16 pad; u32 term; } Entry;
typedef struct Config { u32 size; u8 flag; u8 pad[3]; void *target; u32 mode; u8 x, y, z, w; } Config;
extern const u8 d_021C3C94[];
extern void *func_02045EC0(void *bank, u32 idx);
extern int func_02027778(Config *, void *);
extern void func_02045808(void *);
int func_021C0AC8(void *parent, void *bank, u16 size)
{
    Config c;
    Entry e[3];
    u32 i;
    int r;
    for (i = 0; i < 3; i++) {
        e[i].str = func_02045EC0(bank, d_021C3C94[i]);
        e[i].flag = 0x39E3;
        e[i].term = 0;
    }
    e[2].term = 1;
    c.size = size;
    c.flag = 3;
    c.target = e;
    c.mode = 1;
    c.x = 0x20;
    c.y = 0x18;
    c.z = 13;
    c.w = 3;
    r = func_02027778(&c, parent);
    for (i = 0; i < 3; i++)
        func_02045808(e[i].str);
    return r;
}
