/*
 * function: UNION_CHARA_Main
 * address:  0x0217B264
 * packet:   pkt_ov019_0217B264
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   MISC_SAVEDATA_GetBlock44  0x0200ED48  thumb
 *   func_0201283C  0x0201283C  thumb
 *   func_02012964  0x02012964  thumb
 *   FIELDMAP_GetUnionEff  0x02188CE0  thumb  ov021
 *   memcmp         0x0203EFC8  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   UNION_CHARA_DeleteSlot  0x0217B054  thumb  ov019
 *   UNION_CHARA_AddBeaconMembers  0x0217B098  thumb  ov019
 *   UNION_CHARA_FocusRequestedMember  0x0217B1D0  thumb  ov019
 *   UNION_CHARA_RunAction  0x0217B370  thumb  ov019
 *   UNION_CHARA_TickBeaconLife  0x0217B3EC  thumb  ov019
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Entry {
    u8   pad0[7];
    u8   f7_lo : 4;
    u8   active : 1;
    u8   f7_hi : 3;
    u8   pad8[0x6C - 8];
    u16  h6C;
    u16  pad6E;
    void *slots[5];
    u8   pad84[8];
} Entry;

struct Big;
struct BigObj;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *MISC_SAVEDATA_GetBlock44(void *p);
extern u32 func_0201283C(const struct BigObj *p);
extern u32 func_02012964(const struct BigObj *p);
extern u32 FIELDMAP_GetUnionEff(u8 *p);
extern int   memcmp(const void *a, const void *b, u32 n);
extern void  MI_CpuFill8(void *dst, u8 val, u32 size);
extern void  UNION_CHARA_DeleteSlot(u8 *w, Entry *e, void *p);
extern void  UNION_CHARA_AddBeaconMembers(u8 *w, u32 a, u32 b, u32 c, Entry *e);
struct ent;
struct obj;
extern int UNION_CHARA_FocusRequestedMember(struct obj *o, struct ent *e);
extern int UNION_CHARA_RunAction(char *base, unsigned char *p, int r2);
extern int UNION_CHARA_TickBeaconLife(char *base, char *p);

void UNION_CHARA_Main(u8 *w, void *sys, void *q)
{
    int i;
    int flag;
    u32 a;
    u32 b;
    u32 c;
    Entry *e;
    u8 buf[6] = {0, 0, 0, 0, 0, 0};

    flag = 0;
    a = (u32)MISC_SAVEDATA_GetBlock44(GAME_DATA_GetSaveControl(sys));
    b = func_0201283C(sys);
    c = FIELDMAP_GetUnionEff(q);
    func_02012964(sys);
    if (memcmp(buf, w + 0x28A4, 6) != 0) {
        flag = 1;
    }
    e = (Entry *)(w + 0x2910);
    for (i = 0; i < 10; i++, e++) {
        if (e->active == 1) {
            int cnt;
            int j;
            void *p;

            UNION_CHARA_TickBeaconLife((char *)w, (char *)e);
            UNION_CHARA_AddBeaconMembers(w, a, b, c, e);
            if (flag == 1) {
                if (UNION_CHARA_FocusRequestedMember((struct obj *)w, (struct ent *)e) == 1) {
                    flag = 0;
                }
            }
            cnt = 0;
            for (j = 0; j < 5; j++) {
                p = e->slots[j];
                if (p != 0) {
                    if (UNION_CHARA_RunAction((char *)w, p, (int)q) == 0) {
                        UNION_CHARA_DeleteSlot(w, e, p);
                        e->slots[j] = 0;
                        cnt++;
                    }
                } else {
                    cnt++;
                }
            }
            if (cnt >= 5 && e->h6C == 0) {
                MI_CpuFill8(e, 0, sizeof(Entry));
            }
        }
    }
    MI_CpuFill8(w + 0x28A4, 0, 6);
}
