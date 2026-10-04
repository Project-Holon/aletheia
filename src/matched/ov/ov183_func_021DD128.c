/*
 * function: func_021DD128
 * address: 0x021DD128
 * packet: pkt_ov183_021DD128
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_021FC754 0x021FC754 thumb ov186
 *   d_021E32A8 0x021E32A8 data a4
 */
#include "../include/Obj00050.h"
#include "../include/Obj06599.h"
#include "../include/Obj14423.h"
typedef unsigned short u16;
typedef unsigned char u8;
struct Record { u8 a, b, c, d; int value; };
extern const struct Record d_021E32A8[];
extern void *func_021FD12C(int a, void *owner, u16 heap);
extern void func_021FD170(char *p, char *q, void *text);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
extern void *func_021FC6A4(unsigned short plane, unsigned a, unsigned short b, unsigned short c, unsigned char d, unsigned char e, void *owner, unsigned short heap);
extern void func_021FC754(char *p, void *a, void *b, void *font, unsigned short value);
void func_021DD128(char *p, char *q)
{
    if (!((struct Obj00050 *)p)->fE4) {
        int first, second, i;
        const struct Record *rec;
        char *slot;
        ((struct Obj00050 *)p)->fE4 = 1;
        if (!((struct Obj00050 *)p)->f18)
            ((struct Obj00050 *)p)->f18 = func_021FD12C(*(int *)&((struct Obj06599 *)q)->f10, (void *)(*(int *)&((struct Obj00050 *)p)->f4), ((struct Obj00050 *)p)->fB4);
        func_021FD170(((struct Obj00050 *)p)->f18, (char *)(*(int *)&((struct Obj06599 *)q)->f10), (void *)0x14f);
        func_021FB964((void *)(*(int *)&((struct Obj06599 *)q)->f10), 30, ((struct Obj00050 *)p)->fB4);
        first = func_021FC20C(*(char * *)&((struct Obj06599 *)q)->f10);
        second = func_021FC214(*(char * *)&((struct Obj06599 *)q)->f10);
        for (i = 0; i < 2; i++) {
            rec = &d_021E32A8[i];
            slot = p + i * 4;
            ((struct Obj14423 *)slot)->f28 = func_021FC6A4(4, rec->a, rec->b, rec->c, rec->d, 14, (void *)(*(int *)&((struct Obj00050 *)p)->f4), ((struct Obj00050 *)p)->fB4);
            func_021FC754(((struct Obj14423 *)slot)->f28, (void *)second, (void *)rec->value, (void *)first, 0x3da0);
        }
    }
}
