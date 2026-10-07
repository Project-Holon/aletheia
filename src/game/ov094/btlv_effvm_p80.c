/*
 * file:     btlv_effvm_p80.c
 * unit:     yes
 * function: func_02201894, func_022018A8
 * address:  0x02201894
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F8694  0x021F8694  thumb  ov094
 *   d_0220A050  0x0220A050  data  ov094
 *   d_0220A080  0x0220A080  data  ov094
 *   d_0220A110  0x0220A110  data  ov094
 *   d_0220A158  0x0220A158  data  ov094
 *   d_0220A1A0  0x0220A1A0  data  ov094
 */
typedef struct {
    int x, y, z;
} Vec;

typedef struct {
    unsigned int b0 : 1;
    unsigned int b1 : 1;
} Flags;

typedef struct {
    char pad[0x510];
    Flags flags;
} Unit;

extern char *func_021F8694(void);
void func_02201894(int i);
void func_022018A8(Unit *u, Vec *out, int i);
extern const Vec d_0220A050[];
extern const Vec d_0220A080[];
extern const Vec d_0220A110[];
extern const Vec d_0220A158[];
extern const Vec d_0220A1A0[];


void func_02201894(int i)
{
    *(int *)(func_021F8694() + i * 0x5c + 0x4c) = 0;
}


void func_022018A8(Unit *u, Vec *out, int i)
{
    const Vec *t = (const Vec *)u;

    switch (i) {
    case 0:
    case 1:
        t = &d_0220A050[i];
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        if (u->flags.b1)
            t = &d_0220A1A0[i - 2];
        else if (u->flags.b0)
            t = &d_0220A158[i - 2];
        else
            t = &d_0220A080[i - 2];
        break;
    case 6:
    case 7:
        if (u->flags.b1)
            t = &d_0220A1A0[i - 2];
        else
            t = &d_0220A158[i - 2];
        break;
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        t = &d_0220A110[i - 8];
        break;
    }
    out->x = t->x;
    out->y = t->y;
    out->z = t->z;
}
