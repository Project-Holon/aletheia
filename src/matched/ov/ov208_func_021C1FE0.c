/*
 * function: func_021C1FE0
 * address: 0x021C1FE0
 * packet: pkt_ov208_021C1FE0
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021C0C8C 0x021C0C8C thumb ov208
 *   func_021C1D30 0x021C1D30 thumb ov208
 *   func_021C2238 0x021C2238 thumb ov208
 */
#include "../include/Obj00081.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Obj;
struct PrintSys;
struct Descriptor;
struct CharBuf;
extern unsigned func_0204B3F4(struct Obj *);
extern void func_0201C6EC(struct PrintSys *);
extern void *func_02045770(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *, u8);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void func_0204B3DC(struct Obj *, unsigned);
extern void func_021C0C8C(u16 *, u8 *, int, int);
extern void func_021C1D30(u16 *, u8 *, int);
extern void func_021C2238(u16 *, u8 *, int);
void func_021C1FE0(u16 *heap, u8 *p, int key)
{
    u8 i;
    if (func_0204B3F4(*(struct Obj * *)&((struct Obj00081 *)p)->fC8)) {
        if (((struct Obj00081 *)p)->f90 == 1) {
            ((struct Obj00081 *)p)->f30 = 0;
            func_0201C6EC(*(struct PrintSys * *)&((struct Obj00081 *)p)->f40);
            BMP_Clear(func_02045770(*(struct Descriptor * *)&((struct Obj00081 *)p)->f20), 0);
            BMP_WIN_TransferChars(*(struct Descriptor * *)&((struct Obj00081 *)p)->f20);
            func_0204B3DC(*(struct Obj * *)&((struct Obj00081 *)p)->fC8, 0);
        }
    } else {
        for (i = 0; i < 61; i++) func_0204B3DC(*(struct Obj **)(p + i * 4 + 0xdc), 0);
        if (((struct Obj00081 *)p)->f90 == 0) {
            func_021C0C8C(heap, p, key, 0);
            p[0x79] = 255;
            func_0204B3DC(*(struct Obj * *)&((struct Obj00081 *)p)->fCC, 0);
            func_0204B3DC(*(struct Obj * *)&((struct Obj00081 *)p)->fD0, 0);
            func_021C1D30(heap, p, key);
            func_021C2238(heap, p, key);
        }
    }
}
