/*
 * function: func_021EB208
 * address: 0x021EB208
 * packet: pkt_ov170_021EB208
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`windows = (void **)p;` before `windows = (void **)(p + 0x94);`). Game
 * code has no line table, so these were stand-ins. The plain single
 * assignment gives EXACT in --lang c99 and --lang c: the output bytes do not
 * change. Older text in this header that asks for the double assignment is
 * superseded.
 *
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_021EAC28 0x021EAC28 thumb ov170
 *   func_021EABD0 0x021EABD0 thumb ov170
 *   func_021EABA0 0x021EABA0 thumb ov170
 *   func_021EAAE4 0x021EAAE4 thumb ov170
 *   func_02045B38 0x02045B38 arm
 *   func_02045C04 0x02045C04 arm
 */
#include "../include/Obj08244.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Rec;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_021EAC28(char *, int, void *, unsigned, int, int, unsigned, unsigned short);
extern void func_021EABD0(unsigned char *w, int i, void *bank, unsigned idx, int x, int y, unsigned font, unsigned short color);
extern void func_021EABA0(void **);
extern void func_021EAAE4(unsigned char *p, unsigned i);
typedef struct { unsigned char pad[18]; unsigned char low : 7; unsigned char flag : 1; unsigned char kind : 4; unsigned char enabled : 1; unsigned char rest : 3; } Entry;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02045C04(struct Rec *rec);
void func_021EB208(char *p, Entry *e, int i)
{
    void **windows;
    unsigned j;
    void *bank;
    windows = (void **)(p + 0x94);
    func_02043B5C(func_02045770(windows[i * 2]), 0);
    j = 0;
    bank = func_02045B38(0, 2, 203, 0x804c);
    if (!e->flag) {
        for (; j < 4; j++) {
            func_021EABD0((unsigned char *)p, i, bank, *(unsigned short *)((char *)e + 0x14 + j * 2), 0, j * 16, ((struct Obj08244 *)p)->f78, 0x440);
        }
    } else {
        func_021EABD0((unsigned char *)p, i, ((struct Obj08244 *)p)->f80, 106, 0, 0, ((struct Obj08244 *)p)->f78, 0x440);
    }
    func_02045C04(bank);
    func_021EABA0(windows + i * 2);
}
