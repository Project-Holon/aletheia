/*
 * function: func_0220D920
 * address: 0x0220D920
 * packet: pkt_ov198_0220D920
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_FillRect 0x02043AF4 arm
 *   func_0220C16C 0x0220C16C thumb ov198
 *   func_0220C2F8 0x0220C2F8 thumb ov198
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int   u32;
struct Bmp;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_FillRect(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void func_0220C16C(u8 *,int,int,u8,u8);
extern void func_0220C2F8(u8 *,int,int,u16,u8);
void func_0220D920(u8 *p, int i)
{
    char *base;
    base = (char *)p + 0x1f70;
    BMP_FillRect(BMP_WIN_GetBmp(*(void **)(base + i * 8)), 92, 32, 24, 8, 0);
    BMP_FillRect(BMP_WIN_GetBmp(*(void **)(base + i * 8)), 64, 24, 64, 8, 0);
    func_0220C16C(p, i, i, 92, 32);
    func_0220C2F8(p, i, i, 64, 24);
}
