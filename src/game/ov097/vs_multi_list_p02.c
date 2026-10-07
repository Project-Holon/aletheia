/*
 * file:     vs_multi_list_p02.c
 * unit:     yes
 * function: func_021F6A28, func_021F6A98, func_021F6B1C, func_021F6B38
 * address:  0x021F6A28
 * region:   ov097
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02045088  0x02045088  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_021F6B7C  0x021F6B7C  thumb  ov097
 *   func_021F6CE4  0x021F6CE4  thumb  ov097
 *   func_021F6D70  0x021F6D70  thumb  ov097
 *   func_021F6EE8  0x021F6EE8  thumb  ov097
 *   func_020452E8 0x020452E8 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0201C6C4  0x0201C6C4  thumb
 */
#include "../../matched/include/Obj07928.h"
#include "../../matched/include/Obj10194.h"

struct Descriptor;
struct CharBuf;
struct PrintSys;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char  u8;

extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern void func_02045088(u16 heapId);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *);
extern void func_021F6B7C(int, int);
extern void func_021F6CE4(int, int);
extern void func_021F6D70(char *p, int idx);
extern void func_021F6EE8(unsigned p, unsigned i);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020450C8(void);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
void func_021F6A28(int *p);
void func_021F6A98(int a);
void func_021F6B1C(u8 *p);
void func_021F6B38(char *p);


void func_021F6A28(int *p)
{
    int *s;
    int a;
    int b;
    unsigned i;

    s = (int *)p[0];
    if (s[2] == 0) {
        a = s[0];
        b = s[1];
    } else {
        a = s[1];
        b = s[0];
    }
    for (i = 0; i < 3; i++) {
        if (func_0201AA18((void *)a) > i)
            p[0xf8 / 4 + i] = (int)func_0201AB28((void *)a, i);
        else
            p[0xf8 / 4 + i] = 0;
        if (func_0201AA18((void *)b) > i)
            p[0x104 / 4 + i] = (int)func_0201AB28((void *)b, i);
        else
            p[0x104 / 4 + i] = 0;
    }
}


void func_021F6A98(int a)
{
    unsigned int i;
    int *p;

    func_02045088(0x71);
    for (i = 0; i < 6; i++)
        *(int *)(a + i * 8 + 0x20) = func_020450F0(0, 0, 0, 0xf, 5, 9, 1);
    for (i = 0; i < 6; i++) {
        p = (int *)(a + i * 8);
        func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)p[8])), 0);
        if (*(int *)(a + i * 4 + 0xf8) != 0) {
            func_021F6B7C(a, i);
            func_021F6CE4(a, i);
            func_021F6D70((char *)a, i);
            func_021F6EE8(a, i);
        } else {
            func_02045334((struct Descriptor *)p[8]);
        }
    }
}

void func_021F6B1C(u8 *p) { u32 i; for(i=0; i<6; i++) { func_020452E8(*(void **)((u32)p+i*8+0x20)); } func_020450C8(); }


void func_021F6B38(char *p)
{
    unsigned i;
    char *e;
    int q;

    func_0201C4E4((struct PrintSys *)(((struct Obj10194 *)p)->f1C));
    for (i = 0; i < 6; i++) {
        q = ((struct Obj10194 *)p)->f1C;
        e = p + i * 8;
        if (((struct Obj07928 *)e)->f24 != 0) {
            if (func_0201C6C4((struct PrintSys *)q, (void *)((int)func_02045770((struct Descriptor *)((struct Obj07928 *)e)->f20))) == 0) {
                func_02045334((struct Descriptor *)((struct Obj07928 *)e)->f20);
                ((struct Obj07928 *)e)->f24 = 0;
            }
        }
    }
}
