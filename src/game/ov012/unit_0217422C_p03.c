/*
 * file:     unit_0217422C_p03.c
 * unit:     yes
 * function: func_02174AD8, func_02174B08, func_02174B40
 * address:  0x02174AD8
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02157450  0x02157450  thumb  ov010
 *   func_020146F8 0x020146F8 thumb
 *   ov110_id 0x0000006E data a1
 *   d_021C39D4 0x021C39D4 data ov110 a4
 *   func_0203A574 0x0203A574 arm
 *   d_02175588 0x02175588 data a4
 */
struct Rec;
typedef unsigned char u8;

typedef unsigned int u32;

void *func_02157450(void *a0, void *a1, u32 kind, struct Rec *rec);
extern void *func_020146F8(char *, int, int, int, int);
extern void func_0203A574(u32,u32,u32,u32);
u32 func_02174AD8(void *a0, u8 *a1, void *a2, void *a3, u32 a4, void **out, u8 *state);
int func_02174B08(char *a, u8 *p, int b, int c, int x, void **out, u8 *state);
void func_02174B40(u32 p);
extern u8 ov110_id[];
extern const int d_021C39D4[];
extern u32 d_02175588[];


u32 func_02174AD8(void *a0, u8 *a1, void *a2, void *a3, u32 a4, void **out, u8 *state)
{
    u8 *q = a1 + 0x2830;
    if (*state == 0) {
        *out = func_02157450(a0, a2, q[0], a3);
    } else {
        return 1;
    }
    (*state)++;
    return 0;
}

int func_02174B08(char *a, u8 *p, int b, int c, int x, void **out, u8 *state)
{
    if (*state == 0) {
        *out = func_020146F8(a, b, (int)ov110_id, (int)d_021C39D4, c);
    } else {
        return 1;
    }
    (*state)++;
    return 0;
}

void func_02174B40(u32 p)
{
    func_0203A574(0x1500, (u32)d_02175588, 14, p);
}
