/*
 * file:     wih_p10.c
 * unit:     yes
 * function: func_02178B98, func_02178C50, func_02178C74, func_02178C98, func_02178CC4, func_02178CDC, func_02178D00, func_02178D20, func_02178D74, func_02178D9C, func_02178DE0
 * address:  0x02178B98
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021797A8     0x021797A8  data  a4
 *   func_02178138  0x02178138  thumb  ov014
 *   func_0217814C  0x0217814C  thumb  ov014
 *   func_02179498  0x02179498  thumb  ov014
 *   func_0203D6BC  0x0203D6BC  arm
 *   func_0203D680  0x0203D680  arm
 *   func_0203D5D4  0x0203D5D4  arm
 *   func_0209004C  0x0209004C  arm
 *   func_0208FDEC 0x0208FDEC arm
 *   func_0208F938 0x0208F938 arm
 *   func_02178CC4 0x02178CC4 thumb ov014
 *   func_0217945C 0x0217945C thumb ov014
 *   DWCi_MOV_WH_SetError             0x0217814C  thumb
 *   DWCi_MOV_WH_ChangeSysState       0x02178138  thumb
 *   func_0208F400 0x0208F400 arm
 *   func_020862F0  0x020862F0  arm
 *   func_0208FCB4  0x0208FCB4  arm
 */
#include "../../matched/include/Obj12474.h"
#include "../../matched/include/G_S.h"
#include "../../matched/include/Obj12475.h"
#include "../../matched/include/Obj12476.h"
#include "../../matched/include/Obj03559.h"
#include "../../matched/include/Obj12477.h"

typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct { unsigned short apiid; unsigned short errcode; } WMCallback;

typedef void (*Cb)(int);

void func_02178138(int a);
void func_0217814C(int a);
int func_02179498(void);
u32 func_0203D6BC(void);
u32 func_0203D680(void);
u32 func_0203D5D4(void);
int func_0209004C(void *p, int a, u32 mask, u32 b, int c);
extern int func_0208FDEC(void (*)(void *));
extern void func_02178CC4(u8 *);
extern void func_0217945C(void);
extern int func_0208F938(void (*)(u8 *), u16);
extern void DWCi_MOV_WH_SetError(int code);
extern void DWCi_MOV_WH_ChangeSysState(int state);
extern int func_0208F400(void (*)(u8 *));
void func_020862F0(u32 a, u32 b);
int func_0208FCB4(void *cb, u32 c, u32 a, u32 b, u32 d, u32 e, u32 f);
void func_02178B98(u8 *m);
int func_02178C50(void);
void func_02178C74(void *arg);
int func_02178C98(void);
int func_02178CDC(void);
void func_02178D00(u8 *p);
int func_02178D20(u32 a, u32 b, u32 c);
void func_02178D74(u8 *p);
void func_02178D9C(u8 *m);
void func_02178DE0(u8 *p);
extern struct S *g_021797A8;


void func_02178B98(u8 *m)
{
    u32 v = ((struct Obj12474 *)m)->f2;
    u32 mask;
    u32 who;
    int c;

    if (v != 0) {
        if (v == 0xF || v == 9 || v == 0xD)
            return;
        func_0217814C(v);
        func_02178138(9);
        return;
    }
    switch (((struct Obj12474 *)m)->f4) {
    case 0xA:
        if (*(u32 *)(((u8 *)g_021797A8) + 0x1E74) == 5) {
            int r;
            int n;

            who = func_0203D6BC();
            n = func_0203D680() - 1;
            mask = (u16)((1 << (n + 1)) - 1);
            c = 1;
            if (func_0203D5D4() == 2)
                c = 0;
            r = func_0209004C(((u8 *)g_021797A8) + 0x1444, 0xD, mask, (u16)who, c);
            if (r != 0) {
                func_0217814C(r);
                func_02179498();
                return;
            }
            func_02178138(5);
            return;
        }
        func_02178138(4);
        break;
    case 0xB:
    case 0xC:
    case 0xD:
        break;
    }
}

int func_02178C50(void)
{
    int result;
    func_02178138(3);
    result = func_0208FDEC(func_02178C74);
    if (result != 2) {
        func_0217814C(result);
        return 0;
    }
    return 1;
}

void func_02178C74(void *arg)
{
    int result = ((u16 *)arg)[1];
    if (result != 0) {
        func_0217814C(result);
        func_02179498();
        return;
    }
    if (func_02178C98() == 0)
        func_02178138(9);
}

int func_02178C98(void) {
 int r;
 int result = 0;
 func_02178138(3);
 r = func_0208F938(func_02178CC4, 0);
 if (r != 2) { func_0217814C(r); func_0217945C(); return result; }
 return 1;
}


static void DWCi_MOV_WH_StateOutEndChild(void *arg)
{
	WMCallback *cb = (WMCallback *)arg;

	if (cb->errcode != 0)
	{
		DWCi_MOV_WH_SetError(cb->errcode);
		return;
	}
	DWCi_MOV_WH_ChangeSysState(1);
}

int func_02178CDC(void) {
 int r;
 func_02178138(3);
 r = func_0208F400(func_02178D00);
 if (r != 2) { func_0217814C(r); return 0; }
 return 1;
}

void func_02178D00(u8 *p) { if (((struct Obj12475 *)p)->f2 != 0) { func_02178138(9); func_0217814C(((struct Obj12475 *)p)->f2); } else { func_02178138(1); } }


int func_02178D20(u32 a, u32 b, u32 c)
{
    func_020862F0(*(u32 *)(((u8 *)g_021797A8) + 0x1E68), *(u32 *)(((u8 *)g_021797A8) + 0x1E8C));
    if (func_0208FCB4((void *)func_02178D74, c, a, b, 0xFFFF, 0xE, 2) == 2)
        return 1;
    return 0;
}

/*
 * extent: two zero alignment bytes at 02178D9A precede labelled 02178D9C.
 */
void func_02178D74(u8 *p) {
 int v = ((struct Obj12476 *)p)->f2;
 if (v != 0 && v != 15) { func_0217814C(v); }
 else { Cb cb = *(Cb *)&((struct Obj12476 *)p)->f20; if (cb != 0) cb(v == 0); }
}


void func_02178D9C(u8 *m)
{
    void (*cb)(u32, u32, u32);

    if (((struct Obj03559 *)m)->f2 != 0) {
        func_0217814C(((struct Obj03559 *)m)->f2);
        return;
    }
    cb = *(void (**)(u32, u32, u32))(((u8 *)g_021797A8) + 0x1E78);
    if (cb != 0) {
        if (((struct Obj03559 *)m)->f4 == 0x15)
            cb(((struct Obj03559 *)m)->f12, ((struct Obj03559 *)m)->fC, ((struct Obj03559 *)m)->f10);
        else if (((struct Obj03559 *)m)->f4 == 9)
            cb(((struct Obj03559 *)m)->f12, 0, 0);
    }
}

void func_02178DE0(u8 *p) {
 Cb cb = *(Cb *)(((u8 *)g_021797A8) + 0x1E64);
 if (cb != 0) cb(((struct Obj12477 *)p)->f2 == 0 ? 1 : 0);
 if (((struct Obj12477 *)p)->f2 != 0) func_02178138(10); else func_02178138(0);
}
