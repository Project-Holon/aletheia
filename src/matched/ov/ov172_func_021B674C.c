/*
 * function: func_021B674C
 * address: 0x021B674C
 * packet: pkt_ov172_021B674C
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B6938 0x021B6938 thumb ov172
 *   func_021B6944 0x021B6944 thumb ov172
 *   func_02030734 0x02030734 arm
 *   func_0203D7C8 0x0203D7C8 arm
 *   d_021C71C0 0x021C71C0 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 func_021B6938(void *);
extern u16 func_021B6944(void *);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_0203D7C8(u16, u32, const void *, int);
extern const char d_021C71C0[];
void func_021B674C(char *p, int count, u16 heap)
{
    u32 width = func_021B6938(p);
    u32 height = func_021B6944(p);
    u8 i;
    if (*(u32 *)(p + 4) == 0) {
        *(void **)(p + 4) = func_02030734(*(u16 *)p, count * 4, 0, d_021C71C0, 0x1D7);
        *(u8 *)(p + 8) = count;
        for (i = 0; i < count; i++)
            (*(void ***)(p + 4))[i] = func_0203D7C8(heap, height * (width * 2), d_021C71C0, 0x1DC);
        *(u32 *)(p + 0xC) = 1;
    }
}
