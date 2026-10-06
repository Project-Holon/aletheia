/*
 * function: func_021B9A24
 * address: 0x021B9A24
 * packet: pkt_ov217_021B9A24
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * declaration: original 021B9A34/38 truncates heap to u16 before sub_020490F4 despite its legacy u32 declaration.
 * declaration: func_02049238's legacy void asm body reads entry r0 into r4 and forwards it twice; retain the visible archive argument.
 * symbols:
 *   sub_020490F4 0x020490F4 arm
 *   func_02049250 0x02049250 arm
 *   func_02062A98 0x02062A98 arm
 *   func_02040E78 0x02040E78 arm
 *   sub_020307B0 0x020307B0 arm
 *   func_02062A4C 0x02062A4C arm
 *   func_02040B1C 0x02040B1C arm
 *   func_02062B30 0x02062B30 arm
 *   func_02041090 0x02041090 arm
 *   sub_020409B4 0x020409B4 arm
 *   func_02049238 0x02049238 arm
 */
#include "../include/Obj14724.h"
#include "../include/Obj25805.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct ArcFile;
struct NitroFileHeader;
extern void *sub_020490F4(u32 id, u32 heap);
extern void *func_02049250(struct ArcFile *, u32, u32);
extern int func_02062A98(struct NitroFileHeader *, void **);
extern void func_02040E78(u32, void *, u32, u32);
extern u32 sub_020307B0(void *p);
extern int func_02062A4C(struct NitroFileHeader *, void **);
extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
extern int func_02062B30(void *, void **);
extern void func_02041090(u32, u32, u32, u32, u8, u8);
extern void sub_020409B4(u32);
extern void func_02049238(struct ArcFile *);
void func_021B9A24(u32 heap)
{
    void *palette;
    void *character;
    void *screen;
    struct ArcFile *arc;
    void *buffer;
    arc = sub_020490F4(192, (u16)((heap & 0x7fff) | 0x8000));
    buffer = func_02049250(arc, 0, heap);
    func_02062A98(buffer, &palette);
    func_02040E78(1, ((struct Obj25805 *)palette)->fC, 512, 0);
    sub_020307B0(buffer);
    buffer = func_02049250(arc, 1, heap);
    func_02062A4C(buffer, &character);
    func_02040B1C(1, ((struct Obj14724 *)character)->f14, ((struct Obj14724 *)character)->f10, 0);
    sub_020307B0(buffer);
    buffer = func_02049250(arc, 2, heap);
    func_02062B30(buffer, &screen);
    func_02041090(1, (u32)((char *)screen + 12), 0, 0, 32, 24);
    sub_020409B4(1);
    sub_020307B0(buffer);
    func_02049238(arc);
}
