/*
 * file:     unit_021AEB20_p01.c
 * unit:     yes
 * function: func_021AEB20, func_021AEB78, func_021AEB7C, func_021AEC74, func_021AECC4, func_021AED08
 * address:  0x021AEB20
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0208B24C  0x0208B24C  arm
 *   func_0208B8B0  0x0208B8B0  arm
 *   func_0208BEF0  0x0208BEF0  arm
 *   func_0208BF38  0x0208BF38  arm
 *   func_021B0CD8  0x021B0CD8  arm  ov013
 *   func_020726D0  0x020726D0  arm
 *   func_020737C0  0x020737C0  arm
 *   func_02082AC0  0x02082AC0  arm
 *   func_021B0D08  0x021B0D08  arm  ov013
 *   d_021B3C80     0x021B3C80  data  ov013
 *   func_02082BCC  0x02082BCC  arm
 *   func_0202EB0C  0x0202EB0C  thumb
 *   func_0208B2BC  0x0208B2BC  arm
 *   func_0208B4C8  0x0208B4C8  arm
 *   func_0208B4B8  0x0208B4B8  arm
 *   func_021B0B48  0x021B0B48  arm  ov013
 *   func_021B07F8  0x021B07F8  arm  ov013
 *   func_021B1F2C 0x021B1F2C arm ov013
 *   func_021B20B0 0x021B20B0 arm ov013
 *   func_021B1F54 0x021B1F54 arm ov013
 *   func_021B2180  0x021B2180  arm  ov013
 *   func_021B0614  0x021B0614  arm  ov013
 *   func_021AEDEC 0x021AEDEC thumb ov013
 */
#include "../../matched/include/G_Work.h"
#include "../../matched/include/Obj19303.h"

struct S;
struct Node;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

extern void func_0208B24C(void);
extern void func_0208B8B0(void);
extern unsigned int func_0208BEF0(unsigned int status);
extern unsigned int func_0208BF38(unsigned int gain);
extern void func_021B0CD8(int x);
extern void func_020726D0(void);
extern void func_020737C0(struct S *p);
extern void func_02082AC0(int v, void *p, u32 n);
extern void func_021B0D08(int x);
extern void func_02082BCC(void *p, int v, u32 n);
extern u32 func_0202EB0C(void);
extern int func_0208B2BC(void *param, void (*cb)(void), void *arg);
extern int func_0208B4C8(void *param, void (*cb)(void), void *arg);
extern u32 func_0208B4B8(void);
extern int func_021B0B48(void *a, u32 b, int *out);
extern int func_021B07F8(const u8 *src, u32 n);
extern struct Node *func_021B1F2C(unsigned int i);
extern int func_021B20B0(int p, int x);
extern int func_021B1F54(struct Node *p);
extern int func_021B2180(int a, int b);
extern int func_021B0614(void *p);
extern void func_021AEDEC(struct Node *p);
void func_021AEB20(void);
/* * Unlabelled leaf (no lr save, so disasm.py never labels it); its address * is taken as a completion callback by func_021AEB7C. */ void func_021AEB78(void);
/* * Microphone sampling step: with mode 0 clears the n buffers; otherwise * stops the pending auto-sampling (param block at G+0x1A20, busy flag * G+0x1A4B), picks the sample window, processes each buffer and, unless * G+0x19B0 is set, analyses the window. Callback is the empty leaf * func_021AEB78. */ void func_021AEB7C(int mode, u32 n, void **bufs, u32 size, int unused, u32 arg6);
/* * note: 2026-10-05 the call to func_021B20B0 is written in each arm of the * null test (new allocation, existing node); the compiler cross-jumps the * shared tail and the first arm uses the call result register directly. */ int func_021AEC74(int i);
int func_021AECC4(int x);
void func_021AED08(int unused,int code,void *p);
extern struct Work *d_021B3C80;



