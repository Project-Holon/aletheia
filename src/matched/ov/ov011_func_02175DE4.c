/*
 * function: func_02175DE4
 * address:  0x02175DE4
 * packet:   pkt_ov011_02175DE4
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_02012B58  0x02012B58  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct {
    u32 w0;
    u8  pad04[0x30];
    u8  f34[3];
    u8  f37;
} Blk;

extern u32 func_02026478(void *obj);
struct BigObj;
extern u8 func_02012B58(const struct BigObj *p);

int func_02175DE4(void *p)
{
    Blk *b;
    int sv;
    int i;

    sv = func_02026478(((void **)p)[1]);
    b = (Blk *)((char *)p + 0x258);
    if (b->f37 == 1) {
        return 0;
    }
    for (i = 0; i < 3; i++) {
        if (b->f34[i] == func_02012B58((const struct BigObj *)sv)) {
            u32 v = (b->w0 << 10) >> 25;
            if (v > 0x14) {
                return 1;
            }
            return v;
        }
    }
    return 0;
}
