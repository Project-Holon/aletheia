/*
 * function: func_021CEFFC
 * address:  0x021CEFFC
 * packet:   pkt_ov093_021CEFFC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B86B8  0x021B86B8  thumb  ov093
 *   func_021B9AF8  0x021B9AF8  thumb  ov093
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021B8670  0x021B8670  thumb  ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D5C30  0x021D5C30  thumb  ov093
 */
#include "../include/Obj09993.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void *func_021B86B8(void ***p);
extern char *func_021B9AF8(char *p, int i);
extern u8 func_021B9B94(char *p);
extern u32 func_021B8670(void ***p);
extern u8 *func_021B9C00(void *p, u32 i);
extern int func_021D5B68(void *m);
extern u32 func_021D5C30(void *m);

u32 func_021CEFFC(u8 *p)
{
    char *arr;
    u32 lim;
    u32 flag;
    u32 i;
    u32 c;
    u8 *w;
    u32 cnt;
    if (func_021B86B8(*(void *** *)&((struct Obj09993 *)p)->f0) == 0) {
        arr = func_021B9AF8(*(char * *)&((struct Obj09993 *)p)->f4, 1);
        cnt = func_021B9B94(arr);
        lim = func_021B8670(*(void *** *)&((struct Obj09993 *)p)->f0);
        if (lim > cnt) {
            lim = cnt;
        }
        flag = 0;
        c = 0;
        for (i = 0; i < lim; i++) {
            w = func_021B9C00(arr, (u8)i);
            if (func_021D5B68(w) == 0) {
                c++;
                if (func_021D5C30(w) != 0) {
                    flag = 1;
                }
            }
        }
        if (c == 1 && flag != 0) {
            return 1;
        }
    }
    return 0;
}
