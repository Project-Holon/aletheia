/*
 * function: func_021CE5AC
 * address:  0x021CE5AC
 * packet:   pkt_ov021_021CE5AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The extent runs long into the unlabelled leaf func_021CE6F0 (filed on its
 * own). Cases 1 and 3 are identical bodies the compiler tail-merged.
 *
 * symbols:
 *   func_02190EF0  0x02190EF0  thumb  ov021
 *   func_021CE9E4  0x021CE9E4  thumb  ov021
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02190BE4  0x02190BE4  thumb  ov021
 *   func_02190C78  0x02190C78  thumb  ov021
 *   func_021909BC  0x021909BC  thumb  ov021
 *   func_021CE73C  0x021CE73C  thumb  ov021
 *   data_021DB498  0x021DB498  data   ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00011.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 h;
    u32 result;
    u8  state;
} Sub;

struct Handle;
extern u32 func_02190EF0(u32 *p);
extern void func_021CE9E4(u32 *p, int n);
extern u32 func_02188C54(u8 *p);
extern u32 *func_02190BE4(u16 *a, u32 b);
extern int func_02190C78(struct Handle *h);
extern int func_021909BC(u32 a);
extern int func_021CE73C(u32 *p);
extern u8 data_021DB498[];

u32 func_021CE5AC(u32 *p)
{
    Sub *q;
    u32 r;

    q = (Sub *)((u8 *)p + 0x130);
    if (!func_02190EF0((u32 *)p[5])) {
        return 0;
    }
    switch (q->state) {
    case 0:
        func_021CE9E4(p, *(u16 *)(data_021DB498 + ((u8 *)p)[0x520] * 12 + 2));
        q->state++;
        break;
    case 1:
        q->h = (u32)func_02190BE4((u16 *)func_02188C54((u8 *)p[0]), 0);
        q->state++;
        break;
    case 2:
        r = func_02190C78((struct Handle *)q->h);
        if (r == 2) {
            break;
        }
        func_021909BC(q->h);
        q->h = 0;
        if (r == 1) {
            q->result = 2;
            q->state = 100;
        } else if (func_021CE73C(p) <= 1) {
            func_021CE9E4(p, *(u16 *)(data_021DB498 + ((u8 *)p)[0x520] * 12 + 4));
            q->state = 5;
        } else {
            func_021CE9E4(p, 0xf);
            q->state++;
        }
        break;
    case 3:
        q->h = (u32)func_02190BE4((u16 *)func_02188C54((u8 *)p[0]), 0);
        q->state++;
        break;
    case 4:
        r = func_02190C78((struct Handle *)q->h);
        if (r == 2) {
            break;
        }
        func_021909BC(q->h);
        q->h = 0;
        if (r == 0) {
            func_021CE9E4(p, *(u16 *)(data_021DB498 + ((u8 *)p)[0x520] * 12 + 4));
            q->state++;
        } else {
            q->result = 2;
            q->state = 100;
        }
        break;
    case 5:
        q->state = 0xff;
        q->result = 1;
        break;
    case 100:
        if (func_021CE73C(p) > 1 && ((u8 *)p)[0x520] == 1) {
            ((struct Obj00011 *)p)->f574 = 9;
        } else {
            ((struct Obj00011 *)p)->f574 = 8;
        }
        q->state = 0xff;
        break;
    case 0xff:
        if (q->h) {
            func_021909BC(q->h);
            q->h = 0;
        }
        q->state = 0;
        return q->result;
    }
    return 0;
}
