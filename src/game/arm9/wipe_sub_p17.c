/*
 * file:     wipe_sub_p17.c
 * unit:     yes
 * function: func_02024464, func_02024498, func_020244D4
 * address:  0x02024464
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_0209F724  0x0209F724  data
 */
struct MsgBank;
struct Rec;
struct U16Vec;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct T {
    u16 f00;
    u16 f02;
    u16 f04;
};

typedef signed char    s8;

extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D478(void *s);
extern void func_02045808(struct U16Vec *vec);
u32 func_02024498(u32 a0, u32 a1, u32 a2);
u16 func_020244D4(void *obj, u32 idx);
extern u16 g_0209F724[];



int func_02024464(struct T *p, u32 a1)
{
    u32 n = func_02024498(p->f00, p->f02, a1);
    u32 i;

    for (i = 0; i < n; i++) {
        if (*(u16 *)((char *)p + i * 2 + 4) == 0xffff) {
            return 0;
        }
    }
    return 1;
}


u32 func_02024498(u32 a0, u32 a1, u32 a2)
{
    u32 x = (u32)func_02045B38(0, 2, g_0209F724[a0], a2);
    u32 y = (u32)func_02045EC0((struct MsgBank *)x, a1);
    u32 z;

    func_02045C04((struct Rec *)x);
    z = func_0201D478((void *)y);
    func_02045808((struct U16Vec *)y);

    return z;
}


u16 func_020244D4(void *obj, u32 idx)
{
    u16 val = ((u16 *)((char *)obj + 4))[idx];

    if (val == 0xffff) {
        return 0xffff;
    }
    return (u16)(val & (0xffff >> 5));
}
