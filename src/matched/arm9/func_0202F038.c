/*
 * function: TIME_ICON_Delete
 * address:  0x0202F038
 * packet:   pkt_0202EF98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_Delete   0x020437AC  arm
 *   func_020307B0   0x020307B0  arm
 *   func_02045770   0x02045770  arm
 *   BMP_Clear   0x02043B5C  arm
 *   BMP_WIN_TransferChars   0x02045334  arm
 *   func_020452E8   0x020452E8  arm
 *   func_02030EAC   0x02030EAC  arm
 *   TCBL_DeleteTask   0x02031194  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TIME_ICON_Delete.c \
 *       --func TIME_ICON_Delete --addr 0x0202F038 --cc 1.1p1 --thumb
 */
#include "../include/Obj01809.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct CharBuf;
struct Descriptor;
struct Node;
struct Obj020437AC;
struct TcblNode;
extern void BMP_Delete(struct Obj020437AC *p);
extern u32 func_020307B0(void *p);
struct Descriptor;
extern void *func_02045770(struct Descriptor *a);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *a);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02030EAC(struct Node *n);
extern void TCBL_DeleteTask(struct TcblNode *n);

void TIME_ICON_Delete(u8 *p)
{
    if (((struct Obj01809 *)p)->f0 == 0 && ((struct Obj01809 *)p)->f4 == 0) {
        BMP_Delete((struct Obj020437AC *)(((struct Obj01809 *)p)->fC));
        func_020307B0(p);
        return;
    }

    ((struct Obj01809 *)p)->f18 = 0;
    BMP_Clear((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj01809 *)p)->f8)), ((struct Obj01809 *)p)->f12);
    BMP_WIN_TransferChars((struct Descriptor *)((struct Obj01809 *)p)->f8);
    func_020452E8((struct Descriptor *)(((struct Obj01809 *)p)->f8));
    BMP_Delete((struct Obj020437AC *)(((struct Obj01809 *)p)->fC));

    if (((struct Obj01809 *)p)->f0 != 0) {
        func_02030EAC((struct Node *)(((struct Obj01809 *)p)->f0));
        func_020307B0(p);
        return;
    }

    if (((struct Obj01809 *)p)->f4 != 0)
        TCBL_DeleteTask((struct TcblNode *)(((struct Obj01809 *)p)->f4));
}
