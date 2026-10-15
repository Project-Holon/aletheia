/*
 * function: INTRUDE_COMM_VIEW_StorePeerRecord
 * address: 0x021D5278
 * packet: pkt_ov122_021D5278
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: zero padding at 0x021D530E; next function at 0x021D5310.
 * symbols:
 *   func_0203EFC8 0x0203EFC8 arm
 *   MI_CpuCopy8 0x02082D44 arm
 */
typedef unsigned short u16;
typedef struct { char f00[8]; u16 f08, f0a; } Entry;
typedef struct { char pad00[0x64]; Entry f64[16]; } Object;
typedef signed int     s32;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern void MI_CpuCopy8(const void *, void *, int);
void INTRUDE_COMM_VIEW_StorePeerRecord(Object *p, const char *data, int value, int tag)
{
    int i;
    if (value >= 20 && value <= 27) {
        for (i = 0; i < 16; i++) {
            if (p->f64[i].f08 && !func_0203EFC8((const u8 *)p->f64[i].f00, (const u8 *)(data + 4), 6)) {
                p->f64[i].f08 = 600;
                p->f64[i].f0a = tag;
                return;
            }
        }
        for (i = 0; i < 16; i++) {
            if (!p->f64[i].f08) {
                MI_CpuCopy8(data + 4, p->f64[i].f00, 6);
                p->f64[i].f08 = 600;
                p->f64[i].f0a = tag;
                return;
            }
        }
    }
}
