/*
 * function: ZUKAN_DETAIL_FORM_Exit
 * address: 0x021C3C70
 * packet: pkt_ov208_021C3C70
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ov208_func_021BC3B4 0x021BC3B4 thumb ov208
 *   ov208_func_021BC97C 0x021BC97C thumb ov208
 *   ov208_func_021BCA54 0x021BCA54 thumb ov208
 *   ov208_func_021C66C8 0x021C66C8 thumb ov208
 *   ov208_func_021C53E0 0x021C53E0 thumb ov208
 *   ov208_func_021C533C 0x021C533C thumb ov208
 *   ov208_func_021C4A48 0x021C4A48 thumb ov208
 *   ov208_func_021BDCA4 0x021BDCA4 thumb ov208
 *   ov208_func_021BC61C 0x021BC61C thumb ov208
 *   ov208_func_021BC464 0x021BC464 thumb ov208
 *   ov208_func_021C4AF4 0x021C4AF4 thumb ov208
 *   func_02030EAC 0x02030EAC arm
 *   ov208_func_021BC34C 0x021BC34C thumb ov208
 */
#include "../include/Obj02547.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ov208Menu {
    u8  pad0[0x12c];
    u32 res[2];
    u32 j;
    u32 k;
    u32 obj[2];
    u8  pad144[0x5b0 - 0x144];
    u32 w5b0;
    u32 w5b4;
    u32 w5b8;
    u32 w5bc;
};

extern void *ov208_func_021BC3B4(int key);
extern void ov208_func_021BC97C(u32 a);
extern void ov208_func_021BCA54(u32 a, u32 packed);
extern void ov208_func_021C66C8(u16 *heap, u8 *p, int key);
extern void ov208_func_021C53E0(u32 res, u32 obj);
extern void ov208_func_021C533C(u16 *heap, u8 *p, int key);
extern void ov208_func_021C4A48(u16 *heap, u8 *p, int key);
extern void ov208_func_021BDCA4(void *s, u8 v);
extern void ov208_func_021BC61C(u32 a);
extern void ov208_func_021BC464(u32 a);
extern void ov208_func_021C4AF4(u16 *heap, u8 *p, int key);
struct Node;
extern void func_02030EAC(struct Node *n);
extern void ov208_func_021BC34C(void *proc);

int ZUKAN_DETAIL_FORM_Exit(void *proc, int *seq, u16 *heap, u8 *p, int key)
{
    void *sys;
    u8 i;
    sys = ov208_func_021BC3B4(key);
    ov208_func_021BC97C(((struct Obj02547 *)p)->f5BC);
    ov208_func_021BC97C(((struct Obj02547 *)p)->f5B8);
    ov208_func_021BCA54(7, ((struct Obj02547 *)p)->f5B4);
    ov208_func_021C66C8(heap, p, key);
    for (i = 0; i < 2; i++) {
        if (((struct Ov208Menu *)p)->obj[i] != 0)
            ov208_func_021C53E0(((struct Ov208Menu *)p)->res[i], ((struct Ov208Menu *)p)->obj[i]);
        ((struct Ov208Menu *)p)->obj[i] = 0;
    }
    ov208_func_021C533C(heap, p, key);
    ov208_func_021C4A48(heap, p, key);
    ov208_func_021BDCA4(sys, 0);
    ov208_func_021BC61C(((struct Obj02547 *)p)->f6AC);
    ov208_func_021BC464(((struct Obj02547 *)p)->f6A8);
    ov208_func_021BC464(((struct Obj02547 *)p)->f6A4);
    ov208_func_021C4AF4(heap, p, key);
    func_02030EAC((struct Node *)(((struct Obj02547 *)p)->f6A0));
    ov208_func_021BC34C(proc);
    return 1;
}
