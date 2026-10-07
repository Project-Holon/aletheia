/*
 * file:     field_flash_p02.c
 * unit:     yes
 * function: func_021C6E94, func_021C6EA8, func_021C6EDC
 * address:  0x021C6E94
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
 *   func_021C6CBC  0x021C6CBC  thumb  ov021
 *   func_021C6CC4  0x021C6CC4  thumb  ov021
 *   func_021C6CE0  0x021C6CE0  thumb  ov021
 *   func_021C6CD0  0x021C6CD0  thumb  ov021
 *   func_021C6E74  0x021C6E74  thumb  ov021
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Q Q;

typedef struct { u8 n; u8 pad[3]; Q **f4; u32 *f8; } R;

extern void func_021C6CBC(void);
extern u32 func_021C6CE0(u8 *p);
extern void func_021C6CC4(u32 *a0);
extern int func_021C6CD0(u32 a);
extern void func_021C6E74(R *r, int i);
void func_021C6E94(R *r, int i);
void func_021C6EA8(R *r, int i);
void func_021C6EDC(R *r, int i);

void func_021C6E94(R *r, int i)
{
    if (r->f4[i] != 0)
        func_021C6CBC();
}

void func_021C6EA8(R *r, int i)
{
    if (r->f4[i] != 0 && r->f8[i] != 0) {
        if (func_021C6CE0((u8 *)r->f4[i]) == 0 && func_021C6CE0((u8 *)r->f8[i]) == 2)
            func_021C6CC4((u32 *)r->f4[i]);
    }
}

void func_021C6EDC(R *r, int i)
{
    if (r->f4[i] != 0 && func_021C6CD0((u32)r->f4[i]) == 1)
        func_021C6E74(r, i);
}
