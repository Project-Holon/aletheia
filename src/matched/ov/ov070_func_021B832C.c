/*
 * function: ITEMMENU_OpenActionMenu
 * address: 0x021B832C
 * packet: pkt_ov070_021B832C
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: ITEMMENU_OpenPopupList reads the count in r2; passing j keeps it in r2.
 * symbols:
 *   d_021BB998 0x021BB998 data ov070 a4
 *   d_021BB95C 0x021BB95C data a1
 *   ITEMMENU_BuildActionList 0x021B8280 thumb ov070
 *   ITEMMENU_OpenPopupList 0x021BA9C0 thumb ov070
 */
typedef struct { int v[11]; } T44;
typedef struct { unsigned char v[4]; } T4;
extern T44 d_021BB998;
extern T4 d_021BB95C;
struct Obj;
extern void ITEMMENU_BuildActionList(struct Obj *p, unsigned char *q);
extern void ITEMMENU_OpenPopupList(unsigned char *p, int *tbl, int n);
void ITEMMENU_OpenActionMenu(struct Obj *p)
{
    T44 t = d_021BB998;
    T4 a = d_021BB95C;
    int tmp[4];
    int j;
    int i;
    ITEMMENU_BuildActionList(p, (unsigned char *)(&a));
    i = 0;
    j = 0;
    for (; i < 4; i++) {
        int c = a.v[i];
        if (c != 0xFF) {
            *(int *)((char *)p + j * 4 + 0x828) = c;
            tmp[j] = t.v[a.v[i]];
            j++;
        }
    }
    ITEMMENU_OpenPopupList((unsigned char *)p, tmp, j);
}
