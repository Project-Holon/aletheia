/*
 * function: UNION_COMM_RemoveMember
 * address:  0x02173614
 * packet:   pkt_ov012_02173614
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   memcmp        0x0203EFC8  arm
 *   MI_CpuFill8 0x02082BCC  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 mac[6];
    u8 f6;
    u8 b0 : 1;
    u8 b1 : 1;
} Rec;

extern int memcmp(const void *a, const void *b, int n);
extern void MI_CpuFill8(void *p, u32 v, u32 n);

void UNION_COMM_RemoveMember(u8 *self, const u8 *mac)
{
    int i;
    Rec *r;

    i = 0;
    r = (Rec *)(self + 0x1c);
    for (; i < 5; i++) {
        if (r[i].b1 == 1 && memcmp(mac, &r[i], 6) == 0) {
            MI_CpuFill8(&r[i], 0, 8);
            return;
        }
    }
}
