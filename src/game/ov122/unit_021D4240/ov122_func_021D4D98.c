/*
 * function: func_021D4D98
 * address: 0x021D4D98
 * packet: pkt_ov122_021D4D98
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: explicit if/else calls preserve the shared stack home and call ordering.
 * tables: original pool maps y=5714, x=5710, rows=5840/5860, extra=5850.
 * symbols:
 *   func_02158630 0x02158630 thumb ov010
 *   func_02158678 0x02158678 thumb ov010
 *   func_021586C8 0x021586C8 thumb ov010
 *   func_021D4CD8 0x021D4CD8 thumb ov122
 *   func_021D4590 0x021D4590 thumb ov122
 *   func_021D45BC 0x021D45BC thumb ov122
 *   func_021D44BC 0x021D44BC thumb ov122
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02041B6C 0x02041B6C arm
 *   data_021D5714 0x021D5714 data ov122 a4
 *   data_021D5840 0x021D5840 data a4
 *   data_021D5850 0x021D5850 data a4
 *   data_021D5860 0x021D5860 data a4
 *   data_021D5710 0x021D5710 data a4
 */
#include "../../../matched/include/Obj00265.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { int f00, f04, f08, f0c; } Row;
extern int data_021D5714[], data_021D5710[];
extern Row data_021D5840, data_021D5850, data_021D5860;
struct Ctx;
struct MsgBank;
struct Obj;
struct WordSet;
extern u32 func_02012138(const struct Ctx *p);
extern int func_02158630(int);
extern int func_02026CA0(int *);
extern void func_021D4CD8(int, int, int, int, void *);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_021D4590(u32 i, u32 p);
extern int func_02158678(void *p);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_021D45BC(u32 i, u32 p);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021D44BC(int, void *, Row *, const int *, const int *);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern int func_021586C8(int, int);
extern void func_02041B6C(u32 bit);
void func_021D4D98(char *p)
{
    int force = 0;
    int scratch = 0;
    int object, mode, count;
    object = func_02012138(((struct Obj00265 *)p)->f354);
    mode = func_02158630(object);
    if (!((struct Obj00265 *)p)->f374) {
        scratch = 0;
        if (func_02026CA0(&scratch) != 30) ((struct Obj00265 *)p)->f374 = 1;
    }
    if (((struct Obj00265 *)p)->f36C != ((struct Obj00265 *)p)->f370) force = 1;
    if (((struct Obj00265 *)p)->f368 != ((struct Obj00265 *)p)->f364) force = 1;
    func_021D4CD8(4, 2, 0, 0, p);
    func_021D4CD8(6, 4, 0, 0, p);
    func_021D4CD8(8, 12, 0, 0, p);
    if (mode == 0) {
        func_0201EFA4(((struct Obj00265 *)p)->f48, 0, ((struct Obj00265 *)p)->f36C, 2, 0, 1);
        func_021D4CD8(5, 3, force, 1, p);
        if (((struct Obj00265 *)p)->f364 & 32) func_021D4CD8(7, 5, force, 1, p);
        else func_021D4CD8(7, 6, force, 1, p);
        if (((struct Obj00265 *)p)->f374) func_021D4CD8(9, 5, force, 1, p);
        else func_021D4CD8(9, 6, force, 1, p);
    } else {
        func_021D4590(5, (u32)p); func_021D4590(7, (u32)p); func_021D4590(9, (u32)p);
    }
    if (mode == 2 && ((struct Obj00265 *)p)->f128 != func_02158678((void *)object)) ((struct Obj00265 *)p)->f124 = 0;
    if (((struct Obj00265 *)p)->f124 != mode) {
        switch (mode) {
        case 0:
            func_0204B3DC(((struct Obj00265 *)p)->f3A4, 0);
            func_021D45BC(10, (u32)p);
            func_02045CAC(((struct Obj00265 *)p)->f44, 0, ((struct Obj00265 *)p)->f54);
            func_021D44BC(0, p, &data_021D5840, data_021D5710, data_021D5714);
            break;
        case 1:
            func_0204B3DC(((struct Obj00265 *)p)->f3A4, 0);
            func_021D45BC(10, (u32)p);
            func_02045CAC(((struct Obj00265 *)p)->f44, 15, ((struct Obj00265 *)p)->f54);
            func_021D44BC(0, p, &data_021D5860, data_021D5710, data_021D5714);
            break;
        case 2:
            count = func_02158678((void *)object);
            ((struct Obj00265 *)p)->f128 = count;
            func_0204B3DC(((struct Obj00265 *)p)->f3A4, 0);
            func_021D45BC(10, (u32)p);
            func_0201EFA4(((struct Obj00265 *)p)->f48, 0, count, 1, 0, 1);
            func_02045CAC(((struct Obj00265 *)p)->f44, 16, ((struct Obj00265 *)p)->f50);
            func_0201F250(((struct Obj00265 *)p)->f48, ((struct Obj00265 *)p)->f54, ((struct Obj00265 *)p)->f50);
            func_021D44BC(0, p, &data_021D5860, data_021D5710, data_021D5714);
            break;
        case 3:
            func_02045CAC(((struct Obj00265 *)p)->f44, 17, ((struct Obj00265 *)p)->f54);
            func_021D44BC(0, p, &data_021D5860, data_021D5710, data_021D5714);
            if (func_021586C8(object, *(int *)&((struct Obj00265 *)p)->f54)) {
                func_021D44BC(10, p, &data_021D5850, 0, 0);
                func_0204B3DC(((struct Obj00265 *)p)->f3A4, 1);
            }
            break;
        }
        ((struct Obj00265 *)p)->f124 = mode;
    }
    func_02041B6C(7);
}
