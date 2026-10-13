/*
 * function: BTL_POKESET_GetPlainDamage
 * address:  0x0689CCF8
 * packet:   pkt_0689CC8C
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * notes:    unlabelled Thumb function after BTL_POKESET_GetTotalDamage; seeded in
 *           layout/function_starts.txt.
 *
 * symbols:
 *   func_021B9A24  0x021B9A24  thumb
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   BTL_POKESET_Clear  0x0689CB3C  thumb
 *   BTL_POKESET_Add  0x0689CB48  thumb
 *   BTL_POKESET_AddWithDamage  0x0689CBB8  thumb
 *   BTL_POKESET_Remove  0x0689CC14  thumb
 *   BTL_POKESET_Get  0x0689CC70  thumb
 *   BTL_POKESET_SeekStart  0x0689CC84  thumb
 *   BTL_POKESET_SeekNext  0x0689CC8C  thumb
 *   BTL_POKESET_GetTotalDamage  0x0689CCB4  thumb
 *   BTL_POKESET_GetCount  0x0689CD38  thumb
 *   BTL_POKESET_GetCountMax  0x0689CD40  thumb
 *   BTL_POKESET_SetEmptyMarked  0x0689CD48  thumb
 *   BTL_POKESET_IsRemovedAll  0x0689CD50  thumb
 *   BTL_POKESET_CopyAlive  0x0689CD78  thumb
 *   BTL_POKESET_CopyFriends  0x0689CDCC  thumb
 *   BTL_POKESET_CopyEnemies  0x0689CE58  thumb
 */

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u32 id[6];
    u16 a[6];
    u16 b[6];
    u8 c[6];
    u16 d[6];
    u8 n;
    u8 max;
    u8 f44;
    u8 f45;
} S;

struct S {
    u32 arr[16];
    u8 _40[0x42 - 0x40];
    u8 f42;
    u8 _43;
    u8 f44;
};

void MI_CpuFill8(void *p, int v, int n);
int BTL_POKEPARAM_IsFainted(u32 x);
int BTL_POKEPARAM_GetPokeId();
int func_021B9A24(int a, int b);
void BTL_POKESET_Clear(void *p);
void BTL_POKESET_Add(S *p, u32 id);
void BTL_POKESET_AddWithDamage(S *p, u32 id, u16 amt, int flag);
void BTL_POKESET_Remove(S *p, u32 id);
u32 BTL_POKESET_Get(S *p, u32 i);
void BTL_POKESET_SeekStart(char *p);
int BTL_POKESET_SeekNext(struct S *s);
int BTL_POKESET_GetTotalDamage(S *p, u32 id, u32 *out);
#pragma opt_common_subs off
int BTL_POKESET_GetPlainDamage(S *p, u32 id, u32 *out);
int BTL_POKESET_GetCount(S *p);
int BTL_POKESET_GetCountMax(S *p);
void BTL_POKESET_SetEmptyMarked(S *p, u8 v);
int BTL_POKESET_IsRemovedAll(S *p);
int BTL_POKESET_CopyAlive(S *p, S *q);
int BTL_POKESET_CopyFriends(S *p, int a, S *q);
int BTL_POKESET_CopyEnemies(S *p, int a, S *q);

int BTL_POKESET_GetPlainDamage(S *p, u32 id, u32 *out)
{
    u32 i;
    u32 t;
    for (i = 0; i < p->n; i++) {
        t = p->id[i];
        if (t == id && p->c[i] == 1) {
            *out = p->a[i];
            return 1;
        }
    }
    return 0;
}
#pragma opt_common_subs reset
