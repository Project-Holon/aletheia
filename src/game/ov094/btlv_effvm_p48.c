/*
 * file:     btlv_effvm_p48.c
 * unit:     yes
 * function: func_021FC9F4, func_021FCA04, func_021FCD14, func_021FCF2C
 * address:  0x021FC9F4
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
 *   func_021F8710 0x021F8710 thumb ov094
 *   func_021F7F1C 0x021F7F1C thumb ov094
 *   func_021FD04C 0x021FD04C thumb ov094
 *   d_02209E58 0x02209E58 data a4
 *   func_021F8694 0x021F8694 thumb ov094
 *   func_021FF348 0x021FF348 thumb ov094
 *   d_02209E28 0x02209E28 data ov094 a4
 *   d_0220AD18 0x0220AD18 data ov094 a4
 *   d_0220AD38 0x0220AD38 data ov094 a4
 *   func_02011324  0x02011324  thumb
 *   func_021FD070  0x021FD070  thumb  ov094
 */
struct ScriptVm;
typedef struct {
    unsigned lo : 16;
    unsigned bit : 1;
} Flags;

typedef unsigned char u8;

typedef enum { KEY_ZERO, KEY_ONE, KEY_TWO, KEY_THREE, KEY_MAX = 7 } Key;

typedef struct {
    char pad00[0xdc];
    int dc, e0;
    char pade4[0x164];
    u8 kind;
} State;

typedef struct { int v[4][3]; } Targets;

typedef struct {
    unsigned int word0;
    char pad[0xd8];
    int dc;
    int e0;
} Unit;

extern int func_021F8710(void);
extern int func_021F7F1C(int);
extern int func_021FD04C(State *, int);
extern int func_021F8694(void);
extern int func_021FF348(void *, int);
extern void *func_02011324(struct ScriptVm *vm);
extern int func_021FD070(int a, int b);
int func_021FC9F4(void *a, Flags *s);
int func_021FCA04(State *s, int cmd, int *out);
int func_021FCD14(State *s, int unused, int *out);
int func_021FCF2C(int a, int idx);
extern const Targets d_02209E58;
extern const Targets d_02209E28;
extern const int d_0220AD18[], d_0220AD38[];


/*
 * Wait callback: done once flag bit 16 of the state word is clear.
 */
int func_021FC9F4(void *a, Flags *s)
{
    if (s->bit)
        return 0;
    return 1;
}


int func_021FCA04(State *s, int cmd, int *out)
{
    Key k;
    int n = 1;
    int mode;
    Targets t;
    int group;
    int *p;
    int i;
    int hi;

    switch (cmd) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6:
    case 7: case 8: case 9: case 10: case 11: case 12: case 13:
        out[0] = cmd;
        break;
    case 14:
        out[0] = s->dc;
        if (out[0] == 0xff) {
            if (func_021F7F1C(0) == 1) {
                out[0] = 0;
            } else if (func_021F7F1C(2) == 1) {
                out[0] = 2;
            } else if (func_021F7F1C(4) == 1) {
                out[0] = 4;
            } else if (func_021F7F1C(4) == 1) {
                out[0] = 6;
            }
        }
        break;
    case 15:
        if (s->dc > 1) {
            out[0] = s->dc ^ 2;
        } else {
            out[0] = 0xff;
        }
        break;
    case 16:
        out[0] = s->e0;
        if (out[0] == 0xff) {
            mode = func_021F8710();
            n = 0;
            if (mode == 0 || mode == 3) {
                if (s->kind == 8 || s->kind == 10) {
                    out[0] = s->dc;
                    n = 1;
                    if (func_021F7F1C(s->dc ^ 1)) {
                        out[1] = s->dc ^ 1;
                        n++;
                    }
                } else {
                    k = KEY_ONE;
                    n = 0;
                    if (func_021F7F1C(s->dc ^ k)) {
                        out[0] = s->dc ^ k;
                        n++;
                    }
                }
            } else {
                switch (s->kind) {
                case 0: case 1: case 2: case 3:
                    break;
                case 4:
                    if (mode == 2 && s->dc != 4 && s->dc != 5) {
                        t = d_02209E58;
                        group = s->dc > 3 ? 2 : 0;
                        i = 0;
                        p = t.v[(s->dc & 1) + group];
                        for (; i < 3; i++) {
                            if (func_021F7F1C(p[i])) {
                                out[n] = p[i];
                                n++;
                            }
                        }
                    } else {
                        for (k = KEY_TWO; k <= KEY_MAX; k++) {
                            if (s->dc != k && func_021F7F1C(k)) {
                                out[n] = k;
                                n++;
                            }
                        }
                    }
                    break;
                case 5: case 7: case 9: case 13:
                    k = (s->dc & 1) ? KEY_TWO : KEY_THREE;
                    hi = (mode == 2) ? 7 : 5;
                    if (mode == 2) {
                        if (s->dc <= 3)
                            k += 2;
                        if (s->dc >= 6)
                            hi -= 2;
                    }
                    for (; k <= hi; k += 2) {
                        if (func_021F7F1C(k)) {
                            out[n] = k;
                            n++;
                        }
                    }
                    break;
                case 11:
                    k = (s->dc & 1) ? KEY_TWO : KEY_THREE;
                    for (; k <= KEY_MAX; k += 2) {
                        if (func_021F7F1C(k)) {
                            out[n] = k;
                            n++;
                        }
                    }
                    break;
                case 6: case 12:
                    k = (s->dc & 1) ? KEY_THREE : KEY_TWO;
                    for (; k <= KEY_MAX; k += 2) {
                        if (func_021F7F1C(k)) {
                            out[n] = k;
                            n++;
                        }
                    }
                    break;
                case 8: case 10:
                    for (k = KEY_TWO; k <= KEY_MAX; k++) {
                        if (func_021F7F1C(k)) {
                            out[n] = k;
                            n++;
                        }
                    }
                    break;
                }
            }
        }
        break;
    case 17:
        if (s->e0 > 1) {
            out[0] = s->e0 ^ 2;
        } else {
            out[0] = 0xff;
        }
        break;
    case 18:
        n = 0;
        for (k = KEY_ZERO; k <= KEY_MAX; k++) {
            if (func_021F7F1C(k)) {
                out[n] = k;
                n++;
            }
        }
        break;
    case 19: case 20:
        k = (cmd == 19) ? KEY_ZERO : (Key)n;
        n = 0;
        for (; k <= KEY_MAX; k += 2) {
            if (func_021F7F1C(k)) {
                out[n] = k;
                n++;
            }
        }
        break;
    }
    if (out[0] != 0xff && out[0] < 8) {
        if (func_021F7F1C(out[0]) == 1) {
            out[0] = func_021FD04C(s, out[0]);
        } else {
            out[0] = 0xff;
            n = 0;
        }
    }
    return n;
}


