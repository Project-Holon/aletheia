/*
 * file:     ctvt_draw_p05.c
 * unit:     yes
 * function: func_021BDBC4, func_021BDC70
 * address:  0x021BDBC4
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201C450 0x0201C450 thumb
 *   func_02049B40 0x02049B40 arm
 *   func_0201DD68 0x0201DD68 thumb
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_0203101C 0x0203101C arm
 *   func_0202F038  0x0202F038  thumb
 *   func_02031140  0x02031140  arm
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_0201D83C  0x0201D83C  thumb
 */
#include "../../matched/include/Obj01758.h"

struct GfFont;
struct MsgBank;
struct Tcbl;
struct PrintSys;
struct Rec;
struct S02031140;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_0201C450(u16 n, u32 heap);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201DD68(void);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void func_0202F038(u8 *p);
extern void func_02031140(struct S02031140 *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
void func_021BDBC4(u8 *p);
void func_021BDC70(u32 *a0);

/*
 * Extent remainder: zero alignment halfword at 021BDC6E.
 */
void func_021BDBC4(u8 *p)
{
    ((struct Obj01758 *)p)->f1C8=(u32)func_0201D7EC(23,0,0,0,((struct Obj01758 *)p)->f0);
    ((struct Obj01758 *)p)->f1CC=(u32)func_02045B38(0,2,27,((struct Obj01758 *)p)->f0);
    ((struct Obj01758 *)p)->f1D0=(u32)func_0201C450(0x800,((struct Obj01758 *)p)->f0);
    func_02049B40(23,5,0,0x140,32,((struct Obj01758 *)p)->f0);
    func_02049B40(23,5,4,0x140,32,((struct Obj01758 *)p)->f0);
    func_0201DD68();
    func_0201F5BC(4,0x140,9,0,((struct Obj01758 *)p)->f0);
    func_0201F5BC(0,0x200,9,0,((struct Obj01758 *)p)->f0);
    ((struct Obj01758 *)p)->f1D8=(u32)func_0203101C(((struct Obj01758 *)p)->f0,((struct Obj01758 *)p)->f0,1,0);
    ((struct Obj01758 *)p)->f1DC=0;
}


void func_021BDC70(u32 *a0)
{
    u32 i;
    u32 v;

    i = 0x77;
    v = a0[i];
    if (v != 0) {
        func_0202F038((u8 *)v);
        a0[i] = 0;
    }
    i = 0x76;
    func_02031140((struct S02031140 *)a0[i]);
    func_0201C6EC((struct PrintSys *)a0[i - 2]);
    func_0201C4C0((struct PrintSys *)a0[i - 2]);
    func_02045C04((struct Rec *)a0[i - 3]);
    func_0201D83C((void *)a0[i - 4]);
}
