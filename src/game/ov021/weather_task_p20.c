/*
 * file:     weather_task_p20.c
 * unit:     yes
 * function: func_021A2CC8, func_021A2CEC, func_021A2CF8, func_021A2D04
 * address:  0x021A2CC8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021A0224  0x021A0224  thumb  ov021
 */
typedef unsigned char u8;

typedef unsigned int  u32;

typedef struct {
    u8 pad[0x77C];
    u8 active;
    u8 mode;
    u8 half;
    u8 pad77F;
    u32 value;
} Obj021A2CC8;

typedef struct {
    u32 pad0;
    u32 handle;
    u8 pad8[0x774];
    u8 active;
    u8 mode;
    u8 half;
    u8 pad77F;
    u32 value;
} Obj021A2D04;

typedef unsigned short u16;

void func_021A0224(u8 *p, u32 a, u32 b, u32 c, u32 d, u16 e);
void func_021A2CC8(Obj021A2CC8 *p, u8 mode, u32 value, int n);
void func_021A2CEC(char *p);
u8 func_021A2CF8(char *p);
void func_021A2D04(Obj021A2D04 *p);


void func_021A2CC8(Obj021A2CC8 *p, u8 mode, u32 value, int n)
{
    p->active = 1;
    p->mode = mode;
    p->value = value;
    p->half = n / 2;
}

void func_021A2CEC(char *p)
{
    p[0x77c] = 0;
}


u8 func_021A2CF8(char *p)
{
    return p[0x77c];
}


void func_021A2D04(Obj021A2D04 *p)
{
    func_021A0224((u8 *)p->handle, 0x7FDF, p->value, p->mode, p->mode, p->half);
}
