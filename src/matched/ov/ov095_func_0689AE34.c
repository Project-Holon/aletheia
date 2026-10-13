/*
 * function: BTLV_SCD_ShowTargetMenu
 * address: 0x0689AE34
 * packet: pkt_ov095_0689AE34
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 0689AF8E..0689AF90 is the two-byte C0 46 alignment nop; no follower.
 * symbols:
 *   func_0689AF90 0x0689AF90 arm ov095
 *   func_0689AF98 0x0689AF98 thumb ov095
 *   func_0689AFA8 0x0689AFA8 thumb ov095
 *   func_0689AFB8 0x0689AFB8 thumb ov095
 *   func_0689AFC8 0x0689AFC8 thumb ov095
 *   func_0689AFD8 0x0689AFD8 thumb ov095
 *   func_0689AFE8 0x0689AFE8 thumb ov095
 *   func_0689AFF8 0x0689AFF8 thumb ov095
 *   func_0689B008 0x0689B008 thumb ov095
 *   func_0689B018 0x0689B018 thumb ov095
 *   func_0689B028 0x0689B028 thumb ov095
 *   func_0689B038 0x0689B038 thumb ov095
 *   func_0689B048 0x0689B048 thumb ov095
 *   func_0689B058 0x0689B058 thumb ov095
 *   func_0689B068 0x0689B068 thumb ov095
 *   func_0689B078 0x0689B078 thumb ov095
 *   func_0689B088 0x0689B088 thumb ov095
 */
#include "../include/Obj03219.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct { u32 kind:7, id:16, rest:9; } Q;
typedef struct { u8 flags, state; u16 pad; s16 hp, max; u32 word; } Row;
typedef struct { Row rows[6]; u8 mode, type; u16 pad; } Desc;
extern void func_0689AF90(u32, void *, u32);
extern u8 func_0689AF98(void *);
extern int func_0689AFA8(void *, void *, u32);
extern u8 func_0689AFB8(void *, u32);
extern u32 func_0689AFC8(u16, u32);
extern int func_0689AFD8(void *);
extern u32 func_0689AFE8(u16, u32);
extern void *func_0689AFF8(char *const *, u8);
extern int func_0689B008(void *);
extern u8 func_0689B018(void *, u32);
extern int func_0689B028(void *, int);
extern u16 func_0689B038(void *);
extern int func_0689B048(void *, int);
extern int func_0689B058(void *);
extern u32 func_0689B068(void *);
extern int func_0689B078(void *);
extern void func_0689B088(char *, int, int);
void BTLV_SCD_ShowTargetMenu(u8 *list, u8 n, int unused, u8 *s)
{
    Desc desc;
    u16 key;
    void *mon;
    u32 word;
    u8 idx;
    Row *r;
    int status;
    key = (*(Q * *)&((struct Obj03219 *)s)->f70)->id;
    func_0689AF90(0, &desc, sizeof(desc));
    desc.mode = func_0689AFB8(((struct Obj03219 *)s)->fA0, func_0689AFA8(((struct Obj03219 *)s)->fA0, ((struct Obj03219 *)s)->fA4, func_0689AF98(((struct Obj03219 *)s)->f6C)));
    desc.type = func_0689AFC8(key, 0x1b);
    if (key == 0xae) desc.type = func_0689AFD8(((struct Obj03219 *)s)->f6C);
    if (desc.type == 0 && func_0689AFE8(key, 0xb)) desc.type = 14;
    while (n-- != 0) {
        mon = func_0689AFF8(*(char *const * *)&((struct Obj03219 *)s)->fA4, *list);
        word = func_0689B008(mon);
        idx = func_0689B018(((struct Obj03219 *)s)->fA0, *list) - 2;
        r = &desc.rows[idx];
        r->hp = func_0689B028(mon, 0xd);
        r->flags |= 4;
        if (r->hp != 0) {
            status = func_0689B038(mon);
            r->word = word;
            r->max = func_0689B048(mon, 0xe);
            if (status == 32 || status == 29) r->flags = (r->flags & ~3) | 2;
            else r->flags = (r->flags & ~3) | (func_0689B068((void *)func_0689B058(mon)) & 3);
            if (func_0689B078(mon)) r->state = 3;
            else r->state = 1;
        } else r->state = 2;
        list++;
    }
    func_0689B088(*(char * *)&((struct Obj03219 *)s)->fB0, 3, (int)&desc);
}
