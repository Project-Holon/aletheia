/*
 * function: func_021E02F8
 * address: 0x021E02F8
 * packet: pkt_ov183_021E02F8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   BR_RES_LoadBgGraphics 0x021FB964 thumb ov186
 *   BR_UTIL_Create 0x021FC6A4 thumb ov186
 *   func_021FC868 0x021FC868 thumb ov186
 *   func_021FC754 0x021FC754 thumb ov186
 *   d_021E37D8 0x021E37D8 data ov183
 */
#include "../include/Obj01765.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Record { u8 a, b, c, d; int value; };
extern const struct Record d_021E37D8[];
extern unsigned BR_RES_GetFont(char *p);
extern int BR_RES_GetMsgData(char *);
extern void BR_RES_LoadBgGraphics(void *ctx, unsigned kind, unsigned short heap);
typedef unsigned int   u32;
extern void *BR_UTIL_Create(unsigned short plane, unsigned a, unsigned short b, unsigned short c, unsigned char d, unsigned char e, void *owner, unsigned short heap);
extern void func_021FC868(u8 *p, u32 a, u32 b, u32 c);
extern void func_021FC754(char *p, void *a, void *b, void *font, unsigned short value);
void func_021E02F8(char *p, int *q)
{
    int first, second, i;
    const struct Record *r;
    first = BR_RES_GetFont((char *)q[2]);
    second = BR_RES_GetMsgData((char *)q[2]);
    BR_RES_LoadBgGraphics((void *)q[2], 25, ((struct Obj01765 *)p)->f54);
    for (i = 0; i < 6; i++) {
        r = &d_021E37D8[i];
        *(void **)(p + i * 4 + 0x20) = BR_UTIL_Create(1, r->a, r->b, r->c, r->d, 14, ((struct Obj01765 *)p)->f48, ((struct Obj01765 *)p)->f54);
        func_021FC868(*(void **)(p + i * 4 + 0x20), 0, 1, 0);
        func_021FC754(*(void **)(p + i * 4 + 0x20), (void *)second, (void *)r->value, (void *)first, 15776);
    }
}
