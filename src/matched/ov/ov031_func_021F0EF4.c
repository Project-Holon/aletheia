/*
 * function: UNION_SUBDISP_UpdateLineHighlights
 * address:  0x021F0EF4
 * packet:   pkt_ov031_021F0EF4
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   UNION_SUBDISP_UpdateLineHighlights  0x021F0EF4  thumb
 *   UNION_SUBDISP_SetLinePalette  0x021F0F68  thumb  ov031
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct {
    u16 cnt;
    u8 idx;
    u8 pad;
} Slot;

typedef struct {
    char pad[0x34];
    Slot s[3];
} A;

typedef struct {
    char pad[0x440];
    int n;
} B;

extern int UNION_SUBDISP_SetLinePalette(void *, int, int);

void UNION_SUBDISP_UpdateLineHighlights(A *p, B *q)
{
    int i;
    int k;
    int n;

    for (i = 0; i < 3; i++) {
        if (p->s[i].cnt != 0) {
            p->s[i].cnt--;
            if (p->s[i].cnt == 0) {
                n = q->n;
                if (n < 3)
                    k = p->s[i].idx;
                else
                    k = p->s[i].idx + 2 - n;
                if (k >= 0 && k < 3)
                    UNION_SUBDISP_SetLinePalette(p, k, 0);
            }
        }
    }
}
