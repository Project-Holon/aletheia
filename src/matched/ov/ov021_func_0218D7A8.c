/*
 * function: FIELD_G3D_MAPPER_ApplyLayout
 * address:  0x0218D7A8
 * packet:   pkt_ov021_0218D7A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Reconciles the grid object's live entries with a freshly laid-out cell
 * array (FIELD_G3D_MAPPER_UpdateBlocking's tail): entries whose id survives move to the new
 * position, the rest are hidden and released; new cells then take a free
 * entry.  Returns 1 when any free entry was claimed.
 *
 * symbols:
 *   FIELD_G3D_MAPPER_IsCellUsed  0x0218DD84  thumb ov021
 *   FIELD_G3D_MAPPER_GetCellGridIndex  0x0218DD98  thumb ov021
 *   FIELD_G3D_MAPPER_GetCellPos  0x0218DDA4  thumb ov021
 *   FIELD_G3D_MAPPER_ResetCell  0x0218DD70  thumb ov021
 *   FIELD_G3D_MAPPER_ReleaseGroundAnimeSlot  0x0218DD4C  thumb ov021
 *   FIELD_BUILDMODEL_UnregisterObject  0x0218B9FC  thumb ov021
 *   FIELD_G3D_MAP_SetPos  0x02169500  thumb ov010
 *   FIELD_G3D_MAP_SetVisible  0x021694F8  thumb ov010
 *   FIELD_G3D_MAP_Unload  0x021694D4  thumb ov010
 *   FIELD_G3D_MAP_StartLoad  0x02169470  thumb ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec {
    int x;
    int y;
    int z;
} Vec;

typedef struct Cell {
    u32 id;             /* 0x00 */
    int x;              /* 0x04 */
    int y;              /* 0x08 */
    int z;              /* 0x0C */
} Cell;

typedef struct Entry {
    int obj;            /* 0x00 */
    u8 desc[0x14];      /* 0x04 */
    Cell cell;          /* 0x18 */
} Entry;

typedef struct Obj {
    u16 heap;           /* 0x00 */
    u8 pad02[2];
    int size;           /* 0x04 */
    int height;         /* 0x08 */
    u32 mode;           /* 0x0C */
    u32 f10;            /* 0x10 */
    u16 w;              /* 0x14 */
    u16 h;              /* 0x16 */
    u32 count;          /* 0x18 */
    int *table;         /* 0x1C */
    u32 f20;            /* 0x20 */
    Entry *entries;     /* 0x24 */
    Cell *f28;          /* 0x28 */
    u8 cols;            /* 0x2C */
    u8 rows;            /* 0x2D */
    u16 n;              /* 0x2E */
    u8 pad30[0x64 - 0x30];
    int f64;            /* 0x64 */
} Obj;

extern int FIELD_G3D_MAPPER_IsCellUsed(u32 a);
extern u32 FIELD_G3D_MAPPER_GetCellGridIndex(u8 *p);
extern void FIELD_G3D_MAPPER_GetCellPos(Cell *c, Vec *v);
extern int FIELD_G3D_MAPPER_ResetCell(u32 a);
extern void FIELD_G3D_MAPPER_ReleaseGroundAnimeSlot(void **a);
extern void FIELD_BUILDMODEL_UnregisterObject(int a, int obj);
extern void FIELD_G3D_MAP_SetPos(u8 *p, u8 *q);
extern void FIELD_G3D_MAP_SetVisible(u8 *p, u16 v);
extern void FIELD_G3D_MAP_Unload(int obj);
extern void FIELD_G3D_MAP_StartLoad(u8 *obj, u32 member);

int FIELD_G3D_MAPPER_ApplyLayout(Obj *p, Cell *nc)
{
    int placed;
    int moved;
    int changed;
    int ret;
    int i;
    int j;

    ret = 0;
    for (i = 0; i < p->n; i++) {
        if (FIELD_G3D_MAPPER_IsCellUsed((u32)(&p->entries[i].cell))) {
            u32 id;
            moved = 0;
            id = FIELD_G3D_MAPPER_GetCellGridIndex((u8 *)(&p->entries[i].cell));
            for (j = 0; j < p->n; j++) {
                if (id == FIELD_G3D_MAPPER_GetCellGridIndex((u8 *)(&nc[j])) && !moved) {
                    Vec v;
                    FIELD_G3D_MAPPER_GetCellPos(&nc[j], &v);
                    FIELD_G3D_MAP_SetPos((u8 *)p->entries[i].obj, (u8 *)(&v));
                    FIELD_G3D_MAPPER_ResetCell((u32)(&nc[j]));
                    moved = 1;
                }
            }
            if (!moved) {
                FIELD_G3D_MAPPER_ResetCell((u32)(&p->entries[i].cell));
                FIELD_G3D_MAP_SetVisible((u8 *)p->entries[i].obj, 0);
                FIELD_BUILDMODEL_UnregisterObject(p->f64, p->entries[i].obj);
                FIELD_G3D_MAPPER_ReleaseGroundAnimeSlot((void **)p->entries[i].desc);
                FIELD_G3D_MAP_Unload(p->entries[i].obj);
            }
        }
    }
    changed = 0;
    for (i = 0; i < p->n; i++) {
        if (FIELD_G3D_MAPPER_IsCellUsed((u32)(&nc[i]))) {
            placed = 0;
            for (j = 0; j < p->n; j++) {
                if (!FIELD_G3D_MAPPER_IsCellUsed((u32)(&p->entries[j].cell)) && !placed) {
                    int obj = p->table[FIELD_G3D_MAPPER_GetCellGridIndex((u8 *)(&nc[i]))];
                    Vec v;
                    FIELD_G3D_MAPPER_GetCellPos(&nc[i], &v);
                    if (obj != -1) {
                        FIELD_G3D_MAP_StartLoad((u8 *)p->entries[j].obj, (u32)obj);
                        FIELD_G3D_MAP_SetPos((u8 *)p->entries[j].obj, (u8 *)(&v));
                        FIELD_G3D_MAP_SetVisible((u8 *)p->entries[j].obj, 1);
                    }
                    p->entries[j].cell = nc[i];
                    placed = 1;
                    changed = 1;
                }
            }
        }
    }
    if (changed == 1)
        ret = 1;
    return ret;
}
