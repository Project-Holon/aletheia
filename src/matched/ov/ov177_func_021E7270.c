/*
 * function: func_021E7270
 * address: 0x021E7270
 * packet: pkt_ov177_021E7270
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   d_021E8CBE 0x021E8CBE data a1
 */
#include "../include/Obj00133.h"
typedef struct { short x, y; unsigned short id; unsigned char a, flag; } Request;
typedef unsigned short u16;

extern void func_02082BCC(void *, unsigned, unsigned);
typedef signed int     s32;
typedef unsigned int   u32;
struct Obj;
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *e, unsigned short f, unsigned short g);
extern int func_021E5978(int *p, int i);
extern unsigned func_021E7CF0(void *, unsigned short, unsigned short);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(unsigned);
extern void func_0204AFD8(unsigned);
extern void func_0204ADA4(unsigned);
extern void *func_020490F4(unsigned int id, u16 heap);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern const unsigned char d_021E8CBE[];
void func_021E7270(char *p)
{
    int i;
    for (i = 0; i < 6; i++) {
        if (*(void **)(p + i * 4 + 0x16c)) {
            func_0204B3B4(*(void **)(p + i * 4 + 0x16c));
            *(void **)(p + i * 4 + 0x16c) = 0;
        }
        if (*(void **)(p + i * 4 + 0x1a8)) {
            func_0204B3B4(*(void **)(p + i * 4 + 0x1a8));
            *(void **)(p + i * 4 + 0x1a8) = 0;
        }
    }
    for (i = 0; i < 6; i++)
        func_0204A8D4(*(unsigned *)(p + i * 4 + 0x1c4));
    func_0204AFD8(*(unsigned *)&((struct Obj00133 *)p)->f1E0);
    func_0204ADA4(*(unsigned *)&((struct Obj00133 *)p)->f1E4);
    func_0204A8D4(*(unsigned *)&((struct Obj00133 *)p)->f1F8);
    func_0204ADA4(*(unsigned *)&((struct Obj00133 *)p)->f1F4);
    func_0204AFD8(*(unsigned *)&((struct Obj00133 *)p)->f1FC);
}
