/*
 * function: func_021F81C8
 * address: 0x021F81C8
 * packet: pkt_ov135_021F81C8
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_021F91A0 0x021F91A0 thumb ov135
 *   func_021F7F9C 0x021F7F9C thumb ov135
 *   func_021F8098 0x021F8098 thumb ov135
 *   func_021F8154 0x021F8154 thumb ov135
 */
#include "../include/Obj08180.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void STRBUF_Delete(struct U16Vec *vec);
extern int func_021F91A0(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g);
extern void func_021F7F9C(void *, void *, u32, u32, u32, u16, void *);
extern void func_021F8098(void *, void *, int, int, u32, int, u16, void *);
extern void func_021F8154(void *, void *, int, u32, u32, u16, int, void *);
void func_021F81C8(void *bank, void *names, int unused, u8 *win, u32 index, int mode, int place, void *g)
{
    int i;
    void *str;
    int show = 1;
    str = func_02045EC0(bank, 0x6b);
    func_021F91A0(((struct Obj08180 *)win)->f0, (u32)str, 1, 0, 0, 0x440, (u32)g);
    for (i = 1; i < 3; i++)
        BMP_Clear(func_02045770(*(void **)(win + i * 4)), 0);
    func_021F7F9C(((struct Obj08180 *)win)->f4, names, index, 0, 0, 0x440, g);
    if (index == 29 && mode == 2)
        show = 0;
    else if (index == 32 && mode == 1)
        show = 0;
    if (show) {
        if (mode == 1 || mode == 2)
            func_021F8098(((struct Obj08180 *)win)->f4, bank, mode, 0, 0, 70, 0x440, g);
    }
    func_021F8154(((struct Obj08180 *)win)->f8, bank, place, 2, 0, 0x440, 0, g);
    STRBUF_Delete(str);
}
