/*
 * function: func_021FCF2C
 * address:  0x021FCF2C
 * packet:   pkt_021FD1CC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02011324  0x02011324  thumb
 *   func_021F7F1C  0x021F7F1C  thumb  ov094
 *   func_021FD070  0x021FD070  thumb  ov094
 */
typedef struct {
    unsigned int word0;
    char pad[0xd8];
    int dc;
    int e0;
} Unit;

extern Unit *func_02011324(int a);
extern int func_021F7F1C(int i);
extern int func_021FD070(int a, int b);

int func_021FCF2C(int a, int idx)
{
    Unit *s = func_02011324(a);
    int v;

    switch (idx) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        v = idx;
        break;
    case 14:
        v = s->dc;
        if (v == 0xff) {
            if (func_021F7F1C(2) == 1)
                return 2;
            if (func_021F7F1C(4) == 1)
                return 4;
            if (func_021F7F1C(6) == 1)
                return 6;
            return 0;
        }
        break;
    case 15:
        if (s->dc > 1)
            v = s->dc ^ 2;
        else
            v = 0xff;
        break;
    case 16:
        v = s->e0;
        if (v == 0xff) {
            if (s->dc & 1) {
                if (func_021F7F1C(2) == 1)
                    return 2;
                if (func_021F7F1C(4) == 1)
                    return 4;
                if (func_021F7F1C(6) == 1)
                    return 6;
                return 0;
            } else {
                if (func_021F7F1C(3) == 1)
                    return 3;
                if (func_021F7F1C(5) == 1)
                    return 5;
                if (func_021F7F1C(7) == 1)
                    return 7;
                return 1;
            }
        }
        break;
    case 17:
        if (s->e0 > 1)
            v = s->e0 ^ 2;
        else
            v = 0xff;
        break;
    }
    return func_021FD070(a, v);
}
