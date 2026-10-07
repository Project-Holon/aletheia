/*
 * file:     scrcmd_proc_fld_p07.c
 * unit:     yes
 * function: func_021B4878, func_021B4894, func_021B4918
 * address:  0x021B4878
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02045808 0x02045808 arm
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CD10 0x0201CD10 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0201EF6C 0x0201EF6C thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 */
#include "../../matched/include/Obj01121.h"

struct CharBuf;
struct Descriptor;
struct Cfg;
struct MsgBank;
struct Rec;
struct U16Vec;
struct WordSet;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16_021B4878;

typedef signed char    s8;

typedef short s16_021B4894;

typedef signed int     s32;

extern u32 func_0201F73C(u32, u32, u32, u32);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void *func_02045770(struct Descriptor *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern signed char func_02012FFC(void);
extern struct Rec *func_0201CD10(u32 a0, s16_021B4894 a1, s16_021B4894 a2, u32 a3, u32 a4, s32 a5, u32 a6, u32 a7, u32 a8, u16 a9, u32 a10);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 a);
extern void func_0201EF6C(struct WordSet *p, u32 i, u32 v, u32 a, u32 b);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
int func_021B4878(u32 a);
void func_021B4894(char *w, u32 b);
void func_021B4918(char *w, u32 a, u16 b, u32 c, u16 d);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021B4878(u32 a)
{
func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)a)), 15);
return func_0201F73C(a, 0, 228, 9);
}


void func_021B4894(char *w, u32 b)
{
    u32 t;
    u32 win;

    t = (u32)func_02045EC0((struct MsgBank *)(((struct Obj01121 *)w)->f188), b);
    func_0201F250((struct WordSet *)(((struct Obj01121 *)w)->f190), (void *)(((struct Obj01121 *)w)->f198), (void *)t);
    func_02045808((struct U16Vec *)t);
    ((struct Obj01121 *)w)->f1B8 = (u32)func_0201CD10(((struct Obj01121 *)w)->f17C, 0, 0, ((struct Obj01121 *)w)->f198,
                                        ((struct Obj01121 *)w)->f8, func_02012FFC(), ((struct Obj01121 *)w)->f1B4, 0,
                                        ((struct Obj01121 *)w)->f4, 0xFFFF, 0);
    win = ((struct Obj01121 *)w)->f17C;
    func_02045334((struct Descriptor *)win);
    func_02045374((struct Cfg *)win);
    func_020409B4(func_02045730((struct Descriptor *)win));
}


/*
 * The spilled third parameter is narrow (u16 here; s16/u8 give the same
 * bytes): as u32/int its entry spill `str r2, [sp, #8]` lands after the
 * `lsls` instead of before it.
 *
 * Addresses are Black-image addresses.
 */
void func_021B4918(char *w, u32 a, u16 b, u32 c, u16 d)
{
    func_021B4878(((struct Obj01121 *)w)->f17C);
    func_0201EF6C((struct WordSet *)(((struct Obj01121 *)w)->f190), 0, b, 0, 0);
    func_0201EFA4((struct WordSet *)(((struct Obj01121 *)w)->f190), 1, d, 2, 0, 1);
    func_0201EFA4((struct WordSet *)(((struct Obj01121 *)w)->f190), 2, d * c, 7, 0, 1);
    func_021B4894((char *)((u32)w), a);
}
