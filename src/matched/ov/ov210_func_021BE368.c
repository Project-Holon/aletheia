/*
 * function: ZKNSEARCH_MAIN_InitBmpWindows
 * address: 0x021BE368
 * packet: pkt_ov210_021BE368
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_Init 0x02045088 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   ZKNSEARCH_MAIN_InitWindowTexts 0x021BE4B4 thumb ov210
 *   d_021C0900 0x021C0900 data a1
 */
typedef unsigned char u8;
struct Record { u8 a, b, c, d, e, f; };
extern const struct Record d_021C0900[];
extern void BMP_WIN_Init(unsigned short);
extern unsigned BMP_WIN_Create(unsigned, unsigned, unsigned, unsigned, u8, u8, u8);
extern void ZKNSEARCH_MAIN_InitWindowTexts(u8 *);
void ZKNSEARCH_MAIN_InitBmpWindows(u8 *p)
{
    unsigned i;
    BMP_WIN_Init(123);
    for (i = 0; i < 16; i++) {
        const struct Record *r = &d_021C0900[i];
        *(unsigned *)(p + i * 8 + 0x14c) = BMP_WIN_Create(r->a, r->b, r->c, r->d, r->e, r->f, 1);
    }
    ZKNSEARCH_MAIN_InitWindowTexts(p);
}
