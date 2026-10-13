/*
 * function: BTL_TOKUSEI_Forecast_SetFormForWeather
 * address:  0x021DB374
 * packet:   pkt_ov093_021DB374
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 */
#include "../include/Obj10063.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct QF;
extern void *func_021C7CF4(int *p, int i);
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
extern int func_021D59B4(u8 *p, int k);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);

void BTL_TOKUSEI_Forecast_SetFormForWeather(void *a, int id, u32 k)
{
    u8 *r;
    void *m;
    u32 v;
    u32 s;

    m = func_021C7CF4(a, id);
    if (BTL_POKEPARAM_GetSpecies(m) == 0x15f) {
        v = (u8)func_021D59B4(m, 0x13);
        switch (k) {
        case 0:
            s = 0;
            break;
        case 1:
            s = 1;
            break;
        case 2:
            s = 2;
            break;
        case 3:
            s = 3;
            break;
        default:
            s = 0;
            break;
        }
        if (s != v) {
            r = (u8 *)func_021C88A4(a, 0x39, id);
            ((struct Obj10063 *)r)->f0 |= 0x800000;
            r[4] = id;
            r[5] = s;
            func_021C8838(r + 8, 2, 0xde);
            func_021C8860((struct S *)(r + 8), id);
            func_021C88C8(a, r);
        }
    }
}
