/*
 * function: func_021B3A64
 * address:  0x021B3A64
 * packet:   pkt_ov021_021B3A64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B3A64 0x021B3A64 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_02186670 0x02186670 thumb ov020
 *   func_0201F81C 0x0201F81C thumb
 *   func_021B385C 0x021B385C thumb ov021
 *   func_0201F878 0x0201F878 thumb
 *   func_02045C04 0x02045C04 arm
 */
#include "../include/Obj00037.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef unsigned int   u32;
struct MsgBank;
struct Rec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02186670(char *base, char *out, u16 *cnt, int n, u16 id);
extern void *func_0201F81C(int, int);
extern void func_021B385C(char *p, int idx, int mode, int val, int arg);
struct Slot;
extern void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern void func_02045C04(struct Rec *rec);

void func_021B3A64(char *p, int i)
{
    int k = 0;
    void *q = func_02045B38(0, 2, 54, ((struct Obj00037 *)p)->f4);

    func_02186670(((struct Obj00037 *)p)->f1C, p + 32, (u16 *)(p + 352), i - 247, ((struct Obj00037 *)p)->f4);
    ((struct Obj00037 *)p)->f180 = func_0201F81C(((struct Obj00037 *)p)->f160 + 1, ((struct Obj00037 *)p)->f4);
    for (; k < ((struct Obj00037 *)p)->f160; k++) {
        func_021B385C(p, k, ((struct Obj00037 *)p)->f162, *(u16 *)(p + 32 + k * 8), (int)q);
    }
    func_0201F878((struct Slot *)(*(char * *)&((struct Obj00037 *)p)->f180 + k * 8), (u32)(((struct Obj00037 *)p)->f188), 11, -2, ((struct Obj00037 *)p)->f4);
    func_02045C04(q);
}