/*
 * lever: enum key retains loop entry guards and constant one; shared outer
 *   exit, separate output store/increment, and branch-local n=0 reproduce
 *   the original scheduling (r1 266 bytes DIFF; r2 532 bytes; r3 EXACT).
 */
int func_021FCD14(State *s, int unused, int *out)
{
    Key k = KEY_ONE;
    int n = 1;
    int mode;
    Targets t;
    int group;
    int *p;
    int i;

    out[0] = s->e0;
    if (out[0] == 0xff) {
    mode = func_021F8710();
    n = 0;
    if (mode == 0 || mode == 3) {
        if (s->kind == 8 || s->kind == 10) {
            out[0] = s->dc;
            n = 1;
            if (func_021F7F1C(s->dc ^ 1)) {
                out[1] = s->dc ^ 1;
                n++;
            }
        } else {
            n = 0;
            if (func_021F7F1C(s->dc ^ 1)) {
                out[0] = s->dc ^ 1;
                n++;
            }
        }
    } else {
        switch (s->kind) {
        case 0: case 1: case 2: case 3:
            break;
        case 4:
            if (mode == 2 && s->dc != 4 && s->dc != 5) {
                t = d_02209E28;
                group = s->dc > 3 ? 2 : 0;
                i = 0;
                p = t.v[(s->dc & 1) + group];
                for (; i < 3; i++) {
                    if (func_021F7F1C(p[i]) && !func_021FF348((void *)func_021F8694(), p[i])) {
                        out[n] = p[i];
                        n++;
                    }
                }
            } else {
                for (k = KEY_TWO; k <= KEY_MAX; k++) {
                    if (s->dc != k && func_021F7F1C(k) && !func_021FF348((void *)func_021F8694(), k)) {
                        out[n] = k;
                        n++;
                    }
                }
            }
            break;
        case 5: case 7: case 9: case 13:
            if (mode == 1) {
                out[0] = (s->dc & k) ? 0 : k;
                n = 1;
            } else {
                if (s->dc != 4 && s->dc != 5) {
                    out[0] = d_0220AD18[s->dc];
                    n = k;
                } else {
                    out[0] = s->dc ^ 1;
                    n = 1;
                }
            }
            break;
        case 11:
            if (mode == 1) {
                out[0] = (s->dc & k) ? 0 : k;
                n = 1;
            } else {
                if (s->dc != 4 && s->dc != 5) {
                    out[0] = d_0220AD38[s->dc];
                    n = k;
                } else {
                    out[0] = s->dc ^ 1;
                    n = 1;
                }
            }
            break;
        case 6: case 12:
            k = (s->dc & k) ? KEY_THREE : KEY_TWO;
            for (; k <= KEY_MAX; k += 2) {
                if (func_021F7F1C(k) && !func_021FF348((void *)func_021F8694(), k)) {
                    out[n] = k;
                    n++;
                }
            }
            break;
        case 8: case 10:
            for (k = KEY_TWO; k <= KEY_MAX; k++) {
                if (func_021F7F1C(k) && !func_021FF348((void *)func_021F8694(), k)) {
                    out[n] = k;
                    n++;
                }
            }
            break;
        }
    }
    }
    return n;
}


int func_021FCF2C(int a, int idx)
{
    Unit *s = func_02011324((struct ScriptVm *)a);
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
