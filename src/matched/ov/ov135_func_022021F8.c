/*
 * function: func_022021F8
 * address: 0x022021F8
 * packet: pkt_ov135_022021F8
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 022022B6..022022B8 zero alignment padding.
 * symbols:
 *   func_02202608 0x02202608 thumb ov135
 *   func_02007A18 0x02007A18 thumb
 *   func_022026A0 0x022026A0 thumb ov135
 *   func_0200ADB8 0x0200ADB8 thumb
 *   func_02007664 0x02007664 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_0201AB28 0x0201AB28 thumb
 *   func_0201A9C8 0x0201A9C8 thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_02012F98 0x02012F98 thumb
 *   func_02012934 0x02012934 thumb
 *   func_02007C34 0x02007C34 thumb
 *   func_0200AD94 0x0200AD94 thumb
 */
#include "../include/Obj01260.h"
#include "../include/Obj23460.h"
#include "../include/Obj23461.h"
#include "../include/Obj23462.h"
#include "../include/Obj23463.h"
#include "../include/Obj23464.h"
#include "../include/Obj23465.h"
#include "../include/Obj23466.h"
#include "../include/Obj23467.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void *func_02202608(unsigned);
typedef signed int     s32;
typedef unsigned int   u32;
struct BigObj;
struct Ctx;
struct Party;
struct PerapVoice;
struct Rec0200AD94;
struct Sub020079BCEntry;
extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);
extern void func_022026A0(u8 *p, u32 k);
extern void func_0200ADB8(void *dest, const void *src, u32 a2);
extern void func_02007664(void *, unsigned, unsigned);
extern void func_020307B0(void *);
extern void *func_0201AB28(void *, unsigned);
extern u32 func_0201A9C8(struct Party *p, s32 idx);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012F98(void *);
extern void *func_02012934(const struct BigObj *p);
extern void func_02007C34(struct PerapVoice *p, void *a);
extern void func_0200AD94(struct Rec0200AD94 *p, u16 v);
void func_022021F8(u8 *p, int flag)
{
    void *mon;
    void *save;
    void *box;
    if (((struct Obj01260 *)p)->fC4 != 0xFF) {
        mon = func_02202608(0x48);
        func_022026A0((u8 *)func_02007A18(((struct Obj23460 *)(*(u8 * *)&((struct Obj01260 *)p)->f0))->fC, ((struct Obj01260 *)p)->fC4, ((struct Obj01260 *)p)->fC6), (u32)mon);
        if (flag) func_0200ADB8(((struct Obj23461 *)(*(u8 * *)&((struct Obj01260 *)p)->f0))->f0, mon, ((struct Obj01260 *)p)->fC4);
        func_02007664(((struct Obj23462 *)(*(u8 * *)&((struct Obj01260 *)p)->f0))->fC, ((struct Obj01260 *)p)->fC4, ((struct Obj01260 *)p)->fC6);
        func_020307B0(mon);
    } else {
        mon = func_0201AB28(((struct Obj23463 *)(*(u8 * *)&((struct Obj01260 *)p)->f0))->f8, ((struct Obj01260 *)p)->fC6);
        if (flag) func_0200ADB8(((struct Obj23464 *)(*(u8 * *)&((struct Obj01260 *)p)->f0))->f0, mon, ((struct Obj01260 *)p)->fC4);
        func_0201A9C8(((struct Obj23465 *)(*(u8 * *)&((struct Obj01260 *)p)->f0))->f8, ((struct Obj01260 *)p)->fC6);
        save = func_020120F4(((struct Obj23466 *)(*(u8 * *)&((struct Obj01260 *)p)->f0))->f40);
        box = func_02012F98(save);
        func_02007C34(box, func_02012934(save));
    }
    if (flag) func_0200AD94(((struct Obj23467 *)(*(u8 * *)&((struct Obj01260 *)p)->f0))->f0, 1);
}
