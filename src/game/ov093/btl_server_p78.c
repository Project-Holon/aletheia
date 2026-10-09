/*
 * file:     btl_server_p78.c
 * unit:     yes
 * function: func_021C70E4, func_021C7194, func_021C71E0, func_021C728C, func_021C7330, func_021C7374, func_021C7474, func_021C75EC, func_021C7664, func_021C76F4, func_021C7780, func_021C77B0, func_021C7820, func_021C785C, func_021C78A8, func_021C78F4, func_021C7998, func_021C79E0, func_021C7A54, func_021C7AA0, func_021C7AD0, func_021C7B0C, func_021C7B3C, func_021C7B7C, func_021C7BA8, func_021C7BF8, func_021C7C18, func_021C7C24, func_021C7CBC, func_021C7CC8, func_021C7CD4, func_021C7CDC, func_021C7CE8, func_021C7CF4, func_021C7D00
 * address:  0x021C70E4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021CD568  0x021CD568  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   func_0201BD28  0x0201BD28  thumb
 *   func_021D7BA4  0x021D7BA4  thumb  ov093
 *   func_021D75A8  0x021D75A8  thumb  ov093
 *   func_0201C1D8  0x0201C1D8  thumb
 *   func_021D7674  0x021D7674  thumb  ov093
 *   func_021D7B10  0x021D7B10  thumb  ov093
 *   func_0201C1E8 0x0201C1E8 thumb
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D58A8 0x021D58A8 thumb ov093
 *   func_021D5AD8 0x021D5AD8 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021C2AB0 0x021C2AB0 thumb ov093
 *   func_021D5814 0x021D5814 thumb ov093
 *   func_021C82B8  0x021C82B8  thumb  ov093
 *   func_021D78AC  0x021D78AC  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021D7B2C  0x021D7B2C  thumb  ov093
 *   func_021D7B3C  0x021D7B3C  thumb  ov093
 *   func_02082BCC  0x02082BCC  arm
 *   func_021B8DDC  0x021B8DDC  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_021C7D24 0x021C7D24 thumb ov093
 *   func_021B86A0 0x021B86A0 thumb ov093
 */
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj07759.h"
#include "../../matched/include/Obj18319.h"
#include "../../matched/include/Obj18320.h"
#include "../../matched/include/Obj18322.h"
#include "../../matched/include/Obj18323.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

/* 021C7CD4  movs r1,#0x7e; lsls r1,#6; ldrh r0,[r0,r1] */
struct Q6 { u8 pad[0x1f80]; u16 v; };

