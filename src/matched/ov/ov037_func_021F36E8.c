/*
 * function: func_021F36E8
 * address: 0x021F36E8
 * packet: pkt_ov037_021F36E8
 * region: ov037
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of alignment padding at 021F3722.
 * interface: retain r1=3 at 0200B3A4 despite its accessor not reading r1.
 * symbols:
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_020127A4 0x020127A4 thumb
 */
typedef unsigned char  u8;
struct Big;
struct Ctx;
struct SaveBlock;
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
typedef signed int     s32;
typedef unsigned int   u32;
struct Rec94;
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern void *func_020127A4(struct SaveBlock *p);
void func_021F36E8(void *a, int v)
{
    void *save;
    int *p;
    save = func_020120F4(a);
    p = func_0200B3A4((struct Rec94 *)func_02012EC4(save), 3);
    func_020127A4(save);
    if (v) p[0] = 1;
    else p[0] = 0;
    if (p[0]) *((unsigned char *)p + 4) = 1;
    else *((unsigned char *)p + 4) = 0;
}
