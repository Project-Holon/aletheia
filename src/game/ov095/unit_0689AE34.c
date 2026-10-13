/*
 * file:     unit_0689AE34.c
 * unit:     yes
 * function: func_0689AE34
 * address:  0x0689AE34
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   POKE_TOOL_GetGender  0x02017F00  thumb
 *   func_0201BD28  0x0201BD28  thumb
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   func_02082A48  0x02082A48  arm
 *   func_021B8D8C  0x021B8D8C  thumb
 *   func_021B8E70  0x021B8E70  thumb
 *   func_021B98AC  0x021B98AC  thumb
 *   func_021D5440  0x021D5440  thumb
 *   func_021D5444  0x021D5444  thumb
 *   func_021D5864  0x021D5864  thumb
 *   func_021D59B4  0x021D59B4  thumb
 *   func_021D62A8  0x021D62A8  thumb
 *   func_021D80A8  0x021D80A8  thumb
 *   func_0220270C  0x0220270C  thumb
 */
#include "../../matched/include/Obj03219.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef unsigned int u32;

typedef struct { u32 kind:7, id:16, rest:9; } Q;

typedef struct { u8 flags, state; u16 pad; s16 hp, max; u32 word; } Row;

typedef struct { Row rows[6]; u8 mode, type; u16 pad; } Desc;

extern void func_02082A48(u32, void *, u32);
extern u8 func_021D5440(void *);
extern int func_021B8D8C(void *, void *, u32);
extern u8 func_021B8E70(void *, u32);
extern u32 func_0201BD28(u16, u32);
extern int func_021D80A8(void *);
extern u32 WAZA_TOOL_GetFlag(u16, u32);
extern void *func_021B98AC(char *const *, u8);
extern int func_021D5864(void *);
extern int func_021D59B4(void *, int);
extern u16 func_021D5444(void *);
extern u32 POKE_TOOL_GetGender(void *);
extern int func_021D62A8(void *);
extern void func_0220270C(char *, int, int);
void func_0689AE34(u8 *list, u8 n, int unused, u8 *s);

void func_0689AE34(u8 *list, u8 n, int unused, u8 *s)
{
    Desc desc;
    u16 key;
    void *mon;
    u32 word;
    u8 idx;
    Row *r;
    int status;
    key = (*(Q * *)&((struct Obj03219 *)s)->f70)->id;
    func_02082A48(0, &desc, sizeof(desc));
    desc.mode = func_021B8E70(((struct Obj03219 *)s)->fA0, func_021B8D8C(((struct Obj03219 *)s)->fA0, ((struct Obj03219 *)s)->fA4, func_021D5440(((struct Obj03219 *)s)->f6C)));
    desc.type = func_0201BD28(key, 0x1b);
    if (key == 0xae) desc.type = func_021D80A8(((struct Obj03219 *)s)->f6C);
    if (desc.type == 0 && WAZA_TOOL_GetFlag(key, 0xb)) desc.type = 14;
    while (n-- != 0) {
        mon = func_021B98AC(*(char *const * *)&((struct Obj03219 *)s)->fA4, *list);
        word = func_021D5864(mon);
        idx = func_021B8E70(((struct Obj03219 *)s)->fA0, *list) - 2;
        r = &desc.rows[idx];
        r->hp = func_021D59B4(mon, 0xd);
        r->flags |= 4;
        if (r->hp != 0) {
            status = func_021D5444(mon);
            r->word = word;
            r->max = func_021D59B4(mon, 0xe);
            if (status == 32 || status == 29) r->flags = (r->flags & ~3) | 2;
            else r->flags = (r->flags & ~3) | (POKE_TOOL_GetGender((void *)func_021D5864(mon)) & 3);
            if (func_021D62A8(mon)) r->state = 3;
            else r->state = 1;
        } else r->state = 2;
        list++;
    }
    func_0220270C(*(char * *)&((struct Obj03219 *)s)->fB0, 3, (int)&desc);
}
