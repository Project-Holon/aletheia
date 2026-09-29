/*
 * function: func_02208814
 * address:  0x02208814
 * packet:   pkt_ov094_02208814
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Lever: the 0x80-byte-stride array at obj+0x54 is a struct member
 * (obj->e[idx]); the cast-pointer forms schedule `adds #0x54` before the
 * index shift, the member form schedules it after (as the original does).
 *
 * symbols:
 *   d_0220AAF0     0x0220AAF0  data   ov094  a4
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B878  0x0204B878  arm
 */

typedef unsigned int u32;
typedef unsigned short u16;

typedef struct E {
    int h;
    char pad[124];
} E;

typedef struct O {
    char pad[0x54];
    E e[8];
} O;

typedef struct T7 {
    u32 w[7];
} T7;

extern T7 d_0220AAF0;
extern void func_0204B3DC(int h, int f);
extern void func_0204B878(int h, u16 f);

void func_02208814(O *obj, int k, int idx)
{
    T7 t = d_0220AAF0;

    if (obj->e[idx].h != 0) {
        if (k == 0) {
            func_0204B3DC(obj->e[idx].h, 0);
            func_0204B878(obj->e[idx].h, 0);
        } else {
            func_0204B3DC(obj->e[idx].h, 1);
            func_0204B878(obj->e[idx].h, t.w[k]);
        }
    }
}
