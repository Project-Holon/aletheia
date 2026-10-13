/*
 * unit: yes
 * function: func_021DBBD8, func_021DBCE0
 * address: 0x021DBBD8
 * packet: pkt_ov093_021DBBD8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_GetItem 0x021D5B40 thumb ov093
 *   func_021C7D00 0x021C7D00 thumb ov093
 *   func_021C8120 0x021C8120 thumb ov093
 *   func_021C7F68 0x021C7F68 thumb ov093
 *   BTL_POKEPARAM_TestTurnFlag 0x021D5BB0 thumb ov093
 *   BTL_POKEPARAM_GetConsumedItem 0x021D6740 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_CALC_Random 0x021D78AC thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   gPickpocketHandlers 0x021F06C0 data a4
 */
#include "../include/Obj06258.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int key);
struct QI;
struct QK;
struct UtilWork;
extern void *func_021C7CF4(int *p, int i);
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern int func_021C7D00(u8 *p, int b);
extern u8 *func_021C8120(u8 *p, int b);
extern u8 func_021C7F68(int *p, int b, u8 *out);
extern int BTL_POKEPARAM_TestTurnFlag(struct UtilWork *p, u32 n);
extern u16 BTL_POKEPARAM_GetConsumedItem(struct QK *p);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern u32 BTL_CALC_Random(u32 k);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);
void func_021DBBD8(int a, void *b, u8 c)
{
    u8 *buf;
    void *m;
    u32 flag;
    u8 i;
    u8 n;
    u8 selected;
    u16 value;
    u8 *r;
    if (c == BTL_EVENT_GetVar(2) && !BTL_POKEPARAM_GetItem(func_021C7CF4(b, c))) {
        flag = func_021C7D00(b, c);
        buf = func_021C8120(b, 14);
        buf[12] = (u8)func_021C7F68(b, (u16)(flag | 0x200), buf);
        n = 0;
        buf[13] = 0;
        for (i = 0; i < (u32)buf[12]; i++) {
            m = func_021C7CF4(b, buf[i]);
            if (BTL_POKEPARAM_TestTurnFlag(m, 8) && BTL_POKEPARAM_GetConsumedItem(m)) {
                buf[6 + n++] = BTL_POKEPARAM_GetPokeId(m);
            }
        }
        if (n) {
            selected = (buf + (u8)BTL_CALC_Random(n))[6];
            value = BTL_POKEPARAM_GetConsumedItem(func_021C7CF4(b, selected));
            if (value) {
                r = (u8 *)func_021C88A4(b, 0x20, c);
                ((struct Obj06258 *)r)->f0 |= 0x800000;
                r[6] = c;
                ((struct Obj06258 *)r)->f4 = value;
                r[8] = 1;
                r[9] = selected;
                func_021C8838(r + 12, 2, 0x1ea);
                func_021C8860((struct S *)(r + 12), c);
                func_021C8860((struct S *)(r + 12), value);
                func_021C88C8(b, r);
            }
        }
    }
}
extern u8 gPickpocketHandlers[];
void *func_021DBCE0(int *p) { *p = 1; return gPickpocketHandlers; }