extern void func_021CD568(u8 *w, u16 v, u32 id, ...);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021D74F8(int line);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int key, u32 val);
extern void func_021D7630(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int func_021D775C(int key);
extern void func_021D7540(int line);
extern u32 func_0201BD28(u32 v, u32 n);
extern int func_021D7BA4(int a);
extern void func_021D75A8(int key, u32 val);
extern u16 func_0201C1D8(void *p);
extern void func_021D7674(int key, u32 a, u32 b, u32 c);
extern u32 func_021D7B10(u32 a, u32 b);
extern int func_0201C1E8(int a);
extern u8 *func_021B9934(char *p, int i);
extern int func_021D58A8(u8 *, int);
extern int func_021D5AD8(u8 *, int);
extern int func_021D59B4(u8 *p, int k);
extern int func_021C2AB0(u8 *);
extern int func_021D5814(void *, int);
extern int func_021C82B8(void *p, int z);
extern u32 func_021D78AC(u32 range);
extern int func_021D76BC(int key, u32 val);
extern u32 func_021D7B2C(u32 a, u32 b);
extern u32 func_021D7B3C(u32 a, u32 b);
void func_02082BCC(void *, int, u32);
extern u8 func_021B8DDC(u32 x);
extern int func_021B9A24(unsigned int a, unsigned int b);
extern int func_021C7D24(u8 *);
extern int func_021B86A0(unsigned int **, unsigned int);
void func_021C70E4(u8 *p, int a, int b, int c, int e, u32 f);
int func_021C7194(u8 *p, u8 *a, u32 v);
int func_021C71E0(u8 *p, u8 *a, u32 x, u8 *out);
u16 func_021C728C(u8 *p, u8 *a, u8 *b, u8 *s);
int func_021C7330(u8 *p, u8 *a);
u16 func_021C7374(u8 *p, u8 *a, u8 *b, u8 *c, int flag);
u16 func_021C7474(u8 *p, u8 *a, u8 *b, u8 *c, u32 flag);
int func_021C75EC(u8 *p, u8 *a, int k);
int func_021C7664(u8 *p, u32 x, u8 *a);
int func_021C76F4(u8 *p, u8 *a, u32 k);
void func_021C7780(u8 *p, u8 *a);
int func_021C77B0(u8 *p, u8 *a, u32 b, u32 c, u32 d, u32 e);
void func_021C7820(u8 *p, u8 *a, u32 k);
void func_021C785C(u8 *p, u32 a, u8 *b, u32 c, u32 d);
void func_021C78A8(u8 *p, u8 *a, u32 b, u32 c, u32 d);
u16 func_021C78F4(u8 *p, u8 *a, u8 *b, u32 s);
void func_021C7998(u8 *p, u32 x);
u32 func_021C79E0(u8 *p, u32 x, u8 *a);
int func_021C7A54(u8 *p, u8 *a, u32 c);
void func_021C7AA0(u8 *p, u8 *a);
void func_021C7AD0(u8 *p, u8 *a, u32 k);
void func_021C7B0C(u8 *p, u8 *a);
void func_021C7B3C(u8 *p, u32 a, u16 b, u16 c);
void func_021C7B7C(u8 *p, unsigned int i);
void func_021C7BA8(u8 *p, u8 a, u32 b, u32 c, u32 *out);
void func_021C7BF8(u8 *p);
void func_021C7C18(void *p);
void func_021C7C24(u16 *p, int unused, u8 *b, u8 *c, int e);
u16 func_021C7CBC(u8 *p);
u16 func_021C7CC8(u8 *p);
u16 func_021C7CD4(struct Q6 *p);
u16 func_021C7CDC(u8 *p);
u16 func_021C7CE8(u8 *p);
void *func_021C7CF4(int *p, int i);
int func_021C7D00(u8 *p, int b);




void func_021C70E4(u8 *p, int a, int b, int c, int e, u32 f)
{
    int m;
    if (c != 6) {
        m = 2;
    } else {
        m = 1;
        if (b == 6) m = 0;
    }
    if (e) {
        switch (m) {
        case 0: func_021CD568(*(u8 * *)&((struct Obj00003 *)p)->fC, f, 0x4c, a); return;
        case 1: func_021CD568(*(u8 * *)&((struct Obj00003 *)p)->fC, f, 0x4d, b, a); return;
        case 2: func_021CD568(*(u8 * *)&((struct Obj00003 *)p)->fC, f, 0x4e, b, c, a); return;
        }
    } else {
        switch (m) {
        case 0: func_021CD4B0(*(u8 * *)&((struct Obj00003 *)p)->fC, 0x4c, a); return;
        case 1: func_021CD4B0(*(u8 * *)&((struct Obj00003 *)p)->fC, 0x4d, b, a); return;
        case 2: func_021CD4B0(*(u8 * *)&((struct Obj00003 *)p)->fC, 0x4e, b, c, a); return;
        }
    }
}




int func_021C7194(u8 *p, u8 *a, u32 v)
{
    int r;
    func_021D74F8(12399);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0x17, v);
    func_021D7630(0x51, 0);
    func_021D70F0(p, 0x4f);
    r = func_021D775C(0x51);
    func_021D7540(12405);
    return r;
}




