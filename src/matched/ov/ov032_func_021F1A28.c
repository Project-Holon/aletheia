/*
 * function: func_021F1A28
 * address:  0x021F1A28
 * packet:   pkt_ov032_021F1A28
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte-correct; the only wildcard is the bl to GPOWER_GetPowerCost (blocker: no
 * witness outside the range for an unlabelled arm9 leaf, the integrator's; it sits
 * in the word run after GPOWER_GetActiveIdOfSameType/GPOWER_GetSelectedMinutesLeft). Verified leaf C
 * (EXACT, arm9 0x02010FA0, thumb, `one --thumb` with no --region):
 *   typedef unsigned short u16;
 *   u16 GPOWER_GetPowerCost(unsigned char *rec, int slot)
 *   { return *(u16 *)(rec + slot * 0xc + 2); }
 * `u8 c` and `int flag` with `flag = 0` after the p[0x7f] store are what
 * put the flag's zero store after the argument copies.
 *
 * symbols:
 *   func_021F1A28 0x021F1A28 thumb
 *   func_021F1B94 0x021F1B94 thumb ov032
 *   func_021F1CF0 0x021F1CF0 thumb ov032
 *   BEACON_VIEW_SetArrowAnim 0x021F05E8 thumb ov032
 *   TCBL_AddTask 0x020311B8 arm
 *   TCBL_GetWork 0x02031290 arm
 *   TCBL_SetTaskFunc 0x02031288 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   WORDSET_SetSlotFromMsgA0 0x0201F184 thumb
 *   GPOWER_GetPowerCost 0x02010FA0 thumb
 *   func_02007FB8 0x02007FB8 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   GPOWER_GetActiveIdOfSameType 0x02010EA0 thumb
 *   GPOWER_GetSelectedMinutesLeft 0x02010EEC thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef signed int     s32;
struct Rec02010FA0;
struct S02030FB4;
struct WordSet;
extern void func_021F1B94(void *h, u8 *t);
extern void func_021F1CF0(void *h, u8 *t);
extern void BEACON_VIEW_SetArrowAnim(u8 *p, int a, u32 b);
extern void *TCBL_AddTask(u32 a, void *fn, u32 sz, u32 a3);
extern void *TCBL_GetWork(struct S02030FB4 *p);
extern void TCBL_SetTaskFunc(int *p, int v);
extern void MI_CpuFill8(void *p, int v, int n);
extern void WORDSET_SetSlotFromMsgA0(struct WordSet *p, u32 i, s32 v);
extern unsigned int GPOWER_GetPowerCost(struct Rec02010FA0 *p, int idx);
extern u32 func_02007FB8(u8 *base, u16 id, u16 d);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u8 GPOWER_GetActiveIdOfSameType(int slot, u8 *rec);
extern int GPOWER_GetSelectedMinutesLeft(void);

void func_021F1A28(char *p, int b, u8 c, int *r)
{
    void *h;
    int flag;
    u8 *t;

    h = TCBL_AddTask(*(u32 *)(p + 0xa0), (void *)func_021F1B94, 0x24, 0);
    t = TCBL_GetWork(h);
    MI_CpuFill8(t, 0, 0x24);
    p[0x7f] = 0x30;
    flag = 0;
    if (c == 0)
        flag = 1;
    p[0x80] = flag;
    *(char **)(t + 0x1c) = p;
    t[2] = 0x5a;
    *(int *)(t + 0xc) = b;
    t[3] = c;
    WORDSET_SetSlotFromMsgA0((struct WordSet *)(*(u32 *)(p + 0x110)), 1, b);
    if (t[3] == 0) {
        *(u16 *)(t + 0x12) = GPOWER_GetPowerCost((struct Rec02010FA0 *)(*(u32 *)(p + 0x24)), b);
        *(u16 *)(t + 0x10) = func_02007FB8((u8 *)(*(u32 *)(p + 0x18)), 0x23f, *(u16 *)(p + 0x96));
        WORDSET_SetSlotNumber((struct WordSet *)(*(u32 *)(p + 0x110)), 2, *(u16 *)(t + 0x12), 3, 0, 1);
        WORDSET_SetSlotNumber((struct WordSet *)(*(u32 *)(p + 0x110)), 3, *(u16 *)(t + 0x10), 3, 0, 1);
        if (b == GPOWER_GetActiveIdOfSameType(b, (u8 *)(*(u32 *)(p + 0x24)))) {
            *(u16 *)(t + 0x14) = GPOWER_GetSelectedMinutesLeft();
            if (*(u16 *)(t + 0x14) != 0) {
                *(u16 *)(t + 0x16) = *(u16 *)(t + 0x14) / 60;
                *(u16 *)(t + 0x18) = *(u16 *)(t + 0x14) % 60;
                WORDSET_SetSlotNumber((struct WordSet *)(*(u32 *)(p + 0x110)), 4, *(u16 *)(t + 0x16), 3, 0, 1);
                WORDSET_SetSlotNumber((struct WordSet *)(*(u32 *)(p + 0x110)), 5, *(u16 *)(t + 0x18), 2, 0, 1);
            }
        }
    }
    if (t[3] != 0)
        BEACON_VIEW_SetArrowAnim((u8 *)p, 0, 2);
    BEACON_VIEW_SetArrowAnim((u8 *)p, 1, 2);
    BEACON_VIEW_SetArrowAnim((u8 *)p, 2, 2);
    BEACON_VIEW_SetArrowAnim((u8 *)p, 3, 2);
    if (*(u16 *)(t + 0x14) != 0 || *(u16 *)(t + 0x10) < *(u16 *)(t + 0x12))
        TCBL_SetTaskFunc(h, (int)((void *)func_021F1CF0));
    *(int **)(t + 0x20) = r;
    (*r)++;
}
