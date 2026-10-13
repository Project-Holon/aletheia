/*
 * file:     unit_02179CAC.c
 * unit:     yes
 * function: func_02179CAC, func_02179CE4, func_02179D14, func_02179D30, func_02179D3C, func_02179D68, func_02179D78, func_02179D80
 * address:  0x02179CAC
 * region:   ov015
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_0217AB80  0x0217AB80  data  ov015
 *   d_0217ABA0  0x0217ABA0  data  ov015
 *   func_0217A014 0x0217A014 arm ov015
 *   func_0217A5A4 0x0217A5A4 arm ov015
 *   g_0217AB80  0x0217AB80  data  a4
 *   func_0217A024  0x0217A024  arm  ov015
 *   d_0217AB40  0x0217AB40  data  ov015
 *   d_0217AAC0           0x0217AAC0  data   ov015
 *   func_02179B38        0x02179B38  thumb  ov015
 *   func_0217A334        0x0217A334  arm    ov015
 *   IRC_IsConnect        0x0217A024  arm    ov015
 *   IRC_IsSender         0x0217A014  arm    ov015
 *   IRC_Init             0x02179F74  arm    ov015
 *   IRC_SetRecvCallback  0x0217A584  arm    ov015
 *   func_02179FC4        0x02179FC4  arm    ov015
 *   func_0217A134        0x0217A134  arm    ov015
 *   func_02179B24        0x02179B24  thumb  ov015
 *   GFL_NET_HANDLE_RemoveHandle        0x0203A338  arm
 *   _u32_div_f           0x0209C2B0  arm
 */
#include "../../matched/include/G_s_aba0.h"
#include "../../matched/include/G_State.h"
#include "../../matched/include/G_s_ab40.h"

#define W(off) (*(u32 *)(w + (off)))
#define B(off) (w[(off)])
typedef unsigned char u8;

typedef unsigned int u32;

struct flags_ab80 {
    u8 pad[0xE];
    u8 fE;
    u8 b0 : 1;
    u8 b1 : 1;
};

typedef unsigned short u16;

extern unsigned int func_0217A014(void);
extern unsigned int func_0217A5A4(void);
extern int func_0217A024(void);
extern void func_02179B38(u8 *pkt, u32 len, u32 type);
extern int func_0217A334(void);
extern int IRC_IsConnect(void);
extern int IRC_IsSender(void);
extern void IRC_Init(u8 unit);
extern void IRC_SetRecvCallback(void (*cb)(u8 *, u32, u32));
extern void func_02179FC4(void);
extern void func_0217A134(void);
extern int func_02179B24(void);
extern void GFL_NET_HANDLE_RemoveHandle(u32 a0);
int func_02179CAC(void);
void func_02179CE4(void);
void func_02179D14(void);
u8 func_02179D30(void);
int func_02179D3C(void);
u8 func_02179D68(void);
int func_02179D78(void);
void func_02179D80(void);
extern struct State d_0217AB80;
extern struct s_aba0 d_0217ABA0;
extern u8 g_0217AB80[];
extern struct s_ab40 d_0217AB40;
extern u8 d_0217AAC0[];






int func_02179CAC(void)
{
    if (((unsigned char *)&d_0217AB80)[0xc] == 0)
        return 0;
    if (((unsigned char *)&d_0217ABA0)[5] != 0)
        return 1;
    if (((unsigned char *)&d_0217AB80)[0x1d] == 1) {
        if (func_02179D3C() == 0)
            return 1;
    }
    return 0;
}





void func_02179CE4(void) { d_0217AB80.f28 = func_0217A014(); ((u8 *)&d_0217ABA0)[7] = func_0217A5A4(); d_0217AB80.f29 = 1; ((u8 *)&d_0217ABA0)[2] = 0; ((u8 *)&d_0217ABA0)[3] = 14; if (d_0217AB80.f28 != 1) d_0217AB80.f14 = 1; }





void func_02179D14(void) { ((u8 *)&d_0217AB80)[0x1c] = func_0217A014(); ((u8 *)&d_0217ABA0)[7] = func_0217A5A4(); }





u8 func_02179D30(void)
{
    return g_0217AB80[0x1c];
}




int func_02179D3C(void)
{
    u32 a;
    u32 b;

    if (func_0217A024() == 1)
        return 1;
    a = ((u32 *)&d_0217AB40)[0x3c / 4];
    b = ((u32 *)&d_0217AB40)[0x40 / 4];
    if (b < a || (b == 0 && a == 0))
        return 1;
    return 0;
}


u8 func_02179D68(void) { return ((struct flags_ab80 *)&d_0217AB80)->b1; }


int func_02179D78(void)
{
    return func_0217A024();
}


void func_02179D80(void)
{
    u8 *w = d_0217AAC0;

    if (((u8 *)&d_0217AB80)[0x1D] != 0 || W(0xC0) < W(0xBC) || W(0xC0) == 0) {

        if (W(0xC0) == 0)
            func_0217A334();

        if (B(0xDD) != 1)
            return;

        if (W(0xC0) != 0) {
            if (IRC_IsConnect() == 1) {
                W(0xC0) = 0;
                if (IRC_IsSender() == 1)
                    B(0xCE) = 0;
                else
                    B(0xCE) = 1;
                if (B(0xE1) == 1)
                    B(0xE4) = 1;
                return;
            }
            if (W(0xC0) < 5) {
                W(0xC0)++;
                return;
            }
            if (W(0xC0) == 5) {
                IRC_Init(3);
                IRC_SetRecvCallback(func_02179B38);
                W(0xC0)++;
                return;
            }
            func_0217A334();
            if (W(0xC0) < W(0xBC)) {
                if (B(0xDC) == 1 && W(0xC0) % 5 == 0)
                    func_02179FC4();
                W(0xC0)++;
                return;
            }
            B(0xDD) = 0;
            B(0xE5) = 1;
            GFL_NET_HANDLE_RemoveHandle(1 - func_02179B24());
            func_0217A134();
        } else {
            if (IRC_IsConnect() != 0)
                return;
            if (W(0xBC) != 0) {
                func_0217A134();
                W(0xC0) = 1;
                return;
            }
            B(0xDD) = 0;
            B(0xE5) = 1;
            W(0xC0) = 0xFFFF;
            GFL_NET_HANDLE_RemoveHandle(1 - func_02179B24());
            func_0217A134();
        }
    }
}
