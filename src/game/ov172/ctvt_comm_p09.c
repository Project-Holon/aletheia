/*
 * file:     ctvt_comm_p09.c
 * unit:     yes
 * function: func_021B8978, func_021B8A14, func_021B8A98
 * address:  0x021B8978
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BDFEC 0x021BDFEC thumb ov172
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_021B69F0 0x021B69F0 thumb ov172
 *   func_02082A7C 0x02082A7C arm
 *   func_021BA194 0x021BA194 thumb ov172
 *   d_021C6EC0 0x021C6EC0 data a2
 *   func_0203D3F8 0x0203D3F8 arm
 *   func_021BDFFC 0x021BDFFC thumb ov172
 *   func_021B6E88 0x021B6E88 thumb ov172
 */
#include "../../matched/include/Obj03854.h"
#include "../../matched/include/Obj05444.h"
#include "../../matched/include/Obj06560.h"
#include "../../matched/include/Obj24086.h"

struct Entry;
struct Link;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u16 a[9]; } Table;

extern int func_021BDFEC(void *p);
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *p);
extern void func_021B69F0(void);
extern void func_02082A7C(int, void *, int);
extern int func_021BA194(int unused, int a, void *buf, unsigned n);
extern u32 func_0203D3F8(u32, u32, u32, u32, u32, u32, u32, u32);
extern u32 func_021BDFFC(void *p);
extern void func_021B6E88(char *p, void *q);
void func_021B8978(int a, int b, int c, char *q);
u32 func_021B8A14(int unused, char *q);
void func_021B8A98(int a, u32 b, char *list, char *q);
extern const Table d_021C6EC0;

void func_021B8978(int a, int b, int c, char *q)
{
    void *p;
    char *data, *input;
    Table table;
    p = (void *)func_021BDFEC(((struct Obj03854 *)q)->f3DC);
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

u32 func_021B8A14(int unused, char *q)
{
    u32 entry, result;
    u8 available, write, read;
    entry = (u32)func_020399A8();
    write = ((struct Obj06560 *)q)->f1AC;
    read = ((struct Obj06560 *)q)->f1AD;
    if (read > write) available = 64 - read;
    else available = write - read;
    if (available > 8) available = 8;
    if (available != 0) {
        result = func_0203D3F8(entry, 255, 0x2002, available * 8, (u32)(q + 0x1ae + read * 8), 1, 1, 0);
        if (result != 0) {
            ((struct Obj06560 *)q)->f1AD += available;
            if (((struct Obj06560 *)q)->f1AD >= 64) ((struct Obj06560 *)q)->f1AD -= 64;
        }
        return result;
    }
    return 1;
}


void func_021B8A98(int a, u32 b, char *list, char *q)
{
    char *p;
    u8 n, i;
    p = (char *)func_021BDFFC(((struct Obj24086 *)q)->f3DC);
    n = (b >> 3) & 0xff;
    func_0203D1A4((struct Link *)((u32)func_020399A8()));
    for (i = 0; i < n; i++)
        func_021B6E88(p, list + i * 8);
}
