/*
 * function: MAP_MATRIX_ApplyReplace
 * address:  0x02159CC4
 * packet:   pkt_ov010_02159CC4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MAP_REPLACE_Create  0x02159D84  thumb  ov010
 *   MAP_REPLACE_GetRecordCount  0x02159DC8  thumb  ov010
 *   MAP_REPLACE_LoadRecord  0x02159DCC  thumb  ov010
 *   MAP_MATRIX_ApplyReplaceRecord  0x02159C68  thumb  ov010
 *   MAP_REPLACE_Delete  0x02159DEC  thumb  ov010
 */

typedef unsigned int u32;

struct Obj;
extern struct Obj *MAP_REPLACE_Create(int a, int b);
extern u32 MAP_REPLACE_GetRecordCount(void *p);
typedef unsigned char  u8;
extern u32 MAP_REPLACE_LoadRecord(u8 *p, int n);
extern void MAP_MATRIX_ApplyReplaceRecord(struct Obj *a, int b, int c);
extern int MAP_REPLACE_Delete(int a0);

void MAP_MATRIX_ApplyReplace(u32 *a, int b, int c)
{
    void *l = MAP_REPLACE_Create(c, b);
    int n = MAP_REPLACE_GetRecordCount(l);
    int i;
    for (i = 0; i < n; i++) {
        u32 t = MAP_REPLACE_LoadRecord(l, i);
        if (t == a[1])
            MAP_MATRIX_ApplyReplaceRecord((struct Obj *)a, (int)l, c);
    }
    MAP_REPLACE_Delete((int)l);
}
