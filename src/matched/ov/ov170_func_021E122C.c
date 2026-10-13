/*
 * function: func_021E122C
 * address:  0x021E122C
 * packet:   pkt_ov170_021E122C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ED108 0x021ED108 thumb
 *   func_021EBFA8 0x021EBFA8 thumb
 *   func_021EC000 0x021EC000 thumb
 *   func_021EBFEC 0x021EBFEC thumb
 *   func_021DE980 0x021DE980 thumb
 *   func_021DEA3C 0x021DEA3C thumb
 *   func_021DEAFC 0x021DEAFC thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *
 * Callback of func_021E6A60 (state machine in the 021E1324 family): show
 * window 10, return the held item to its slot, then hide the window.
 */

typedef struct {
    unsigned short idx;
    unsigned short slot;
} Entry;

typedef struct {
    unsigned char pad[8];
    Entry *entry;
    unsigned short state;
} Blk;

extern void func_021ED108(char *w, int on);
extern void func_021EBFA8(char *w, int i, int v);
extern void func_021EC000(char *w, int i, int v);
typedef unsigned int   u32;
extern u32 func_021EBFEC(char *p, int i);
extern void func_021DE980(unsigned char *p, int mode);
extern void func_021DEA3C(int a, int b, int c, int d);
extern int func_021DEAFC(int a);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);

#define WORK(p) (*(char **)((p) + 0x2C))

int func_021E122C(unsigned char *p)
{
    Blk *b = (Blk *)(WORK(p) + 0x58);
    switch (b->state) {
    case 0:
        func_021ED108(WORK(p), 1);
        func_021EBFA8(WORK(p), 10, 1);
        func_021EC000(WORK(p), 10, 1);
        b->state = 1;
        break;
    case 1:
        if (func_021EBFEC(WORK(p), 10) != 0)
            break;
        func_021ED108(WORK(p), 0);
        b->state = 2;
        break;
    case 2: {
        unsigned char old = p[0x16];
        p[0x16] = b->entry->idx;
        if (p[0x17] != 0xFF && p[0x17] != p[0x14])
            func_021DE980(p, 2);
        else
            func_021DEA3C((int)p, old, old, 2);
        b->state = 3;
        break;
    }
    case 3:
        if (func_021DEAFC((int)p) != 0)
            break;
        if (p[0x17] != 0xFF && p[0x17] != p[0x14]) {
            b->state = 5;
        } else {
            GFL_USE_PlaySeDefaultVolume(0x667);
            b->state = 4;
        }
        break;
    case 4:
        func_021ED108(WORK(p), 1);
        func_021EBFA8(WORK(p), 10, 2);
        b->state = 5;
        break;
    case 5:
        if (func_021EBFEC(WORK(p), 10) != 0)
            break;
        func_021EC000(WORK(p), 10, 0);
        func_021ED108(WORK(p), 0);
        b->state = 6;
        break;
    case 6:
        b->state = 0;
        return 0;
    }
    return 1;
}
