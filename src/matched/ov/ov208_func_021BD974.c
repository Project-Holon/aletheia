/*
 * function: ZUKAN_DETAIL_TOUCHBAR_Update
 * address: 0x021BD974
 * packet: pkt_ov208_021BD974
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02040804 0x02040804 arm
 *   func_02041EE4 0x02041EE4 arm
 *   ZUKAN_DETAIL_TOUCHBAR_OffsetActorPos 0x021BDD48 thumb
 *   ZKND_TBAR_SetTouchEnable 0x021BD358 thumb
 *   ZKND_TBAR_UpdateButtons 0x021BD23C thumb
 *   ZUKAN_DETAIL_TOUCHBAR_UpdateInput 0x021BDFDC thumb
 *   ZUKAN_DETAIL_TOUCHBAR_LoadPaletteTable 0x021BE20C thumb
 *   ZUKAN_DETAIL_TOUCHBAR_UpdateArrowInput 0x021BE6A8 thumb
 *   d_021C8388 0x021C8388 data a4
 *   d_021C8384 0x021C8384 data a1
 */
typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;
struct Ov208Fade {
    int f0; int f4; int state; int fc; int mode; int f14; int f18; int f1c;
    int idx;
    u8 cnt;
    char pad25[0x0b];
    void *f30; int f34; char pad38[0x7c];
    s16 pos;
};
extern const int d_021C8388[];
extern const u8 d_021C8384[];
struct Ov208Menu;
extern u32 func_02040804(u32 layer);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern void ZUKAN_DETAIL_TOUCHBAR_OffsetActorPos(char *p, short offset);
extern void ZKND_TBAR_SetTouchEnable(char *p, int v);
extern void ZKND_TBAR_UpdateButtons(char *p);
extern void ZUKAN_DETAIL_TOUCHBAR_UpdateInput(struct Ov208Menu *m);
typedef signed int     s32;
struct Ov208Pal;
extern s32 ZUKAN_DETAIL_TOUCHBAR_LoadPaletteTable(struct Ov208Pal *m);
extern void ZUKAN_DETAIL_TOUCHBAR_UpdateArrowInput(char *p);
void ZUKAN_DETAIL_TOUCHBAR_Update(struct Ov208Fade *m)
{
    int v;
    switch (m->state) {
    case 0:
    case 2:
        break;
    case 1:
        if (m->cnt == 0) {
            if ((int)func_02040804((int)1) >= 0) {
                func_02041EE4(1, 3, 0);
                m->pos = 0;
                ZUKAN_DETAIL_TOUCHBAR_OffsetActorPos((char *)m, m->pos);
                m->state = 2;
                if (m->f34 != 0)
                    ZKND_TBAR_SetTouchEnable(m->f30, 1);
                break;
            }
            func_02041EE4(1, 4, d_021C8388[m->idx]);
            m->pos = m->pos - (s16)d_021C8388[m->idx];
            ZUKAN_DETAIL_TOUCHBAR_OffsetActorPos((char *)m, m->pos);
            m->cnt = d_021C8384[m->idx];
        } else {
            m->cnt--;
        }
        break;
    case 3:
        if (m->cnt == 0) {
            if ((int)func_02040804((int)1) <= -24) {
                func_02041EE4(1, 3, -24);
                m->pos = 24;
                ZUKAN_DETAIL_TOUCHBAR_OffsetActorPos((char *)m, m->pos);
                m->state = 0;
            } else {
                func_02041EE4(1, 5, d_021C8388[m->idx]);
                m->pos = m->pos + (s16)d_021C8388[m->idx];
                ZUKAN_DETAIL_TOUCHBAR_OffsetActorPos((char *)m, m->pos);
                m->cnt = d_021C8384[m->idx];
            }
        } else {
            m->cnt--;
        }
        break;
    }
    ZKND_TBAR_UpdateButtons(m->f30);
    if (m->mode == 0) {
        ZUKAN_DETAIL_TOUCHBAR_UpdateInput((struct Ov208Menu *)m);
        ZUKAN_DETAIL_TOUCHBAR_LoadPaletteTable((struct Ov208Pal *)m);
    } else if (m->mode == 2) {
        ZUKAN_DETAIL_TOUCHBAR_UpdateArrowInput((char *)m);
    }
}
