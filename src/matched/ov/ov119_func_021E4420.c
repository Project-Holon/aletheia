/*
 * function: func_021E4420
 * address: 0x021E4420
 * packet: pkt_ov119_021E4420
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * arithmetic: count additions wrap unsigned then compare signed results; indexed address uses typed word-pointer addition under valid-object preconditions; the guarded int counter never increments above INT_MAX.
 * note 2026-10-05 (wave D9r lane 131): removed the 11 dead first assignments
 * (`off1 = 0x5F4;` before `off1 = 0x6B8;`; `off3 = 0x828;` before `off3 =
 * 0x730;` and 9 more). Game code has no line table, so these were stand-ins.
 * The plain single assignment gives EXACT in --lang c99 and --lang c: the
 * output bytes do not change. Older text in this header that asks for the
 * double assignment is superseded.
 *
 * symbols:
 *   func_02049B40 0x02049B40 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0200785C 0x0200785C thumb
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045334 0x02045334 arm
 *   BMP_WIN_SetPosY 0x02045788 arm
 */
#include "../include/Obj00001.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
struct CharBuf;
struct Descriptor;
struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0200785C(void *,u32,void *);
extern void func_0201DD78(u32,u32,u32);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
extern void func_02045334(struct Descriptor *d);
extern void BMP_WIN_SetPosY(struct Descriptor *p, u8 v);
void func_021E4420(char *p)
{
    int off1, h, off, off2, off3;
    int a,b,c,d,e,f,g;
    int i, zero;
    char *q;
    off = 0x5F4;
    func_02049B40(23,5,4,448,32,*(u16 *)(p+off));
    i = 0;
    if (i >= (int)((u32)*(int *)(p+off+0x3C)+1u)) goto done;
        zero = 0;
        off1 = 0x6B8;
        off = 0x630;
        off3 = 0x730;
        off2 = 0x730;
        a = 0x6B8;
        b = 0x6B8;
        c = 0x728;
        d = 0x730;
        e = 0x6B8;
        f = 0x6B8;
        g = 0x630;
        h = 0x6B8;
        do {
            q = (char *)((u32 *)p+i);
            if (*(u32 *)(q+h) == 0)
                *(u32 *)(q+off1) = func_020450F0(5,0,0,15,2,14,0);
            if (i == *(int *)(p+off))
                func_02045CAC(((struct Obj00001 *)p)->f720,16,*(void **)(p+off2));
            else func_0200785C(((struct Obj00001 *)p)->f828,i,*(void **)(p+off3));
            func_0201DD78(15,2,zero);
            func_02043B5C(func_02045770(*(void **)(q+a)),zero);
            func_0201C7A4(func_02045770(*(void **)(q+b)),zero,1,*(void **)(p+d),*(void **)(p+c));
            func_02045334(*(void **)(q+e));
            BMP_WIN_SetPosY(*(void **)(q+f),zero);
        } while (++i < (int)((u32)*(int *)(p+g)+1u));
done:;
}
