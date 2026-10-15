/*
 * function: PLIST_MESSAGE_Create
 * address:  0x021BB594
 * packet:   pkt_ov091_021BB594
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02030734  0x02030734  arm
 *   BMP_MENUWORK_LoadCharAndPltt  0x0201F5BC  thumb
 *   TCBL_Create   0x0203101C  arm
 *   APP_KEYCURSOR_CreateDefault  0x02028590  thumb
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   sPlistMessageAllocSite     0x021BED28  data  ov091  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 sPlistMessageAllocSite[];
extern void *func_02030734(u32 heap, u32 size, int align, const char *file, u16 line);
extern void BMP_MENUWORK_LoadCharAndPltt(u32 a, u32 b, u32 c, u32 d, u16 e);
struct Tcbl;
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 APP_KEYCURSOR_CreateDefault(int a, int b, int c, u16 d);
extern u32 PRINTSYS_QUE_Create(void *p);

u32 *PLIST_MESSAGE_Create(u16 *h)
{
    u32 *r;
    u32 z;

    r = func_02030734(*h, 0x38, 0, (const char *)sPlistMessageAllocSite, 0x64);
    z = 0;
    BMP_MENUWORK_LoadCharAndPltt(0, 1, 0xc, 0, *h);
    r[2] = (u32)TCBL_Create(*h, *h, 1, 0);
    r[3] = z;
    r[0] = 4;
    r[9] = z;
    r[8] = z;
    r[11] = z;
    r[13] = z;
    r[12] = z;
    r[5] = APP_KEYCURSOR_CreateDefault(0xf, 1, 1, *h);
    r[10] = PRINTSYS_QUE_Create((void *)(*h));
    return r;
}
