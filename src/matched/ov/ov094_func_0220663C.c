/*
 * function: func_0220663C
 * address: 0x0220663C
 * packet: pkt_ov094_0220663C
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202173C 0x0202173C thumb
 *   func_02021ED8 0x02021ED8 thumb
 *   func_0220687C 0x0220687C thumb ov094
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef struct PalAnmObj PalAnmObj;
typedef struct { char *p; int state, colour, flag; } Ctx;
extern int func_0202173C(PalAnmObj *, u16, u16, s16, u8, u8, u16, void *);
extern u32 func_02021ED8(const char *);
extern void func_0220687C(char *, void *);
void func_0220663C(void *task, Ctx *c)
{
    switch (c->state) {
    case 0:
        if (c->flag == 1)
            func_0202173C(*(PalAnmObj **)(c->p + 0x64), 8, 2, 0, 0, 8, 0x7fff, *(void **)c->p);
        else
            func_0202173C(*(PalAnmObj **)(c->p + 0x64), 2, c->colour, 0, 0, 8, 0x7fff, *(void **)c->p);
        c->state++;
        break;
    case 1:
        if (func_02021ED8(*(char **)(c->p + 0x64)) == 0) {
            if (c->flag == 1)
                func_0202173C(*(PalAnmObj **)(c->p + 0x64), 8, 2, 0, 8, 0, 0x7fff, *(void **)c->p);
            else
                func_0202173C(*(PalAnmObj **)(c->p + 0x64), 2, c->colour, 0, 8, 0, 0x7fff, *(void **)c->p);
            c->state++;
        }
        break;
    case 2:
        if (func_02021ED8(*(char **)(c->p + 0x64)) == 0)
            func_0220687C(c->p, task);
        break;
    }
}