void func_021AEB20(void)
{
    func_0208B24C();
    func_0208B8B0();
    func_0208BEF0(1);
    func_0208BF38(3);
    func_021B0CD8(1);
    func_020726D0();
    func_020737C0((struct S *)(((u8 *)d_021B3C80) + 0x19B8));
    func_02082AC0(0, ((u8 *)d_021B3C80) + 0x1104, 0x880);
    *(u32 *)(((u8 *)d_021B3C80) + 0x1A44) = 0;
    func_021B0D08(1);
}


/*
 * Unlabelled leaf (no lr save, so disasm.py never labels it); its address
 * is taken as a completion callback by func_021AEB7C.
 */
void func_021AEB78(void)
{
}



/*
 * Microphone sampling step: with mode 0 clears the n buffers; otherwise
 * stops the pending auto-sampling (param block at G+0x1A20, busy flag
 * G+0x1A4B), picks the sample window, processes each buffer and, unless
 * G+0x19B0 is set, analyses the window. Callback is the empty leaf
 * func_021AEB78.
 */
void func_021AEB7C(int mode, u32 n, void **bufs, u32 size, int unused, u32 arg6)
{
    u8 *addr;
    u32 i;

    addr = (u8 *)arg6;

    if (mode == 0) {
        for (i = 0; i < n; i++) {
            func_02082BCC(bufs[i], 0, size);
        }
        return;
    }
    if (func_0202EB0C() == 0) {
        if (((u8 *)d_021B3C80)[0x1A4B] != 0) {
            func_0208B2BC(((u8 *)d_021B3C80) + 0x1A20, func_021AEB78, 0);
            ((u8 *)d_021B3C80)[0x1A4B] = 0;
        }
    } else {
        if (((u8 *)d_021B3C80)[0x1A4B] != 0) {
            func_0208B4C8(((u8 *)d_021B3C80) + 0x1A20, func_021AEB78, 0);
            ((u8 *)d_021B3C80)[0x1A4B] = 0;
        }
    }
    if ((u32)(func_0208B4B8() - (u32)addr) < size) {
        addr = addr + size;
    }
    if (((*(volatile u16 *)0x02FFFFA8 & 0x8000) >> 15) != 0
        || *(u16 *)(((u8 *)d_021B3C80) + 0x19B2) != 0) {
        addr = ((u8 *)d_021B3C80) + 0x1104;
    }
    for (i = 0; i < n; i++) {
        func_021B0B48(bufs[i], size, 0);
    }
    if (*(u16 *)(((u8 *)d_021B3C80) + 0x19B0) == 0) {
        func_021B07F8(addr, size);
    }
    ((u8 *)d_021B3C80)[0x1A4A] = 2;
}



/*
 * note: 2026-10-05 the call to func_021B20B0 is written in each arm of the
 *   null test (new allocation, existing node); the compiler cross-jumps the
 *   shared tail and the first arm uses the call result register directly.
 */
int func_021AEC74(int i)
{
    struct Node *p = d_021B3C80->f1A1C;
    int r;

    if (p == 0) {
        p = func_021B1F2C(i);
        if (p == 0) {
            return 0;
        }
        r = func_021B20B0((int)p, 0);
    } else {
        r = func_021B20B0((int)p, 0);
    }
    if (r != 0) {
        func_021B1F54(p);
        d_021B3C80->f1A1C = 0;
        return 0;
    }
    d_021B3C80->f1A1C = p;
    return 1;
}



int func_021AECC4(int x)
{
    u8 *p = *(u8 **)(((u8 *)d_021B3C80) + 0x1A1C);
    int r;

    if (p != 0 && ((struct Obj19303 *)p)->fC == 4) {
        r = 0;
        if (func_021B2180((int)p, 0) != 0) {
            return r;
        }
        if (func_021B0614(*(void **)(((u8 *)d_021B3C80) + 0x1A1C)) != 0) {
            r = 1;
        }
        return r;
    }
    return 0;
}


void func_021AED08(int unused,int code,void *p)
{
    switch(code) {
    case 9: func_021AEDEC(p); break;
    case 7: func_021B0614(p); break;
    case 12: func_021AEDEC(p); break;
    }
}
