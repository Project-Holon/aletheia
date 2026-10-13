/*
 * file:     unit_0689CFF0.c
 * unit:     yes
 * function: func_0689CFF0, func_0689D01C, func_0689D050, func_0689D064, func_0689D098, func_0689D0C8
 * address:  0x0689CFF0
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 */
#include "../../matched/include/Obj21912.h"

typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct { u32 value; u16 kind; u8 data, flag; } Rec;

typedef struct { u32 pos; Rec r[120]; } O;

extern void MI_CpuFill8(void *, int, u32);
void func_0689CFF0(void *p);
void func_0689D01C(O *p, u32 kind, u32 value, u32 data);
void func_0689D050(O *p);
int func_0689D064(O *p, u32 kind, u32 value);
int func_0689D098(O *p, u32 kind, u32 value);
u16 func_0689D0C8(O *p, u32 value);

void func_0689CFF0(void *p)
{
    u32 i;
    MI_CpuFill8(p, 0, 964);
    ((struct Obj21912 *)p)->f0 = 0;
    for (i = 0; i < 120; i++) {
        *(u16 *)((u32)p + i * 8 + 8) = 0;
    }
}

void func_0689D01C(O *p, u32 kind, u32 value, u32 data)
{
    p->r[p->pos].kind = kind;
    p->r[p->pos].value = value;
    p->r[p->pos].data = data;
    p->r[p->pos].flag = 0;
    p->pos++;
    if (p->pos >= 120)
        p->pos = 0;
}

void func_0689D050(O *p)
{
    int i;
    i = p->pos - 1;
    if (i < 0) i = 119;
    p->r[i].flag = 1;
}

int func_0689D064(O *p, u32 kind, u32 value)
{
    int i;
    int end;
    end = p->pos;
    i = end;
    for (;;) {
        i--;
        if (i < 0) i = 119;
        if (i == end || p->r[i].kind == 0)
            break;
        if (kind == p->r[i].kind && value == p->r[i].value)
            return 1;
    }
    return 0;
}

int func_0689D098(O *p, u32 kind, u32 value)
{
    int i;
    int count;
    int end;
    end = p->pos;
    count = 0;
    i = end;
    for (;;) {
        i--;
        if (i < 0) i = 119;
        if (i == end || p->r[i].kind == 0)
            break;
        if (kind == p->r[i].kind && value == p->r[i].value)
            count++;
    }
    return count;
}

u16 func_0689D0C8(O *p, u32 value)
{
    int i;
    int end;
    u16 kind;
    end = p->pos;
    i = end;
    for (;;) {
        i--;
        if (i < 0) i = 119;
        if (i == end)
            break;
        kind = p->r[i].kind;
        if (kind == 0)
            break;
        if (p->r[i].flag != 0 && value == p->r[i].value)
            return kind;
    }
    return 0;
}
