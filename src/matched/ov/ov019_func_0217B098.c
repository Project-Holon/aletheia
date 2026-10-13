/*
 * function: UNION_CHARA_AddBeaconMembers
 * address:  0x0217B098
 * packet:   pkt_ov019_0217B098
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02087C6C  0x02087C6C  arm
 *   func_0203EFC8  0x0203EFC8  arm
 *   UNION_CHARA_CheckMemberUnique  0x0217B158  thumb  ov019
 *   UNION_CHARA_AddSlot  0x0217AFE4  thumb  ov019
 *   UNION_CHARA_SetNextAction  0x0217AE38  thumb  ov019
 *   func_0217F894  0x0217F894  thumb  ov019
 *   func_0200EDC4  0x0200EDC4  thumb
 *   UNION_EFF_AddIcon  0x0217F948  thumb  ov019
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 mac[6];
    u8 pad;
    u8 f0 : 1;
    u8 f1 : 1;
} Ent8;

typedef struct {
    u8 pad[0x28];
    Ent8 tab[5];
    u8 pad2[0x5c - 0x50];
    int f5c;
    u8 pad3[0x6c - 0x60];
    u16 f6c;
    u8 pad4[2];
    u8 *slot[5];
} Obj;

extern void func_02087C6C(void *);
typedef signed int     s32;
extern s32 func_0203EFC8(const u8 *a, const u8 *b, unsigned int n);
struct ent;
extern int UNION_CHARA_CheckMemberUnique(char *base, struct ent *excl, u8 *mac);
extern u8 *UNION_CHARA_AddSlot(int, Obj *, Ent8 *, int, int, int *);
extern int UNION_CHARA_SetNextAction(char *p, char v);
extern int func_0217F894(void *p, char *q);
typedef unsigned int   u32;
struct L0200EDC4;
extern int func_0200EDC4(struct L0200EDC4 *l, u32 val);
extern void UNION_EFF_AddIcon(char *p, u32 a, u32 b);

void UNION_CHARA_AddBeaconMembers(int a, int b, int c, int d, Obj *e)
{
    int out;
    u8 buf[8];
    int i;

    if (e->f6c == 0)
        return;
    func_02087C6C(buf);
    for (i = 0; i < 5; i++) {
        if (e->slot[i] == 0 && e->tab[i].f1 == 1
            && func_0203EFC8(buf, (const u8 *)(&e->tab[i]), 6) != 0
            && UNION_CHARA_CheckMemberUnique((char *)a, (struct ent *)e, (u8 *)(&e->tab[i])) != 0) {
            e->slot[i] = UNION_CHARA_AddSlot(a, e, &e->tab[i], i, 0, &out);
            e->slot[i][8] = 1;
            UNION_CHARA_SetNextAction((char *)e->slot[i], 0);
            if (i == 0) {
                if (func_0217F894((void *)c, (char *)e) == 1)
                    UNION_EFF_AddIcon((char *)d, out, 0);
                else if (func_0200EDC4((struct L0200EDC4 *)b, e->f5c) == 1)
                    UNION_EFF_AddIcon((char *)d, out, 1);
            }
        }
    }
}
