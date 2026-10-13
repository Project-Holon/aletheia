/*
 * function: func_021E8024
 * address: 0x021E8024
 * packet: pkt_ov170_021E8024
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EC000 0x021EC000 thumb ov170
 *   func_021ED508 0x021ED508 thumb ov170
 *   func_021EF57C 0x021EF57C thumb ov170
 *   func_021E8FC0 0x021E8FC0 thumb ov170
 *   func_021E0190 0x021E0190 thumb ov170
 *   func_021ECB20 0x021ECB20 thumb ov170
 *   func_021ECB60 0x021ECB60 thumb ov170
 *   func_021DD694 0x021DD694 thumb ov170
 *   func_020061E4 0x020061E4 thumb
 *   func_021EBBC8 0x021EBBC8 thumb ov170
 *   func_021E8F50 0x021E8F50 thumb ov170
 *   func_0201AB28 0x0201AB28 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   func_0202136C 0x0202136C thumb
 *   func_021EBC58 0x021EBC58 thumb ov170
 *   func_021ED888 0x021ED888 thumb ov170
 *   func_021DD2D0 0x021DD2D0 thumb ov170
 *   func_02017E88 0x02017E88 thumb
 *   func_021E8FE8 0x021E8FE8 thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23928.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct WinMgr;
extern void func_021EC000(char *, int, int);
extern void func_021ED508(unsigned char *p, int a, int b);
extern void func_021EF57C(struct WinMgr *mgr);
extern int func_021E8FC0(char *, int, int);
extern int func_021E0190(char *);
extern void func_021ECB20(char *, int, int);
extern void func_021ECB60(char *, int, int);
extern int func_021DD694(void ***, unsigned);
extern void func_020061E4(unsigned);
extern void func_021EBBC8(u8 *, unsigned, int);
extern int func_021E8F50(char *, int);
extern void *func_0201AB28(void *, unsigned);
extern unsigned POKE_TOOL_GetPartyValue(void *, unsigned, unsigned);
extern unsigned func_0202136C(u16);
extern void func_021EBC58(u8 *, int, int, int);
extern void func_021ED888(char *, int);
extern int func_021DD2D0(void ***, int, unsigned);
extern unsigned func_02017E88(void *, unsigned, unsigned);
extern int func_021E8FE8(u8 *, int);
#define W (*(char **)(p + 0x2c))
#define S (*(int *)(W + 0xA194))
int func_021E8024(char *p)
{
    unsigned slot;
    switch (S) {
    case 0:
        func_021EC000(W, 4, 0);
        func_021ED508((unsigned char *)p, 14, 0);
        func_021EF57C(*(struct WinMgr **)(W + 0x74));
        S++;
        return func_021E8FC0(p, (int)func_021E0190, 0x59);
    case 1:
        if (((struct Obj00000 *)p)->f16 >= 30) {
            func_021ECB20(p, 2, 1);
            func_021ECB60(W, ((struct Obj00000 *)p)->f16, 0);
            slot = ((struct Obj00000 *)p)->f16 - 30;
            if (func_021DD694((void ***)p, slot) == 0) {
                func_020061E4(0x557);
                func_021EBBC8((u8 *)p, 6, 24);
                *(u8 *)(W + 0xA170) = 1;
                ((struct Obj00000 *)p)->f28 = 14;
                return func_021E8F50(p, 6);
            }
            if (func_0202136C(POKE_TOOL_GetPartyValue(func_0201AB28(((struct Obj23928 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f8, slot), 6, 0)) == 1) {
                func_020061E4(0x557);
                func_021EBC58((u8 *)p, 0, 5, 24);
                *(u8 *)(W + 0xA170) = 1;
                ((struct Obj00000 *)p)->f28 = 14;
                return func_021E8F50(p, 6);
            }
        } else {
            func_021ED888(W, 0);
            func_021ECB20(p, 1, 1);
            func_021ECB60(W, ((struct Obj00000 *)p)->f16, 0);
        }
        if (func_02017E88((void *)func_021DD2D0((void ***)p, ((struct Obj00000 *)p)->f14, ((struct Obj00000 *)p)->f16), 0x4c, 0) != 0) {
            func_020061E4(0x557);
            func_021EBBC8((u8 *)p, 3, 24);
            *(u8 *)(W + 0xA170) = 1;
            ((struct Obj00000 *)p)->f28 = 14;
            return func_021E8F50(p, 6);
        }
        func_021EBBC8((u8 *)p, 0, 24);
        return func_021E8F50(p, func_021E8FE8((u8 *)p, 1));
    }
    return 0x59;
}
