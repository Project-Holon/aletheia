/*
 * function: func_021F168C
 * address: 0x021F168C
 * packet: pkt_ov194_021F168C
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F5354 0x021F5354 thumb ov194
 *   func_021F3ED0 0x021F3ED0 thumb ov194
 *   func_021F3D54 0x021F3D54 thumb ov194
 *   func_021F31B8 0x021F31B8 thumb ov194
 *   func_021F4D78 0x021F4D78 thumb ov194
 *   func_021F1F7C 0x021F1F7C thumb ov194
 *   func_021F4608 0x021F4608 thumb ov194
 *   func_021F42A0 0x021F42A0 thumb ov194
 *   func_021F1968 0x021F1968 thumb ov194
 *   func_021F1878 0x021F1878 thumb ov194
 *   func_021F4B84 0x021F4B84 thumb ov194
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 */
#include "../include/Obj02908.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021F5354(u8 *);
extern void func_021F3ED0(u8 *);
extern void func_021F3D54(u8 *);
extern void func_021F31B8(u8 *);
struct PrintSys;
struct Rec;
struct S020315D4;
struct U16Vec;
struct WordSet;
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_021F4D78(u8 *);
extern void func_021F1F7C(u8 *);
extern void func_021F4608(void *p);
extern void func_021F42A0(u8 *);
extern void func_021F1968(u8 *);
extern int func_021F1878(void *a0);
extern void BMP_OAM_DeleteSys(void *);
extern void func_021F4B84(unsigned char *p);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32);
int func_021F168C(void *a,u32 b,u32 c,u8 *d)
{
    func_021F5354(*(u8 * *)&((struct Obj02908 *)d)->f2CC);
    func_021F3ED0(d+596);
    func_021F3D54(d+560);
    func_021F31B8(d+252);
    STRBUF_Delete(((struct Obj02908 *)d)->f2D0);
    func_021F4D78(*(u8 * *)&((struct Obj02908 *)d)->f22C);
    func_021F1F7C(d+104);
    func_021F4608(d+672);
    func_021F42A0(d+612);
    func_021F1968(d+4);
    func_021F1878(d+100);
    BMP_OAM_DeleteSys(((struct Obj02908 *)d)->f2C0);
    func_021F4B84(((struct Obj02908 *)d)->f0);
    func_0201ED04(((struct Obj02908 *)d)->f2BC);
    MSGDATA_Delete(((struct Obj02908 *)d)->f2B8);
    func_0201C6EC(((struct Obj02908 *)d)->f2B4);
    func_0201C4C0(((struct Obj02908 *)d)->f2B4);
    GF_FONT_Delete(((struct Obj02908 *)d)->f2B0);
    func_020315D4(a);
    func_020306F0(30);
    return 1;
}
