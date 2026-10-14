/*
 * function: BTLV_EFFVM_ResolveBattlerList
 * address: 0x021FCA04
 * packet: pkt_ov094_021FCA04
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTLV_EFFECT_GetMode 0x021F8710 thumb ov094
 *   BTLV_EFFECT_IsPokeSpriteLoaded 0x021F7F1C thumb ov094
 *   BTLV_EFFVM_ResolveSide 0x021FD04C thumb ov094
 *   d_02209E58 0x02209E58 data a4
 */
typedef unsigned char u8;
typedef enum { KEY_ZERO, KEY_ONE, KEY_TWO, KEY_THREE, KEY_MAX = 7 } Key;
typedef struct {
    char pad00[0xdc];
    int dc, e0;
    char pade4[0x164];
    u8 kind;
} State;
typedef struct { int v[4][3]; } Targets;
extern const Targets d_02209E58;
extern int BTLV_EFFECT_GetMode(void);
extern int BTLV_EFFECT_IsPokeSpriteLoaded(int);
extern int BTLV_EFFVM_ResolveSide(State *, int);

int BTLV_EFFVM_ResolveBattlerList(State *s, int cmd, int *out)
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
            if (BTLV_EFFECT_IsPokeSpriteLoaded(0) == 1) {
                out[0] = 0;
            } else if (BTLV_EFFECT_IsPokeSpriteLoaded(2) == 1) {
                out[0] = 2;
            } else if (BTLV_EFFECT_IsPokeSpriteLoaded(4) == 1) {
                out[0] = 4;
            } else if (BTLV_EFFECT_IsPokeSpriteLoaded(4) == 1) {
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
            mode = BTLV_EFFECT_GetMode();
            n = 0;
            if (mode == 0 || mode == 3) {
                if (s->kind == 8 || s->kind == 10) {
                    out[0] = s->dc;
                    n = 1;
                    if (BTLV_EFFECT_IsPokeSpriteLoaded(s->dc ^ 1)) {
                        out[1] = s->dc ^ 1;
                        n++;
                    }
                } else {
                    k = KEY_ONE;
                    n = 0;
                    if (BTLV_EFFECT_IsPokeSpriteLoaded(s->dc ^ k)) {
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
                            if (BTLV_EFFECT_IsPokeSpriteLoaded(p[i])) {
                                out[n] = p[i];
                                n++;
                            }
                        }
                    } else {
                        for (k = KEY_TWO; k <= KEY_MAX; k++) {
                            if (s->dc != k && BTLV_EFFECT_IsPokeSpriteLoaded(k)) {
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
                        if (BTLV_EFFECT_IsPokeSpriteLoaded(k)) {
                            out[n] = k;
                            n++;
                        }
                    }
                    break;
                case 11:
                    k = (s->dc & 1) ? KEY_TWO : KEY_THREE;
                    for (; k <= KEY_MAX; k += 2) {
                        if (BTLV_EFFECT_IsPokeSpriteLoaded(k)) {
                            out[n] = k;
                            n++;
                        }
                    }
                    break;
                case 6: case 12:
                    k = (s->dc & 1) ? KEY_THREE : KEY_TWO;
                    for (; k <= KEY_MAX; k += 2) {
                        if (BTLV_EFFECT_IsPokeSpriteLoaded(k)) {
                            out[n] = k;
                            n++;
                        }
                    }
                    break;
                case 8: case 10:
                    for (k = KEY_TWO; k <= KEY_MAX; k++) {
                        if (BTLV_EFFECT_IsPokeSpriteLoaded(k)) {
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
            if (BTLV_EFFECT_IsPokeSpriteLoaded(k)) {
                out[n] = k;
                n++;
            }
        }
        break;
    case 19: case 20:
        k = (cmd == 19) ? KEY_ZERO : (Key)n;
        n = 0;
        for (; k <= KEY_MAX; k += 2) {
            if (BTLV_EFFECT_IsPokeSpriteLoaded(k)) {
                out[n] = k;
                n++;
            }
        }
        break;
    }
    if (out[0] != 0xff && out[0] < 8) {
        if (BTLV_EFFECT_IsPokeSpriteLoaded(out[0]) == 1) {
            out[0] = BTLV_EFFVM_ResolveSide(s, out[0]);
        } else {
            out[0] = 0xff;
            n = 0;
        }
    }
    return n;
}
