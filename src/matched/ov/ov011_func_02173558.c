/*
 * function: func_02173558
 * address: 0x02173558
 * packet: pkt_ov011_02173558
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02167688 0x02167688 thumb ov010
 * Extent contains followers 02173568, already-filed 02173580, and 0217358C;
 * the lead stays separate to preserve the existing follower file.
 */
typedef struct { void *sys; void *obj; } Work;
extern void func_02167688(Work *);
void func_02173558(int a, char *p)
{
    if (p != 0)
        func_02167688(*(Work **)(p + 8));
}
