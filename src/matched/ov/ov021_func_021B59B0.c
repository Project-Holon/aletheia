/*
 * function: SCRCMD_FLD_BATTLE_PartyCheckTaskMain
 * address:  0x021B59B0
 * packet:   pkt_ov021_021B59B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PARTY_SELECT_LIST_Create  0x021CC720  thumb  ov021
 *   PARTY_SELECT_LIST_Main  0x021CC810  thumb  ov021
 *   PARTY_SELECT_LIST_Delete  0x021CC7B4  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u8 f14;
    u8 f15;
    u16 f16;
    u16 *f18;
} Work;

struct Obj;
extern struct Obj *PARTY_SELECT_LIST_Create(u32 a, u32 b, u32 c, u32 d, u32 e, u16 heap);
extern int PARTY_SELECT_LIST_Main(struct Obj *p);
extern u32 PARTY_SELECT_LIST_Delete(struct Obj *p, u32 *out);
extern u32 func_020307B0(void *p);

int SCRCMD_FLD_BATTLE_PartyCheckTaskMain(int a0, int *state, Work *w)
{
    int loc;

    switch (*state) {
    case 0:
        w->f8 = (u32)PARTY_SELECT_LIST_Create(w->f4, w->fc, w->f10, w->f14, w->f15, w->f16);
        (*state)++;
        break;
    case 1:
        if (PARTY_SELECT_LIST_Main((struct Obj *)w->f8)) {
            *w->f18 = PARTY_SELECT_LIST_Delete((struct Obj *)w->f8, (u32 *)(&loc));
            if (loc == 1) {
                *w->f18 = 3;
            }
            func_020307B0((void *)w->f10);
            return 1;
        }
        break;
    }
    return 0;
}
