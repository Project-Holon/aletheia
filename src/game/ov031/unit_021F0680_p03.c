/*
 * file:     unit_021F0680_p03.c
 * unit:     yes
 * function: func_021F0EF4, func_021F0F40, func_021F0F68
 * address:  0x021F0EF4
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204162C  0x0204162C  arm
 *   func_020413B0  0x020413B0  arm
 *   func_02041B6C  0x02041B6C  arm
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef struct {
    u16 cnt;
    u8 idx;
    u8 pad;
} Slot;

typedef struct {
    char pad[0x34];
    Slot s[3];
} A;

typedef struct {
    char pad[0x440];
    int n;
} B;

extern u32 func_0204162C(int channel);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(u32 bit);
void func_021F0EF4(A *p, B *q);
void func_021F0F40(A *p, int unused, int idx);
int func_021F0F68(void *unused, int idx, int flag);


void func_021F0EF4(A *p, B *q)
{
    int i;
    int k;
    int n;

    for (i = 0; i < 3; i++) {
        if (p->s[i].cnt != 0) {
            p->s[i].cnt--;
            if (p->s[i].cnt == 0) {
                n = q->n;
                if (n < 3)
                    k = p->s[i].idx;
                else
                    k = p->s[i].idx + 2 - n;
                if (k >= 0 && k < 3)
                    func_021F0F68(p, k, 0);
            }
        }
    }
}

void func_021F0F40(A *p, int unused, int idx) { int i; for(i=0;i<3;i++) if(p->s[i].cnt!=0 && idx!=p->s[i].idx) p->s[i].cnt=1; }


int func_021F0F68(void *unused, int idx, int flag)
{
    u16 *map;
    int pal;

    map = (u16 *)func_0204162C(6);
    switch ((u16)(map[idx * 0xE0] >> 12)) {
    case 0:
    case 1:
        if (flag == 0)
            pal = 0;
        else
            pal = 1;
        break;
    case 2:
    case 3:
        if (flag == 0)
            pal = 2;
        else
            pal = 3;
        break;
    default:
        return 0;
    }
    func_020413B0(6, 0, idx * 7, 0x20, 7, pal);
    func_02041B6C(6);
    return 1;
}
