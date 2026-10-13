/*
 * function: func_02161BF8
 * address:  0x02161BF8
 * packet:   pkt_ov010_02161BF8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_IsCommBlocked  0x02012144  thumb
 *   GAMESYSTEM_SetCommBlocked  0x0201213C  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026400  0x02026400  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   d_021BFB3C     0x021BFB3C  data  ov203
 *   ov203_id       0x000000CB  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Obj {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    u8 f08[0x18];       /* 0x08 */
    u32 f20;            /* 0x20 */
} Obj;

extern u8 d_021BFB3C[];
extern u8 ov203_id[];

struct Comm;
struct Ctx;
extern u8 GAMESYSTEM_IsCommBlocked(const struct Ctx *p);
extern void GAMESYSTEM_SetCommBlocked(struct Ctx *p, u32 v);
extern u32 func_02026454(void *obj);
extern void func_02026400(struct Comm *p);
struct IcaAnime;
extern void GAMESYSTEM_CallProc(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 GAMESYSTEM_GetProcStatus(const struct Ctx *p);

int func_02161BF8(void *a0, int *state, Obj *o)
{
    switch (*state) {
    case 0:
        o->f20 = GAMESYSTEM_IsCommBlocked(o->f00);
        GAMESYSTEM_SetCommBlocked(o->f00, 1);
        if (func_02026454(o->f04) == 0) {
            *state = *state + 2;
        } else {
            func_02026400(o->f04);
            *state = *state + 1;
        }
        break;
    case 1:
        if (func_02026454(o->f04) == 0)
            *state = *state + 1;
        break;
    case 2:
        GAMESYSTEM_CallProc(o->f00, (u32)ov203_id, d_021BFB3C, o->f08);
        *state = *state + 1;
        break;
    case 3:
        if (GAMESYSTEM_GetProcStatus(o->f00) == 0) {
            GAMESYSTEM_SetCommBlocked(o->f00, o->f20);
            return 1;
        }
        break;
    }
    return 0;
}
