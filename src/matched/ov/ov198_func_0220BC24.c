/*
 * function: B_PLIST_ANM_CreateTileWindows
 * address: 0x0220BC24
 * packet: pkt_ov198_0220BC24
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: a nonconst table pointer preserves the original load/store schedule.
 * symbols:
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_0220BC70 0x0220BC70 thumb ov198
 *   d_02211B14 0x02211B14 data a1
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Item { u8 a,b,c,d,e,f; } Item;
extern Item d_02211B14[];
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_0220BC70(u8 *, unsigned int);
void B_PLIST_ANM_CreateTileWindows(u8 *p)
{
    Item *s = d_02211B14;
    u32 i;
    for (i=0;i<2;i++,s++)
        *(void **)(p+i*8+0x1F60)=(void *)BMP_WIN_Create(s->a,s->b,s->c,s->d,s->e,s->f,1);
    func_0220BC70(p,p[0x2180]);
}
