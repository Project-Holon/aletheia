/*
 * function: func_021B8978
 * address: 0x021B8978
 * packet: pkt_ov172_021B8978
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BDFEC 0x021BDFEC thumb ov172
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_021B69F0 0x021B69F0 thumb ov172
 *   func_02082A7C 0x02082A7C arm
 *   func_021BA194 0x021BA194 thumb ov172
 *   d_021C6EC0 0x021C6EC0 data a2
 */
#include "../include/Obj03854.h"
#include "../include/Obj05444.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 a[9]; } Table;
extern const Table d_021C6EC0;
extern void *func_021BDFEC(void *);
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern u32 func_0203D1A4(struct Link *p);
extern void func_021B69F0(void);
extern void func_02082A7C(int, void *, int);
extern int func_021BA194(int unused, int a, void *buf, unsigned n);
void func_021B8978(int a, int b, int c, char *q)
{
    void *p;
    char *data, *input;
    Table table;
    p = func_021BDFEC(((struct Obj03854 *)q)->f3DC);
    data = *(char * *)&((struct Obj03854 *)q)->f1A4;
    input = data + 8;
    func_0203D1A4((struct Link *)((u32)func_020399A8()));
    if (((struct Obj05444 *)data)->f5 == 0) {
        func_021B69F0();
        func_02082A7C(0, ((struct Obj03854 *)q)->f1A8, 0xc800);
    }
    func_021BA194((int)p, (int)input, *(char * *)&((struct Obj03854 *)q)->f1A8 + (((struct Obj05444 *)data)->f5 << 11), ((struct Obj05444 *)data)->f0);
    if (((struct Obj05444 *)data)->f4 == 1) {
        table = d_021C6EC0;
        ((struct Obj03854 *)q)->f1A0 = table.a[((struct Obj05444 *)data)->f6];
        ((struct Obj03854 *)q)->f198 = 1;
        ((struct Obj03854 *)q)->f19C = ((struct Obj05444 *)data)->f2;
    }
    ((struct Obj03854 *)q)->f194 = 0;
}
