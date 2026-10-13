/*
 * function: func_021BC958
 * address:  0x021BC958
 * packet:   pkt_ov099_021BC958
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_MENULIST_Main  0x020200CC  thumb
 *   func_021BA8EC  0x021BA8EC  thumb  ov099
 *   func_021BA8BC  0x021BA8BC  thumb  ov099
 *   BMP_MENULIST_Delete  0x0202020C  thumb
 *   BMP_MENUWORK_Delete  0x0201F868  thumb
 *
 * Twins: func_021BCA14 (+0x22 byte, +0x134e halfword) and func_021BCAD0
 * (stores 1 - r at +0x20).
 */
#include "../include/Obj01915.h"
#include "../include/Obj22029.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

struct Descriptor;
extern void *func_02045770(struct Descriptor *);
typedef signed int     s32;
struct Obj;
struct PrintSys;
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern s32 BMP_MENULIST_Main(struct Obj *o);
extern void func_021BA8EC(char *p);
extern int func_021BA8BC(void *p);
extern void BMP_MENULIST_Delete(struct Obj *o, u16 *a, u16 *b);
extern u32 BMP_MENUWORK_Delete(void *p);

int func_021BC958(char *p, int v)
{
    int r;
    int q;

    q = ((struct Obj01915 *)p)->f1B8;
    if (((struct Obj01915 *)p)->f1B0 != 0) {
        if (func_0201C6C4((struct PrintSys *)q, (void *)((int)func_02045770((struct Descriptor *)((struct Obj01915 *)p)->f1AC))) == 0) {
            BMP_WIN_TransferChars((struct Descriptor *)((struct Obj01915 *)p)->f1AC);
            ((struct Obj01915 *)p)->f1B0 = 0;
        }
    }
    r = BMP_MENULIST_Main((struct Obj *)(((struct Obj01915 *)p)->fBC));
    if (r != -2) {
        if (r == -1) {
            return v;
        }
        ((struct Obj01915 *)p)->f134C = r;
        ((struct Obj22029 *)(*(char * *)&((struct Obj01915 *)p)->f248))->f21 = r;
    }
    ((struct Obj01915 *)p)->f1CC = 0x4e;
    func_021BA8EC(p);
    ((struct Obj01915 *)p)->f1A4 = (void *)func_021BA8BC(((struct Obj01915 *)p)->f1A4);
    BMP_MENULIST_Delete((struct Obj *)(((struct Obj01915 *)p)->fBC), 0, (u16 *)(p + 0x236));
    BMP_MENUWORK_Delete((void *)(((struct Obj01915 *)p)->fB8));
    return v;
}