int func_021C71E0(u8 *p, u8 *a, u32 x, u8 *out)
{
    u8 id = func_0201BD28(x, 8);
    u32 r;

    out[1] = 0;
    out[5] = 3;
    if (id > 1) {
        r = func_021D7BA4(id);
        func_021D74F8(12432);
        func_021D75EC(3, func_021D5440(a));
        func_021D75EC(0x29, id);
        func_021D75A8(0x2a, r);
        func_021D7630(0x51, 0);
        func_021D7630(0x42, 0);
        func_021D70F0(p, 0x35);
        if (id <= 5 && func_021D775C(0x51) != 0) {
            out[0] = id;
            out[2] = 0;
        } else {
            out[0] = func_021D775C(0x2a);
            out[2] = func_021D775C(0x42);
        }
        out[3] = 1;
        func_021D7540(12455);
        return 1;
    }
    out[0] = 1;
    out[2] = 0;
    out[3] = 0;
    return 0;
}




u16 func_021C728C(u8 *p, u8 *a, u8 *b, u8 *s)
{
    u32 t = func_0201C1D8((void *)(((struct Obj07759 *)s)->f0));
    u16 x;
    u32 y;

    func_021D74F8(12487);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x12, ((struct Obj07759 *)s)->f0);
    func_021D75EC(0x16, s[6]);
    func_021D75EC(0x1a, ((struct Obj07759 *)s)->f8);
    func_021D7630(0x30, t);
    func_021D70F0(p, 0x37);
    func_021D7674(0x31, 0x1000, 0x29, 0x200000);
    func_021D70F0(p, 0x38);
    x = func_021D775C(0x30);
    y = func_021D775C(0x31);
    func_021D7540(12500);
    return func_021D7B10(x, y);
}




int func_021C7330(u8 *p, u8 *a)
{
    int r;
    func_021D74F8(12521);
    func_021D75EC(4, func_021D5440(a));
    func_021D7630(0x51, 1);
    func_021D70F0(p, 0x80);
    r = func_021D775C(0x51);
    func_021D7540(12526);
    return r;
}




/*
 *   no witness outside this caller (7374-r2.log). Verified blocker C copied
 *   from ov093_func_021C1E74.c, whose header records its EXACT compile:
 *   typedef unsigned short u16; typedef unsigned int u32;
 *   extern u32 sub_0201BD28(u16, u32);
 * lever: bind the category call result before initialising k to prevent
 *   its constant assignment moving before the call.
 */
u16 func_021C7374(u8 *p, u8 *a, u8 *b, u8 *c, int flag)
{
    int k;
    u16 value;
    u8 index;
    int mode = func_0201C1E8(*(u16 *)c);
    k = 10;
    if (mode != 2) k = 8;
    func_021D74F8(12542);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75A8(0x3b, 0x1f);
    func_021D75A8(0x51, 0);
    func_021D70F0(p, 0x39);
    index = func_021D775C(0x3b);
    if (index != 0x1f) a = (u8 *)func_021B9934(*(char **)(p + 8), index);
    if (func_021D775C(0x51)) value = func_021D58A8(a, k);
    else if (flag) value = func_021D5AD8(a, k);
    else value = func_021D59B4(a, k);
    func_021D75EC(0x12, *(u16 *)c);
    func_021D75EC(0x16, c[6]);
    func_021D75EC(0x1a, *(u32 *)(c + 8));
    func_021D75A8(0x33, value);
    func_021D7674(0x35, 1 << 12, 410, 1 << 17);
    func_021D70F0(p, 0x3b);
    value = func_021D775C(0x33);
    value = func_021D7B10(value, func_021D775C(0x35));
    func_021D7540(12579);
    return value;
}




/*
 *   no witness outside this caller (7474-r1.log). Verified blocker C copied
 *   from ov093_func_021C1E74.c, whose header records its EXACT compile:
 *   typedef unsigned short u16; typedef unsigned int u32;
 *   extern u32 sub_0201BD28(u16, u32);
 */
