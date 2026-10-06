/*
 * function: func_021B38E0
 * address:  0x021B38E0
 * packet:   pkt_ov021_021B38E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Spill slots: the image puts the idx*4 offset at sp+4, q at sp+8, n at sp+0xc.
 * A single-def offset local is folded into a compiler temporary, and temps
 * take slots above every spilled local; the second (redundant) assignment in
 * the flag arm keeps off a real local, and declaration order (n, q, ..., off;
 * last declared lowest) gives the image layout.
 *
 * symbols:
 *   func_021B38E0 0x021B38E0 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_02021288 0x02021288 thumb
 *   func_0201F81C 0x0201F81C thumb
 *   func_021B385C 0x021B385C thumb ov021
 *   func_02020FE4 0x02020FE4 thumb
 *   func_0201102C 0x0201102C thumb
 *   func_021B3834 0x021B3834 thumb ov021
 *   func_0201F878 0x0201F878 thumb
 *   func_02045C04 0x02045C04 arm
 *   d_021D946C 0x021D946C data
 *   d_021D95DE 0x021D95DE data
 *   d_021DE1A8 0x021DE1A8 data
 */
#include "../include/Obj00037.h"
#include "../include/Obj12843.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef unsigned int   u32;
struct MsgBank;
struct Rec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02021288(u32 id);
extern void *func_0201F81C(int, int);
extern void func_021B385C(char *p, int idx, int mode, int val, int arg);
extern u32 func_02020FE4(void *a, u32 sel, u32 id);
extern u32 func_0201102C(u32 v);
struct Slot;
extern u32 func_021B3834(u8 *p, int n);
extern void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern void func_02045C04(struct Rec *rec);

extern u8 d_021D946C[];
extern u8 d_021D95DE[];
extern u16 *d_021DE1A8[];

void func_021B38E0(char *p, int a, int b, int c)
{
    int n;
    void *q = func_02045B38(0, 2, 54, ((struct Obj00037 *)p)->f4);
    int idx;
    int k;
    int v;
    char *e;
    int off;

    if (a == 0xff) {
        idx = d_021D946C[c];
    } else {
        idx = b + 6;
    }
    off = idx * 4;
    if (func_02021288(**(u16 **)((char *)d_021DE1A8 + off))) {
        ((struct Obj00037 *)p)->f162 = 1;
        off = idx * 4;
    }
    n = d_021D95DE[idx];
    ((struct Obj00037 *)p)->f180 = func_0201F81C(n + 1, ((struct Obj00037 *)p)->f4);
    for (k = 0; k < n; k++) {
        v = (*(u16 **)((char *)d_021DE1A8 + off))[k];
        func_021B385C(p, k, ((struct Obj00037 *)p)->f162, v, (int)q);
        e = p + k * 8;
        ((struct Obj12843 *)e)->f20 = v;
        ((struct Obj12843 *)e)->f24 = func_0201102C(func_02020FE4((void *)v, 0, ((struct Obj00037 *)p)->f4));
    }
    ((struct Obj00037 *)p)->f160 = k;
    func_021B3834((u8 *)(p + 32), ((struct Obj00037 *)p)->f160);
    func_0201F878((struct Slot *)(*(char * *)&((struct Obj00037 *)p)->f180 + k * 8), (u32)(((struct Obj00037 *)p)->f188), 11, -2, ((struct Obj00037 *)p)->f4);
    func_02045C04(q);
}
