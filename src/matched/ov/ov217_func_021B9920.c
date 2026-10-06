/*
 * function: func_021B9920
 * address: 0x021B9920
 * packet: pkt_ov217_021B9920
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 (wD9r lane26): closed by the real return type of func_02062B30 (int, as in the matched
 *   sibling 021B9A24). Declared void, mwcc hoists the block-4 constant 5 into r6.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049250 0x02049250 arm
 *   func_02062A98 0x02062A98 arm
 *   func_02040E78 0x02040E78 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02062A4C 0x02062A4C arm
 *   func_02040B1C 0x02040B1C arm
 *   func_02062B30 0x02062B30 arm
 *   func_02041090 0x02041090 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct ArcFile;
struct NitroFileHeader;
extern void *func_020490F4(unsigned int id, u32 heap);
extern void *func_02049250(struct ArcFile *, u32, u32);
extern int func_02062A98(struct NitroFileHeader *, void **);
extern void func_02040E78(u32, void *, u32, u32);
extern u32 func_020307B0(void *p);
extern int func_02062A4C(struct NitroFileHeader *, void **);
extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
extern int func_02062B30(void *, void **);
extern void func_02041090(u32, u32, u32, u32, u8, u8);
extern void func_020409B4(u32);
extern void func_02049238(struct ArcFile *);
void func_021B9920(u32 heap)
{
    void *palette;
    void *character;
    void *screen;
    void *screen2;
    struct ArcFile *arc;
    void *buffer;
    arc = func_020490F4(192, heap);
    buffer = func_02049250(arc, 9, heap);
    func_02062A98(buffer, &palette);
    func_02040E78(4, *(void **)((char *)palette + 12), 512, 0);
    func_020307B0(buffer);
    buffer = func_02049250(arc, 10, heap);
    func_02062A4C(buffer, &character);
    func_02040B1C(4, *(void **)((char *)character + 0x14), *(u32 *)((char *)character + 0x10), 0);
    func_020307B0(buffer);
    buffer = func_02049250(arc, 11, heap);
    func_02062B30(buffer, &screen);
    func_02041090(4, (u32)((char *)screen + 12), 0, 0, 32, 24);
    func_020409B4(4);
    func_020307B0(buffer);
    buffer = func_02049250(arc, 12, heap);
    func_02062B30(buffer, &screen2);
    func_02041090(5, (u32)((char *)screen2 + 12), 0, 0, 32, 24);
    func_020409B4(5);
    func_020307B0(buffer);
    func_02049238(arc);
}
