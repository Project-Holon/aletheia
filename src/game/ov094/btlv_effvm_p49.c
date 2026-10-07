/*
 * file:     btlv_effvm_p49.c
 * unit:     yes
 * function: func_021FD04C, func_021FD070
 * address:  0x021FD04C
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
 *   func_021F7F1C  0x021F7F1C  thumb  ov094
 */
typedef struct {
    unsigned int bit0 : 1;
} Unit;

struct OneBit {
    unsigned int v : 1;
};

extern int func_021F7F1C(int i);
extern struct OneBit *func_02011324(int a);
int func_021FD04C(Unit *s, int i);
int func_021FD070(int a, int b);


int func_021FD04C(Unit *s, int i)
{
    if (func_021F7F1C(i) == 1) {
        if (s->bit0)
            i ^= 1;
    } else {
        i = 0xff;
    }
    return i;
}


int func_021FD070(int a, int b)
{
    int r = b;

    if (func_02011324(a)->v)
        r ^= 1;
    return r;
}
