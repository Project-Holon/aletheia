/*
 * function: BTLV_EFFVM_ResolveBattlerListExpanded
 * address: 0x021FCD14
 * packet: pkt_ov094_021FCD14
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: enum key retains loop entry guards and constant one; shared outer
 *   exit, separate output store/increment, and branch-local n=0 reproduce
 *   the original scheduling (r1 266 bytes DIFF; r2 532 bytes; r3 EXACT).
 * symbols:
 *   BTLV_EFFECT_GetMode 0x021F8710 thumb ov094
 *   BTLV_EFFECT_IsPokeSpriteLoaded 0x021F7F1C thumb ov094
 *   BTLV_EFFECT_GetMcss 0x021F8694 thumb ov094
 *   BTLV_MCSS_IsVanished 0x021FF348 thumb ov094
 *   d_02209E28 0x02209E28 data ov094 a4
 *   d_0220AD18 0x0220AD18 data ov094 a4
 *   d_0220AD38 0x0220AD38 data ov094 a4
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
extern const Targets d_02209E28;
extern const int d_0220AD18[], d_0220AD38[];
extern int BTLV_EFFECT_GetMode(void);
extern int BTLV_EFFECT_IsPokeSpriteLoaded(int);
extern int BTLV_EFFECT_GetMcss(void);
extern int BTLV_MCSS_IsVanished(void *, int);

int BTLV_EFFVM_ResolveBattlerListExpanded(State *s, int unused, int *out)
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
            n = 0;
            if (BTLV_EFFECT_IsPokeSpriteLoaded(s->dc ^ 1)) {
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
                    if (BTLV_EFFECT_IsPokeSpriteLoaded(p[i]) && !BTLV_MCSS_IsVanished((void *)BTLV_EFFECT_GetMcss(), p[i])) {
                        out[n] = p[i];
                        n++;
                    }
                }
            } else {
                for (k = KEY_TWO; k <= KEY_MAX; k++) {
                    if (s->dc != k && BTLV_EFFECT_IsPokeSpriteLoaded(k) && !BTLV_MCSS_IsVanished((void *)BTLV_EFFECT_GetMcss(), k)) {
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
                if (BTLV_EFFECT_IsPokeSpriteLoaded(k) && !BTLV_MCSS_IsVanished((void *)BTLV_EFFECT_GetMcss(), k)) {
                    out[n] = k;
                    n++;
                }
            }
            break;
        case 8: case 10:
            for (k = KEY_TWO; k <= KEY_MAX; k++) {
                if (BTLV_EFFECT_IsPokeSpriteLoaded(k) && !BTLV_MCSS_IsVanished((void *)BTLV_EFFECT_GetMcss(), k)) {
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
