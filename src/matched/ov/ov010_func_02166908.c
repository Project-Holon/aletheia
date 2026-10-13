/*
 * function: SYMBOL_MAP_PickerTaskMain
 * address:  0x02166908
 * packet:   pkt_ov010_02166908
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Former blocker: ABS32 for 0x000000DA (overlay id 218) and 0x021BAB5C (its callback table) have no
 * witness outside this function; GAME_EVENT_CallProc is not a listed overlay-id consumer and the
 * word is referenced only from this pool. Every concrete byte matches.
 *
 * symbols:
 *   func_020124E8  0x020124E8  thumb
 *   GAME_EVENT_CallProc  0x02012444  thumb
 *   ov_id_DA  0x000000DA  data
 *   d_021BAB5C  0x021BAB5C  data  a4 ov218
 
 * 2026-10-05 (D8 lane 15): the callback table d_021BAB5C lives in ov218 (loaded by this function); the data line now carries the ov218 token and the relocation resolves.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u8 pad0;
    u8 f1;
    u16 f2;
    int f4;
    u8 pad8[0x114];
    u16 *p11c;
    u16 *p120;
    u16 *p124;
};

struct Obj;
extern void *func_020124E8(struct Obj *p);
extern void GAME_EVENT_CallProc(struct Obj *obj, u32 a1, u32 a2, u32 a3);
extern char ov_id_DA[];
extern char d_021BAB5C[];

int SYMBOL_MAP_PickerTaskMain(void *a, int *st)
{
    struct S *s = func_020124E8(a);
    switch (*st) {
    case 0:
        GAME_EVENT_CallProc(a, (u32)ov_id_DA, (u32)d_021BAB5C, (u32)s);
        *st = *st + 1;
        break;
    case 1:
        if (s->f4 == 1) {
            *s->p124 = 1;
            *s->p11c = s->f1;
            *s->p120 = s->f2;
        } else {
            *s->p124 = 0;
            *s->p11c = 0;
            *s->p120 = 0;
        }
        return 1;
    }
    return 0;
}
