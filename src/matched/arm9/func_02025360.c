/*
 * function: ACTOR_TOOL_AllocRun
 * address:  0x02025360
 * packet:   pkt_02025360
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * actor_tool.c: allocate a run of len free (0xFF) slots in one bank and
 * stamp every slot of the run with its start index; returns the start, or 0.
 * ACTOR_TOOL_FreeRun frees what this stamps.
 *
 * THE LEVER (wave 18, lane ties_b; it was DIFF 116/116, 21 out after wave
 * 17, docs/notes/pkt_02025360.c.txt): the scan loop's bound is written
 * `j < i + len` in the loop condition, and `end = i + len` is computed only
 * after the scan for the fill. With `end` assigned before the scan and used
 * as its bound, end / scan base / count pointer rotate through r2/r3/r4
 * instead of the image's r4/r2/r3. Found by tools/permuter.py anneal
 * (seed 2101, mutation expand(end)).
 */

typedef unsigned char u8;
typedef unsigned int  u32;
struct ActorTool {
    u32 f00;
    u8  count[2];
    u8  slot[2][16];
};
int ACTOR_TOOL_AllocRun(struct ActorTool *p, int len, u32 bank)
{
    int i, j, end;
    u32 sel = 1;
    u8 *dst;

    if (bank == 0)
        sel = 0;
    i = 0;
    if (i < p->count[sel]) {
        do {
            if (p->slot[sel][i] == 0xff) {
                for (j = i; j < i + len; j++) {
                    if (p->slot[sel][j] != 0xff) {
                        i = j;
                        break;
                    }
                }
                end = i + len;
                if (j == end) {
                    for (j = i; j < end; j++) {
                        dst = (u8 *)p + (sel << 4);
                        dst[j + 6] = (u8)i;
                    }
                    return i;
                }
            }
            i++;
        } while (i < p->count[sel]);
    }
    return 0;
}