u16 func_021C7474(u8 *p, u8 *a, u8 *b, u8 *c, u32 flag)
{
    int k;
    u32 field;
    u16 value;
    u8 other;
    int scale;
    int mode = func_0201C1E8(*(u16 *)c);
    k = 11;
    if (mode != 2) k = 9;
    field = *(u32 *)(c + 8);
    func_021D74F8(12595);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x3c, k);
    func_021D75A8(0x3d, 0);
    func_021D7630(0x51, 0);
    func_021D70F0(p, 0x3a);
    if (func_021D775C(0x3d) & 1) {
        if (k == 9) k = 11;
        else k = 9;
        if (k == 9) field = 1;
        else field = 2;
    }
    other = func_021D775C(0x51);
    func_021D7540(12610);
    if (other) value = func_021D58A8(b, k);
    else if (flag) value = func_021D5AD8(b, k);
    else value = func_021D59B4(b, k);
    if (func_021C2AB0(p) == 4 && func_021D5814(b, 5) && k == 11)
        value = func_021D7B10(value, 6 << 10);
    func_021D74F8(12631);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x12, *(u16 *)c);
    func_021D75EC(0x16, c[6]);
    func_021D75EC(0x1a, field);
    func_021D75A8(0x34, value);
    func_021D7674(0x35, 4 << 10, 410, 4 << 15);
    func_021D70F0(p, 0x3c);
    value = func_021D775C(0x34);
    scale = func_021D775C(0x35);
    func_021D7540(12642);
    return func_021D7B10(value, scale);
}




int func_021C75EC(u8 *p, u8 *a, int k)
{
    int f = func_021D5814(a, k);
    u32 v = 0x1000;
    int x;
    int r;

    func_021D74F8(12664);
    func_021D75EC(2, func_021D5440(a));
    func_021D7630(0x51, f);
    func_021D70F0(p, 0x40);
    x = func_021D775C(0x51);
    if (x != 0)
        v = 0x1800;
    func_021D75EC(0x44, x);
    func_021D75A8(0x35, v);
    func_021D70F0(p, 0x41);
    r = func_021D775C(0x35);
    func_021D7540(12681);
    return r;
}




int func_021C7664(u8 *p, u32 x, u8 *a)
{
    int c41;
    int c45;
    int c26;
    int s;

    s = func_0201BD28(x, 10);
    func_021D74F8(12701);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x25, s);
    func_021D7630(0x45, 0);
    func_021D7630(0x41, 0);
    func_021D75A8(0x26, 0);
    func_021D70F0(p, 0x6c);
    c41 = func_021D775C(0x41);
    c45 = func_021D775C(0x45);
    c26 = func_021D775C(0x26);
    func_021D7540(12712);
    if (c41 != 0 && s != 0)
        return 0;
    if (s == 0)
        s = s + c26;
    if (c45 != 0)
        s = s << 1;
    return s;
}




int func_021C76F4(u8 *p, u8 *a, u32 k)
{
    int res;
    int c26;
    int c41;

    func_021D74F8(12745);
    func_021D75EC(4, func_021D5440(a));
    func_021D75A8(0x26, k);
    func_021D7630(0x41, 0);
    res = 0;
    func_021D70F0(p, 0x6d);
    c26 = func_021D775C(0x26);
    c41 = func_021D775C(0x41);
    func_021D7540(12753);
    if (c41 != 0)
        return 0;
    if (c26 != 0) {
        if (func_021C82B8(p, res) != 0)
            return 1;
        if (func_021D78AC(100) < (u8)c26)
            res = 1;
        return res;
    }
    return res;
}



void func_021C7780(u8 *p, u8 *a)
{
    int line = 12778;
    func_021D74F8(line);
    func_021D75A8(2, func_021D5440(a));
    func_021D70F0(p, 110);
    func_021D7540(line + 3);
}




