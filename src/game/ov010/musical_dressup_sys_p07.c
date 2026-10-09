/*
 * file:     musical_dressup_sys_p07.c
 * unit:     yes
 * function: func_02156F24, func_02156F68, func_02156F98, func_02156FC4, func_02156FD0
 * address:  0x02156F24
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F8480  0x021F8480  thumb ov132
 *   func_021F879C  0x021F879C  thumb
 *   func_021F8640  0x021F8640  thumb
 *   func_02030734  0x02030734  arm
 *   d_02172754  0x02172754  data
 *   func_020307B0  0x020307B0  arm
 *   func_021F67E0  0x021F67E0  thumb  ov112
 */
#include "../../matched/include/Obj17620.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Stage_02156F24 {
    void *f00;          /* 0x00 */
    void *f04[4];       /* 0x04 */
    u8 pad14[0x20 - 0x14];
} Stage_02156F24;

typedef short s16;

typedef struct Obj_02156F24 {
    u32 kind;
} Obj_02156F24;

typedef struct Stage_02156F98 {
    void *f00;          /* 0x00 */
    Obj_02156F24 *f04[4];        /* 0x04 */
} Stage_02156F98;

typedef struct Obj_02156FD0 {
    u32 kind;           /* 0x00 */
    u8 pad04[0x78 - 0x04];
    u16 f78;            /* 0x78 */
} Obj_02156FD0;

typedef struct Stage {
    void *f00;          /* 0x00 */
    Obj_02156FD0 *f04[4];        /* 0x04 */
} Stage;

extern u8 *func_021F8480(u8 *input, int heap);
extern int func_021F879C(int);
extern void func_021F8640(int);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *);
extern char *func_021F67E0(u16 a, u8 b, u8 c, u8 d, u32 e, u16 heap);
int func_02156F24(int a, int *state, int c, int *d);
Stage_02156F24 *func_02156F68(u32 heap, void *p);
int func_02156F98(struct Stage *);
int func_02156FC4(int a0, int a1, int a2);
void func_02156FD0(Stage *, u8, u16, u8, u32, u16, u16);
extern const char d_02172754[];




int func_02156F24(int a, int *state, int c, int *d)
{
    switch (*state) {
    case 0:
        d[1] = (int)func_021F8480((u8 *)d[0], 0x2e);
        *state = 1;
        break;
    case 1:
        if (func_021F879C(d[1]) == 1)
            *state = 2;
        break;
    case 2:
        func_021F8640(d[1]);
        return 1;
    }
    return 0;
}




Stage_02156F24 *func_02156F68(u32 heap, void *p)
{
    Stage_02156F24 *s;
    u8 i;

    s = func_02030734(heap, 0x20, 0, d_02172754, 0xBE);
    s->f00 = p;
    for (i = 0; i < 4; i++)
        s->f04[i] = 0;
    return s;
}




int func_02156F98(struct Stage *s){
    u8 i;

    for (i = 0; i < 4; i++) {
        if (s->f04[i] != 0 && s->f04[i]->kind == 2)
            func_020307B0(s->f04[i]);
    }
    func_020307B0(s);
}






int func_02156FC4(int a0, int a1, int a2)
{
    int a3;

a3 = a0 + 4;
a0 = a1 << 2;
*(int *)((char *)a3 + a0) = a2;
a0 = 0;
((struct Obj17620 *)((char *)a2))->f0 = a0;
    return a0;}


void func_02156FD0(Stage *s, u8 idx, u16 id, u8 v, u32 w, u16 x, u16 y)
{
    s->f04[idx] = (Obj_02156FD0 *)func_021F67E0(id, v, 0, 0, w, y);
    s->f04[idx]->kind = 2;
    s->f04[idx]->f78 = x;
}
