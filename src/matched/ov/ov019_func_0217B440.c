/*
 * function: UNION_CHARA_RefreshParentMarks
 * address:  0x0217B440
 * packet:   pkt_ov019_0217B440
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAME_DATA_GetSaveControl 0x02012EBC  thumb
 *   func_0200ED48 0x0200ED48  thumb
 *   GAME_DATA_GetWifiList 0x0201283C  thumb
 *   FIELDMAP_GetUnionEff 0x02188CE0  thumb  ov021
 *   UNION_CHARA_GetMmdl 0x0217AFB0  thumb  ov019
 *   func_0217F894 0x0217F894  thumb  ov019
 *   func_0200EDC4 0x0200EDC4  thumb
 *   UNION_EFF_AddIcon 0x0217F948  thumb  ov019
 */

typedef unsigned char u8;

struct ent {
    u8 pad0[7];
    u8 : 4;
    u8 on : 1;
    u8 : 3;
    u8 pad1[0x54];
    int f5c;
    u8 pad2[0x10];
    int *p70;
    u8 pad3[0x18];
};

typedef unsigned int   u32;
struct Big;
struct BigObj;
struct L0200EDC4;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200ED48(void *p);
extern u32 GAME_DATA_GetWifiList(const struct BigObj *p);
extern u32 FIELDMAP_GetUnionEff(u8 *p);
extern void *UNION_CHARA_GetMmdl(void **a, u8 *b, u8 *c);
extern int func_0217F894(void *p, char *q);
extern int func_0200EDC4(struct L0200EDC4 *l, u32 val);
extern void UNION_EFF_AddIcon(char *p, u32 a, u32 b);

void UNION_CHARA_RefreshParentMarks(char *base, int x, void *y)
{
    struct ent *q;
    int a;
    int b;
    int c;
    int r;
    int i;

    a = (int)func_0200ED48(GAME_DATA_GetSaveControl((struct Big *)x));
    b = GAME_DATA_GetWifiList((const struct BigObj *)x);
    c = FIELDMAP_GetUnionEff((u8 *)y);
    q = (struct ent *)(base + 0x2910);
    for (i = 0; i < 10; i++, q++) {
        if (q->on == 1 && q->p70 != 0) {
            r = (int)UNION_CHARA_GetMmdl((void **)base, (u8 *)(*q->p70), (u8 *)q->p70);
            if (r != 0) {
                if (func_0217F894((void *)b, (char *)q) == 1) {
                    UNION_EFF_AddIcon((char *)c, r, 0);
                } else if (func_0200EDC4((struct L0200EDC4 *)a, q->f5c) == 1) {
                    UNION_EFF_AddIcon((char *)c, r, 1);
                }
            }
        }
    }
}
