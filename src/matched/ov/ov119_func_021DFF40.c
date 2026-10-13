/*
 * function: func_021DFF40
 * address: 0x021DFF40
 * packet: pkt_ov119_021DFF40
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * 2026-10-02: the 02045CAC/0201F250/021E0FF4 statements are repeated in both arms of
 *  the 0x11EE test (the compiler tail-merges them), which keeps the 0x834 and 0x724
 *  constants live into the merged tail.
 * symbols:
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_021D8FA4 0x021D8FA4 thumb ov119
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   MSGDATA_ReadString 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 *   func_021E0FF4 0x021E0FF4 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DFFE0 0x021DFFE0 thumb ov119
 */
#include "../include/Obj01252.h"
extern int func_021D8AA8(void *);
extern void *func_021D8FA4(void *, int);
typedef unsigned int   u32;
struct MsgBank;
struct WordSet;
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021E0FF4(void *, int, int);
extern void func_021D8E84(void *, int);
extern void func_021DFFE0(char *p);
void func_021DFF40(char *p)
{
    void *a;
    if (((struct Obj01252 *)p)->fF2C < 0xC8) {
        return;
    }
    if (func_021D8AA8(p)) {
        a = func_021D8FA4(p, 0);
    } else {
        a = func_021D8FA4(p, 1);
    }
    func_0201EEF4(((struct Obj01252 *)p)->f724, 1, a);
    func_0201F02C(((struct Obj01252 *)p)->f724, 0, (void *)(((struct Obj01252 *)p)->f834));
    if (((struct Obj01252 *)p)->f118C != 7 && ((struct Obj01252 *)p)->f118C != 8) {
        if (((struct Obj01252 *)p)->f11EE) {
            MSGDATA_ReadString(((struct Obj01252 *)p)->f720, 0x84, ((struct Obj01252 *)p)->f73C);
            func_0201F250(((struct Obj01252 *)p)->f724, ((struct Obj01252 *)p)->f738, ((struct Obj01252 *)p)->f73C);
            func_021E0FF4(p, 1, 0);
        } else {
            MSGDATA_ReadString(((struct Obj01252 *)p)->f720, 0x31, ((struct Obj01252 *)p)->f73C);
            func_0201F250(((struct Obj01252 *)p)->f724, ((struct Obj01252 *)p)->f738, ((struct Obj01252 *)p)->f73C);
            func_021E0FF4(p, 1, 0);
        }
    }
    func_021D8E84(p, (int)func_021DFFE0);
}
