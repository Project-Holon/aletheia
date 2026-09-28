/*
 * function: func_021FFC18
 * address:  0x021FFC18
 * packet:   pkt_021FFC18
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02049F34  0x02049F34  arm
 *   func_02049E34  0x02049E34  arm
 *   DC_FlushRange  0x020862F0  arm
 *
 * Load the palette (archive 0x20, file 0, out at +0xEA0, handle at
 * +0xE9C) and the 16 character files 0x31.. (handles at +0xE1C, char
 * data at +0xE5C) from archive 0x20 on heap 0x48, then flush the first
 * 0x200 bytes of each character block.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0x14];
    void *pixels;
} CharData;

typedef struct {
    u8 pad0[0xE1C];
    void *res[16];
    CharData *chr[16];
    void *pal;
    void *palData;
} Obj;

extern void *func_02049F34(u32 arc, u32 file, void **out, u32 heap);
extern void *func_02049E34(u32 arc, u32 file, u32 comp, CharData **out, u32 heap);
extern void DC_FlushRange(void *p, u32 size);

void func_021FFC18(Obj *p)
{
    int i;

    p->pal = func_02049F34(0x20, 0, &p->palData, 0x48);
    for (i = 0; i < 16; i++) {
        p->res[i] = func_02049E34(0x20, i + 0x31, 0, &p->chr[i], 0x48);
    }
    for (i = 0; i < 16; i++) {
        DC_FlushRange(p->chr[i]->pixels, 0x200);
    }
}
