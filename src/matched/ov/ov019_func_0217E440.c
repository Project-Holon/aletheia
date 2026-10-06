/*
 * function: func_0217E440
 * address:  0x0217E440
 * packet:   pkt_ov019_0217E440
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0217BB20  0x0217BB20  thumb  ov019
 *   func_0217F074  0x0217F074  thumb  ov019
 *   func_0217B8E4  0x0217B8E4  thumb  ov019
 *   func_0217B9CC  0x0217B9CC  thumb  ov019
 *   func_0217B9F4  0x0217B9F4  thumb  ov019
 *   func_0217FE38  0x0217FE38  thumb  ov019
 *   func_0217FE24  0x0217FE24  thumb  ov019
 *   func_02175240  0x02175240  thumb  ov012
 *   func_02175208  0x02175208  thumb  ov012
 *   func_02175214  0x02175214  thumb  ov012
 *   func_02174D98  0x02174D98  thumb  ov012
 *   func_02174DF0  0x02174DF0  thumb  ov012
 *   func_02012934  0x02012934  thumb
 *   func_0201AC2C  0x0201AC2C  thumb
 *   func_0201A2A8  0x0201A2A8  thumb
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_0203D378  0x0203D378  arm
 */
#include "../include/Obj09416.h"

typedef unsigned char u8;

typedef struct {
    int f0;
    int f4;
    void *f8;
} Sys;

int func_0217BB20(char *p);
typedef unsigned int   u32;
struct BigObj;
void func_0217F074(void *p);
int func_0217B8E4(char *p, char v);
void *func_0217B9CC(char *p);
void func_0217B9F4(void *h);
void func_0217FE38(u8 *p);
int func_0217FE24(u8 *p);
void func_02175240(u8 *p, int v);
void func_02175208(u8 *p);
int func_02175214(u8 *p);
u32 func_02174D98(u32 p);
int func_02174DF0(u32 v);
void *func_02012934(const struct BigObj *p);
struct Link;
struct Rec534;
void func_0201AC2C(const struct Rec534 *src, struct Rec534 *dst);
void func_0201A2A8(void *a0, void *a1);
struct Entry;
struct Entry *func_020399A8(void);
u32 func_0203D1A4(struct Link *p);
struct Link;
void func_02039C68(struct Link *a, unsigned int b, unsigned int c);
unsigned int func_02039CB4(struct Link *a, unsigned int b, unsigned int c);
u32 func_0203D378(void);

int func_0217E440(u8 *w, void *obj, int a2, u8 *state)
{
    u8 *p;
    int idx;
    void *h;

    p = *(u8 * *)&((struct Obj09416 *)w)->f355C;
    idx = func_0203D1A4((struct Link *)((int)func_020399A8()));
    if (func_0217BB20((char *)w) == 1) {
        func_0217F074(w);
        return 1;
    }
    switch (*state) {
    case 0:
        switch (p[0x16d]) {
        case 0:
        default:
            func_0201AC2C(func_02012934((*(Sys * *)&((struct Obj09416 *)w)->f0)->f8), (struct Rec534 *)(((int *)(p + 0x148))[idx]));
            break;
        case 1:
            h = func_0217B9CC((char *)w);
            func_0201AC2C(h, (struct Rec534 *)(((int *)(p + 0x148))[idx]));
            func_0217B9F4(h);
            break;
        }
        func_0201A2A8((void *)(((struct Obj09416 *)w)->f352C), (void *)(((int *)(p + 0x148))[idx]));
        (*state)++;
        break;
    case 1:
        func_02175240(p, 1);
        func_0217FE38(p);
        func_02175208(p);
        func_02039C68((struct Link *)func_020399A8(), 0x14, 0x14);
        (*state)++;
        break;
    case 2:
        if (func_02039CB4((struct Link *)func_020399A8(), 0x14, 0x14) == 1)
            (*state)++;
        break;
    case 3:
        if (func_02174D98(((int *)(p + 0x148))[idx]) == 1)
            (*state)++;
        break;
    case 4:
        if (func_02175214(p) == 1)
            (*state)++;
        break;
    case 5:
        func_02039C68((struct Link *)func_020399A8(), 0x10, 0x14);
        (*state)++;
        break;
    case 6:
        if (func_02039CB4((struct Link *)func_020399A8(), 0x10, 0x14) == 1)
            (*state)++;
        break;
    case 7:
        if (func_0203D378() == 1) {
            if (func_02174DF0((u32)(p + 0xcc)) == 1)
                (*state)++;
        } else {
            (*state)++;
        }
        break;
    case 8:
        if (func_0217FE24(p) == 1) {
            func_0217B8E4((char *)w, 0x30);
            return 1;
        }
        break;
    }
    return 0;
}
