/*
 * file:     btl_server_p67.c
 * unit:     yes
 * function: func_021C5108, func_021C51D0, func_021C5200
 * address:  0x021C5108
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021BFF60 0x021BFF60 thumb ov093
 *   func_021D8510 0x021D8510 thumb ov093
 *   func_021DCF24 0x021DCF24 thumb ov093
 *   func_021D8538 0x021D8538 thumb ov093
 *   func_021DCFA4 0x021DCFA4 thumb ov093
 *   func_021E0434 0x021E0434 thumb ov093
 *   func_021BD2B4 0x021BD2B4 thumb ov093
 *   func_021BD338 0x021BD338 thumb ov093
 *   func_021BD34C 0x021BD34C thumb ov093
 *   func_021D6264 0x021D6264 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021EF90C 0x021EF90C thumb ov093
 *   func_021BC2B0 0x021BC2B0 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021C3FDC 0x021C3FDC thumb ov093
 *   func_021D74F8 0x021D74F8 thumb ov093
 *   func_021D75A8 0x021D75A8 thumb ov093
 *   func_021D70F0 0x021D70F0 thumb ov093
 *   func_021D7540 0x021D7540 thumb ov093
 *   func_021B85EC 0x021B85EC thumb ov093
 *   func_021C52C8 0x021C52C8 thumb ov093
 *   func_021C52D8 0x021C52D8 thumb ov093
 *   func_021C52E8 0x021C52E8 thumb ov093
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021BC310 0x021BC310 thumb ov093
 *   func_021B86DC 0x021B86DC thumb ov093
 *   func_021C5308 0x021C5308 thumb ov093
 *   func_021C52F8 0x021C52F8 thumb ov093
 */
#include "../../matched/include/Obj00003.h"

struct UtilSlots;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Flags { u8 a:1; u8 b:1; u8 rest:6; };

extern u8 func_021D5440(u8 *p);
extern void func_021BFF60(u8 *, u8 *, int);
extern void func_021D8510(void *p);
extern void func_021DCF24(u8 *);
extern void func_021D8538(void *p);
extern void func_021DCFA4(void *p);
extern void func_021E0434(u8 *);
extern void func_021BD2B4(u8 *, u8 **);
extern void func_021BD338(u8 *, u8 *);
extern int func_021BD34C(u8 *, u8 **, u8 **);
extern void func_021D6264(struct UtilSlots *p, int v);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern int func_021EF90C(int a);
extern int func_021BC2B0(u8 *);
extern int func_021D59B4(u8 *p, int k);
extern void func_021C3FDC(u8 *, u8 *);
extern void func_021D74F8(int);
extern void func_021D75A8(int, u32);
extern void func_021D70F0(void *a, int id);
extern void func_021D7540(int);
extern int func_021B85EC(u32 **p);
extern u32 func_021C52C8(u8 *, int);
extern int func_021C52D8(u8 *, int, u8);
extern int func_021C52E8(u8 *, int, u8);
extern u8 *func_021B9934(char *p, int i);
extern void *func_021B86B8(void ***p);
extern int func_021BC310(u8 *);
extern u16 func_021B86DC(void **p);
extern int func_021C5308(u8 *, u8 *);
extern void func_021C52F8(u8 *, int, u8);
void func_021C5108(u8 *p, u8 *a, int b);
void func_021C51D0(u8 *p, u8 *a);
int func_021C5200(u8 *p);


/*
 * extent: 198 compiled bytes followed by two zero padding bytes at 021C51CE.
 */
void func_021C5108(u8 *p, u8 *a, int b)
{
    u32 it;
    u8 *cur;
    int k = func_021D5440(a);
    func_021C51D0(p, a);
    func_021BFF60(p, a, 0);
    if (b == 0) {
        func_021D8510(a);
        func_021DCF24(a);
    } else {
        func_021D8538(a);
        func_021DCFA4(a);
    }
    func_021E0434(a);
    func_021BD2B4((u8 *)&it, (u8 **)p);
    func_021BD338((u8 *)&it, p);
    while (func_021BD34C((u8 *)&it, (u8 **)p, &cur)) {
        func_021D6264((struct UtilSlots *)cur, k);
        func_021CD4B0(((struct Obj00003 *)p)->fC, 0x2c, func_021D5440(cur), k);
    }
    func_021EF90C(k);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x23, k);
    if (!func_021BC2B0(p) && (u16)func_021D59B4(a, 0x11) == 0x7f)
        func_021C3FDC(p, a);
}


void func_021C51D0(u8 *p, u8 *a)
{
    int line = 0x27DF;
    func_021D74F8(line);
    func_021D75A8(2, func_021D5440(a));
    func_021D70F0(p, 0xA3);
    func_021D7540(line + 3);
}

int func_021C5200(u8 *p)
{
    int result = 0;
    u32 i;
    u32 count;
    u8 *a;
    if (func_021B85EC(((struct Obj00003 *)p)->f4)) {
        count = func_021C52C8(p + 0x3e0, 0);
        for (i = 0; i < count; i++) {
            if (!func_021C52D8(p + 0x3e0, 0, i)) {
                a = func_021B9934((char *)(*(u8 * *)&((struct Obj00003 *)p)->f8), func_021C52E8(p + 0x3e0, 0, i));
                if (!func_021B86B8(((struct Obj00003 *)p)->f4) && !((struct Flags *)(p + 0x78a))->b && func_021BC2B0(p) && func_021BC310(p)) {
                    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x55, func_021B86DC(((struct Obj00003 *)p)->f4));
                    ((struct Flags *)(p + 0x78a))->b = 1;
                }
                if (func_021C5308(p, a)) result = 1;
                func_021C52F8(p + 0x3e0, 0, i);
            }
        }
    }
    return result;
}
