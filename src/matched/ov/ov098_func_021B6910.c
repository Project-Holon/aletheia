/*
 * unit:     yes
 * address:  0x021B6910
 * packet:   pkt_ov098_021B6910
 * region:   ov098
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_021B6910, func_021B694C, func_021B6988
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 *   func_021B6140  0x021B6140  thumb  ov098
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_021B6B8C  0x021B6B8C  thumb  ov098
 *   STRBUF_Delete  0x02045808  arm
 *   func_021B6148  0x021B6148  thumb  ov098
 *   func_0201F02C  0x0201F02C  thumb
 */
#include "../include/Obj07932.h"
#include "../include/Obj07933.h"
#include "../include/Obj07934.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern int func_021B6140(void *p);
extern u32 func_021B6148(u8 *p);
struct WordSet;
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021B6B8C(char *a, int b);
extern void STRBUF_Delete(struct U16Vec *vec);

void func_021B6910(int a, int b) {
    int r;
    int t;
    r = (int)func_02045EC0((struct MsgBank *)(((struct Obj07932 *)a)->f20), 0);
    t = func_021B6140((void *)b);
    func_0201EEF4(((struct Obj07932 *)a)->f30, 0, (void *)t);
    func_0201F250((struct WordSet *)(*(int *)&((struct Obj07932 *)a)->f30), (void *)(((struct Obj07932 *)a)->f2C), (void *)r);
    func_021B6B8C((char *)a, 0x50);
    STRBUF_Delete((struct U16Vec *)r);
}

void func_021B694C(int a, int b) {
    int r;
    int t;
    r = (int)func_02045EC0((struct MsgBank *)(((struct Obj07933 *)a)->f20), 3);
    t = func_021B6148((u8 *)b);
    func_0201F02C((struct WordSet *)(((struct Obj07933 *)a)->f30), 0, (void *)t);
    func_0201F250((struct WordSet *)(((struct Obj07933 *)a)->f30), (void *)(((struct Obj07933 *)a)->f2C), (void *)r);
    func_021B6B8C((char *)a, 0);
    STRBUF_Delete((struct U16Vec *)r);
}

void func_021B6988(int a, int b) {
    int r;
    int t;
    r = (int)func_02045EC0((struct MsgBank *)(((struct Obj07934 *)a)->f20), 1);
    t = func_021B6140((void *)b);
    func_0201EEF4(((struct Obj07934 *)a)->f30, 0, (void *)t);
    func_0201F250((struct WordSet *)(*(int *)&((struct Obj07934 *)a)->f30), (void *)(((struct Obj07934 *)a)->f2C), (void *)r);
    func_021B6B8C((char *)a, 0x50);
    STRBUF_Delete((struct U16Vec *)r);
}
