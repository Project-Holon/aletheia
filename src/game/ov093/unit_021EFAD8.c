/*
 * file:     unit_021EFAD8.c
 * unit:     yes
 * function: func_021EFAD8, func_021EFB34
 * address:  0x021EFAD8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021EFCE4  0x021EFCE4  thumb  ov093
 *   func_021EFC0C 0x021EFC0C thumb ov093
 *   func_021EF83C 0x021EF83C thumb ov093
 *   func_021E8A98 0x021E8A98 thumb ov093
 *   func_021E8AC8 0x021E8AC8 thumb ov093
 */
union Slot;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 v; } Slot;

typedef struct {
    u32 pad00[2];
    u32 t[8];
    Slot c[8];
    u32 z48[8];
    u32 w[8][6];
    u32 z128[8];
    u32 used[8];
} S;

void *func_021EFCE4(char *arg0, int arg1);
extern void func_021EFC0C(u32);
extern void func_021EF83C(char *, u32);
extern u32 func_021E8A98(Slot);
extern void func_021E8AC8(union Slot *p, u8 v);
int func_021EFAD8(char *a, u32 b, u32 c);
void func_021EFB34(S *a, u32 v);


/*
 * Lever: the append store is written `((u32 *)(a + b * 0x18 + 0x68))[n] = c`;
 * the flat `*(u32 *)(a + b * 0x18 + n * 4 + 0x68)` schedules the scaled index
 * before the row base (two instructions swapped).  A single `!= 0` guard with
 * one trailing `return 0` shares the exit.
 */
int func_021EFAD8(char *a, u32 b, u32 c)
{
    u32 n;
    u32 i;

    if (func_021EFCE4(a, b) != 0) {
        n = *(u32 *)(a + 0x128 + b * 4);
        if (n < 6) {
            for (i = 0; i < n; i++) {
                if (c == *(u32 *)(a + b * 0x18 + i * 4 + 0x68))
                    return 0;
            }
            ((u32 *)(a + b * 0x18 + 0x68))[n] = c;
            *(u32 *)(a + 0x128 + b * 4) = n + 1;
            return 1;
        }
    }
    return 0;
}

/*
 * lever: unsigned long outer index closes register rotation and missing base spill.
 */
void func_021EFB34(S *a, u32 v)
{
    unsigned long i;
    u32 j;
    int found;
    for (i = 0; i < 8; i++) {
        if (func_021EFCE4((char *)a, i) && a->z128[i]) {
            found = 0;
            for (j = 0; j < a->z128[i]; j++) {
                if (v == a->w[i][j]) { found = 1; break; }
            }
            if (found) {
                for (; j < 5; j++) a->w[i][j] = a->w[i][j + 1];
                a->w[i][j] = 0x1f;
                a->z128[i] = a->z128[i] - 1;
                if (a->z128[i] == 0) {
                    if (a->t[i]) { func_021EFC0C(a->t[i]); a->t[i] = 0; }
                    func_021EF83C((char *)a, i);
                } else {
                    if (v == func_021E8A98(a->c[i])) func_021E8AC8((union Slot *)(&a->c[i]), a->w[i][0]);
                }
            }
        }
    }
}
