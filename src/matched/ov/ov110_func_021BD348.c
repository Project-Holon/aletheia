/*
 * function: func_021BD348
 * address: 0x021BD348
 * packet: pkt_ov110_021BD348
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: the RGB555 lerp is a static inline helper (u16 colour params, as ov105 func_021B8734)
 * symbols:
 *   func_02061CA4 0x02061CA4 arm
 *   tbl_020A1B38 0x020A1B38 data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
extern s16 tbl_020A1B38[];
typedef signed int     s32;
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
#define F (*(int *)(p + 0xB8))
static inline void lerp(u16 *p, int n, u16 a, u16 b)
{
 u8 r,g,blue; int dr,dg,db;
 g=(a&0x3E0)>>5;
 r=a&31;
 blue=(a&0x7C00)>>10;
 db=((u8)((b&0x7C00)>>10)-blue)*n>>12;
 dr=((u8)(b&31)-r)*n>>12;
 dg=((u8)((b&0x3E0)>>5)-g)*n>>12;
 *p=(u8)(r+dr)|((u8)(g+dg)<<5)|((u8)(blue+db)<<10);
}
void func_021BD348(char *p)
{
    int j;
    s16 t;
    u8 i;
    if (F + 0x400 >= 0x10000)
        F = F - 0xFC00;
    else
        F = F + 0x400;
    j = F >> 4;
    t = (tbl_020A1B38[j * 2 + 1] + 0x1000) / 2;
    for (i = 0; i < 5; i++) {
        lerp((u16 *)(p + i * 2 + 0xAC), t, *(u16 *)(p + i * 2 + 0x98), *(u16 *)(p + i * 2 + 0xA2));
    }
    func_02061CA4((void *)14, 0x56, (u32)(p + 0xAC), 10);
}
