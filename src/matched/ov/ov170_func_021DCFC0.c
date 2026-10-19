/*
 * function: BOX2_MAIN_StepWindowFrameFade
 * address:  0x021DCFC0
 * packet:   pkt_ov170_021DCFC0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_SetActorAutoAnim 0x021EBFCC thumb
 *   BOX2_SEQ_IsActorAnimActive 0x021EBFEC thumb
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj00000.h"

typedef struct {
    unsigned char flag : 1;
    unsigned char id : 7;
    unsigned char lo : 4;
    unsigned char hi : 4;
    unsigned char state;
    unsigned char count;
    unsigned char x;
    unsigned char y;
    unsigned char w;
    unsigned char h;
} Fade;

extern void BOX2_SEQ_SetActorAutoAnim(char *p, int i, int v);
typedef unsigned int   u32;
extern u32 BOX2_SEQ_IsActorAnimActive(char *p, int i);
typedef unsigned char  u8;
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(unsigned bit);

int BOX2_MAIN_StepWindowFrameFade(char *p)
{
    Fade *f = (Fade *)(*(char * *)&((struct Obj00000 *)p)->f2C + 0x1A6);
    switch (f->state) {
    case 0:
        if (f->flag == 0) {
            BOX2_SEQ_SetActorAutoAnim(*(char * *)&((struct Obj00000 *)p)->f2C, f->id, f->lo);
        } else {
            BG_SYS_FillTileMap(f->id, f->x, f->y, f->w, f->h, f->lo);
            func_02041B6C(f->id);
        }
        f->state++;
        break;
    case 1:
        if (f->flag == 0) {
            if (BOX2_SEQ_IsActorAnimActive(*(char * *)&((struct Obj00000 *)p)->f2C, f->id) == 0)
                return 0;
        } else {
            f->count++;
            if (f->count == 4) {
                BG_SYS_FillTileMap(f->id, f->x, f->y, f->w, f->h, f->hi);
                func_02041B6C(f->id);
                f->count = 0;
                f->state++;
            }
        }
        break;
    case 2:
        f->count++;
        if (f->count == 2)
            return 0;
        break;
    }
    return 1;
}
