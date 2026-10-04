/*
 * unit:     yes
 * function: func_021BA880, func_021BA984
 * address:  0x021BA880
 * packet:   pkt_ov088_021BA880
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 0x021BA984 is an unlabelled tail-call stub (function_starts seed);
 * verified with tu over 0x021BA880..0x021BA990 (272 bytes).
 *
 * symbols:
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   func_02040EBC  0x02040EBC  arm
 *   func_021BC054  0x021BC054  thumb  ov088
 *   func_021BBF98  0x021BBF98  thumb  ov088
 *   func_021BC080  0x021BC080  thumb  ov088
 *   func_021BBF1C  0x021BBF1C  thumb  ov088
 *   func_021BBFA8  0x021BBFA8  thumb  ov088
 *   func_020362DC  0x020362DC  arm
 *   func_020061E4  0x020061E4  thumb
 *   d_021BD784     0x021BD784  data  ov088  a4
 */
#include "../include/Obj02127.h"

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 mask;
    u32 msg;
} MsgEnt;

extern const MsgEnt d_021BD784[8];

extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_02040EBC(u32 a0, u32 a1);
extern int func_021BC054(char *p, int v);
extern void func_021BBF98(char *p);
extern int func_021BC080(char *p, int v);
extern void func_021BBF1C(char *p, u32 a1);
extern int func_021BBFA8(char *p);
extern u32 func_020362DC(void);
extern void func_020061E4(u32);

int func_021BA880(char *p)
{
    u32 i;
    switch (((struct Obj02127 *)p)->f12A) {
    case 0:
        func_020434DC(0x1e, 0);
        func_02043598(0x17, 0);
        func_02040EBC(0, 0x7d8c);
        func_02040EBC(4, 0x7d8c);
        ((struct Obj02127 *)p)->f12A = ((struct Obj02127 *)p)->f12A + 1;
        return func_021BC054(p, 10);
    case 1:
        for (;;) {
            i = ((struct Obj02127 *)p)->f14C;
            if (i >= 8) {
                func_021BBF98(p);
                ((struct Obj02127 *)p)->f12A = 3;
                return func_021BC080(p, 10);
            }
            if ((d_021BD784[i].mask & ((struct Obj02127 *)p)->f148) == 0) {
                ((struct Obj02127 *)p)->f14C += 1;
                continue;
            }
            func_021BBF1C(p, d_021BD784[i].msg);
            ((struct Obj02127 *)p)->f14C += 1;
            ((struct Obj02127 *)p)->f12A = ((struct Obj02127 *)p)->f12A + 1;
            break;
        }
        break;
    case 2:
        if (func_021BBFA8(p) == 0 && (func_020362DC() & 3)) {
            func_020061E4(0x547);
            ((struct Obj02127 *)p)->f12A = 1;
        }
        break;
    case 3:
        func_020434DC(0x1e, 1);
        func_02043598(0x17, 1);
        ((struct Obj02127 *)p)->f12A = 0;
        return func_021BC054(p, 5);
    }
    return 10;
}

int func_021BA984(char *p)
{
    return func_021BC080(p, 1);
}
