/*
 * function: BOX2_SEQ_SetBox2Main
 * address:  0x021E24EC
 * packet:   pkt_ov170_021E24EC
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_UI_GetBackButtonPoint 0x021EF1FC thumb
 *   func_020307B0 0x020307B0 arm
 *   BOX2_MAIN_SelectBox 0x021DD1C4 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb
 *   BOX2_SEQ_OpenBoxUp 0x021E19D4 thumb
 *   BOX2_SEQ_OpenBoxLeft 0x021E1A78 thumb
 *   BOX2_SEQ_OpenBoxDown 0x021E1A28 thumb
 *   BOX2_SEQ_OpenBoxRight 0x021E1ACC thumb
 *
 * Touch-drag paging of the box list: a drag of three or more pixels
 * starts a scroll of |d| / 8 steps in its direction; each later call
 * spends one step until the count runs out.
 */

typedef struct {
    short left;
    short dir;
} Scroll;

extern int BOX2_UI_GetBackButtonPoint(unsigned *a, unsigned *b);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void BOX2_MAIN_SelectBox(char *p, int a);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_SEQ_OpenBoxUp(char *p);
extern int BOX2_SEQ_OpenBoxLeft(char *p);
extern int BOX2_SEQ_OpenBoxDown(char *p);
extern int BOX2_SEQ_OpenBoxRight(char *p);

#define WORK(p) (*(char **)((p) + 0x2C))
#define STATE(p) (*(int *)((p) + 0x28))
#define SCROLL(p) (*(Scroll **)(WORK(p) + 0xA190))
#define LASTY(p) (*(unsigned *)(WORK(p) + 0xA184))
#define ABS(x) ((x) < 0 ? -(x) : (x))

int BOX2_SEQ_SetBox2Main(unsigned char *p)
{
    unsigned x, y;
    Scroll *s;
    unsigned old;
    int d;

    if (BOX2_UI_GetBackButtonPoint(&x, &y) == 0) {
        func_020307B0(SCROLL(p));
        return STATE(p);
    }
    s = SCROLL(p);
    old = LASTY(p);
    LASTY(p) = y;
    d = old - y;
    if (ABS(d) >= 3) {
        s->left = ABS(d) / 8;
        if (y < old) {
            s->dir = 1;
            BOX2_MAIN_SelectBox((char *)p, 1);
            GFL_USE_PlaySeDefaultVolume(0x548);
            if (STATE(p) == 0x15)
                return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_SEQ_OpenBoxUp, 0xF);
            return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_SEQ_OpenBoxLeft, 0xF);
        }
        if (y > old) {
            s->dir = -1;
            BOX2_MAIN_SelectBox((char *)p, -1);
            GFL_USE_PlaySeDefaultVolume(0x548);
            if (STATE(p) == 0x15)
                return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_SEQ_OpenBoxDown, 0xF);
            return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_SEQ_OpenBoxRight, 0xF);
        }
    }
    if (s->left != 0) {
        s->left--;
        if (s->dir == 1) {
            BOX2_MAIN_SelectBox((char *)p, 1);
            GFL_USE_PlaySeDefaultVolume(0x548);
            if (STATE(p) == 0x15)
                return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_SEQ_OpenBoxUp, 0xF);
            return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_SEQ_OpenBoxLeft, 0xF);
        }
        if (s->dir == -1) {
            BOX2_MAIN_SelectBox((char *)p, -1);
            GFL_USE_PlaySeDefaultVolume(0x548);
            if (STATE(p) == 0x15)
                return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_SEQ_OpenBoxDown, 0xF);
            return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_SEQ_OpenBoxRight, 0xF);
        }
    }
    return 0xF;
}
