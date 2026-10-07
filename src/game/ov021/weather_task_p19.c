/*
 * file:     weather_task_p19.c
 * unit:     yes
 * function: func_021A2C6C, func_021A2C98
 * address:  0x021A2C6C
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
 *   func_02028B50  0x02028B50  thumb
 *   func_02006148  0x02006148  thumb
 *   func_020061F8  0x020061F8  thumb
 *   func_02005C64  0x02005C64  thumb
 *   func_02028A7C  0x02028A7C  thumb
 *   func_020061E4  0x020061E4  thumb
 */
struct SoundSys2;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u16 state;
    u16 id;
    u32 pad4;
    u32 flag;
} Snd021A2C6C;

typedef unsigned char  u8;

typedef struct {
    u16 state;
    u16 id;
    u32 pad4;
    u32 flag;
} Snd021A2C98;

void func_02028B50(u8 *p, int a0);
int func_02006148(u32 a0);
void func_020061F8(int h);
int func_02005C64(void);
void func_02028A7C(struct SoundSys2 *s, u32 id);
void func_020061E4(u32 a);
void func_021A2C6C(Snd021A2C6C *p, int a);
void func_021A2C98(Snd021A2C98 *p, int a);


void func_021A2C6C(Snd021A2C6C *p, int a)
{
    if (p->state == 1) {
        p->state = 0;
        if (p->flag != 0)
            func_02028B50((u8 *)a, p->id);
        else
            func_020061F8(func_02006148(p->id));
    }
}


void func_021A2C98(Snd021A2C98 *p, int a)
{
    if (p->state == 2 && func_02005C64() == 0) {
        p->state = 1;
        if (p->flag != 0)
            func_02028A7C((struct SoundSys2 *)a, p->id);
        else
            func_020061E4(p->id);
    }
}
