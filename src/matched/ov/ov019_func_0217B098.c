/*
 * function: func_0217B098
 * address:  0x0217B098
 * packet:   pkt_ov019_0217B098
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02087C6C  0x02087C6C  arm
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_0217B158  0x0217B158  thumb  ov019
 *   func_0217AFE4  0x0217AFE4  thumb  ov019
 *   func_0217AE38  0x0217AE38  thumb  ov019
 *   func_0217F894  0x0217F894  thumb  ov019
 *   func_0200EDC4  0x0200EDC4  thumb
 *   func_0217F948  0x0217F948  thumb  ov019
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 mac[6];
    u8 pad;
    u8 f0 : 1;
    u8 f1 : 1;
} Ent8;

typedef struct {
    u8 pad[0x28];
    Ent8 tab[5];
    u8 pad2[0x5c - 0x50];
    int f5c;
    u8 pad3[0x6c - 0x60];
    u16 f6c;
    u8 pad4[2];
    u8 *slot[5];
} Obj;

extern void func_02087C6C(void *);
extern int func_0203EFC8(void *, void *, int);
extern int func_0217B158(int, Obj *, Ent8 *);
extern u8 *func_0217AFE4(int, Obj *, Ent8 *, int, int, int *);
extern void func_0217AE38(u8 *, int);
extern int func_0217F894(int, Obj *);
extern int func_0200EDC4(int, int);
extern void func_0217F948(int, int, int);

void func_0217B098(int a, int b, int c, int d, Obj *e)
{
    int out;
    u8 buf[8];
    int i;

    if (e->f6c == 0)
        return;
    func_02087C6C(buf);
    for (i = 0; i < 5; i++) {
        if (e->slot[i] == 0 && e->tab[i].f1 == 1
            && func_0203EFC8(buf, &e->tab[i], 6) != 0
            && func_0217B158(a, e, &e->tab[i]) != 0) {
            e->slot[i] = func_0217AFE4(a, e, &e->tab[i], i, 0, &out);
            e->slot[i][8] = 1;
            func_0217AE38(e->slot[i], 0);
            if (i == 0) {
                if (func_0217F894(c, e) == 1)
                    func_0217F948(d, out, 0);
                else if (func_0200EDC4(b, e->f5c) == 1)
                    func_0217F948(d, out, 1);
            }
        }
    }
}
