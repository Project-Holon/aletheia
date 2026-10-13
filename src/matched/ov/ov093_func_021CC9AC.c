/*
 * function: BTL_SERVER_FLOW_AllocHandExRecord
 * address:  0x021CC9AC
 * packet:   pkt_ov093_021CC9AC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gHandExRecordSizeTable     0x021EFE9C  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct SizeEntry {
    u8 id;
    u8 size;
};

struct Rec {
    u32 id : 8;
    u32 b : 5;
    u32 size : 10;
    u32 x : 1;
    u32 pad : 2;
    u32 y : 1;
    u32 rest : 5;
};

struct Pack {
    u32 lo : 10;
    u32 off : 9;
    u32 rest : 13;
    u8 data[500];
};

extern struct SizeEntry gHandExRecordSizeTable[0x3B];

struct Rec *BTL_SERVER_FLOW_AllocHandExRecord(struct Pack *p, int id, int b)
{
    u32 i;
    u32 size;
    u32 off;
    u32 j;
    struct Rec *rec;

    i = 0;
    size = 0;
    for (; i < 0x3B; i++) {
        if (id == gHandExRecordSizeTable[i].id) {
            size = gHandExRecordSizeTable[i].size;
            break;
        }
    }
    if (size != 0) {
        while (size & 3) {
            size++;
        }
        off = p->off;
        if (off + size <= 500) {
            rec = (struct Rec *)(p->data + off);
            for (j = 0; j < size; j++) {
                p->data[p->off + j] = 0;
            }
            rec->id = id;
            rec->size = size;
            rec->b = b;
            rec->x = 0;
            rec->y = 1;
            p->off = p->off + size;
            return rec;
        }
    }
    return 0;
}
