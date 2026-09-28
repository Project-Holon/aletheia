/*
 * function: func_021DCFC0
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
 *   func_021EBFCC 0x021EBFCC thumb
 *   func_021EBFEC 0x021EBFEC thumb
 *   func_020413B0 0x020413B0 arm
 *   func_02041B6C 0x02041B6C arm
 */

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

extern void func_021EBFCC(char *p, int i, int v);
extern int func_021EBFEC(char *p, int i);
extern void func_020413B0(unsigned index, unsigned char x, unsigned char y, unsigned char w, unsigned char h, unsigned char pal);
extern void func_02041B6C(unsigned bit);

int func_021DCFC0(char *p)
{
    Fade *f = (Fade *)(*(char **)(p + 0x2C) + 0x1A6);
    switch (f->state) {
    case 0:
        if (f->flag == 0) {
            func_021EBFCC(*(char **)(p + 0x2C), f->id, f->lo);
        } else {
            func_020413B0(f->id, f->x, f->y, f->w, f->h, f->lo);
            func_02041B6C(f->id);
        }
        f->state++;
        break;
    case 1:
        if (f->flag == 0) {
            if (func_021EBFEC(*(char **)(p + 0x2C), f->id) == 0)
                return 0;
        } else {
            f->count++;
            if (f->count == 4) {
                func_020413B0(f->id, f->x, f->y, f->w, f->h, f->hi);
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
