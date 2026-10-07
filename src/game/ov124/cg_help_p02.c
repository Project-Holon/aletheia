/*
 * file:     cg_help_p02.c
 * unit:     yes
 * function: func_021D4698, func_021D46BC
 * address:  0x021D4698
 * region:   ov124
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02049B40 0x02049B40 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 */
#include "../../matched/include/Obj00991.h"
#include "../../matched/include/Obj00068.h"

struct Obj;
struct CharBuf;
struct Descriptor;
struct GfFont;
struct MsgBank;
struct R;
struct U16Vec;
struct Cfg;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 text; u16 color; u16 pad; u32 flag; } Request;

extern u32 func_020307B0(void *p);
extern void func_0204B3B4(struct Obj *);
extern void func_0204ADA4(u32);
extern void func_0204A8D4(u32);
extern void func_0204AFD8(u32);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern void func_0201DD78(u32, u32, u32);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02049B40(u32, u32, u32, u32, u32, u16);
extern void func_0201F5BC(u32, u32, u32, u32, u16);
extern u8 func_0201F548(int);
extern void func_0201DD68(void);
extern u32 func_0201C440(void *);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern u32 func_020450F0(u32, u32, u32, u32, u8, u8, u8);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_0201F73C(void *, int, int, int);
extern void func_020409B4(u32);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02027FEC(u32, u32, u32, u32, u8, u16);
extern void func_02045808(struct U16Vec *vec);
extern void func_0202843C(u8 *);
void func_021D4698(char *p);
void func_021D46BC(char *p);

void func_021D4698(char *p) {func_020307B0(((struct Obj00991 *)p)->f44);func_0204B3B4(*(struct Obj * *)&((struct Obj00991 *)p)->f5C);func_0204ADA4(((struct Obj00991 *)p)->f50);func_0204A8D4(((struct Obj00991 *)p)->f54);func_0204AFD8(((struct Obj00991 *)p)->f58);}

void func_021D46BC(char *p)
{
    Request req;
    ((struct Obj00068 *)p)->f28 = func_0201D7EC(23, 0, 0, 0, ((struct Obj00068 *)p)->f0);
    func_0201DD78(15, 2, 0);
    ((struct Obj00068 *)p)->f2C = func_02045B38(0, 2, 21, ((struct Obj00068 *)p)->f0);
    func_02049B40(23, 5, 4, 480, 32, ((struct Obj00068 *)p)->f0);
    func_0201F5BC(5, 1, 13, 0, ((struct Obj00068 *)p)->f0);
    func_02049B40(5, func_0201F548(0), 4, 416, 64, ((struct Obj00068 *)p)->f0);
    func_0201DD68();
    *(u32 *)&((struct Obj00068 *)p)->f30 = func_0201C440((void *)(u32)((struct Obj00068 *)p)->f0);
    ((struct Obj00068 *)p)->f34 = func_02027F60(4, 11, *(u32 *)&((struct Obj00068 *)p)->f28, *(u32 *)&((struct Obj00068 *)p)->f30, ((struct Obj00068 *)p)->f0);
    *(u32 *)&((struct Obj00068 *)p)->f24 = func_020450F0(5, 2, 4, 28, 4, 15, 1);
    *(u32 *)&((struct Obj00068 *)p)->f20 = func_020450F0(5, 2, 9, 28, 12, 15, 1);
    func_02043B5C(func_02045770(((struct Obj00068 *)p)->f24), 1);
    func_02045334((struct Descriptor *)*(u32 *)&((struct Obj00068 *)p)->f24);
    func_02045374((struct Cfg *)(*(u32 *)&((struct Obj00068 *)p)->f24));
    func_0201F73C(((struct Obj00068 *)p)->f24, 1, 1, 14);
    func_02043B5C(func_02045770(((struct Obj00068 *)p)->f20), 0);
    func_02045334((struct Descriptor *)*(u32 *)&((struct Obj00068 *)p)->f20);
    func_02045374((struct Cfg *)(*(u32 *)&((struct Obj00068 *)p)->f20));
    func_020409B4(5);
    func_020409B4(4);
    ((struct Obj00068 *)p)->f1C = 0;
    req.text = (u32)func_02045EC0(((struct Obj00068 *)p)->f2C, 24);
    req.color = 0x39e3;
    req.flag = 0;
    ((struct Obj00068 *)p)->f3C = func_02027FEC(*(u32 *)&((struct Obj00068 *)p)->f34, (u32)&req, 11, 21, 11, ((struct Obj00068 *)p)->f0);
    func_02045808((void *)req.text);
    req.text = (u32)func_02045EC0(((struct Obj00068 *)p)->f2C, 26);
    *(u32 *)&((struct Obj00068 *)p)->f38 = func_02027FEC(*(u32 *)&((struct Obj00068 *)p)->f34, (u32)&req, 0, 21, 11, ((struct Obj00068 *)p)->f0);
    func_02045808((void *)req.text);
    req.text = (u32)func_02045EC0(((struct Obj00068 *)p)->f2C, 25);
    req.flag = 1;
    ((struct Obj00068 *)p)->f40 = func_02027FEC(*(u32 *)&((struct Obj00068 *)p)->f34, (u32)&req, 22, 21, 10, ((struct Obj00068 *)p)->f0);
    func_02045808((void *)req.text);
    func_0202843C(*(u8 * *)&((struct Obj00068 *)p)->f38);
    *(u16 *)0x050005e2 = 0;
}
