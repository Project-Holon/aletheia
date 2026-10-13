/*
 * function: func_021E84FC
 * address: 0x021E84FC
 * packet: pkt_ov093_021E84FC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: byte locals plus declaration order restore the spill/register assignment.
 * permuter: rejected added return target; transferred only declarations and two temporaries.
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   func_021B9A40 0x021B9A40 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   BTLV_CORE_MakeSlotKind2Index 0x021E8940 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   func_021C7D34 0x021C7D34 thumb ov093
 */
#include "../include/Obj07838.h"
#include "../include/Obj21548.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Word { u32 v; } Word;
extern int BTL_EVENT_GetVar(int);
extern unsigned char func_021B9A40(unsigned int x);
extern void *func_021C88A4(char *p, int a, int b);
extern Word BTLV_CORE_MakeSlotKind2Index(int);
extern void func_021C8838(void *, int, int);
struct S;
extern void func_021C8860(struct S *, u32);
extern void func_021C88C8(void *a, void *b);
extern int func_021C7D34(char *p, int i);
void func_021E84FC(int a, int b, int c, const int *d)
{
    int tmp;
    u8 *p;
    u8 selected;
    int code;
    u8 own;
    u8 other;
    int target;
    int slot;
    u8 message;
    u8 mode;
    u8 *tmp1;
    if (c == BTL_EVENT_GetVar(3) && d[0] != 0) {
        mode = 14;
        own = func_021B9A40(c);
        other = func_021B9A40((u8)BTL_EVENT_GetVar(6));
        code = 0;
        message = 0;
        target = 31;
        switch (d[1]) {
        case 1:
            message = 0xa4;
            mode = 11;
            selected = own;
            code = 0x28d;
            target = c;
            break;
        case 2:
            message = 0xa8;
            selected = other;
            mode = 12;
            code = 0x28e;
            target = (u8)BTL_EVENT_GetVar(6);
            break;
        case 3:
            message = 0xac;
            selected = other;
            mode = 13;
            code = 0x28f;
            target = (u8)BTL_EVENT_GetVar(6);
            break;
        }
        if (mode != 14) {
            p = func_021C88A4((char *)b, 25, c);
            ((struct Obj07838 *)p)->f4 = mode;
            p[12] = selected;
            *(Word *)(p + 8) = BTLV_CORE_MakeSlotKind2Index(4);
            func_021C8838(p + 16, 1, message);
            func_021C8860((struct S *)(p + 16), selected);
            func_021C88C8((void *)b, p);
            if (target != 31) {
                tmp = func_021C7D34((char *)b, target);
                slot = tmp;
                if (slot != 6) {
                    p = func_021C88A4((char *)b, 0x37, c);
                    p[6] = slot;
                    p[7] = 6;
                    tmp1 = p + 4;
                    ((struct Obj21548 *)tmp1)->f0 = code;
                    func_021C88C8((void *)b, p);
                }
            }
        }
    }
}