int func_021C77B0(u8 *p, u8 *a, u32 b, u32 c, u32 d, u32 e)
{
    int r;
    int res;

    func_021D74F8(12801);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(3, c);
    func_021D75EC(0x1f, b);
    func_021D75EC(0x20, d);
    func_021D75EC(0x19, e);
    res = 0;
    func_021D7630(0x41, 0);
    func_021D70F0(p, 0x5b);
    r = func_021D775C(0x41);
    func_021D7540(12810);
    if (r == 0)
        res = 1;
    return res;
}



void func_021C7820(u8 *p, u8 *a, u32 k)
{
    int line = 12826;
    func_021D74F8(line);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(25, k);
    func_021D70F0(p, 92);
    func_021D7540(line + 4);
}




void func_021C785C(u8 *p, u32 a, u8 *b, u32 c, u32 d)
{
    func_021D74F8(12846);
    func_021D75EC(3, a);
    func_021D75EC(2, func_021D5440(b));
    func_021D75EC(0x1f, c);
    func_021D75EC(0x20, d);
    func_021D70F0(p, 0x5d);
    func_021D7540(12852);
}




void func_021C78A8(u8 *p, u8 *a, u32 b, u32 c, u32 d)
{
    func_021D74F8(12868);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x12, b);
    func_021D75EC(0x1f, c);
    func_021D75EC(0x20, d);
    func_021D70F0(p, 0x5e);
    func_021D7540(12874);
}




u16 func_021C78F4(u8 *p, u8 *a, u8 *b, u32 s)
{
    int k;
    u32 y;
    u16 r;

    if (b != 0)
        k = func_021D5440(b);
    else
        k = 0x1f;
    func_021D74F8(12894);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, (u8)k);
    func_021D7674(0x35, 0x1000, 410, 0x20000);
    func_021D75A8(0x20, s);
    func_021D70F0(p, 0x8c);
    s = (u16)func_021D775C(0x20);
    y = func_021D775C(0x35);
    if (s != 0)
        s = (u16)func_021D7B2C(s, y);
    func_021D76BC(0x20, s);
    func_021D70F0(p, 0x8d);
    r = func_021D775C(0x20);
    func_021D7540(12911);
    return r;
}




void func_021C7998(u8 *p, u32 x)
{
    func_021D74F8(12930);
    func_021D75EC(0x39, x);
    func_021D7630(0x41, 0);
    func_021D70F0(p, 0x7d);
    if (func_021D775C(0x41) == 0)
        func_021D70F0(p, 0x7e);
    func_021D7540(12938);
}




u32 func_021C79E0(u8 *p, u32 x, u8 *a)
{
    u32 s = func_0201BD28(x, 0x1a);
    int c;
    u32 m;
    u32 r;

    func_021D74F8(12956);
    func_021D75EC(2, func_021D5440(a));
    func_021D75A8(0x35, 0);
    func_021D70F0(p, 0x8f);
    c = func_021D775C(0x35);
    func_021D7540(12961);
    m = func_021D59B4(a, 0xe);
    if (c != 0)
        r = func_021D7B10(m, c);
    else
        r = func_021D7B3C(m, s);
    if (r == 0)
        return 1;
    if (r > m)
        r = m;
    return r;
}




int func_021C7A54(u8 *p, u8 *a, u32 c)
{
    int r;
    func_021D74F8(12996);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0x2d, c);
    func_021D7630(0x41, 0);
    func_021D70F0(p, 0x9a);
    r = func_021D775C(0x41);
    func_021D7540(13002);
    return r;
}



void func_021C7AA0(u8 *p, u8 *a)
{
    int line = 13017;
    func_021D74F8(line);
    func_021D75EC(2, func_021D5440(a));
    func_021D70F0(p, 155);
    func_021D7540(line + 3);
}



