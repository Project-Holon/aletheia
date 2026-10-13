/*
 * function: INTRUDE_COMM_PickEntryForKind
 * address:  0x021763D8
 * packet:   pkt_ov011_021763D8
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gIntrudePickTable     0x02176C4C  data  ov011  a1
 *   func_020056EC  0x020056EC  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 key;
    u8 f1;
    u8 f2;
    u8 f3;
} Ent;

typedef struct {
    u8  pad[0xc];
    u16 h0c;
    u16 h0e;
} Src;

extern Ent gIntrudePickTable[];
extern u32 func_020056EC(u32 a);

void INTRUDE_COMM_PickEntryForKind(u8 *p, u32 key)
{
    int sum;
    u32 i;
    u32 lv;

    sum = ((Src *)p)->h0c + ((Src *)p)->h0e;
    for (i = 0; i < 0xe0; i++) {
        Ent *e = &gIntrudePickTable[i];
        if (key == e->key && e->f1 <= sum && (e->f3 & 2)) {
            lv = e->f2;
            if (lv == 100 || lv >= func_020056EC(0x65)) {
                p[key] = i;
                return;
            }
        }
    }
}
