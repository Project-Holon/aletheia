/*
 * function: func_02206140
 * address:  0x02206140
 * packet:   pkt_ov094_02206140
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02206950  0x02206950  thumb
 *   func_022064CC  0x022064CC  thumb
 *   func_02206908  0x02206908  thumb
 *   func_02206B14  0x02206B14  thumb
 *   func_02206B30  0x02206B30  thumb
 *   func_02206B58  0x02206B58  thumb
 *   KEY_GetTrg  0x020362DC  arm  arm9
 *   KEY_GetCont  0x0203630C  arm  arm9
 *   CLACT_SetUnitDrawEnable  0x0204B22C  arm  arm9
 *
 * `const Ctx *c` lets the scheduler hoist the reload of c above the
 * bitfield store in the ret != -1 arm.
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    char p0[0x58];
    int f58;
    char p5c[0x68 - 0x5c];
    u32 lo : 4;
    u32 b4 : 1;
    u32 cur : 4;
    u32 prev : 4;
    u32 redraw : 1;
    u32 rest68 : 18;
    u32 b0 : 1;
    u32 b1 : 1;
    u32 rest6c : 30;
    char p70[0x17c - 0x70];
    void *f17c;
    char p180[0x220 - 0x180];
    int f220;
    char p224[0x242 - 0x224];
    u8 tbl[3][8];
    u8 f25a[8];
    u8 f262[4];
    u16 f266[3];
    u16 f26c[4];
    u8 *f274;
    int f278;
    int f27c;
} W;

typedef struct {
    u8 (*tab)[4];
    int *flags;
} Ctx;

extern u32 KEY_GetTrg(void);
extern unsigned int KEY_GetCont(void);
struct Bank;
extern void CLACT_SetUnitDrawEnable(struct Bank *bank, u32 mode);
extern void func_02206950(W *p);
extern void func_022064CC(W *p, u8 (*tab)[4], s8 (*rows)[12]);
extern int func_02206908(char *p, char *q, int i);
extern void func_02206B14(char *p);
extern void func_02206B30(char *p);
extern void func_02206B58(char *p);

int func_02206140(W *p, const Ctx *c, s8 (*rows)[12], u8 *list, int ret, int arg6)
{
    int keys;
    int cont;
    int done;
    s8 *row;
    int i;
    int k;
    int v;

    keys = KEY_GetTrg();
    cont = KEY_GetCont();
    done = 0;
    if (p->b0 == 0)
        keys &= ~2;
    if (p->redraw) {
        p->redraw = 0;
        func_02206950(p);
        func_022064CC(p, c->tab, rows);
        CLACT_SetUnitDrawEnable(p->f17c, 1);
    }
    v = -1;
    if (ret != v) {
        *p->f274 = 0;
        p->cur = 0;
        p->prev = 0xF;
        func_022064CC(p, c->tab, rows);
        return ret;
    }
    if (keys == 0)
        goto end;
    if (*p->f274 != 0) {
        v = -128;
        row = rows[p->cur];
        switch (keys) {
        case 0x40:
            v = row[6];
            break;
        case 0x80:
            v = row[7];
            break;
        case 0x20:
            v = row[8];
            break;
        case 0x10:
            v = row[9];
            break;
        case 2:
            k = row[11];
            if (k < 0) {
                if (p->b4 == 1)
                    v = (s8)-k;
            } else {
                v = k;
            }
            break;
        }
        if (keys == 1) {
            ret = row[10];
            if (ret < 4 && (cont & 0x200) && p->f58 == 5 && (arg6 == 1 || p->f220 == 1))
                goto draw;
            if (ret < 4 && (cont & 0x200) && p->f58 == 2 && arg6 == 1)
                goto draw;
            if (p->f25a[ret] == 1) {
                if (func_02206908((char *)p, (char *)c, ret) == 0)
                    func_02206B30((char *)p);
                else
                    func_02206B58((char *)p);
                done = 1;
            } else if (ret < 4 && (cont & 0x200) && p->f58 == 2 && p->f262[ret] == 1) {
                func_02206B30((char *)p);
            }
        } else if (v != -128) {
            func_02206B14((char *)p);
            if (v < 0) {
                if (-v != p->prev && p->prev != 0xF)
                    v = (s8)p->prev;
                else
                    v *= -1;
            } else if (v & 0x40) {
                i = 0;
                v &= ~0x40;
                for (; list[i] != 0xff; i++) {
                    if (p->prev == list[i]) {
                        v = (s8)p->prev;
                        break;
                    }
                }
            }
            p->prev = p->cur;
            p->cur = v;
            if (keys == 2) {
                if (v != 0xF)
                    func_02206B58((char *)p);
                ret = v;
                done = 1;
            }
        }
    } else if (keys & 0xcf3) {
        *p->f274 = 1;
        func_02206950(p);
        func_02206B14((char *)p);
    }
draw:
    func_022064CC(p, c->tab, rows);
end:
    if (done == 1) {
        switch (p->f58) {
        case 2:
            if (func_02206908((char *)p, (char *)c, p->cur) == 0)
                p->f266[p->f27c] = p->f26c[p->cur];
        case 1:
        case 5:
            if (func_02206908((char *)p, (char *)c, p->cur) == 0)
                p->tbl[p->f27c][p->f58] = p->cur;
            p->b1 = 1;
            break;
        case 3:
            if (func_02206908((char *)p, (char *)c, ret) == 0)
                p->tbl[p->f27c][p->f58] = p->cur | (p->tbl[p->f27c][2] << 4);
            p->b1 = 1;
            break;
        }
        p->cur = 0;
        p->prev = 0xF;
        p->redraw = 1;
        CLACT_SetUnitDrawEnable(p->f17c, 0);
    }
    return ret;
}