void func_021C7AD0(u8 *p, u8 *a, u32 k)
{
    int line = 13033;
    func_021D74F8(line);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(45, k);
    func_021D70F0(p, 156);
    func_021D7540(line + 4);
}



void func_021C7B0C(u8 *p, u8 *a)
{
    int line = 13050;
    func_021D74F8(line);
    func_021D75EC(2, func_021D5440(a));
    func_021D70F0(p, 157);
    func_021D7540(line + 3);
}




void func_021C7B3C(u8 *p, u32 a, u16 b, u16 c)
{
    func_021D74F8(13068);
    func_021D75EC(2, a);
    func_021D75EC(0xf, b);
    func_021D75EC(0x10, c);
    func_021D70F0(p, 0x89);
    func_021D7540(13073);
}



void func_021C7B7C(u8 *p, unsigned int i) { func_021D74F8(13085); func_021D75EC(2,i); func_021D70F0(p,138); func_021D7540(13088); }




void func_021C7BA8(u8 *p, u8 a, u32 b, u32 c, u32 *out)
{
    func_021D74F8(13102);
    func_021D75EC(2, a);
    func_021D75EC(0x52, c);
    func_021D75EC(0x53, b);
    func_021D75A8(0x1e, *out);
    func_021D70F0(p, 0x9f);
    *out = func_021D775C(0x1e);
    func_021D7540(13109);
}



void func_021C7BF8(u8 *p) { func_021D74F8(13123); func_021D70F0(p, 121); func_021D7540(13125); }




void func_021C7C18(void *p)
{
    func_02082BCC(p, 0, (u32)0xc);
}




void func_021C7C24(u16 *p, int unused, u8 *b, u8 *c, int e)
{
    u8 x = func_021D5440(b);
    u8 y = func_021D5440(c);
    int mx = func_021B8DDC(x);
    int my = func_021B8DDC(y);
    u8 same = (func_021B9A24(x, y) == 0);
    u16 *q = 0;
    if (mx == 0) {
        if (same) {
            if (e == 0) {
                q = p;
            } else if (e > 3) {
                q = p + 1;
            } else if (e < 3) {
                q = p + 2;
            }
        }
    } else if (my == 0) {
        if (same) {
            if (e == 0) {
                q = p + 3;
            } else if (e > 3) {
                q = p + 4;
            } else if (e < 3) {
                q = p + 5;
            }
        }
    }
    if (q != 0) {
        if (*q < 9999) {
            *q += 1;
        }
    }
}




/*
 * ldrh at #0x1f7c (pool constant)
 */
u16 func_021C7CBC(u8 *p)
{
    return ((struct Obj18319 *)p)->f1F7C;
}




/*
 * ldrh at #0x1f7e (pool constant)
 */
u16 func_021C7CC8(u8 *p)
{
    return ((struct Obj18320 *)p)->f1F7E;
}



/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: movs r1, #0x7e; lsls r1, r1, #6; ldrh r0, [r0, r1]; bx lr.
 */
u16 func_021C7CD4(struct Q6 *p) { return p->v; }




/*
 * ldrh at #0x1f82 (pool constant)
 */
u16 func_021C7CDC(u8 *p)
{
    return ((struct Obj18322 *)p)->f1F82;
}




u16 func_021C7CE8(u8 *p)
{
    return ((struct Obj18323 *)p)->f1F86;
}



/*
 * Forwarding tail call: p[2] and the caller's i go to func_021B9934, whose
 * listing reads both (lsls r1, r1, #2), and its result is returned.
 */
void *func_021C7CF4(int *p, int i)
{
    return func_021B9934((char *)p[2], i);
}


int func_021C7D00(u8 *p, int b) { int i = func_021C7D24(p + 0x1ab8); if (!func_021B86A0(*(unsigned int ** *)&((struct Obj00003 *)p)->f4, i)) i = 6; return i; }
